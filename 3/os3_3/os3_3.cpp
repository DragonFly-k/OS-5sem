#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>//библиотека для работы с процессами
#include <iomanip> 

int main()
{                                          //все процессы и потоки в системе
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0); //снимок указанных процессов
    PROCESSENTRY32 peProcessEntry; //структура для хранения информации о процессе
    peProcessEntry.dwSize = sizeof(PROCESSENTRY32);
    try
    {
        if (!Process32First(snap, &peProcessEntry))//если не удалось получить информацию о первом процессе
            throw L"Process32First";
        do
        {
            std::wcout << L"Pid: " << peProcessEntry.th32ProcessID <<"\t"
                << L"Name: " << peProcessEntry.szExeFile << "\n";
        } while (Process32Next(snap, &peProcessEntry));//делаем снимок следующего процесса
    }
    catch (char* msg) {
        std::wcout << L"ERROR: " << msg << "\n";
    }
    system("pause");
    return 0;
}