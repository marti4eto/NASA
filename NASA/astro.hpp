#ifndef ASTRO_HPP
#define ASTRO_HPP

#include <iostream>
#include <string>

class Astro {
private:
    std::string name;
    int age;
    double height;
    double weight;

    void copy(const Astro& other);

public:
    //rule of 5
    Astro();
    Astro(std::string name, int age, double height, double weight);
    Astro(const Astro& other);
    ~Astro();
    Astro& operator=(const Astro& other);


//geturi
    std::string getName() const;
    int getAge() const;
    double getHeight() const;
    double getWeight() const;

    void print() const;
    //predefinirane na operators
    bool operator==(const Astro& other) const;
    bool operator!=(const Astro& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Astro& obj);
    friend std::istream& operator>>(std::istream& in, Astro& obj);
};

#endif