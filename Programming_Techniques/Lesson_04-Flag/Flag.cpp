#include <bits/stdc++.h>

struct Time {
    int day, month, year, hour, minute, second;
};

bool Is_Leap_Year(int year);
bool Is_Valid_Time(const Time &d);

Time data() {
    Time d;
    while (true) {
        std::cin >> d.day >> d.month >> d.year >> d.hour >> d.minute >> d.second;
        if (Is_Valid_Time(d)) break;
        else
            std::cout << "Time is invalid! Please re-enter: ";
    }
    return d;
}

bool Is_Leap_Year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool Is_Valid_Time(const Time &d) {
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (d.day < 1 || d.day > days_in_month[d.month])
        return false;
    if (d.month < 1 || d.month > 12)
        return false;
    if (d.month == 2 && Is_Leap_Year(d.year))
        days_in_month[2] = 29;
    if (d.year <= 0)
        return false;

    if (d.hour < 0 || d.hour > 23)
        return false;
    if (d.minute < 0 || d.minute > 59)
        return false;
    if (d.second < 0 || d.second > 59)
        return false;
    return true;
}

// a = after, b = before
bool Is_Earlier(const Time &b, const Time &a) {
    if (b.year != a.year) return b.year < a.year;
    if (b.month != a.month) return b.month< a.month;
    if (b.day != a.day) return b.day< a.day;
    if (b.hour != a.hour) return b.hour < a.hour;
    if (b.minute != a.minute) return b.minute < a.minute;
    return b.second < a.second;
}


void Begin_Time(const Time &d) {
    if (!Is_Valid_Time(d)) {
        std::cout << "Begin time is invalid!" << std::endl;
        return;
    }
    std::cout << "Begin time: "
              << std::setw(2) << std::setfill('0') << d.day << "-"
              << std::setw(2) << std::setfill('0') << d.month << "-"
              << d.year << " | "
              << std::setw(2) << std::setfill('0') << d.hour << ":"
              << std::setw(2) << std::setfill('0') << d.minute << ":"
              << std::setw(2) << std::setfill('0') << d.second << std::endl;
}

void End_Time(const Time &d) {
    if (!Is_Valid_Time(d)) {
        std::cout << "End time is invalid!" << std::endl;
        return;
    }
    std::cout << "End time: "
              << std::setw(2) << std::setfill('0') << d.day << "-"
              << std::setw(2) << std::setfill('0') << d.month << "-"
              << d.year << " | "
              << std::setw(2) << std::setfill('0') << d.hour << ":"
              << std::setw(2) << std::setfill('0') << d.minute << ":"
              << std::setw(2) << std::setfill('0') << d.second << std::endl;
}

// format time
void Form_24(const Time &d) {
    std::cout << std::setw(2) << std::setfill('0') << d.day << "-"
              << std::setw(2) << std::setfill('0') << d.month << "-"
              << d.year << " | "
              << std::setw(2) << std::setfill('0') << d.hour << ":"
              << std::setw(2) << std::setfill('0') << d.minute << ":"
              << std::setw(2) << std::setfill('0') << d.second << std::endl;
}

void Form_12(const Time &d) {
    int hour = d.hour % 12;
    if (hour == 0) hour = 12;
    std::string AmPm = (d.hour < 12 ? "Am" : "Pm");
    std::cout << std::setw(2) << std::setfill('0') << d.day << "-"
              << std::setw(2) << std::setfill('0') << d.month << "-"
              << d.year << " | "
              << std::setw(2) << std::setfill('0') << d.hour << ":"
              << std::setw(2) << std::setfill('0') << d.minute << ":"
              << std::setw(2) << std::setfill('0') << d.second 
              << " " << AmPm << std::endl;
}

long long To_Seconds(const Time &d) {
    return ((d.day * 24LL * d.hour) * 60 + d.minute) * 60 + d.second;
}


int main() {
    std::cout << "Enter Begin Time: ";
    Time begin = data();

    std::cout << "Enter End Time: ";
    Time end = data();
    
    Begin_Time(begin);
    End_Time(end);

    if (!Is_Earlier(begin, end))
        std::cout << "Error: Begin time must be earlier than End time!" << std::endl;
    
    long long countdown = To_Seconds(end) - To_Seconds(begin);
    Time down = begin;
    bool running = true;

    int format_time;
    std::cout << "Choose time format ('1' = 12h or '2' = 24h): ";
    std::cin >> format_time;

    while (running) {
        if (format_time == 1) Form_12(begin);
        else Form_24(begin);
        
    }

    return 0;
}