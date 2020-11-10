#include "Memory.h"

CMemory Memory;

bool CMemory::getHandle()
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (hSnapshot == INVALID_HANDLE_VALUE)
		return false;

	PROCESSENTRY32 ProcEntry;

	ProcEntry.dwSize = sizeof(PROCESSENTRY32);

	while (Process32Next(hSnapshot, &ProcEntry))
	{
		if (!strcmp(ProcEntry.szExeFile, "csgo.exe"))
		{
			processId = ProcEntry.th32ProcessID;
			handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);
		}
	}

	CloseHandle(hSnapshot);

	return (processId && handle ? true : false);
}

bool CMemory::getRequiredModules()
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, processId);
	if (hSnapshot == INVALID_HANDLE_VALUE)
		return false;

	MODULEENTRY32 mEntry;

	mEntry.dwSize = sizeof(MODULEENTRY32);

	while (Module32Next(hSnapshot, &mEntry))
	{
		if (!strcmp(mEntry.szModule, "client.dll"))
		{
			Offsets.Client = (uintptr_t)mEntry.modBaseAddr;
		}
		else if (!strcmp(mEntry.szModule, "engine.dll"))
		{
			Offsets.Engine = (uintptr_t)mEntry.modBaseAddr;
		}
	}

	CloseHandle(hSnapshot);

	return (Offsets.Client && Offsets.Engine ? true : false);
}