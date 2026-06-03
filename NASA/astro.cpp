#include "Astro.hpp"

Astro::Astro() {
    id = "";
    name = "";
    gender = 'M';
    age = 0;
    height = 0;
    weight = 0;
}

Astro::Astro(string id, string name, char gender, int age, double height, double weight) {
    this->id = id;
    this->name = name;
    this->gender = gender;
    this->age = age;
    this->height = height;
    this->weight = weight;
}

string Astro::getId() const {
    return id;
}

string Astro::getName() const {
    return name;
}

char Astro::getGender() const {
    return gender;
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
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Gender: " << gender << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << " cm" << endl;
    cout << "Weight: " << weight << " kg" << endl;
    cout << "------------------------" << endl;
}