#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Astro.hpp"
#include "Engineer.hpp"
#include "Discoverer.hpp"
#include "Intro.hpp"

std::vector<Astro> astronauts;
std::vector<Engineer> rockets;
std::vector<Discoverer> destinations;

int astronautCount = 0;
int rocketCount = 0;
int destinationCount = 0;
//zapisvam neshata v failove, za da ne gi gubim pri zatvarqne na programata
void saveAstronautsToFile() { 
    std::ofstream ofs("astronauts.txt");

    for (const auto& a : astronauts) {
        ofs << a.getName() << std::endl;
        ofs << a.getAge() << std::endl;
        ofs << a.getHeight() << std::endl;
        ofs << a.getWeight() << std::endl;
    }
}

void saveRocketsToFile() {
    std::ofstream ofs("rockets.txt");

    for (const auto& r : rockets) {
        ofs << r.getName() << std::endl;
        ofs << r.getCapacity() << std::endl;
        ofs << r.getMaxDistance() << std::endl;
        ofs << r.getTopSpeed() << std::endl;
    }
}

void saveDestinationsToFile() {
    std::ofstream ofs("discoveries.txt");

    for (const auto& d : destinations) {
        ofs << d.getName() << std::endl;
        ofs << d.getType() << std::endl;
        ofs << d.getDistance() << std::endl;
        ofs << d.getResource() << std::endl;
    }
}

int mainMenu() {
    int option;

    std::cout << "========================================" << std::endl;
    std::cout << "           NASA CONTROL CENTER          " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << " 1. Astronauts" << std::endl;
    std::cout << " 2. Rockets" << std::endl;
    std::cout << " 3. Destinations" << std::endl;
    std::cout << " 4. Launch Mission" << std::endl;
    std::cout << " 5. Statistics" << std::endl;
    std::cout << " 0. Exit" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << " Choose option: ";
    std::cin >> option;

    return option;
}

void showStatistics() {
    std::cout << "========================================" << std::endl;
    std::cout << "              NASA STATISTICS           " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << " Astronauts   : " << astronautCount << std::endl;
    std::cout << " Rockets      : " << rocketCount << std::endl;
    std::cout << " Destinations : " << destinationCount << std::endl;
    std::cout << "========================================" << std::endl;
}

void addAstronaut() {
    Astro astronaut;

    std::cin >> astronaut;
    astronauts.push_back(astronaut);

    astronautCount++;
    saveAstronautsToFile();

    std::cout << "Astronaut added successfully!" << std::endl;
}

void listAstronauts() {
    std::cout << "========================================" << std::endl;
    std::cout << "            LIST OF ASTRONAUTS          " << std::endl;
    std::cout << "========================================" << std::endl;

    if (astronauts.empty()) {
        std::cout << "No astronauts added yet." << std::endl;
        return;
    }

    for (size_t i = 0; i < astronauts.size(); i++) {
        std::cout << astronauts[i] << std::endl;
    }
}

