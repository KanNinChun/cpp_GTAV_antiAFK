#pragma once
#include <iostream>
#include <windows.h>

std::string GetActiveWindowTitle()
{
    char wnd_title[256];
    HWND hwnd = GetForegroundWindow(); // get handle of currently active window
    GetWindowText(hwnd, wnd_title, sizeof(wnd_title));
    return wnd_title;
}

void console_topmost()
{
    HWND window = FindWindow(NULL, GetActiveWindowTitle().c_str());
    SetWindowPos(window, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE); // set the exe to top most ,so it wouldn't disappear when you click on other window
}

void console_position(int width, int height)
{
    HWND console = GetConsoleWindow();
    MoveWindow(console, 0, 0, width, height, TRUE);
}

void console_setTitle()
{
    SetConsoleTitleA("AFK BOT");
}

void console_functions()
{
    console_setTitle();
    console_topmost();
    console_position(400, 200);
}