/*
	OperationStateChild.cpp
	���α׷� ���� : ���α׷� �������� ���� ��ȯ��
*/

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <Windows.h>

int _tmain(int argc, TCHAR* argv[])
{
	float num1, num2;
	_fputts(_T("Return Value Test \n"), stdout);
	_tscanf(_T("%f %f"), &num1, &num2);

	if (num2 == 0)
	{
		exit(-1); // or return -1;
	}

	_tprintf(_T("OperationResult : %f \n"), num1 / num2);

	return 1;
}