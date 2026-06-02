#include <random>
#include <windows.h>
#include <iostream>

#include "discoverer.hpp"
#include "color.hpp"

using namespace std;

void drawRocket()
{
    color(15);
    cout << "          /\\          " << endl;
    cout << "         /  \\         " << endl;
    cout << "        /____\\        " << endl;

    color(11);
    cout << "        |NASA|        " << endl;

    color(15);
    cout << "        |    |        " << endl;
    cout << "        |____|        " << endl;

    color(12);
    cout << "         /||\\         " << endl;

    color(14);
    cout << "        /_||_\\        " << endl;

    resetColor();
}

void drawStars()
{
    color(11);
    cout << "       *        .       *      " << endl;

    color(14);
    cout << "    .       *       .          " << endl;

    color(13);
    cout << "         *      .       *      " << endl;

    resetColor();
}

void playSuccessfulLaunchAnimation()
{
    for (int i = 10; i >= 0; i--)
    {
        system("cls");

        for (int space = 0; space < i; space++)
        {
            cout << endl;
        }

        drawRocket();

        cout << endl;
        color(14);
        cout << "        Launching..." << endl;
        resetColor();

        Sleep(250);
    }

    system("cls");

    drawStars();
    cout << endl;

    color(10);
    cout << "MISSION SUCCESSFUL!" << endl;
    resetColor();

    cout << endl;

    color(11);
    cout << "The rocket reached space successfully!" << endl;
    resetColor();

    Sleep(2000);
}

void playFailedLaunchAnimation()
{
    for (int i = 10; i >= 4; i--)
    {
        system("cls");

        for (int space = 0; space < i; space++)
        {
            cout << endl;
        }

        drawRocket();

        cout << endl;
        color(14);
        cout << "        Launching..." << endl;
        resetColor();

        Sleep(250);
    }

    for (int i = 4; i <= 10; i++)
    {
        system("cls");

        for (int space = 0; space < i; space++)
        {
            cout << endl;
        }

        drawRocket();

        cout << endl;

        color(12);
        cout << "        Engine problem..." << endl;

        color(14);
        cout << "        Returning..." << endl;

        resetColor();

        Sleep(250);
    }

    system("cls");

    drawRocket();

    cout << endl;

    color(12);
    cout << "MISSION FAILED!" << endl;

    color(14);
    cout << "The rocket returned to the launch pad." << endl;

    resetColor();

    Sleep(2000);
}
//uspeshna misiq 


Discoverer::Discoverer()
{
    planetType = 1;
    distanceFromEarth = 0;
    suitableForLife = false;
    hasLife = false;
    richResource = "";
    missionSuccess = false;
    missionCompleted = false;
}

Discoverer::Discoverer(int planetType, double distanceFromEarth, bool suitableForLife, bool hasLife, std::string richResource)
{
    setPlanetType(planetType);
    setDistanceFromEarth(distanceFromEarth);
    this->suitableForLife = suitableForLife;
    this->hasLife = hasLife;
    this->richResource = richResource;

    missionSuccess = false;
    missionCompleted = false;
}

Discoverer::Discoverer(const Discoverer& other)
{
    planetType = other.planetType;
    distanceFromEarth = other.distanceFromEarth;
    suitableForLife = other.suitableForLife;
    hasLife = other.hasLife;
    richResource = other.richResource;
    missionSuccess = other.missionSuccess;
    missionCompleted = other.missionCompleted;
}

Discoverer::Discoverer(Discoverer&& other) noexcept
{
    planetType = other.planetType;
    distanceFromEarth = other.distanceFromEarth;
    suitableForLife = other.suitableForLife;
    hasLife = other.hasLife;
    richResource = other.richResource;
    missionSuccess = other.missionSuccess;
    missionCompleted = other.missionCompleted;

    other.planetType = 1;
    other.distanceFromEarth = 0;
    other.suitableForLife = false;
    other.hasLife = false;
    other.richResource = "";
    other.missionSuccess = false;
    other.missionCompleted = false;
}

Discoverer::~Discoverer()
{}

