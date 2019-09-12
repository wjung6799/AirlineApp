#pragma once
#include <string>
#include "FlightTime.h"

namespace AirlineApp {
	class Flight {
	public:
		Flight() = default;
		Flight(const int& month, const int& day, const int& year, const int& hour, const int& minute,
			const int& flightDuration, const int& capacity, const std::string& departure, const std::string& destination);
		void setFlightId(int number);
		std::string getFlightId();
		FlightTime getFlightTime();
		std::string getString();
		int mCapacity = -1;
	private:
		FlightTime mFlightTime;
		int mFlightDuration = -1;
		std::string mFlightId;
		std::string mDeparture;
		std::string mDestination;
	};
}