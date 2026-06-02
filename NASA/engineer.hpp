// engineer.hpp

#ifndef ENGINEER_HPP
#define ENGINEER_HPP

#include <iostream>
#include <string>
#include <fstream>

class Engineer
{
private:
    std::string rocketName;
    int astronautCapacity;
    double travelDistance;
    double topSpeed;
    double reliability; // percentage: 0 - 100

public:
    // rule of 5
    Engineer();
    Engineer(std::string rocketName, int astronautCapacity, double travelDistance, double topSpeed, double reliability);
    Engineer(const Engineer& other);
    Engineer(Engineer&& other) noexcept;
    ~Engineer();

    std::string getRocketName() const;
    int getAstronautCapacity() const;
    double getTravelDistance() const;
    double getTopSpeed() const;
    double getReliability() const;

    void setRocketName(const std::string& rocketName);
    void setAstronautCapacity(int astronautCapacity);
    void setTravelDistance(double travelDistance);
    void setTopSpeed(double topSpeed);
    void setReliability(double reliability);

    void print() const;

    Engineer& operator=(const Engineer& other);
    Engineer& operator=(Engineer&& other) noexcept;

    void saveToFile(std::ofstream& file) const;
    void loadFromFile(std::ifstream& file);

    friend std::ostream& operator<<(std::ostream& out, const Engineer& engineer);
    friend std::istream& operator>>(std::istream& in, Engineer& engineer);
};

#endif