Discoverer& Discoverer::operator=(const Discoverer& other)
{
    if (this != &other)
    {
        planetType = other.planetType;
        distanceFromEarth = other.distanceFromEarth;
        suitableForLife = other.suitableForLife;
        hasLife = other.hasLife;
        richResource = other.richResource;
        missionSuccess = other.missionSuccess;
        missionCompleted = other.missionCompleted;
    }

    return *this;
}

Discoverer& Discoverer::operator=(Discoverer&& other) noexcept
{
    if (this != &other)
    {
        planetType = other.planetType;
        distanceFromEarth = other.distanceFromEarth;
        suitableForLife = other.suitableForLife;
        hasLife = other.hasLife;
        richResource = other.richResource;
        missionSuccess = other.missionSuccess;
        missionCompleted = other.missionCompleted;

        other.planetType = 1;
        other.distanceFromEarth = 0;
        other.suitableForLife = false;
        other.hasLife = false;
        other.richResource = "";
        other.missionSuccess = false;
        other.missionCompleted = false;
    }

    return *this;
}

// geturi
int Discoverer::getPlanetType() const
{
    return planetType;
}

double Discoverer::getDistanceFromEarth() const
{
    return distanceFromEarth;
}

bool Discoverer::getSuitableForLife() const
{
    return suitableForLife;
}

bool Discoverer::getHasLife() const
{
    return hasLife;
}

std::string Discoverer::getRichResource() const
{
    return richResource;
}

bool Discoverer::getMissionSuccess() const
{
    return missionSuccess;
}

bool Discoverer::getMissionCompleted() const
{
    return missionCompleted;
}

// seturi
void Discoverer::setPlanetType(int planetType)
{
    if (planetType >= 1 && planetType <= 3)
    {
        this->planetType = planetType;
    }
    else
    {
        this->planetType = 1;
    }
}

void Discoverer::setDistanceFromEarth(double distanceFromEarth)
{
    if (distanceFromEarth >= 0)
    {
        this->distanceFromEarth = distanceFromEarth;
    }
    else
    {
        this->distanceFromEarth = 0;
    }
}

void Discoverer::setSuitableForLife(bool suitableForLife)
{
    this->suitableForLife = suitableForLife;
}

void Discoverer::setHasLife(bool hasLife)
{
    this->hasLife = hasLife;
}

void Discoverer::setRichResource(const std::string& richResource)
{
    this->richResource = richResource;
}

std::string Discoverer::getPlanetTypeAsText() const
{
    if (planetType == 1)
    {
        return "Small planet";
    }
    else if (planetType == 2)
    {
        return "Big planet";
    }
    else
    {
        return "Star";
    }
}

std::string Discoverer::getMissionResultAsText() const
{
    if (!missionCompleted)
    {
        return "Mission has not started yet.";
    }

    if (missionSuccess)
    {
        return "Mission successful! Samples and materials collected.";
    }

    return "Mission failed! The discoverers returned empty-handed.";
}

void Discoverer::startMission(double rocketReliability)
{
    if (rocketReliability < 0)
    {
        rocketReliability = 0;
    }

    if (rocketReliability > 100)
    {
        rocketReliability = 100;
    }

    double missionChance = 50;

    if (rocketReliability > 50)
    {
        missionChance += (rocketReliability - 50) / 2;
    }
    else if (rocketReliability < 50)
    {
        missionChance -= (50 - rocketReliability) / 2;
    }

    if (missionChance < 5)
    {
        missionChance = 5;
    }

    if (missionChance > 95)
    {
        missionChance = 95;
    }

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(1, 100);

    int randomNumber = distribution(generator);

    missionSuccess = randomNumber <= missionChance;
    missionCompleted = true;

    std::cout << "Mission chance: " << missionChance << "%" << std::endl;
    std::cout << "Random result: " << randomNumber << std::endl;

    Sleep(1200);

    if (missionSuccess)
    {
        playSuccessfulLaunchAnimation();
    }
    else
    {
        playFailedLaunchAnimation();
    }
}

