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
        std::cout << target << " " << "not found!" << std::endl;
        std::cout << "auto exit in 1.5 second!" << std::endl;
        Sleep(1500);
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
        if (GetKeyState(VK_NUMPAD1))
        {
            system("cls");
            std::cout << currentDateTime() << " : AFKING" << std::endl;
            pressA();
            pressD();
            sleep_override(seconds);
        }

    }
}