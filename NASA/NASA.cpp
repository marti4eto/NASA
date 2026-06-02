#include <iostream>
#include <windows.h>

#include "Intro.hpp"
#include "color.hpp"
#include "astro.hpp"
#include "engineer.hpp"
#include "discoverer.hpp"

using namespace std;

void showMainMenu()
{
    int choice;

    while (true)
    {
        system("cls");

        color(11);
        cout << "========================================" << endl;
        cout << "              NASA NETWORK              " << endl;
        cout << "========================================" << endl;
        resetColor();

        cout << endl;

        color(15);
        cout << "Mission Control Main Menu" << endl;
        resetColor();

        cout << "Select a system to access:" << endl;

        cout << endl;

        color(8);
        cout << "----------------------------------------" << endl;
        resetColor();

        cout << "  1. Astronaut Management" << endl;
        cout << "  2. Engineer Management" << endl;
        cout << "  3. Discovery Missions" << endl;

        cout << endl;

        color(8);
        cout << "  Animation Tests" << endl;
        resetColor();

        cout << "  4. Successful mission animation" << endl;
        cout << "  5. Failed mission animation" << endl;

        cout << endl;

        color(8);
        cout << "----------------------------------------" << endl;
        resetColor();

        cout << "  0. Disconnect from NASA Network" << endl;

        cout << endl;

        color(11);
        cout << "Choose option: ";
        resetColor();

        cin >> choice;

        if (choice == 1)
        {
            system("cls");

            color(11);
            cout << "========================================" << endl;
            cout << "          ASTRONAUT MANAGEMENT          " << endl;
            cout << "========================================" << endl;
            resetColor();

            cout << endl;
            cout << "Astro menu will be connected here." << endl;

            cout << endl;
            system("pause");
        }
        else if (choice == 2)
        {
            system("cls");

            color(11);
            cout << "========================================" << endl;
            cout << "           ENGINEER MANAGEMENT          " << endl;
            cout << "========================================" << endl;
            resetColor();

            cout << endl;
            cout << "Engineer menu will be connected here." << endl;

            cout << endl;
            system("pause");
        }
        else if (choice == 3)
        {
            system("cls");

            color(11);
            cout << "========================================" << endl;
            cout << "            DISCOVERY MISSIONS          " << endl;
            cout << "========================================" << endl;
            resetColor();

            cout << endl;

            Discoverer discoverer;
            cin >> discoverer;

            double rocketReliability;

            cout << endl;
            cout << "Enter rocket reliability percent: ";
            cin >> rocketReliability;

            discoverer.startMission(rocketReliability);

            system("cls");

            color(11);
            cout << "========================================" << endl;
            cout << "              MISSION REPORT            " << endl;
            cout << "========================================" << endl;
            resetColor();

            cout << endl;
            discoverer.print();

            cout << endl;
            system("pause");
        }
        else if (choice == 4)
        {
            playSuccessfulLaunchAnimation();
            system("pause");
        }
        else if (choice == 5)
        {
            playFailedLaunchAnimation();
            system("pause");
        }
        else if (choice == 0)
        {
            system("cls");

            color(11);
            cout << "Disconnecting from NASA Network";
            resetColor();

            for (int i = 0; i < 5; i++)
            {
                cout << ".";
                Sleep(400);
            }

            system("cls");

            color(10);
            cout << "Disconnected successfully." << endl;
            resetColor();

            Sleep(1200);
            break;
        }
        else
        {
            cout << endl;

            color(12);
            cout << "Invalid option. Please try again." << endl;
            resetColor();

            Sleep(1000);
        }
    }
}
int main()
{
    if (!loginSystem())
    {
        return 0;
    }

    showIntro();

    showMainMenu();

    resetColor();
    return 0;
}