#pragma once
#include <vector>
#include "Flight.h"
#include "Passenger.h"

namespace AirlineApp {
	const int kPassengerId = 1000;
	const int kFlightId = 1000;
	class DataManager {
	public:
		Flight& addFlight(const int& month, const int& day, const int& year, const int& hour, const int& minute, const int& flightDuration, const int& capacity);
		std::vector<Flight> getFlight(int month, int day, int year, int hour, int minute);
		Flight& getFlight(std::string flightId);
	private:
		std::vector<Flight> mFlights;
		int mNextFlightNumb = kFlightId;
	};
}
