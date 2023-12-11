import time
import subprocess
import pyautogui
import random
import pyperclip

def paste_in_chat():
    messages = ["Hey, that would be nice if u helped me with achieving my goal", "I really wanna get this goal finished by tomorrow", "Thank u so much for ur donations:)", "Thanks a million for your generous donation! Your support is invaluable.", "Your donation is a game-changer! Thank you for making a difference.", "Grateful for your generosity! Your donation fuels our mission.", "A heartfelt thank you for your donation! Your kindness is appreciated.", "Big thanks for your impactful donation! Your generosity makes a difference.", "Heartfelt gratitude for your generous support. Your donation drives our mission.", "Thank you for investing in our cause. Your donation is a powerful catalyst.", "Grateful for your donation! Your belief propels us forward.", "Thanks for your generous contribution! Your support is invaluable."]
    random_message = random.choice(messages)  # Use random.choice() to pick a random message
    pyperclip.copy(random_message)  # Copy the message to the clipboard
    pyautogui.click(55, 334)
    pyautogui.hotkey("command", "v")  # Simulate paste (Ctrl+V)
    pyautogui.press("enter")  


def switch_and_press_space(app_name, original_app_name):
    try:
        # Activate the specified app
        activate_script = f'tell application "{app_name}" to activate'
        subprocess.run(["osascript", "-e", activate_script])
        time.sleep(1)

        paste_in_chat()

        time.sleep(2)

        # Simulate pressing the space bar (adjust as needed)
        time.sleep(1)

        pyautogui.click(850, 550)
        pyautogui.click(850, 550)

        time.sleep(1)
        
        pyautogui.press('space')
        pyautogui.press('space')

        time.sleep(1)

        # Switch back to the original app
        original_activate_script = f'tell application "{original_app_name}" to activate'
        subprocess.run(["osascript", "-e", original_activate_script])

    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    app_name = "Roblox"  # Replace with the actual name of your application
    original_app_name = "Opera"  # Replace with the name of the app to switch back to

    while True:
        switch_and_press_space(app_name, original_app_name)

        # Wait for 3 minutes before repeating
        time.sleep((60))
