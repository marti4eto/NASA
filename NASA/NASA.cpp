#include <iostream>
#include <vector>
#include <string>

#include "Astro.hpp"
#include "Engineer.hpp"
#include "Discoverer.hpp"
#include <fstream>

std::vector<Astro> astronauts;
std::vector<Engineer> rockets;
std::vector<Discoverer> destinations;

void addRocket();
void removeRocket();
void listRockets();

void addDestination();
void removeDestination();
void listDestinations();

// ID counters
int rocketCount = 0;
int smallPlanetCount = 0;
int bigPlanetCount = 0;
int starCount = 0;

// Helpers
std::string generateRocketId() {
    rocketCount++;
    return "R" + std::to_string(rocketCount);
}

std::string generateDestinationId(const std::string& type) {
    if (type == "SmallPlanet") {
        smallPlanetCount++;
        return "SP" + std::to_string(smallPlanetCount);
    }
    else if (type == "BigPlanet") {
        bigPlanetCount++;
        return "BP" + std::to_string(bigPlanetCount);
    }
    else {
        starCount++;
        return "ST" + std::to_string(starCount);
    }
}

// Persistence helpers
void saveRocketsToFile() {
    std::ofstream ofs("rockets.txt");
    for (const auto& r : rockets) {
        ofs << r.getId() << "\n";
        ofs << r.getName() << "\n";
        ofs << r.getCapacity() << "\n";
        ofs << r.getMaxDistance() << "\n";
        ofs << r.getTopSpeed() << "\n";
    }
}

void saveDestinationsToFile() {
    std::ofstream ofs("discoveries.txt");
    for (const auto& d : destinations) {
        ofs << d.getId() << "\n";
        ofs << d.getName() << "\n";
        ofs << d.getType() << "\n";
        ofs << d.getDistance() << "\n";
        ofs << d.getResource() << "\n";
    }
}

int mainMenu() {
    int option;

    std::cout << "===== NASA CONTROL CENTER =====" << std::endl;
    std::cout << "1. Astronauts" << std::endl;
    std::cout << "2. Engineer" << std::endl;
    std::cout << "3. Discoverer" << std::endl;
    std::cout << "4. Launch Mission" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Choose option: ";
    std::cin >> option;

    return option;
}

int maleCount = 0;
int femaleCount = 0;

std::string generateAstroId(char gender) {
    if (gender == 'M' || gender == 'm') {
        maleCount++;
        return "M" + std::to_string(maleCount);
    }

    femaleCount++;
    return "F" + std::to_string(femaleCount);
}

void addAstronaut() {
    std::string name;
    char gender;
    int age;
    double height;
    double weight;

    std::cout << "===== ADD ASTRONAUT =====" << std::endl;

    std::cout << "Name: ";
    std::cin >> name;

    std::cout << "Gender M/F: ";
    std::cin >> gender;

    while (gender != 'M' && gender != 'm' && gender != 'F' && gender != 'f') {
        std::cout << "Invalid gender. Enter M or F: ";
        std::cin >> gender;
    }

    std::cout << "Age: ";
    std::cin >> age;

    std::cout << "Height in cm: ";
    std::cin >> height;

    std::cout << "Weight in kg: ";
    std::cin >> weight;

    std::string id = generateAstroId(gender);

    Astro newAstro(id, name, gender, age, height, weight);
    astronauts.push_back(newAstro);

    std::cout << "Astronaut added successfully!" << std::endl;
    std::cout << "Generated ID: " << id << std::endl;
}

void listAstronauts() {
    std::cout << "===== LIST OF ASTRONAUTS =====" << std::endl;

    if (astronauts.empty()) {
        std::cout << "No astronauts added yet." << std::endl;
        return;
    }

    for (int i = 0; i < astronauts.size(); i++) {
        astronauts[i].print();
    }
}

void removeAstronaut() {
    std::string id;

    std::cout << "===== REMOVE ASTRONAUT =====" << std::endl;
    std::cout << "Enter astronaut ID: ";
    std::cin >> id;

    for (int i = 0; i < astronauts.size(); i++) {
        if (astronauts[i].getId() == id) {
            astronauts.erase(astronauts.begin() + i);
            std::cout << "Astronaut removed successfully!" << std::endl;
            return;
        }
    }

    std::cout << "Astronaut not found." << std::endl;
}


