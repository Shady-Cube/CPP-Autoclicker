#include "CPP_Clicker.h"

int main()
{
    srand(time(NULL)); // Set random seed based on system time

    Menu();
    Clicker();
}

void Menu()
{
    // Welcome user
    std::cout << R"( ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ 
||C |||+ |||+ |||C |||l |||i |||c |||k |||e |||r ||
||__|||__|||__|||__|||__|||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|/__\|/__\|/__\|/__\|/__\|)" << std::endl;
    std::cout << "Version 1.0\n";
    std::cout << "Hold \"F\" to autoclick\n";

    // Ask user for CPS
    std::cout << "\nPlease enter the average CPS\n";
    std::cin >> CPS;
}

void Clicker()
{
    switch (Debug) // Check if debug mode is on
    {
    case true:
        while (1)
        {
            if (GetAsyncKeyState('F')) // Check if Click button is pressed
            {
                // Click
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 6 + 2));
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);

                std::cout << "Click! " << ClickDelay << "ms since last click.\n"; // Debug line

                ClickDelay = 1000 / CPS + rand() % rand() % rand() % 5 * CPS - rand() % rand() % rand() % 5 * CPS; // Set random sleep delay
                std::this_thread::sleep_for(std::chrono::milliseconds(ClickDelay));

                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Prevent the last mouse state being MOUSEEVENTF_LEFTDOWN
            }
        }    
        break;

    case false:
        while (1)
        {
            if (GetAsyncKeyState('F')) // Check if Click button is pressed
            {
                // Click
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 6 + 2));
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);

                ClickDelay = 1000 / CPS + rand() % rand() % rand() % 7 * CPS - rand() % rand() % rand() % 7 * CPS; // Set random sleep delay
                std::this_thread::sleep_for(std::chrono::milliseconds(ClickDelay));

                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0); // Prevent the last mouse state being MOUSEEVENTF_LEFTDOWN
            }
        }
        break;
    }
}

