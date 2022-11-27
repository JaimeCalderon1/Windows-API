#pragma once

#include <vector>
#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <wchar.h>

//DWORD procID(const wchar_t* procName);
DWORD procID();

uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t* modName);

uintptr_t FindDMAaddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int>);