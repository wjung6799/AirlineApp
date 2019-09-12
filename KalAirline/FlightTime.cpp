#include "FlightTime.h"

namespace AirlineApp {
	FlightTime::FlightTime(const int& month, const int& day, const int& year, const int& hour, const int& minute) {
		mMonth = month;
		mDay = day;
		mYear = year;
		mHour = hour;
		mMinute = minute;
	}

	int FlightTime::compare(FlightTime other) {
		if (other.mYear != (*this).mYear) {
			return other.mYear - (*this).mYear;
		}
		else if (other.mMonth != (*this).mMonth) {
			return other.mMonth - (*this).mMonth;
		}
		else if (other.mDay != (*this).mDay) {
			return other.mDay - (*this).mDay;
		}
		else if (other.mHour != (*this).mHour) {
			return other.mHour - (*this).mHour;
		}
		else if (other.mMinute != (*this).mMinute) {
			return other.mMinute - (*this).mMinute;
		}
		return 0;
	}

	int FlightTime::getMonth() {
		return mMonth;
	}
	int FlightTime::getDay() {
		return mDay;
	}
	int FlightTime::getYear() {
		return mYear;
	}
	int FlightTime::getHour() {
		return mHour;
	}
	int FlightTime::getMinute() {
		return mMinute;
	}

	std::string FlightTime::getString() {
		std::string str = std::to_string(mMonth) + "/" + std::to_string(mDay) + "/" + std::to_string(mYear) + " @" + std::to_string(mHour) + ":" + std::to_string(mMinute);
		return str;
	}
}
