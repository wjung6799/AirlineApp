#include "DataManager.h"
#include <iostream>
#include <stdexcept>

namespace AirlineApp {
	Flight& DataManager::addFlight(const int& month, const int& day, const int& year, const int& hour, const int& minute, const int& flightDuration,
		const int& capacity, const std::string& departure, const std::string& destination) {
		Flight theFlight(month, day, year, hour, minute, flightDuration, capacity, departure, destination);
		theFlight.setFlightId(mNextFlightNumb++);
		mFlights.push_back(theFlight);

		return mFlights[mFlights.size() - 1];
	}

	Flight& DataManager::getFlight(std::string flightId) {
		for (auto& flight : mFlights) {
			if (flight.getFlightId().compare(flightId) == 0) {
				return flight;
			}
		}
		throw std::logic_error("No flight found");
	}

	std::vector<Flight> DataManager::getFlight(int month, int day, int year, int hour, int minute) {
		std::vector<Flight> vect;
		FlightTime target(month, day, year, hour, minute);
		for (auto& flight : mFlights) {
			if (flight.getFlightTime().compare(target) == 0) {
				vect.push_back(flight);
			}
		}

		return vect;
	}

	std::vector<Flight>& DataManager::getAllFlight() {
		return mFlights;
	}

	Passenger& DataManager::addPassenger(const std::string& firstName, const std::string& lastName) {
		Passenger passenger(firstName, lastName);
		mPassengers.push_back(passenger);
		return passenger;
	}

	void DataManager::displayFlight() {
		int counter = 1;
		for (auto& flight : mFlights) {
			std::cout << counter << ". " << flight.getString() << " seat left :" << flight.mCapacity << std::endl;
		}
	}
}