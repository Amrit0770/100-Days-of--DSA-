import speech_recognition as sr
import pyttsx3
import webbrowser
import sys

# Initialize the text-to-speech engine
try:
    engine = pyttsx3.init()
except Exception as e:
    print(f"Warning: Text-to-speech engine failed to initialize: {e}")
    engine = None

def speak(text):
    print(f"Assistant: {text}")
    if engine:
        try:
            engine.say(text)
            engine.runAndWait()
        except Exception as e:
            print(f"Warning: Could not speak: {e}")

def listen():
    recognizer = sr.Recognizer()
    try:
        # Check if we are in a terminal that might not have a microphone
        with sr.Microphone() as source:
            print("Listening...")
            recognizer.adjust_for_ambient_noise(source)
            audio = recognizer.listen(source, timeout=5)
            query = recognizer.recognize_google(audio)
            print(f"User: {query}")
            return query.lower()
    except Exception:
        # Fallback to text input for testing environment or if microphone fails
        print("Microphone not detected or error occurred. Please type your command below.")
        query = input("User (type command): ")
        return query.lower()

def process_command(command):
    if "show world map" in command:
        speak("Sure, showing the world map.")
        webbrowser.open("https://www.google.com/maps")
        return True

    elif "search vacation" in command:
        location = command.replace("search vacation in", "").strip()
        if location == "search vacation" or not location:
             speak("Which location would you like to search for your vacation?")
             location = listen()

        speak(f"Searching for vacation ideas in {location}.")
        webbrowser.open(f"https://www.google.com/search?q=vacation+ideas+in+{location}")
        return True

    elif "search" in command:
        query = command.replace("search", "").strip()
        speak(f"Searching for {query}.")
        webbrowser.open(f"https://www.google.com/search?q={query}")
        return True

    elif "exit" in command or "stop" in command:
        speak("Goodbye! Have a great day.")
        return False

    else:
        speak("I am not sure how to help with that yet. Try saying 'show world map' or 'search vacation in Hawaii'.")
        return True

def main():
    speak("Hello! I am your personal voice assistant. How can I help you today?")

    running = True
    while running:
        command = listen()
        if command:
            running = process_command(command)
        else:
            speak("I didn't catch that. Could you repeat?")

if __name__ == "__main__":
    main()
