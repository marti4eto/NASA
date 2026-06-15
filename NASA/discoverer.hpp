#ifndef DISCOVERER_HPP
#define DISCOVERER_HPP

#include <iostream>
#include <string>

class Discoverer {
private:
    std::string name;
    std::string type;
    double distance;
    std::string resource;

    void copy(const Discoverer& other);

public:
    Discoverer();
    Discoverer(std::string name, std::string type, double distance, std::string resource);
    Discoverer(const Discoverer& other);
    ~Discoverer();
    Discoverer& operator=(const Discoverer& other);

    std::string getName() const;
    std::string getType() const;
    double getDistance() const;
    std::string getResource() const;

    bool operator==(const Discoverer& other) const;
    bool operator!=(const Discoverer& other) const;
    bool operator<(const Discoverer& other) const;
    bool operator>(const Discoverer& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Discoverer& obj);
    friend std::istream& operator>>(std::istream& in, Discoverer& obj);
};

#endif