#include "Discoverer.hpp"

void Discoverer::copy(const Discoverer& other) {
    id = other.id;
    name = other.name;
    type = other.type;
    distance = other.distance;
    resource = other.resource;
}

Discoverer::Discoverer() {
    id = "";
    name = "";
    type = "";
    distance = 0;
    resource = "";
}

Discoverer::Discoverer(std::string id, std::string name, std::string type, double distance, std::string resource) {
    this->id = id;
    this->name = name;
    this->type = type;
    this->distance = distance;
    this->resource = resource;
}

Discoverer::Discoverer(const Discoverer& other) {
    copy(other);
}

Discoverer::~Discoverer() {
}

Discoverer& Discoverer::operator=(const Discoverer& other) {
    if (this != &other) {
        copy(other);
    }

    return *this;
}

std::string Discoverer::getId() const {
    return id;
}
void Discoverer::setId(std::string id) {
    this->id = id;
}

std::string Discoverer::getName() const {
    return name;
}

std::string Discoverer::getType() const {
    return type;
}

double Discoverer::getDistance() const {
    return distance;
}

std::string Discoverer::getResource() const {
    return resource;
}

bool Discoverer::operator==(const Discoverer& other) const {
    return id == other.id;
}

bool Discoverer::operator!=(const Discoverer& other) const {
    return !(*this == other);
}

bool Discoverer::operator<(const Discoverer& other) const {
    return distance < other.distance;
}

bool Discoverer::operator>(const Discoverer& other) const {
    return distance > other.distance;
}

std::ostream& operator<<(std::ostream& out, const Discoverer& obj) {
    out << "===== Destination Info =====" << std::endl;
    out << "ID: " << obj.id << std::endl;
    out << "Name: " << obj.name << std::endl;
    out << "Type: " << obj.type << std::endl;
    out << "Distance: " << obj.distance << " ly" << std::endl;
    out << "Resource: " << obj.resource << std::endl;
    out << "============================" << std::endl;

    return out;
}

std::istream& operator>>(std::istream& in, Discoverer& obj) {
    int typeOption;
    int resourceOption;

    std::cout << "===== Add Destination =====" << std::endl;

    std::cout << "Name: ";
    in >> obj.name;

    std::cout << "Choose type:" << std::endl;
    std::cout << "1. Small Planet" << std::endl;
    std::cout << "2. Big Planet" << std::endl;
    std::cout << "3. Star" << std::endl;
    std::cout << "Option: ";
    in >> typeOption;

    while (typeOption < 1 || typeOption > 3) {
        std::cout << "Invalid option. Choose 1, 2 or 3: ";
        in >> typeOption;
    }

    if (typeOption == 1) {
        obj.type = "SmallPlanet";
    }
    else if (typeOption == 2) {
        obj.type = "BigPlanet";
    }
    else {
        obj.type = "Star";
    }

    std::cout << "Distance in light years: ";
    in >> obj.distance;

    while (obj.distance <= 0) {
        std::cout << "Distance must be positive. Enter again: ";
        in >> obj.distance;
    }

    std::cout << "Choose resource:" << std::endl;
    std::cout << "1. Hydrogen" << std::endl;
    std::cout << "2. Iron" << std::endl;
    std::cout << "3. Silicon" << std::endl;
    std::cout << "4. Gold" << std::endl;
    std::cout << "5. Uranium" << std::endl;
    std::cout << "Option: ";
    in >> resourceOption;

    while (resourceOption < 1 || resourceOption > 5) {
        std::cout << "Invalid option. Choose from 1 to 5: ";
        in >> resourceOption;
    }

    if (resourceOption == 1) {
        obj.resource = "Hydrogen";
    }
    else if (resourceOption == 2) {
        obj.resource = "Iron";
    }
    else if (resourceOption == 3) {
        obj.resource = "Silicon";
    }
    else if (resourceOption == 4) {
        obj.resource = "Gold";
    }
    else {
        obj.resource = "Uranium";
    }

    return in;
}