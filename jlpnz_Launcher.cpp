#include <Windows.h>
#include <iostream>
#include <string>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    const char CLASS_NAME[] = "JNLP Launcher";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    if (!RegisterClass(&wc))
    {
        std::cerr << "Failed to register window class" << std::endl;
        return 1;
    }

    HWND hWnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "JNLP Launcher",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 300, 100,
        NULL, NULL, hInstance, NULL
    );

    if (!hWnd)
    {
        std::cerr << "Failed to create window" << std::endl;
        return 1;
    }

    ShowWindow(hWnd, nCmdShow);

    HWND urlEdit = CreateWindowEx(
        0,
        "EDIT",
        "",
        WS_CHILD | WS_VISIBLE | WS_BORDER,
        10, 10, 250, 20,
        hWnd, (HMENU)1, hInstance, NULL
    );

    if (!urlEdit)
    {
        std::cerr << "Failed to create edit control" << std::endl;
        return 1;
    }

    HWND launchButton = CreateWindowEx(
        0,
        "BUTTON",
        "Launch",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        10, 40, 100, 20,
        hWnd, (HMENU)2, hInstance, NULL
    );

    if (!launchButton)
    {
        std::cerr << "Failed to create button" << std::endl;
        return 1;
    }

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