void astronautMenu() {
    int option;

    do {
        system("cls");

        std::cout << "===== ASTRONAUT MENU =====" << std::endl;
        std::cout << "1. Add astronaut" << std::endl;
        std::cout << "2. Remove astronaut" << std::endl;
        std::cout << "3. List astronauts" << std::endl;
        std::cout << "0. Back" << std::endl;
        std::cout << "Choose option: ";
        std::cin >> option;

        system("cls");

        switch (option) {
        case 1:
            addAstronaut();
            break;

        case 2:
            removeAstronaut();
            break;

        case 3:
            listAstronauts();
            break;

        case 0:
            break;

        default:
            std::cout << "Invalid option." << std::endl;
        }

        if (option != 0) {
            system("pause");
        }

    } while (option != 0);
}



void engineerMenu() {
    int option;

    do {
        system("cls");

        std::cout << "===== ENGINEER MENU =====" << std::endl;
        std::cout << "1. Add rocket" << std::endl;
        std::cout << "2. Remove rocket" << std::endl;
        std::cout << "3. List rockets" << std::endl;
        std::cout << "0. Back" << std::endl;
        std::cout << "Choose option: ";
        std::cin >> option;

        system("cls");

        switch (option) {
        case 1:
            addRocket();
            break;

        case 2:
            removeRocket();
            break;

        case 3:
            listRockets();
            break;

        case 0:
            break;

        default:
            std::cout << "Invalid option." << std::endl;
        }

        if (option != 0) {
            system("pause");
        }

    } while (option != 0);
}

// remove duplicate rocketCount declared elsewhere

void addRocket() {
    Engineer rocket;

    std::cin >> rocket;

    // generate and assign ID
    std::string id = generateRocketId();
    rocket.setId(id);

    rockets.push_back(rocket);

    // persist
    saveRocketsToFile();

    std::cout << "Rocket added successfully!" << std::endl;
    std::cout << "Generated ID: " << id << std::endl;
}

void listRockets() {

    if (rockets.empty()) {
        std::cout << "No rockets found." << std::endl;
        return;
    }

    for (size_t i = 0; i < rockets.size(); i++) {
        std::cout << rockets[i] << std::endl;
    }
}


void removeRocket() {

    std::string name;

    std::cout << "Rocket name: ";
    std::cin >> name;

    for (size_t i = 0; i < rockets.size(); i++) {

        if (rockets[i].getName() == name) {

            rockets.erase(rockets.begin() + i);

            std::cout << "Rocket removed." << std::endl;
            return;
        }
    }

    std::cout << "Rocket not found." << std::endl;
}
void addDestination() {
    Discoverer destination;

    std::cin >> destination;

    // generate id based on type and assign
    std::string id = generateDestinationId(destination.getType());
    destination.setId(id);

    destinations.push_back(destination);

    // persist
    saveDestinationsToFile();

    std::cout << "Destination added successfully!" << std::endl;
    std::cout << "Generated ID: " << id << std::endl;
}

void listDestinations() {

    if (destinations.empty()) {
        std::cout << "No destinations found." << std::endl;
        return;
    }

    for (size_t i = 0; i < destinations.size(); i++) {
        std::cout << destinations[i] << std::endl;
    }
}

void removeDestination() {

    std::string name;

    std::cout << "Destination name: ";
    std::cin >> name;

    for (size_t i = 0; i < destinations.size(); i++) {

        if (destinations[i].getName() == name) {

            destinations.erase(destinations.begin() + i);

            std::cout << "Destination removed." << std::endl;
            return;
        }
    }

    std::cout << "Destination not found." << std::endl;
}


void discovererMenu() {
    int option;

    do {
        system("cls");

        std::cout << "===== DISCOVERER MENU =====" << std::endl;
        std::cout << "1. Add destination" << std::endl;
        std::cout << "2. Remove destination" << std::endl;
        std::cout << "3. List destinations" << std::endl;
        std::cout << "0. Back" << std::endl;
        std::cout << "Choose option: ";
        std::cin >> option;

        system("cls");

        switch (option) {
        case 1:
            addDestination();
            break;
        case 2:
            removeDestination();
            break;
        case 3:
            listDestinations();
            break;
        case 0:
            break;
        default:
            std::cout << "Invalid option." << std::endl;
        }

        if (option != 0) {
            system("pause");
        }

    } while (option != 0);
}

