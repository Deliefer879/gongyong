/*
	OperationStateParent.cpp
	프로그램 설명 : 프로그램 실행 결과에 따른 반환값 확인
*/

#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi;
	DWORD state;

	si.cb = sizeof(si);
	si.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE;
	si.dwX = 100;
	si.dwY = 200;
	si.dwXSize = 300;
	si.dwYSize = 200;
	//si.lpTitle = _T("return & exit");

	TCHAR command[] = _T("OperationStateChild.exe");

	CreateProcess(NULL, command,
		NULL, NULL, TRUE,
		CREATE_NEW_CONSOLE,
		NULL, NULL,
		&si, &pi
	);

	for (DWORD i = 0; i < 10000; i++)
		for (DWORD i = 0; i < 10000; i++);

	//WaitForSingleObject(pi.hProcess, INFINITE);

	GetExitCodeProcess(pi.hProcess, &state);
	if (state == STILL_ACTIVE)
		_tprintf(_T("STILL_ACTIVE \n\n"));
	else
		_tprintf(_T("state : %d \n\n"), state);
	//CloseHandle(pi.hProcess);

	return 0;
}