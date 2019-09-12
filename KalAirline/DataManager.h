#pragma once
#include <vector>
#include "Flight.h"
#include "Passenger.h"

namespace AirlineApp {
	const int kPassengerId = 1000;
	const int kFlightId = 1000;
	class DataManager {
	public:
		Flight& addFlight(const int& month, const int& day, const int& year, const int& hour, const int& minute, const int& flightDuration,
			const int& capacity, const std::string& departure, const std::string& destination);
		std::vector<Flight> getFlight(int month, int day, int year, int hour, int minute);
		std::vector<Flight>& getAllFlight();
		Flight& getFlight(std::string flightId);
		Passenger& addPassenger(const std::string& firstName, const std::string& lastName);
		void displayFlight();
	private:
		std::vector<Flight> mFlights;
		std::vector<Passenger> mPassengers;
		int mNextFlightNumb = kFlightId;
	};
}
