#pragma once
#include "console.h"
#include "presskey.h"
#include "miscellaneous.h"

char buff[100];
const std::string process = "Grand Theft Auto V";

HWND handle = FindWindowA(NULL, (LPCSTR)process.c_str());

bool checkHandle()  // run at first
{
    if (!handle)
    {
       sprintf_s(buff,  " %s not found! Exit when click ok", process.c_str());
       MessageBoxA(NULL, buff , "Error Message", MB_ICONERROR | MB_OK);
       exit(EXIT_FAILURE);
       return false;
    }
    else
    {
        std::cout << process << " " << "found!" << std::endl;
        Sleep(700);
        system("cls");
        return true;
    }
}


//bool isIconic() // run at second
//{
//    if (IsIconic(handle) != 0)
//    {
//        system("cls");
//        std::cout << target << " " << "if Window minimized Bot wouldn't work" << std::endl;
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}

bool isForeground() // run at third
{
	if (GetForegroundWindow() != handle)
	{
		system("cls");
		std::cout << process << " " << "if Window not in foreground Bot wouldn't work" << std::endl;
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
    while (true && isForeground() == false)
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