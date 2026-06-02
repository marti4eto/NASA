//astro.HPP


#ifndef ASTRO_HPP
#define ASTRO_HPP

#include <iostream>
#include <string>
#include <fstream>

class Astronaut
{
private:
    std::string name;
    double height;
    std::string gender;
    double weight;
    int xpLevel;

public:
    //rule of 5
    Astronaut();
    Astronaut(std::string name, double height, std::string gender, double weight, int xpLevel);
    Astronaut(const Astronaut& other);
    Astronaut(Astronaut&& other) noexcept;
    ~Astronaut();

    std::string getName() const;
    double getHeight() const;
    std::string getGender() const;
    double getWeight() const;
    int getXpLevel() const;

    void setName(const std::string& name);
    void setHeight(double height);
    void setGender(const std::string& gender);
    void setWeight(double weight);
    void setXpLevel(int xpLevel);

    void print() const;
    Astronaut& operator=(const Astronaut& other);
    Astronaut& operator=(Astronaut&& other) noexcept;

    void saveToFile(std::ofstream& file) const;
    void loadFromFile(std::ifstream& file);

    friend std::ostream& operator<<(std::ostream& out, const Astronaut& astronaut);
    friend std::istream& operator>>(std::istream& in, Astronaut& astronaut);
};
#endif  