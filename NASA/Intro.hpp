#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <string>

using namespace std;

void clearScreen() {
    system("cls");
}

void sleep_ms(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

// Рамките на ракетата (отгоре надолу)
vector<string> rocket = {
    "        *        ",
    "       ***       ",
    "      *****      ",
    "       /^\\       ",
    "      / | \\      ",
    "     /  |  \\     ",
    "    | ===== |    ",
    "    |       |    ",
    "    |  [ ]  |    ",
    "    |       |    ",
    "    |_______|    ",
    "    /|     |\\   ",
    "   / |     | \\  ",
};

// Огън под ракетата (различни фази)
vector<string> fire_frames[] = {
    {
        "      | | |      ",
        "     ||| |||     ",
        "      \\ | /      ",
    },
    {
        "      \\   /      ",
        "     ||| |||     ",
        "      | | |      ",
    },
    {
        "     || | ||     ",
        "      \\   /      ",
        "       | |       ",
    }
};

// Земята
vector<string> ground = {
    "===============================",
    "  [###] [##] [###] [##] [####]  ",
    "===============================",
};

int SCREEN_HEIGHT = 35;

void drawFrame(int rocketY, int fireFrame, bool showFire) {
    clearScreen();

    // Колко реда от ракетата са видими (за ефекта на изчезване)
    int rocketStart = rocketY;
    int rocketLines = rocket.size();

    // Рисуваме всеки ред на екрана
    for (int row = 0; row < SCREEN_HEIGHT; row++) {
        int rocketRow = row - rocketStart;

        // Ред от ракетата
        if (rocketRow >= 0 && rocketRow < (int)rocket.size()) {
            // Ако ракетата излиза горе, скриваме горните редове
            if (rocketRow < (int)rocket.size()) {
                cout << rocket[rocketRow] << "\n";
            }
        }
        // Огън под ракетата
        else if (showFire && rocketRow >= (int)rocket.size() && rocketRow < (int)rocket.size() + 3) {
            int fRow = rocketRow - rocket.size();
            cout << fire_frames[fireFrame][fRow] << "\n";
        }
        // Земята накрая
        else if (row >= SCREEN_HEIGHT - (int)ground.size()) {
            int gRow = row - (SCREEN_HEIGHT - ground.size());
            cout << ground[gRow] << "\n";
        }
        else {
            cout << "\n";
        }
    }
}

int main() {
    // Ракетата стартира от земята
    int startY = SCREEN_HEIGHT - (int)ground.size() - (int)rocket.size() - 3;
    int frame = 0;
    int speed = 400;

    cout << "  === PREPARING FOR LAUNCH ===" << endl;
    sleep_ms(2000);

    // Фаза 1: Огън се появява, ракетата трепери
    for (int i = 0; i < 6; i++) {
        drawFrame(startY, frame % 3, true);
        // Малко трепене
        if (i % 2 == 0) {
            cout << "\r" << "  !!! IGNITION !!!" << flush;
        }
        frame++;
        sleep_ms(200);
    }

    // Фаза 2: Ракетата излита нагоре
    for (int y = startY; y >= -(int)rocket.size(); y--) {
        drawFrame(y, frame % 3, true);
        frame++;

        // Ускоряване с времето
        if (y > startY - 5)       sleep_ms(350);
        else if (y > startY - 10) sleep_ms(250);
        else if (y > startY - 15) sleep_ms(150);
        else                       sleep_ms(80);
    }

  

    return 0;
}
