#include "astro.hpp"

// Default constructor
Astronaut::Astronaut()
{
    name = "";
    height = 0;
    gender = 1; // 1 - Male, 2 - Female
    weight = 0;
    xpLevel = 0;
}

// Constructor with parameters
Astronaut::Astronaut(std::string name, double height, int gender, double weight, int xpLevel)
{
    this->name = name;
    this->height = height;

    if (gender == 1 || gender == 2)
    {
        this->gender = gender;
    }
    else
    {
        this->gender = 1;
    }

    this->weight = weight;
    this->xpLevel = xpLevel;
}

// Copy constructor
Astronaut::Astronaut(const Astronaut& other)
{
    name = other.name;
    height = other.height;
    gender = other.gender;
    weight = other.weight;
    xpLevel = other.xpLevel;
}

// Move constructor
Astronaut::Astronaut(Astronaut&& other) noexcept
{
    name = other.name;
    height = other.height;
    gender = other.gender;
    weight = other.weight;
    xpLevel = other.xpLevel;

    other.name = "";
    other.height = 0;
    other.gender = 1;
    other.weight = 0;
    other.xpLevel = 0;
}

// Destructor
Astronaut::~Astronaut()
{
}

// Copy assignment operator
Astronaut& Astronaut::operator=(const Astronaut& other)
{
    if (this != &other)
    {
        name = other.name;
        height = other.height;
        gender = other.gender;
        weight = other.weight;
        xpLevel = other.xpLevel;
    }

    return *this;
}

// Move assignment operator
Astronaut& Astronaut::operator=(Astronaut&& other) noexcept
{
    if (this != &other)
    {
        name = other.name;
        height = other.height;
        gender = other.gender;
        weight = other.weight;
        xpLevel = other.xpLevel;

        other.name = "";
        other.height = 0;
        other.gender = 1;
        other.weight = 0;
        other.xpLevel = 0;
    }

    return *this;
}

// Getters
std::string Astronaut::getName() const
{
    return name;
}

double Astronaut::getHeight() const
{
    return height;
}

int Astronaut::getGender() const
{
    return gender;
}

double Astronaut::getWeight() const
{
    return weight;
}

int Astronaut::getXpLevel() const
{
    return xpLevel;
}

// Setters
void Astronaut::setName(const std::string& name)
{
    this->name = name;
}

void Astronaut::setHeight(double height)
{
    this->height = height;
}

void Astronaut::setGender(int gender)
{
    if (gender == 1 || gender == 2)
    {
        this->gender = gender;
    }
    else
    {
        this->gender = 1;
    }
}

void Astronaut::setWeight(double weight)
{
    this->weight = weight;
}

void Astronaut::setXpLevel(int xpLevel)
{
    this->xpLevel = xpLevel;
}

// Print function
void Astronaut::print() const
{
    std::cout << "Astronaut name: " << name << std::endl;
    std::cout << "Height: " << height << " cm" << std::endl;
    std::cout << "Gender: " << (gender == 1 ? "Male" : "Female") << std::endl;
    std::cout << "Weight: " << weight << " kg" << std::endl;
    std::cout << "Experience level: " << xpLevel << std::endl;
}

// Save to file
void Astronaut::saveToFile(std::ofstream& file) const
{
    file << name << std::endl;
    file << height << std::endl;
    file << gender << std::endl;
    file << weight << std::endl;
    file << xpLevel << std::endl;
}

// Load from file
void Astronaut::loadFromFile(std::ifstream& file)
{
    std::getline(file, name);
    file >> height;
    file >> gender;
    file >> weight;
    file >> xpLevel;
    file.ignore();

    if (gender != 1 && gender != 2)
    {
        gender = 1;
    }
}

// Output operator
std::ostream& operator<<(std::ostream& out, const Astronaut& astronaut)
{
    out << "Astronaut name: " << astronaut.name << std::endl;
    out << "Height: " << astronaut.height << " cm" << std::endl;
    out << "Gender: " << (astronaut.gender == 1 ? "Male" : "Female") << std::endl;
    out << "Weight: " << astronaut.weight << " kg" << std::endl;
    out << "Experience level: " << astronaut.xpLevel << std::endl;

    return out;
}

// Input operator
std::istream& operator>>(std::istream& in, Astronaut& astronaut)
{
    std::cout << "Enter astronaut name: ";
    std::getline(in, astronaut.name);

    std::cout << "Enter height: ";
    in >> astronaut.height;

    std::cout << "Enter gender (1 - Male, 2 - Female): ";
    in >> astronaut.gender;

    while (astronaut.gender != 1 && astronaut.gender != 2)
    {
        std::cout << "Invalid gender. Enter again (1 - Male, 2 - Female): ";
        in >> astronaut.gender;
    }

    std::cout << "Enter weight: ";
    in >> astronaut.weight;

    std::cout << "Enter experience level: ";
    in >> astronaut.xpLevel;

    in.ignore();

    return in;
}