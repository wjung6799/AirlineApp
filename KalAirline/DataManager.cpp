#include "DataManager.h"
#include <iostream>
#include <stdexcept>

namespace AirlineApp {
	Flight& DataManager::addFlight(const int& month, const int& day, const int& year, const int& hour, const int& minute, const int& flightDuration, const int& capacity) {
		Flight theFlight(month, day, year, hour, minute, flightDuration, capacity);
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

}