#ifndef INTRO_HPP
#define INTRO_HPP

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <windows.h>
#include "color.hpp"

using namespace std;

inline void sleepMs(int ms)
{
    this_thread::sleep_for(chrono::milliseconds(ms));
}

inline void clearScreen()
{
    system("cls");
}

inline void printSlow(const string& text, int delay = 35)
{
    for (char ch : text)
    {
        cout << ch;
        sleepMs(delay);
    }
}

inline bool loginSystem()
{
    string username;
    string pass;

    const string correctUsername = "SISI";
    const string correctPass = "1234";

    int attempts = 3;

    while (attempts > 0)
    {
        clearScreen();

        color(11);
        printSlow("========================================\n", 15);
        printSlow("          NASA NETWORK LOGIN            \n", 20);
        printSlow("========================================\n", 15);
        resetColor();

        cout << endl;

        color(14);
        cout << "USERNAME: ";
        resetColor();
        cin >> username;

        color(14);
        cout << "PASSWORD: ";
        resetColor();
        cin >> pass;

        if (username == correctUsername && pass == correctPass)
        {
            clearScreen();

            color(10);
            printSlow("========================================\n", 15);
            printSlow("            ACCESS GRANTED            \n", 20);
            printSlow("========================================\n", 15);
            resetColor();

            cout << endl;

            color(11);
            printSlow("Verifying identity...\n", 20);
            sleepMs(400);
            printSlow("Loading Mission Control access...\n", 35);
            sleepMs(300);

            return true;
        }
        else
        {
            attempts--;

            clearScreen();

            color(12);
            cout << "========================================" << endl;
            cout << "              ACCESS DENIED             " << endl;
            cout << "========================================" << endl;
            resetColor();

            cout << endl;
            cout << "Wrong username or password." << endl;
            cout << "Attempts left: " << attempts << endl;

            sleepMs(1500);
        }
    }

    clearScreen();

    color(12);
    cout << "========================================" << endl;
    cout << "              SYSTEM LOCKED             " << endl;
    cout << "========================================" << endl;
    resetColor();

    cout << endl;
    cout << "Too many failed login attempts." << endl;
    cout << "Program will now close." << endl;

    sleepMs(2500);

    return false;
}

inline void showIntro()
{
    vector<string> rocket =
    {
        "           /\\           ",
        "          /  \\          ",
        "         /____\\         ",
        "        | NASA |        ",
        "        |      |        ",
        "        |  []  |        ",
        "        |      |        ",
        "        |______|        ",
        "        /|    |\\        ",
        "       /_|____|_\\       "
    };

    vector<vector<string>> flame =
    {
        {
            "          /\\/\\          ",
            "         / /\\ \\         ",
            "        /_/  \\_\\        "
        },
        {
            "          ||||          ",
            "         ||||||         ",
            "          \\/\\/          "
        },
        {
            "          \\  /          ",
            "         / /\\ \\         ",
            "        /_/  \\_\\        "
        }
    };

    vector<string> earth =
    {
        "          .-''''''-.",
        "       .-'          '-.",
        "      /   EARTH BASE   \\",
        "      \\                /",
        "       '-.          .-'",
        "          '-......-'"
    };

    int screenHeight = 30;
    int frame = 0;

    clearScreen();

    color(11);
    cout << "\n\n";
    cout << "========================================" << endl;
    cout << "             NASA IT PROJECT            " << endl;
    cout << "        Space Exploration Simulator     " << endl;
    cout << "========================================" << endl << endl;

    color(14);
    printSlow("Initializing mission control systems...\n", 35);
    sleepMs(500);
    printSlow("Loading astronauts, rockets and planets...\n", 25);
    sleepMs(500);
    printSlow("Preparing launch sequence...\n", 15);
    sleepMs(900);

    color(14);
    cout << "\n3..." << endl;
    sleepMs(500);
    cout << "2..." << endl;
    sleepMs(500);
    cout << "1..." << endl;
    sleepMs(500);

    color(12);
    cout << "\nIGNITION!" << endl;
    sleepMs(800);

    for (int y = 14; y >= -13; y--)
    {
        clearScreen();

        for (int row = 0; row < screenHeight; row++)
        {
            int rocketRow = row - y;

            if (rocketRow >= 0 && rocketRow < static_cast<int>(rocket.size()))
            {
                color(15);
                cout << rocket[rocketRow] << endl;
            }
            else if (rocketRow >= static_cast<int>(rocket.size()) &&
                rocketRow < static_cast<int>(rocket.size()) + 3)
            {
                color(12 + frame % 3);
                cout << flame[frame % 3][rocketRow - static_cast<int>(rocket.size())] << endl;
            }
            else if (row >= 23 && row < 23 + static_cast<int>(earth.size()) && y > 0)
            {
                color(9);
                cout << earth[row - 23] << endl;
            }
            else
            {
                if (row % 6 == frame % 6)
                {
                    color(8);
                    cout << "        .              *          .     " << endl;
                }
                else if (row % 7 == frame % 7)
                {
                    color(7);
                    cout << "   *          .              .        * " << endl;
                }
                else
                {
                    cout << endl;
                }
            }
        }

        frame++;

        if (y > 8)
        {
            sleepMs(180);
        }
        else if (y > 0)
        {
            sleepMs(120);
        }
        else
        {
            sleepMs(70);
        }
    }

    clearScreen();

    color(10);
    cout << "\n\n";
    cout << "========================================" << endl;
    cout << "          LAUNCH SUCCESSFUL             " << endl;
    cout << "========================================" << endl << endl;

    color(11);
    printSlow("Welcome SISI to NASA Mission Control.\n", 40);
    sleepMs(2000);

    color(15);
}


