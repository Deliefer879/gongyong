/*
	Operation2.cpp
	���α׷� ���� : �ܼ� ��� ���α׷�2
*/

#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);

	while (1)
	{
		for (DWORD i = 0; i < 10000; i++)
			for (DWORD i = 0; i < 10000; i++);	//Busy Waiting!!

		_fputts(_T("Operation2.exe \n"), stdout);
	}

	return 0;
}