#ifndef ENGINEER_HPP
#define ENGINEER_HPP

#include <iostream>
#include <string>

class Engineer {
private:
    std::string id;
    std::string name;
    int capacity;
    double maxDistance;
    double topSpeed;

    void copy(const Engineer& other);

public:
    Engineer();
    Engineer(std::string id, std::string name, int capacity, double maxDistance, double topSpeed);
    Engineer(const Engineer& other);
    ~Engineer();
    Engineer& operator=(const Engineer& other);

    std::string getId() const;
    std::string getName() const;
    int getCapacity() const;
    double getMaxDistance() const;
    double getTopSpeed() const;
    void setId(std::string id);

    bool operator==(const Engineer& other) const;
    bool operator!=(const Engineer& other) const;
    bool operator<(const Engineer& other) const;
    bool operator>(const Engineer& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Engineer& obj);
    friend std::istream& operator>>(std::istream& in, Engineer& obj);
};

#endif