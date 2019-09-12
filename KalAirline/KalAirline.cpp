// KalAirline.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DataManager.h"
using namespace AirlineApp;

int displayMenu();
int admin(DataManager& dbm);
void addFlight(DataManager& dbm);
int passenger(DataManager& dbm);
int displayPassengerMenu(std::string& firstName, std::string& lastName);
int flightBooking(DataManager& dbm, Passenger& passenger);

int main()
{
	DataManager dataManager;
	while (true) {
		int selection = displayMenu();
		switch (selection) {
			case 0:
				return 0;
			case 1:
				admin(dataManager);
				break;
			case 2:
				passenger(dataManager);
				break;
			default:
				std::cout << "Not a valid input. Please select one of the following" << std::endl;
		}
	}
}


int displayMenu() {
	int selection;
	std::cout << "1. Admin" << std::endl;
	std::cout << "2. Passenger" << std::endl;
	std::cout << std::endl;
	std::cin >> selection;
	return selection;
}

int admin(DataManager& dbm) {
	while (true) {
		int password;
		std::cout << "Enter your password:" << std::endl;
		std::cin >> password;
		if (password == 123) {
			std::cout << "Welcome admin! Add new flight schedule" << std::endl;
			addFlight(dbm);
			break;
		}
		else {
			std::cout << "invalid password" << std::endl;
			break;
		}
	}
	return 0;
}

void addFlight(DataManager& dbm) {
	int month;
	int day;
	int year;
	int hour;
	int minute;
	int flightDuration;
	int capacity;
	std::string departure;
	std::string destination;

	std::cout << "Month?" << std::endl;
	std::cin >> month;
	std::cout << "Day?" << std::endl;
	std::cin >> day;
	std::cout << "Year?" << std::endl;
	std::cin >> year;
	std::cout << "Hour?" << std::endl;
	std::cin >> hour;
	std::cout << "Minute?" << std::endl;
	std::cin >> minute;
	std::cout << "Flight Duration?" << std::endl;
	std::cin >> flightDuration;
	std::cout << "Capacity?" << std::endl;
	std::cin >> capacity;
	std::cin.ignore();
	std::cout << "Departure?" << std::endl;
	std::getline (std::cin, departure);

	std::cout << "Destination?" << std::endl;
	std::getline (std::cin, destination);

	std::cout << "The flight has been added successfully!" << departure << destination <<std::endl;

	dbm.addFlight(month, day, year, hour, minute, flightDuration, capacity, departure, destination);
}

int passenger(DataManager& dbm) {
	while (true) {
		std::string firstName;
		std::string lastName;
		int selection = displayPassengerMenu(firstName, lastName);
		Passenger currentPassenger(firstName, lastName);
		switch (selection) {
		case 0:
			return 0;
		case 1:
			flightBooking(dbm, currentPassenger);
			return 0;
		case 2:
			
			break;
		default:

			break;
		}
	}
	return 0;
}

int flightBooking(DataManager& dbm, Passenger &passenger) {
	while (true) {
		dbm.displayFlight();
		std::vector<Flight> flights = dbm.getAllFlight();
		int selection;
		std::cin >> selection;
		if (selection < 1 || static_cast<int>(flights.size()) < selection) {
			break;
		}
		else if (flights[selection - 1].mCapacity == 0) {
			std::cout << "The flight is fully booked" << std::endl;
			break;
		} else {
			flights[selection - 1].mCapacity--;
			passenger.setFlight(flights[selection - 1]);
			std::cout << "Booking is successful!" << std::endl;
			return 0;
		}
	}
	return 0;
}

int displayPassengerMenu(std::string &firstName, std::string &lastName) {
	int selection;
	std::cout << "Your first name?" << std::endl;
	std::cin >> firstName;
	std::cout << "Your last name?" << std::endl;
	std::cin >> lastName;
	std::cout << "1. Pick a flight" << std::endl;
	std::cout << "2. Check in" << std::endl;
	std::cout << std::endl;
	std::cin >> selection;
	return selection;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
