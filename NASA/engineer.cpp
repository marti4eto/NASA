#include "Engineer.hpp"

void Engineer::copy(const Engineer& other) {
    id = other.id;
    name = other.name;
    capacity = other.capacity;
    maxDistance = other.maxDistance;
    topSpeed = other.topSpeed;
}

Engineer::Engineer() {
    id = "";
    name = "";
    capacity = 0;
    maxDistance = 0;
    topSpeed = 0;
}

Engineer::Engineer(std::string id, std::string name, int capacity, double maxDistance, double topSpeed) {
    this->id = id;
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

std::string Engineer::getId() const {
    return id;
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

void Engineer::setId(std::string id)
{
    this->id = id;
}

bool Engineer::operator==(const Engineer& other) const {
    return id == other.id;
}

bool Engineer::operator!=(const Engineer& other) const {
    return !(*this == other);
}

bool Engineer::operator<(const Engineer& other) const {
    return maxDistance < other.maxDistance;
}

bool Engineer::operator>(const Engineer& other) const {
    return maxDistance > other.maxDistance;
}

std::ostream& operator<<(std::ostream& out, const Engineer& obj) {
    out << "===== Rocket Info =====" << std::endl;
    out << "ID: " << obj.id << std::endl;
    out << "Name: " << obj.name << std::endl;
    out << "Capacity: " << obj.capacity << " astronauts" << std::endl;
    out << "Max distance: " << obj.maxDistance << " light years" << std::endl;
    out << "Top speed: " << obj.topSpeed << " km/s" << std::endl;
    out << "=======================" << std::endl;

    return out;
}

std::istream& operator>>(std::istream& in, Engineer& obj) {
    std::cout << "===== Create Rocket =====" << std::endl;

    std::cout << "Rocket name / max 15 characters: ";
    in >> obj.name;

    while (obj.name.size() > 15) {
        std::cout << "Name is too long. Enter max 15 characters: ";
        in >> obj.name;
    }

    std::cout << "Capacity: ";
    in >> obj.capacity;

    while (obj.capacity <= 0) {
        std::cout << "Capacity must be positive. Enter again: ";
        in >> obj.capacity;
    }

    std::cout << "Max distance in light years: ";
    in >> obj.maxDistance;

    while (obj.maxDistance <= 0) {
        std::cout << "Distance must be positive. Enter again: ";
        in >> obj.maxDistance;
    }

    std::cout << "Top speed: ";
    in >> obj.topSpeed;

    while (obj.topSpeed <= 0) {
        std::cout << "Top speed must be positive. Enter again: ";
        in >> obj.topSpeed;
    }

    return in;
}