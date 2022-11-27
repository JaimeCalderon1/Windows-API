#include "one.h"
#include <cstdlib>
#include <string>

int main()
{
	
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnap != INVALID_HANDLE_VALUE)
	{
		// create structure for our processes
		PROCESSENTRY32 procEntry;
		procEntry.dwSize = sizeof(PROCESSENTRY32);

		
		if (Process32First(hSnap, &procEntry))
		{
			do
			{
				// print out system exe's along with pids
				int bufferSize = WideCharToMultiByte(CP_UTF8, 0, procEntry.szExeFile, -1, NULL, 0, NULL, NULL);
				char* m = new char[bufferSize];
				WideCharToMultiByte(CP_UTF8, 0, procEntry.szExeFile, -1, m, bufferSize, NULL, NULL);
				wprintf(L"%S", m); 
				std::cout << " --- Process ID: " << procEntry.th32ProcessID;
				std::cout << '\n';
				delete[] m;
			} while (Process32Next(hSnap, &procEntry));


		}
	}
}