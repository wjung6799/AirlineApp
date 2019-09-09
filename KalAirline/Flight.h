#pragma once
#include <string>
#include "FlightTime.h"

namespace AirlineApp {
	class Flight {
	public:
		Flight() = default;
		Flight(const int& month, const int& day, const int& year, const int& hour, const int& minute, const int& flightDuration, const int& capacity);
		void setFlightId(int number);
		std::string getFlightId();
		FlightTime getFlightTime();
	private:
		FlightTime mFlightTime;
		int mFlightDuration = -1;
		int mCapacity = -1;
		std::string mFlightId;
	};
}