#endif


/*inline void showIntro()
{
    vector<string> rocket =
    {
        "           /\\           ",
        "          /  \\          ",
        "         /____\\         ",
        "        | NASA |        ",
        "        |      |        ",
        "        |  []  |        ",
        "        |      |        ",
        "        |______|        ",
        "        /|    |\\        ",
        "       /_|____|_\\       "
    };

    vector<vector<string>> fire =
    {
        {
            "          /\\/\\          ",
            "         / /\\ \\         ",
            "          /  \\          "
        },
        {
            "          \\  /          ",
            "         / /\\ \\         ",
            "        /_/  \\_\\        "
        },
        {
            "          ||||          ",
            "         ||||||         ",
            "          \\/\\/          "
        }
    };

    vector<string> ground =
    {
        "================================",
        "      NASA LAUNCH PLATFORM      ",
        "================================"
    };

    int screenHeight = 32;
    int startY = screenHeight - static_cast<int>(rocket.size()) - static_cast<int>(ground.size()) - 3;
    int frame = 0;

    clearScreen();

    color(11);
    cout << "\n\n";
    cout << "========================================" << endl;
    cout << "             NASA IT PROJECT            " << endl;
    cout << "        Space Exploration Simulator     " << endl;
    cout << "========================================" << endl << endl;

    color(15);
    printSlow("Initializing mission control systems...\n", 35);
    sleepMs(500);
    printSlow("Loading astronauts, rockets and planets...\n", 25);
    sleepMs(500);
    printSlow("Preparing launch sequence...\n", 15);
    sleepMs(900);

    color(14);
    cout << "\n3..." << endl;
    sleepMs(500);
    cout << "2..." << endl;
    sleepMs(500);
    cout << "1..." << endl;
    sleepMs(500);

    color(12);
    cout << "\nIGNITION!" << endl;
    sleepMs(800);

    for (int y = startY; y >= -15; y--)
    {
        clearScreen();

        for (int row = 0; row < screenHeight; row++)
        {
            int rocketRow = row - y;

            if (rocketRow >= 0 && rocketRow < rocket.size())
            {
                color(15);
                cout << rocket[rocketRow] << endl;
            }
            else if (rocketRow >= rocket.size() && rocketRow < rocket.size() + 3)
            {
                color(12 + frame % 3);
                cout << fire[frame % 3][rocketRow - rocket.size()] << endl;
            }
            else if (row >= screenHeight - ground.size())
            {
                color(8);
                cout << ground[row - (screenHeight - ground.size())] << endl;
            }
            else
            {
                cout << endl;
            }
        }

        frame++;

        if (y > startY - 5)
        {
            sleepMs(220);
        }
        else if (y > startY - 10)
        {
            sleepMs(150);
        }
        else
        {
            sleepMs(70);
        }
    }

    clearScreen();

    color(10);
    cout << "\n\n";
    cout << "========================================" << endl;
    cout << "          LAUNCH SUCCESSFUL             " << endl;
    cout << "========================================" << endl << endl;

    color(11);
    printSlow("Welcome to NASA Mission Control.\n", 40);
    sleepMs(1000);

    color(15);
}
*/