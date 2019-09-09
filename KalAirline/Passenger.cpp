#include "Passenger.h"
#include <iostream>

namespace AirlineApp {
	Passenger::Passenger(const std::string& firstName, const std::string& lastName) : mFirstName(firstName), mLastName(lastName) {
		
	}

	void Passenger::setFlight(const Flight& flight) {
		mFlight = flight;
	}

	void Passenger::display() {
		std::cout << mFirstName << " " << mLastName << std::endl;
	}
}