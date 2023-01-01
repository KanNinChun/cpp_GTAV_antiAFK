#pragma once
#include<Windows.h>
#include <thread>
#include <chrono>
// Where currentDateTime code i take from
// https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
int seconds;

void sleep_override(int seconds)
{
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
    return buf;
}

int getSleepTime()
{
    system("cls");
    std::cout << "Please Enter How long for 1 afk cycle (s): ";
    std::cin >> seconds;
    std::cout<<std::endl;
    Sleep(500);
    system("cls");
    std::cout << "Press Numpad 1 to start Anti AFK" << std::endl;
    return seconds;
}