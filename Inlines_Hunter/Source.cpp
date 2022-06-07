#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <shlwapi.h>
#include <Psapi.h>
#include "Header.h"
#pragma comment(lib, "Shlwapi.lib")
; DWORD tpid;

BOOL modules(DWORD pid, PCSTR modname)
{
	MODULEENTRY32 md;
	HANDLE mods = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
	if (mods == INVALID_HANDLE_VALUE)
	{
		CloseHandle(mods);
		return (0);
	}
	if (Module32First(mods, &md))
	{
		do
		{
			if (!_strcmpi(PathFindFileNameA(md.szExePath), modname))
				return (1);

		} while (Module32Next(mods, &md));
	}
	return (0);
}

DWORD GetPID(const char* pn)
{
	DWORD procId = 0;
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	if (hSnap != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 pE;
		pE.dwSize = sizeof(pE);

		if (Process32First(hSnap, &pE))
		{
			if (!pE.th32ProcessID)
				Process32Next(hSnap, &pE);
			do
			{
				if (!_stricmp(pE.szExeFile, pn))
				{
					procId = pE.th32ProcessID;
					break;
				}
			} while (Process32Next(hSnap, &pE));
		}
	}
	CloseHandle(hSnap);
	return procId;
}

int EnumAllProc(PCSTR mod)
{
	int mCount = 0;
	PROCESSENTRY32 pe;
	HANDLE th32 = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	pe.dwSize = sizeof(PROCESSENTRY32);

	if (th32 == INVALID_HANDLE_VALUE)
	{
		printf("INVALID_HANDLE_VALUE\n");
		return (0);
	}
	if (Process32First(th32, &pe))
	{
		printf("\nlist of processes that contains this module ");
		if (modules(pe.th32ProcessID, mod))
			printf("\nprocess pid %lX\n", pe.th32ProcessID);
		do
		{
			if (modules(pe.th32ProcessID, mod) && pe.th32ProcessID != tpid)
			{
				printf("\nprocess pid %lX\n", pe.th32ProcessID);
				mCount++;
			}
		} while (Process32Next(th32, &pe));
	}
	if (mCount <= 1)
		printf("\ntotal 0\n");
	else
		printf("\ntotal %d\n", mCount);
	return (mCount);
}
int wmain(void)
{
	HANDLE hw = OpenProcess(PROCESS_ALL_ACCESS, 0, tpid = GetPID("app1.exe"));
	if (!hw)
		return (-1);
	HMODULE hm = LoadLibraryA("user32.dll");
	if (!hm)
		exit(EXIT_FAILURE);
	LPVOID add = GetProcAddress(hm, "MessageBoxA");
	if (!add)
		return (-1);
	long long mem = (long long)add;
	printf("function address : %llX\n", mem);
	if (!ReadProcessMemory(hw, add, bytes, buffsz, 0))
		exit(EXIT_FAILURE);
	for (int i = 0; i < buffsz; i++)
	{
		if (bytes[i] == 0x48 || bytes[i] == 0xFF)
		{
			if (bytes[i + 1] == 0xB8 || bytes[i + 1] == 0xE0)
			{
				IE0 = 1;
				break;
			}
		}
	}
	if (!IE0)
	{
		MessageBoxA(0, "no hook detected", 0, MB_OK);
		return (-1);
	}
	MEMORY_BASIC_INFORMATION data;
	HMODULE hdll;
	if (!VirtualQueryEx(hw, (LPCVOID)mem, &data, sizeof(MEMORY_BASIC_INFORMATION)))
		return (-1);
	hdll = (HMODULE)data.AllocationBase;
	printf("base_address : %llX\nmodule_size %u\n", data.AllocationBase, data.RegionSize);;
	if (!GetModuleFileNameEx(hw, hdll, dllpath, MAX_PATH))
		return (-1);
	printf("module %s\n", dllpath);
	unsigned unsigned char buffer[1024] = { 0 };
	if (!ReadProcessMemory(hw, (LPCVOID)(mem += 2), &buffer, sizeof(buffer), NULL))
		return (-1);
	while (buffer[i])
		buffer[i++];
	unsigned char sortedAdd[1024];
	while (i--)
		sortedAdd[j++] = buffer[i];
	sortedAdd[j] = '\0';
	unsigned long long s_1[] = { sortedAdd[0], sortedAdd[1],sortedAdd[2],sortedAdd[3],sortedAdd[4],sortedAdd[5] };
	long long njumpAdd = (s_1[0] << 40) | (s_1[1] << 32) | (s_1[2] << 24) | (s_1[3] << 16) | (s_1[4] << 8) | (s_1[5]);
	printf("jump_to %llX \n", njumpAdd);
	unsigned char secjump[12] = { 0 };
	if (!ReadProcessMemory(hw, (LPCVOID)njumpAdd, &secjump, sizeof(secjump), 0))
		return (-1);
	if (!VirtualQueryEx(hw, (LPCVOID)njumpAdd, &data, sizeof(MEMORY_BASIC_INFORMATION)))
		return (-1);
	hdll = (HMODULE)data.AllocationBase;
	if (!GetModuleFileNameEx(hw, hdll, dllpath2, MAX_PATH))
		return (-1);
	printf("\n\nthe hooked function jumps to this module (could be av/malicious module)\n");
	printf("base_address : %llX\nmodule_size %u\nmodule_name %s\n", data.AllocationBase, data.RegionSize, dllpath2);
	if (EnumAllProc(PathFindFileNameA((LPCSTR)dllpath2)) <= 1)
		return (0);
	system("pause");
	return (0);
}
