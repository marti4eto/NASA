// discoverer.hpp

#ifndef DISCOVERER_HPP
#define DISCOVERER_HPP

#include <iostream>
#include <string>
#include <fstream>

void playSuccessfulLaunchAnimation();
void playFailedLaunchAnimation();

class Discoverer
{
private:
    int planetType; // 1 - Small planet, 2 - Big planet, 3 - Star
    double distanceFromEarth; // in light years
    bool suitableForLife;
    bool hasLife;
    std::string richResource;
    bool missionSuccess;
    bool missionCompleted;

public:
    // rule of 5
    Discoverer();
    Discoverer(int planetType, double distanceFromEarth, bool suitableForLife, bool hasLife, std::string richResource);
    Discoverer(const Discoverer& other);
    Discoverer(Discoverer&& other) noexcept;
    ~Discoverer();

    int getPlanetType() const;
    double getDistanceFromEarth() const;
    bool getSuitableForLife() const;
    bool getHasLife() const;
    std::string getRichResource() const;
    bool getMissionSuccess() const;
    bool getMissionCompleted() const;

    void setPlanetType(int planetType);
    void setDistanceFromEarth(double distanceFromEarth);
    void setSuitableForLife(bool suitableForLife);
    void setHasLife(bool hasLife);
    void setRichResource(const std::string& richResource);

    std::string getPlanetTypeAsText() const;
    std::string getMissionResultAsText() const;

    void startMission(double rocketReliability);
    void print() const;

    Discoverer& operator=(const Discoverer& other);
    Discoverer& operator=(Discoverer&& other) noexcept;

    void saveToFile(std::ofstream& file) const;
    void loadFromFile(std::ifstream& file);

    friend std::ostream& operator<<(std::ostream& out, const Discoverer& discoverer);
    friend std::istream& operator>>(std::istream& in, Discoverer& discoverer);
};

#endif