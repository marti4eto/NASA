#include "Astro.hpp"

void Astro::copy(const Astro& other) {
    this->name = other.name;
    this->age = other.age;
    this->height = other.height;
    this->weight = other.weight;
}

Astro::Astro() {
    name = "";
    age = 0;
    height = 0;
    weight = 0;
}

Astro::Astro(std::string name, int age, double height, double weight) {
    this->name = name;
    this->age = age;
    this->height = height;
    this->weight = weight;
}

Astro::Astro(const Astro& other) {
    copy(other);
}

Astro::~Astro() {
}

Astro& Astro::operator=(const Astro& other) {
    if (this != &other) {
        copy(other);
    }

    return *this;
}

std::string Astro::getName() const {
    return name;
}

int Astro::getAge() const {
    return age;
}

double Astro::getHeight() const {
    return height;
}

double Astro::getWeight() const {
    return weight;
}

void Astro::print() const {
    std::cout << *this;
}

bool Astro::operator==(const Astro& other) const {
    return this->name == other.name;
}

bool Astro::operator!=(const Astro& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Astro& obj) {
    out << "========================================" << std::endl;
    out << "             ASTRONAUT INFO             " << std::endl;
    out << "========================================" << std::endl;
    out << " Name   : " << obj.name << std::endl;
    out << " Age    : " << obj.age << std::endl;
    out << " Height : " << obj.height << " cm" << std::endl;
    out << " Weight : " << obj.weight << " kg" << std::endl;
    out << "========================================" << std::endl;

    return out;
}

std::istream& operator>>(std::istream& in, Astro& obj) {
    std::cout << "========================================" << std::endl;
    std::cout << "              NEW ASTRONAUT             " << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << " Enter name        : ";
    in >> obj.name;

    std::cout << " Enter age         : ";
    in >> obj.age;

    std::cout << " Enter height (cm) : ";
    in >> obj.height;

    std::cout << " Enter weight (Kg) : ";
    in >> obj.weight;

    std::cout << "========================================" << std::endl;

    return in;

}