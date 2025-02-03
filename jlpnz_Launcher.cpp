#include <Windows.h>
#include <iostream>
#include <string>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // Create a window
    HWND hWnd = CreateWindowEx(
        0,
        "STATIC",
        "JNLP Launcher",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        300,
        100,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (!hWnd)
    {
        std::cerr << "Failed to create window" << std::endl;
        return 1;
    }

    // Create a edit control for the URL
    HWND urlEdit = CreateWindowEx(
        0,
        "EDIT",
        "",
        WS_CHILD | WS_VISIBLE | WS_BORDER,
        10,
        10,
        250,
        20,
        hWnd,
        (HMENU)1,
        hInstance,
        NULL
    );

    if (!urlEdit)
    {
        std::cerr << "Failed to create edit control" << std::endl;
        return 1;
    }

    // Create a button to launch the JNLP
    HWND launchButton = CreateWindowEx(
        0,
        "BUTTON",
        "Launch",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        10,
        40,
        100,
        20,
        hWnd,
        (HMENU)2,
        hInstance,
       