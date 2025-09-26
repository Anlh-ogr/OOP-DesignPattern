#include <bits/stdc++.h>

struct Time {
    int day, month, year;
    int hour, minute, second;
};

bool Is_Leap_Year(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int Days_in_Month(int month, int year) {
    if (month == 2) return Is_Leap_Year(year) ? 29 : 28;
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    return 31;
}

bool Is_Valid_Time(const Time &t) {
    if (t.year <= 0) return false;
    if (t.month < 1 || t.month > 12) return false; 
    if (t.day < 1 || t.day > Days_in_Month(t.month, t.year)) return false;
    
    if (t.hour < 0 || t.hour > 23) return false;
    if (t.minute < 0 || t.minute > 59) return false;
    if (t.second < 0 || t.second > 59) return false;
    
    return true;
}

Time Input_Data(std::string label) {
    Time id;
    bool ok = true;
    do {
        std::cout << "Enter" << label << "time: ";
        std::cin >> id.day >> id.month >> id.year >> id.hour >> id.minute >> id.second;
        if (!Is_Valid_Time(id))
            std::cout << "Invalid! Please re-enter." << std::endl;
        else ok = true;
    } while (!ok);
    return id;
}

// a = after, b = before
bool Is_Earlier(const Time &b, const Time &a) {
    if (b.year != a.year) return b.year < a.year;
    if (b.month != a.month) return b.month < a.month;
    if (b.day != a.day) return b.day < a.day;
    if (b.hour != a.hour) return b.hour < a.hour;
    if (b.minute != a.minute) return b.minute < a.minute;
    return b.second < a.second;
}

// format time 24h
void Time_24(const Time &t) {
    std::cout << std::setw(2) << std::setfill('0') << t.day << "-"
              << std::setw(2) << std::setfill('0') << t.month << "-"
              << t.year << " | "
              << std::setw(2) << std::setfill('0') << t.hour << ":"
              << std::setw(2) << std::setfill('0') << t.minute << ":"
              << std::setw(2) << std::setfill('0') << t.second;
}

// format time 12h
void Time_12(const Time &t) {
    int hour = t.hour % 12;
    if (hour == 0) hour = 12;
    std::string AmPm = (t.hour < 12 ? "Am" : "Pm");
    
    std::cout << std::setw(2) << std::setfill('0') << t.day << "-"
              << std::setw(2) << std::setfill('0') << t.month << "-"
              << t.year << " | "
              << std::setw(2) << std::setfill('0') << hour << ":"
              << std::setw(2) << std::setfill('0') << t.minute << ":"
              << std::setw(2) << std::setfill('0') << t.second << " " << AmPm;
}

// update time
void Tick_Tick(Time &t) {
    t.second++;
    if (t.second == 60) { t.second = 0; t.minute++; }
    if (t.minute == 60) { t.minute = 0; t.hour++ ; }
    if (t.hour == 24) { t.hour = 0; t.day++; }

    if (t.day > Days_in_Month(t.month, t.year)) {
        t.day = 1;
        t.month++;
        if (t.month > 12) { t.month = 1; t.year++; }
    }
}

// count down
void Count_Down(Time start, const Time &end, int format_type) {
    bool running = true;
    while (running) {
        if (format_type == 1) Time_12(start);
        else Time_24(start);
        std::cout << "\n";

        if (!Is_Earlier(start, end)) {
            std::cout << "Time's up" << std::endl;
            running = false;
        } else {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            Tick_Tick(start);
        }
    }
}

/*
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

long long To_Seconds(const Time &d) {
    return ((d.day * 24 + d.hour) * 60 + d.minute) * 60 + d.second;
}
*/

int main() {
    // start time
    Time start = Input_Data(" start ");
    std::cout << "Start time: ";
    Time_24(start);
    std::cout << "\n\n";

    // end time
    Time end = Input_Data(" end ");
    std::cout << "End time: ";
    Time_24(end);
    std::cout << "\n\n";

    if (!Is_Earlier(start, end)) {
        std::cout << "Error: Start must be earlier than End!" << "\n";
        return 0;
    }
    
    int format_type;
    std::cout << "Choose time format ('1' = 12h or '2' = 24h): ";
    std::cin >> format_type;

    Count_Down(start, end, format_type);

    return 0;
}