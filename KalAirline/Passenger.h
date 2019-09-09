#pragma once
#include <string>
#include "Flight.h"

namespace AirlineApp {
	class Passenger {
	public:
		Passenger() = default;
		Passenger(const std::string& firstName, const std::string& lastName);
		void display();
		void setFlight(const Flight& flight);
	private:
		std::string mFirstName;
		std::string mLastName;
		Flight mFlight;
	};
}