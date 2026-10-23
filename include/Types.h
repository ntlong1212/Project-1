#pragma once

#include <string>

struct Time {
    int hour;
    int minute;

    Time(int h = 0, int m = 0) : hour(h), minute(m) {}
};

struct Date {
    int day;
    int month;
    int year;

    Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}
};

struct EventNode {
    Time startTime;
    std::string content;
    EventNode* next;

    EventNode(Time t, const std::string& c) 
        : startTime(t), content(c), next(nullptr) {}
};

struct DayNode {
    Date date;
    EventNode* eventsHead; // Đầu danh sách các sự kiện trong ngày
    DayNode* next;         // Trỏ đến ngày tiếp theo có sự kiện

    DayNode(Date d) 
        : date(d), eventsHead(nullptr), next(nullptr) {}
};

struct CalendarManager {
    DayNode* headDay;      // Đầu danh sách các ngày

    CalendarManager() : headDay(nullptr) {}
};
