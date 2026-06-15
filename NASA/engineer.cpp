#include "Engineer.hpp"

void Engineer::copy(const Engineer& other) {
    name = other.name;
    capacity = other.capacity;
    maxDistance = other.maxDistance;
    topSpeed = other.topSpeed;
}

Engineer::Engineer() {
    name = "";
    capacity = 0;
    maxDistance = 0;
    topSpeed = 0;
}

Engineer::Engineer(std::string name, int capacity, double maxDistance, double topSpeed) {
    this->name = name;
    this->capacity = capacity;
    this->maxDistance = maxDistance;
    this->topSpeed = topSpeed;
}

Engineer::Engineer(const Engineer& other) {
    copy(other);
}

Engineer::~Engineer() {
}

Engineer& Engineer::operator=(const Engineer& other) {
    if (this != &other) {
        copy(other);
    }

    return *this;
}

std::string Engineer::getName() const {
    return name;
}

int Engineer::getCapacity() const {
    return capacity;
}

double Engineer::getMaxDistance() const {
    return maxDistance;
}

double Engineer::getTopSpeed() const {
    return topSpeed;
}

bool Engineer::operator==(const Engineer& other) const {
    return name == other.name;
}

bool Engineer::operator!=(const Engineer& other) const {
    return !(*this == other);
}

bool Engineer::operator<(const Engineer& other) const {
    return capacity < other.capacity;
}

bool Engineer::operator>(const Engineer& other) const {
    return capacity > other.capacity;
}

bool Engineer::operator<=(const Engineer& other) const {
    return capacity <= other.capacity;
}

bool Engineer::operator>=(const Engineer& other) const {
    return capacity >= other.capacity;
}

std::ostream& operator<<(std::ostream& out, const Engineer& obj) {
    out << "========================================" << std::endl;
    out << "              ROCKET INFO               " << std::endl;
    out << "========================================" << std::endl;
    out << " Name         : " << obj.name << std::endl;
    out << " Capacity     : " << obj.capacity << " astronauts" << std::endl;
    out << " Max distance : " << obj.maxDistance << " light years" << std::endl;
    out << " Top speed    : " << obj.topSpeed << " km/s" << std::endl;
    out << "========================================" << std::endl;

    return out;
}

std::istream& operator>>(std::istream& in, Engineer& obj) {
    std::cout << "========================================" << std::endl;
    std::cout << "              CREATE ROCKET             " << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << " Rocket name (Max 15 characters) : ";
    in >> obj.name;

    while (obj.name.size() > 15) {
        std::cout << " Name is too long! Enter max 15 characters : ";
        in >> obj.name;
    }

    std::cout << " Capacity                         : ";
    in >> obj.capacity;

    while (obj.capacity <= 0) {
        std::cout << " Capacity must be positive! Enter again    : ";
        in >> obj.capacity;
    }

    std::cout << " Max distance in light years      : ";
    in >> obj.maxDistance;

    while (obj.maxDistance <= 0) {
        std::cout << " Distance must be positive! Enter again    : ";
        in >> obj.maxDistance;
    }

    std::cout << " Top speed in km/s                : ";
    in >> obj.topSpeed;

    while (obj.topSpeed <= 0) {
        std::cout << " Top speed must be positive! Enter again   : ";
        in >> obj.topSpeed;
    }

    std::cout << "========================================" << std::endl;

    return in;
}