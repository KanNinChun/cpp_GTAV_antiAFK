#pragma once
#include<Windows.h>

void pressA()
{
    SHORT key;
    UINT mappedkey;
    INPUT input = { 0 };
    key = VkKeyScan('a');
    mappedkey = MapVirtualKeyA(LOBYTE(key), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    Sleep(10);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
}

void pressD()
{
    SHORT key;
    UINT mappedkey;
    INPUT input = { 0 };
    key = VkKeyScan('d');
    mappedkey = MapVirtualKeyA(LOBYTE(key), 0);
    input.type = INPUT_KEYBOARD;
    input.ki.dwFlags = KEYEVENTF_SCANCODE;
    input.ki.wScan = mappedkey;
    SendInput(1, &input, sizeof(input));
    Sleep(10);
    input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(input));
}