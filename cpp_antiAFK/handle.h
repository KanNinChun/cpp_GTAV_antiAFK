#pragma once
#include "console.h"
#include "presskey.h"
#include "miscellaneous.h"

std::string name = "Grand Theft Auto V";
std::string filetype = ".exe";
std::string combain = name + filetype;
LPCSTR target = combain.c_str();
HWND handle = FindWindowA(NULL, target);

bool checkHandle()  // run at first
{
    if (handle == INVALID_HANDLE_VALUE)
    {
       MessageBoxA(NULL," Target not found! Exit when click ok", "Error Message", MB_ICONERROR | MB_OK);
       exit(EXIT_FAILURE);
        return false;
    }
    else
    {
        std::cout << target << " " << "found!" << std::endl;
        Sleep(700);
        system("cls");
        return true;
    }
}

bool isIconic() // run at second
{
    if (IsIconic(handle) != 0)
    {
        system("cls");
        std::cout << target << " " << "if Window minimized Bot wouldn't work" << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

void start()
{
    console_functions();
    checkHandle();
    getSleepTime();
    while (true && isIconic() == false)
    {
        SetFocus(GetConsoleWindow());
        SetActiveWindow(GetConsoleWindow());
        if (GetKeyState(VK_NUMPAD1))
        {
            system("cls");
            std::cout << currentDateTime() << " : AFKING" << std::endl;
            pressA();
            pressD();
            sleep_override(seconds);
        }
        else
        {
            system("cls");
            std::cout << currentDateTime() << " : Stoped" << std::endl;
            sleep_override(1);
        }
        Sleep(1); // optimize CPU usage
    }
}