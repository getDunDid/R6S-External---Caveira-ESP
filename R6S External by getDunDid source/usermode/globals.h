#pragma once

#include <Windows.h>
#include <stdint.h>

bool bCaveiraESPStatus = false;

HWND hwnd;
HANDLE hProcess;
uint32_t pid;
uint64_t base_address;

template<typename T> 
T RPM(uintptr_t address) 
{
	T buffer;
	ReadProcessMemory(hProcess, (LPCVOID)address, &buffer, sizeof(T), NULL);
	return buffer;
}

template<typename T> 
void WPM(uintptr_t address, T buffer) 
{
	WriteProcessMemory(hProcess, (LPVOID)address, &buffer, sizeof(buffer), NULL);
}