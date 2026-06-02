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

void sleepMs(int ms)
{
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void clearScreen()
{
    system("cls");
}

void printSlow(const string& text, int delay = 35)
{
    for (char ch : text)
    {
        cout << ch;
        sleepMs(delay);
    }
}

bool loginSystem()
{
    string username;
    string password;

    const string correctUsername = "NASA";
    const string correctPassword = "1234";

    int attempts = 3;

    while (attempts > 0)
    {
        clearScreen();

        color(11);
        cout << "========================================" << endl;
        cout << "          NASA NETWORK LOGIN            " << endl;
        cout << "========================================" << endl;
        resetColor();

        cout << endl;

        color(15);
        cout << "Enter your mission credentials." << endl;
        resetColor();

        cout << endl;

        color(14);
        cout << "USERNAME: ";
        resetColor();
        cin >> username;

        color(14);
        cout << "PASSWORD: ";
        resetColor();
        cin >> password;

        if (username == correctUsername && password == correctPassword)
        {
            clearScreen();

            color(10);
            cout << "========================================" << endl;
            cout << "             ACCESS GRANTED             " << endl;
            cout << "========================================" << endl;
            resetColor();

            cout << endl;

            color(11);
            printSlow("Verifying identity...\n", 35);
            sleepMs(400);
            printSlow("Connecting to NASA internal network...\n", 35);
            sleepMs(400);
            printSlow("Loading Mission Control access...\n", 35);
            sleepMs(700);

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

void showIntro()
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
    int startY = screenHeight - rocket.size() - ground.size() - 3;
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
    printSlow("Loading astronauts, rockets and planets...\n", 35);
    sleepMs(500);
    printSlow("Preparing launch sequence...\n", 35);
    sleepMs(900);

    color(14);
    cout << "\nT-minus 3..." << endl;
    sleepMs(700);
    cout << "T-minus 2..." << endl;
    sleepMs(700);
    cout << "T-minus 1..." << endl;
    sleepMs(700);

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

#endif