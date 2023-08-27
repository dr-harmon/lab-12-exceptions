#pragma once

enum Meridian {
    AM, PM
};

class Time {
private:
    int hour;
    int minute;
    Meridian meridian;
    int getStandardHour(int militaryHour) {
        if (militaryHour < 13) {
            return militaryHour == 0 ? 12 : militaryHour;
        } else {
            return militaryHour - 12;
        }
    }
public:
    Time(int hour, int minute, Meridian meridian) {
        this->hour = hour;
        this->minute = minute;
        this->meridian = meridian;
    }
    Time(int militaryHour, int minute) {
        this->hour = getStandardHour(militaryHour);
        this->minute = minute;
        this->meridian = militaryHour < 12 ? AM : PM;
    }
    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    Meridian getMeridian() const { return meridian; }
    int getMilitaryHour() const {
        switch (getMeridian()) {
            case AM:
            return getHour() == 12 ? 0 : getHour();
            case PM:
            return getHour() == 12 ? 12 : getHour() + 12;
        }
    }
};
