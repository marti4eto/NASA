#ifndef INTRO_HPP
#define INTRO_HPP

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>
#include <windows.h>
#include "color.hpp"

void sleepMs(int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void clearScreen()
{
    system("cls");
}

void printSlow(const std::string& text, int delay = 35)
{
    for (char ch : text)
    {
        std::cout << ch;
        sleepMs(delay);
    }
}

void showIntro()
{
    std::vector<std::string> rocket =
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

    std::vector<std::vector<std::string>> fire =
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

    std::vector<std::string> ground =
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
    std::cout << "\n\n";
    std::cout << "========================================\n";
    std::cout << "             NASA IT PROJECT            \n";
    std::cout << "        Space Exploration Simulator      \n";
    std::cout << "========================================\n\n";

    color(15);
    printSlow("Initializing mission control systems...\n", 35);
    sleepMs(500);
    printSlow("Loading astronauts, rockets and planets...\n", 35);
    sleepMs(500);
    printSlow("Preparing launch sequence...\n", 35);
    sleepMs(900);

    color(14);
    std::cout << "\nT-minus 3...\n";
    sleepMs(700);
    std::cout << "T-minus 2...\n";
    sleepMs(700);
    std::cout << "T-minus 1...\n";
    sleepMs(700);

    color(12);
    std::cout << "\nIGNITION!\n";
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
                std::cout << rocket[rocketRow] << std::endl;
            }
            else if (rocketRow >= rocket.size() && rocketRow < rocket.size() + 3)
            {
                color(12 + frame % 3);
                std::cout << fire[frame % 3][rocketRow - rocket.size()] << std::endl;
            }
            else if (row >= screenHeight - ground.size())
            {
                color(8);
                std::cout << ground[row - (screenHeight - ground.size())] << std::endl;
            }
            else
            {
                std::cout << std::endl;
            }
        }

        frame++;

        if (y > startY - 5)
            sleepMs(220);
        else if (y > startY - 10)
            sleepMs(150);
        else
            sleepMs(70);
    }

    clearScreen();

    color(10);
    std::cout << "\n\n";
    std::cout << "========================================\n";
    std::cout << "          LAUNCH SUCCESSFUL             \n";
    std::cout << "========================================\n\n";

    color(11);
    printSlow("Welcome to NASA Mission Control.\n", 40);
    sleepMs(1000);

    color(15);
}

#endif