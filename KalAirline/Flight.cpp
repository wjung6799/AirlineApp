#include "Flight.h"

namespace AirlineApp {
	Flight::Flight(const int& month, const int& day, const int& year, const int& hour, const int& minute, const int& flightDuration,
		const int& capacity, const std::string& departure, const std::string& destination) {
		FlightTime flightTime(month, day, year, hour, minute);
		mFlightTime = flightTime;
		mFlightDuration = flightDuration;
		mCapacity = capacity;
		mDeparture = departure;
		mDestination = destination;
	}

	void Flight::setFlightId(int number)
	{
		std::string prefix = "F-";
		int id = number;
		mFlightId = prefix + std::to_string(number);
	}

	std::string Flight::getFlightId() {
		return mFlightId;
	}

	FlightTime Flight::getFlightTime() {
		return mFlightTime;
	}

	std::string Flight::getString() {
		std::string str = getFlightId() + " Departure: " + mDeparture + " Destination: " + mDestination + " Flight Time: " + getFlightTime().getString();
		return str;
	}
}