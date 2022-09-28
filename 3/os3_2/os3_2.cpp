#include <iostream>
#include <Windows.h>
#include <process.h>

int main()
{
    LPCWSTR an1 = L"D:\\универ\\осисп\\лабы\\3\\os3\\x64\\Debug\\os3_2_1.exe",
            an2 = L"D:\\универ\\осисп\\лабы\\3\\os3\\x64\\Debug\\os3_2_2.exe";
    STARTUPINFO si1, si2;
    PROCESS_INFORMATION pi1, pi2;
    ZeroMemory(&si1, sizeof(STARTUPINFO));  
    si1.cb = sizeof(STARTUPINFO);
    ZeroMemory(&si2, sizeof(STARTUPINFO)); 
    si2.cb = sizeof(STARTUPINFO);

    if (CreateProcess(an1, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si1, &pi1))
        std::cout << "-- Process OS3_2_1 created\n";
    else
        std::cout << "-- Process OS3_2_1 not created\n";

    if (CreateProcess(an2, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si2, &pi2))
        std::cout << "-- Process OS3_2_2 created\n";
    else
        std::cout << "-- Process OS3_2_2 not created\n";

    for (int i = 0; i < 100; i++) {
        Sleep(1000);
        std::cout << "\t" << _getpid();
    }

    WaitForSingleObject(pi1.hProcess, INFINITE);
    WaitForSingleObject(pi2.hProcess, INFINITE);
    CloseHandle(pi1.hProcess);
    CloseHandle(pi2.hProcess);
    return 0;
}