#pragma once
#include "Headers.h"

class CMemory
{
public:
	template <class type>
	void WriteMem(uintptr_t addressToWrite, type valueToWrite)
	{
		WriteProcessMemory(handle, (LPVOID)(addressToWrite), &valueToWrite, sizeof(valueToWrite), NULL);
	}

	template <class type>
	type ReadMem(uintptr_t addressToReadFrom)
	{
		type result;
		ReadProcessMemory(handle, (LPCVOID)(addressToReadFrom), &result, sizeof(result), NULL);
		return result;
	}

	bool getHandle();
	bool getRequiredModules();

private:
	int processId = 0;
	HANDLE handle = nullptr;

};

extern CMemory Memory;