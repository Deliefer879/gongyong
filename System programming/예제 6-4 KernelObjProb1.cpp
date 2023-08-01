/*
	KernelObjProb1.cpp
	프로그램 설명 : CloseHandle 함수 이해 1
*/

#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;
	si.cb = sizeof(si);

	TCHAR command[] = _T("KernerlobjProb2.exe");
	CreateProcess(
		NULL, command, NULL, NULL, TRUE,
		0, NULL, NULL, &si, &pi
	);

	CloseHandle(pi.hProcess);

	return 0;
}