void launchMissionMenu() {
    // Check prerequisites
    if (astronauts.empty()) {
        std::cout << "Mission error: no astronauts available." << std::endl;
        return;
    }

    if (rockets.empty()) {
        std::cout << "Mission error: no rockets available." << std::endl;
        return;
    }

    if (destinations.empty()) {
        std::cout << "Mission error: no destinations available." << std::endl;
        return;
    }

    std::cout << "===== LAUNCH MISSION =====" << std::endl;

    // Show astronauts
    std::cout << "Available astronauts:" << std::endl;
    for (const auto& a : astronauts) {
        std::cout << a.getId() << " - " << a.getName() << std::endl;
    }

    int numToSend = 0;
    std::cout << "How many astronauts to send? ";
    std::cin >> numToSend;

    if (numToSend <= 0) {
        std::cout << "Invalid number." << std::endl;
        return;
    }

    if (numToSend > static_cast<int>(astronauts.size())) {
        std::cout << "Not enough astronauts available." << std::endl;
        return;
    }

    std::vector<Astro> selected;
    for (int i = 0; i < numToSend; ) {
        std::string aid;
        std::cout << "Enter astronaut ID (#" << (i+1) << "): ";
        std::cin >> aid;

        bool found = false;
        for (const auto& a : astronauts) {
            if (a.getId() == aid) {
                // ensure not already selected
                bool already = false;
                for (const auto& s : selected) {
                    if (s.getId() == aid) { already = true; break; }
                }
                if (already) {
                    std::cout << "Astronaut already selected." << std::endl;
                    found = true; // treat as processed but don't increment i
                    break;
                }

                selected.push_back(a);
                found = true;
                i++;
                break;
            }
        }

        if (!found) {
            std::cout << "Astronaut ID not found. Try again." << std::endl;
        }
    }

    // Show rockets
    std::cout << std::endl << "Available rockets:" << std::endl;
    for (const auto& r : rockets) {
        std::cout << r.getId() << " - " << r.getName()
                  << " (Capacity: " << r.getCapacity()
                  << ", MaxDist: " << r.getMaxDistance() << ")" << std::endl;
    }

    std::string rid;
    std::cout << "Choose rocket ID: ";
    std::cin >> rid;

    int rocketIndex = -1;
    for (size_t i = 0; i < rockets.size(); i++) {
        if (rockets[i].getId() == rid) { rocketIndex = static_cast<int>(i); break; }
    }

    if (rocketIndex == -1) {
        std::cout << "Rocket not found." << std::endl;
        return;
    }

    // Show destinations
    std::cout << std::endl << "Available destinations:" << std::endl;
    for (const auto& d : destinations) {
        std::cout << d.getId() << " - " << d.getName()
                  << " (Distance: " << d.getDistance() << ", Resource: " << d.getResource() << ")" << std::endl;
    }

    std::string did;
    std::cout << "Choose destination ID: ";
    std::cin >> did;

    int destIndex = -1;
    for (size_t i = 0; i < destinations.size(); i++) {
        if (destinations[i].getId() == did) { destIndex = static_cast<int>(i); break; }
    }

    if (destIndex == -1) {
        std::cout << "Destination not found." << std::endl;
        return;
    }

    const Engineer& rocket = rockets[rocketIndex];
    const Discoverer& dest = destinations[destIndex];

    // Validations
    if (static_cast<int>(selected.size()) > rocket.getCapacity()) {
        std::cout << "Mission failed: rocket capacity is too small." << std::endl;
        return;
    }

    if (rocket.getMaxDistance() < dest.getDistance()) {
        std::cout << "Mission failed: destination is too far for this rocket." << std::endl;
        return;
    }

    // Mission summary
    std::cout << std::endl << "===== MISSION SUMMARY =====" << std::endl;
    std::cout << "Rocket: " << rocket.getId() << " - " << rocket.getName() << std::endl;
    std::cout << "Destination: " << dest.getId() << " - " << dest.getName()
              << " (Distance: " << dest.getDistance() << ")" << std::endl;

    std::cout << "Selected astronauts:" << std::endl;
    for (const auto& a : selected) {
        std::cout << a.getId() << " - " << a.getName() << std::endl;
    }

    std::cout << "Resource found: " << dest.getResource() << std::endl;
    std::cout << std::endl << "MISSION LAUNCHED SUCCESSFULLY!" << std::endl;

    system("pause");
}

int main() {
    int option;

    do {
        system("cls");
        option = mainMenu();
        system("cls");

        switch (option) {
        case 1:
            astronautMenu();
            break;
        case 2:
            engineerMenu();
            break;
        case 3:
            discovererMenu();
            break;
        case 4:
            launchMissionMenu();
            system("pause");
            break;
        case 0:
            std::cout << "Program closed." << std::endl;
            break;
        default:
            std::cout << "Invalid option." << std::endl;
            system("pause");
        }

    } while (option != 0);

    return 0;
}