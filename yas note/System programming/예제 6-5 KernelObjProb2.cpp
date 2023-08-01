/* 
	KernelObjProb2.cpp
	프로그램 설명 : CloseHandle 함수 이해2
*/

#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	DWORD n = 0;
	while (n < 100)
	{
		for (DWORD i = 0; i < 10000; i++)
			for (DWORD i = 0; i < 10000; i++);

		_fputts(_T("KernerlObjProb2.exe \n"), stdout);
		n++;
	}

	return 0;
}