#pragma once
#include <string>

namespace AirlineApp {
	class FlightTime {
	public:
		FlightTime() = default;
		FlightTime(const int& month, const int& day, const int& year, const int& hour, const int& minute);
		int compare(FlightTime other);
		int getMonth();
		int getDay();
		int getYear();
		int getHour();
		int getMinute();
		std::string getString();
	private:
		int mMonth;
		int mDay;
		int mYear;
		int mHour;
		int mMinute;
	};
}