void removeAstronaut() {
    std::string name;

    std::cout << "========================================" << std::endl;
    std::cout << "            REMOVE ASTRONAUT            " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << " Enter astronaut name: ";
    std::cin >> name;

    for (size_t i = 0; i < astronauts.size(); i++) {
        if (astronauts[i].getName() == name) {
            astronauts.erase(astronauts.begin() + i);
            astronautCount--;
            saveAstronautsToFile();

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

        std::cout << "========================================" << std::endl;
        std::cout << "             ASTRONAUT MENU             " << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << " 1. Add astronaut" << std::endl;
        std::cout << " 2. Remove astronaut" << std::endl;
        std::cout << " 3. List astronauts" << std::endl;
        std::cout << " 0. Back" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << " Choose option: ";
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

void addRocket() {
    Engineer rocket;

    std::cin >> rocket;
    rockets.push_back(rocket);

    rocketCount++;
    saveRocketsToFile();

    std::cout << "Rocket added successfully!" << std::endl;
}

void listRockets() {
    std::cout << "========================================" << std::endl;
    std::cout << "              LIST OF ROCKETS           " << std::endl;
    std::cout << "========================================" << std::endl;

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

    std::cout << "========================================" << std::endl;
    std::cout << "              REMOVE ROCKET             " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << " Enter rocket name: ";
    std::cin >> name;

    for (size_t i = 0; i < rockets.size(); i++) {
        if (rockets[i].getName() == name) {
            rockets.erase(rockets.begin() + i);
            rocketCount--;
            saveRocketsToFile();

            std::cout << "Rocket removed successfully!" << std::endl;
            return;
        }
    }

    std::cout << "Rocket not found." << std::endl;
}
void compareRockets() {
    if (rockets.size() < 2) {
        std::cout << "You need at least two rockets to compare." << std::endl;
        return;
    }

    std::cout << "========================================" << std::endl;
    std::cout << "        COMPARE ROCKET CAPACITY         " << std::endl;
    std::cout << "========================================" << std::endl;

	//pokazvame raketite s nomerca 

    for (size_t i = 0; i < rockets.size(); i++) {
        std::cout << i + 1 << ". " << rockets[i].getName()
            << " (Capacity: " << rockets[i].getCapacity() << ")"
            << std::endl;
    }

    int first;
    int second;

    std::cout << std::endl;
    std::cout << "Choose first rocket number: ";
    std::cin >> first;

    std::cout << "Choose second rocket number: ";
    std::cin >> second;

    if (first < 1 || first > rockets.size() || second < 1 || second > rockets.size()) {
        std::cout << "Invalid rocket number." << std::endl;
        return;
    }
	//vzimame raketite ot vektora po indeksite im

    Engineer rocket1 = rockets[first - 1];
    Engineer rocket2 = rockets[second - 1];

    std::cout << std::endl;
    
    //predefiniraniq operator 
    if (rocket1 > rocket2) {
        std::cout << rocket1.getName() << " has bigger capacity." << std::endl;
    }
    else if (rocket1 < rocket2) {
        std::cout << rocket2.getName() << " has bigger capacity." << std::endl;
    }
    else {
        std::cout << "Both rockets have equal capacity." << std::endl;
    }

    std::cout << "========================================" << std::endl;
}

void engineerMenu() {
    int option;

    do {
        system("cls");

        std::cout << "========================================" << std::endl;
        std::cout << "              ROCKET MENU               " << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << " 1. Add rocket" << std::endl;
        std::cout << " 2. Remove rocket" << std::endl;
        std::cout << " 3. List rockets" << std::endl;
        std::cout << " 4. Compare rockets by capacity" << std::endl;
        std::cout << " 0. Back" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << " Choose option: ";
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
        case 4:
            compareRockets();
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

void addDestination() {
    Discoverer destination;

    std::cin >> destination;
    destinations.push_back(destination);

    destinationCount++;
    saveDestinationsToFile();

    std::cout << "Destination added successfully!" << std::endl;
}

void listDestinations() {
    std::cout << "========================================" << std::endl;
    std::cout << "           LIST OF DESTINATIONS         " << std::endl;
    std::cout << "========================================" << std::endl;

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

    std::cout << "========================================" << std::endl;
    std::cout << "           REMOVE DESTINATION           " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << " Enter destination name: ";
    std::cin >> name;

    for (size_t i = 0; i < destinations.size(); i++) {
        if (destinations[i].getName() == name) {
            destinations.erase(destinations.begin() + i);
            destinationCount--;
            saveDestinationsToFile();

            std::cout << "Destination removed successfully!" << std::endl;
            return;
        }
    }

    std::cout << "Destination not found." << std::endl;
}

void discovererMenu() {
    int option;

    do {
        system("cls");

        std::cout << "========================================" << std::endl;
        std::cout << "            DESTINATION MENU            " << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << " 1. Add destination" << std::endl;
        std::cout << " 2. Remove destination" << std::endl;
        std::cout << " 3. List destinations" << std::endl;
        std::cout << " 0. Back" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << " Choose option: ";
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
	//proverqva dali ima astonavti, raketi i destinacii, zashtoto bez tqh ne moje da se startira misiqta
    if (astronauts.empty()) {
        std::cout << "Mission error: No astronauts are available." << std::endl;
        return;
    }

    if (rockets.empty()) {
        std::cout << "Mission error: No rockets  are available." << std::endl;
        return;
    }

    if (destinations.empty()) {
        std::cout << "Mission error: No destinations are available." << std::endl;
        return;
    }

    std::cout << "========================================" << std::endl;
    std::cout << "              LAUNCH MISSION            " << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << "Available astronauts:" << std::endl;
	for (const auto& a : astronauts) { // a - vremmena promenliwa koqto shte se izpolzva v cikula
        std::cout << "- " << a.getName() << std::endl;
    }

    int numToSend = 0;
    std::cout << std::endl;
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

	std::vector<Astro> selected; //pazi samo izbranite astonavti za misiqta

    for (int i = 0; i < numToSend; ) {
        std::string astronautName;

        std::cout << "Enter astronaut name #" << i + 1 << ": ";
        std::cin >> astronautName;

        bool found = false;

		for (const auto& a : astronauts) { // Този цикъл минава през всички астронавти в главния списък astronauts. minavame prez vseki astonavt v glavniq spisuk
            if (a.getName() == astronautName) {
                bool alreadySelected = false;

                for (const auto& s : selected) {
                    if (s.getName() == astronautName) {
                        alreadySelected = true;
                        break;
                    }
                }

                if (alreadySelected) { //proverka za poztarqne
                    std::cout << "Astronaut already selected." << std::endl;
                    found = true;
                    break;
                }

				selected.push_back(a); //dobavqme go v spisuka s izbranite astonavti
                found = true;
                i++;
                break;
            }
        }

        if (!found) {
            std::cout << "Astronaut not found. Try again." << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "Available rockets:" << std::endl;

    for (const auto& r : rockets) {
        std::cout << "- " << r.getName()
            << " (Capacity: " << r.getCapacity()
            << ", Max distance: " << r.getMaxDistance() << ")"
            << std::endl;
    }

    std::string rocketName;
    std::cout << std::endl;
    std::cout << "Choose rocket name: ";
    std::cin >> rocketName;

    int rocketIndex = -1;

    for (size_t i = 0; i < rockets.size(); i++) {
        if (rockets[i].getName() == rocketName) {
			rocketIndex = static_cast<int>(i); //ako nameri raketa , zapazva indeksut mu v vektora
            break;
        }
    }

    if (rocketIndex == -1) {
        std::cout << "Rocket not found." << std::endl;
        return;
    }

    std::cout << std::endl;
    std::cout << "Available destinations:" << std::endl;

    for (const auto& d : destinations) {
        std::cout << "- " << d.getName()
            << " (Distance: " << d.getDistance()
            << ", Resource: " << d.getResource() << ")"
            << std::endl;
    }

    std::string destinationName;
    std::cout << std::endl;
    std::cout << "Choose destination name: ";
    std::cin >> destinationName;

    int destinationIndex = -1; //pak proverka ako ne nameri nisho 

    for (size_t i = 0; i < destinations.size(); i++) {
        if (destinations[i].getName() == destinationName) {
            destinationIndex = static_cast<int>(i);
            break;
        }
    }

    if (destinationIndex == -1) {
        std::cout << "Destination not found." << std::endl;
        return;
    }

    const Engineer& rocket = rockets[rocketIndex];
    const Discoverer& destination = destinations[destinationIndex];

    if (static_cast<int>(selected.size()) > rocket.getCapacity()) {
        std::cout << "Mission failed: rocket capacity is too small." << std::endl;
        return;
    }

    if (rocket.getMaxDistance() < destination.getDistance()) {
        std::cout << "Mission failed: destination is too far for this rocket." << std::endl;
        return;
    }

    std::cout << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "              MISSION SUMMARY           " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << " Rocket      : " << rocket.getName() << std::endl;
    std::cout << " Destination : " << destination.getName() << std::endl;
    std::cout << " Distance    : " << destination.getDistance() << " light years" << std::endl;
    std::cout << " Resource    : " << destination.getResource() << std::endl;

    std::cout << std::endl;
    std::cout << " Selected astronauts:" << std::endl;

    for (const auto& a : selected) {
        std::cout << " - " << a.getName() << std::endl;
    }

    std::cout << "========================================" << std::endl;
    std::cout << "        MISSION LAUNCHED SUCCESSFULLY!  " << std::endl;
    std::cout << "========================================" << std::endl;
}

int main() {
    if (!loginSystem()) {
        return 0;
    }

    showIntro();

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
        case 5:
            showStatistics();
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