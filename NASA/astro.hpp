#ifndef ASTRO_HPP
#define ASTRO_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Astro {
private:
    string id;
    string name;
    char gender;
    int age;
    double height;
    double weight;

public:
    Astro();
    Astro(string id, string name, char gender, int age, double height, double weight);

    string getId() const;
    string getName() const;
    char getGender() const;
    int getAge() const;
    double getHeight() const;
    double getWeight() const;

    void print() const;
};

#endif