void Discoverer::print() const
{
    std::cout << "Planet type: " << getPlanetTypeAsText() << std::endl;
    std::cout << "Distance from Earth: " << distanceFromEarth << " light years" << std::endl;
    std::cout << "Suitable for life: " << (suitableForLife ? "Yes" : "No") << std::endl;
    std::cout << "Has life: " << (hasLife ? "Yes" : "No") << std::endl;
    std::cout << "Rich resource: " << richResource << std::endl;
    std::cout << "Mission result: " << getMissionResultAsText() << std::endl;
}

void Discoverer::saveToFile(std::ofstream& file) const
{
    file << planetType << std::endl;
    file << distanceFromEarth << std::endl;
    file << suitableForLife << std::endl;
    file << hasLife << std::endl;
    file << richResource << std::endl;
    file << missionSuccess << std::endl;
    file << missionCompleted << std::endl;
}

// Load from file
void Discoverer::loadFromFile(std::ifstream& file)
{
    file >> planetType;
    file >> distanceFromEarth;
    file >> suitableForLife;
    file >> hasLife;
    file.ignore();

    std::getline(file, richResource);

    file >> missionSuccess;
    file >> missionCompleted;
    file.ignore();

    if (planetType < 1 || planetType > 3)
    {
        planetType = 1;
    }

    if (distanceFromEarth < 0)
    {
        distanceFromEarth = 0;
    }
}

std::ostream& operator<<(std::ostream& out, const Discoverer& discoverer)
{
    out << "Planet type: " << discoverer.getPlanetTypeAsText() << std::endl;
    out << "Distance from Earth: " << discoverer.distanceFromEarth << " light years" << std::endl;
    out << "Suitable for life: " << (discoverer.suitableForLife ? "Yes" : "No") << std::endl;
    out << "Has life: " << (discoverer.hasLife ? "Yes" : "No") << std::endl;
    out << "Rich resource: " << discoverer.richResource << std::endl;
    out << "Mission result: " << discoverer.getMissionResultAsText() << std::endl;

    return out;
}

std::istream& operator>>(std::istream& in, Discoverer& discoverer)
{
    int resourceChoice;

    std::cout << "Choose planet type:" << std::endl;
    std::cout << "1 - Small planet" << std::endl;
    std::cout << "2 - Big planet" << std::endl;
    std::cout << "3 - Star" << std::endl;
    std::cout << "Enter choice: ";
    in >> discoverer.planetType;

    while (discoverer.planetType < 1 || discoverer.planetType > 3)
    {
        std::cout << "Invalid planet type. Enter again: ";
        in >> discoverer.planetType;
    }

    std::cout << "Enter distance from Earth in light years: ";
    in >> discoverer.distanceFromEarth;

    while (discoverer.distanceFromEarth < 0)
    {
        std::cout << "Invalid distance. Enter again: ";
        in >> discoverer.distanceFromEarth;
    }

    std::cout << "Is it suitable for life? (1 - Yes, 0 - No): ";
    in >> discoverer.suitableForLife;

    std::cout << "Does it have life? (1 - Yes, 0 - No): ";
    in >> discoverer.hasLife;

    std::cout << "Choose rich resource:" << std::endl;
    std::cout << "1 - Water" << std::endl;
    std::cout << "2 - Iron" << std::endl;
    std::cout << "3 - Gold" << std::endl;
    std::cout << "4 - Uranium" << std::endl;
    std::cout << "5 - Crystal" << std::endl;
    std::cout << "6 - Unknown material" << std::endl;
    std::cout << "Enter choice: ";
    in >> resourceChoice;

    while (resourceChoice < 1 || resourceChoice > 6)
    {
        std::cout << "Invalid resource. Enter again: ";
        in >> resourceChoice;
    }

    if (resourceChoice == 1)
    {
        discoverer.richResource = "Water";
    }
    else if (resourceChoice == 2)
    {
        discoverer.richResource = "Iron";
    }
    else if (resourceChoice == 3)
    {
        discoverer.richResource = "Gold";
    }
    else if (resourceChoice == 4)
    {
        discoverer.richResource = "Uranium";
    }
    else if (resourceChoice == 5)
    {
        discoverer.richResource = "Crystal";
    }
    else
    {
        discoverer.richResource = "Unknown material";
    }

    discoverer.missionSuccess = false;
    discoverer.missionCompleted = false;

    in.ignore();

    return in;
}