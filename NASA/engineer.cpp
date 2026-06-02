#include "engineer.hpp"

Engineer::Engineer()
{
    rocketName = "";
    astronautCapacity = 0;
    travelDistance = 0;
    topSpeed = 0;
    reliability = 0;
}

Engineer::Engineer(std::string rocketName, int astronautCapacity, double travelDistance, double topSpeed, double reliability)
{
    this->rocketName = rocketName;

    if (astronautCapacity >= 0)
    {
        this->astronautCapacity = astronautCapacity;
    }
    else
    {
        this->astronautCapacity = 0;
    }

    if (travelDistance >= 0)
    {
        this->travelDistance = travelDistance;
    }
    else
    {
        this->travelDistance = 0;
    }

    if (topSpeed >= 0)
    {
        this->topSpeed = topSpeed;
    }
    else
    {
        this->topSpeed = 0;
    }

    if (reliability >= 0 && reliability <= 100)
    {
        this->reliability = reliability;
    }
    else
    {
        this->reliability = 0;
    }
}

Engineer::Engineer(const Engineer& other)
{
    rocketName = other.rocketName;
    astronautCapacity = other.astronautCapacity;
    travelDistance = other.travelDistance;
    topSpeed = other.topSpeed;
    reliability = other.reliability;
}

Engineer::Engineer(Engineer&& other) noexcept
{
    rocketName = other.rocketName;
    astronautCapacity = other.astronautCapacity;
    travelDistance = other.travelDistance;
    topSpeed = other.topSpeed;
    reliability = other.reliability;

    other.rocketName = "";
    other.astronautCapacity = 0;
    other.travelDistance = 0;
    other.topSpeed = 0;
    other.reliability = 0;
}

Engineer::~Engineer()
{
}

Engineer& Engineer::operator=(const Engineer& other)
{
    if (this != &other)
    {
        rocketName = other.rocketName;
        astronautCapacity = other.astronautCapacity;
        travelDistance = other.travelDistance;
        topSpeed = other.topSpeed;
        reliability = other.reliability;
    }

    return *this;
}


Engineer& Engineer::operator=(Engineer&& other) noexcept
{
    if (this != &other)
    {
        rocketName = other.rocketName;
        astronautCapacity = other.astronautCapacity;
        travelDistance = other.travelDistance;
        topSpeed = other.topSpeed;
        reliability = other.reliability;

        other.rocketName = "";
        other.astronautCapacity = 0;
        other.travelDistance = 0;
        other.topSpeed = 0;
        other.reliability = 0;
    }

    return *this;
}

// Geturi
std::string Engineer::getRocketName() const
{
    return rocketName;
}

int Engineer::getAstronautCapacity() const
{
    return astronautCapacity;
}

double Engineer::getTravelDistance() const
{
    return travelDistance;
}

double Engineer::getTopSpeed() const
{
    return topSpeed;
}

double Engineer::getReliability() const
{
    return reliability;
}

// Setters
void Engineer::setRocketName(const std::string& rocketName)
{
    this->rocketName = rocketName;
}

void Engineer::setAstronautCapacity(int astronautCapacity)
{
    if (astronautCapacity >= 0)
    {
        this->astronautCapacity = astronautCapacity;
    }
    else
    {
        this->astronautCapacity = 0;
    }
}

void Engineer::setTravelDistance(double travelDistance)
{
    if (travelDistance >= 0)
    {
        this->travelDistance = travelDistance;
    }
    else
    {
        this->travelDistance = 0;
    }
}

void Engineer::setTopSpeed(double topSpeed)
{
    if (topSpeed >= 0)
    {
        this->topSpeed = topSpeed;
    }
    else
    {
        this->topSpeed = 0;
    }
}

void Engineer::setReliability(double reliability)
{
    if (reliability >= 0 && reliability <= 100)
    {
        this->reliability = reliability;
    }
    else
    {
        this->reliability = 0;
    }
}

void Engineer::print() const
{
    std::cout << "Rocket name: " << rocketName << std::endl;
    std::cout << "Astronaut capacity: " << astronautCapacity << std::endl;
    std::cout << "Travel distance: " << travelDistance << " km" << std::endl;
    std::cout << "Top speed: " << topSpeed << " km/h" << std::endl;
    std::cout << "Reliability: " << reliability << "%" << std::endl;
}

void Engineer::saveToFile(std::ofstream& file) const
{
    file << rocketName << std::endl;
    file << astronautCapacity << std::endl;
    file << travelDistance << std::endl;
    file << topSpeed << std::endl;
    file << reliability << std::endl;
}

void Engineer::loadFromFile(std::ifstream& file)
{
    std::getline(file, rocketName);

    file >> astronautCapacity;
    file >> travelDistance;
    file >> topSpeed;
    file >> reliability;
    file.ignore();

    if (astronautCapacity < 0)
    {
        astronautCapacity = 0;
    }

    if (travelDistance < 0)
    {
        travelDistance = 0;
    }

    if (topSpeed < 0)
    {
        topSpeed = 0;
    }

    if (reliability < 0 || reliability > 100)
    {
        reliability = 0;
    }
}

std::ostream& operator<<(std::ostream& out, const Engineer& engineer)
{
    out << "Rocket name: " << engineer.rocketName << std::endl;
    out << "Astronaut capacity: " << engineer.astronautCapacity << std::endl;
    out << "Travel distance: " << engineer.travelDistance << " km" << std::endl;
    out << "Top speed: " << engineer.topSpeed << " km/h" << std::endl;
    out << "Reliability: " << engineer.reliability << "%" << std::endl;

    return out;
}

std::istream& operator>>(std::istream& in, Engineer& engineer)
{
    std::cout << "Enter rocket name: ";
    std::getline(in, engineer.rocketName);

    std::cout << "Enter astronaut capacity: ";
    in >> engineer.astronautCapacity;

    while (engineer.astronautCapacity < 0)
    {
        std::cout << "Invalid capacity. Enter again: ";
        in >> engineer.astronautCapacity;
    }

    std::cout << "Enter travel distance: ";
    in >> engineer.travelDistance;

    while (engineer.travelDistance < 0)
    {
        std::cout << "Invalid distance. Enter again: ";
        in >> engineer.travelDistance;
    }

    std::cout << "Enter top speed: ";
    in >> engineer.topSpeed;

    while (engineer.topSpeed < 0)
    {
        std::cout << "Invalid speed. Enter again: ";
        in >> engineer.topSpeed;
    }

    std::cout << "Enter reliability (0 - 100): ";
    in >> engineer.reliability;

    while (engineer.reliability < 0 || engineer.reliability > 100)
    {
        std::cout << "Invalid reliability. Enter again (0 - 100): ";
        in >> engineer.reliability;
    }

    in.ignore();

    return in;
}