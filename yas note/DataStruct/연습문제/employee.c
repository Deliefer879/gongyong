#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "employee.h"
#include "CLinkedList.h"

Employee* SetEmployeeInfo(char* name, int eNum)
{
	Employee* newData = (Employee*)malloc(sizeof(Employee));
	strcpy_s(newData->name, NAME_LEN, name);
	newData->eNum = eNum;

	return newData;
}

void ShowEmployeeInfo(Employee* data)
{
	printf("���� ����\n�̸� : %s\n��� : %d\n", data->name, data->eNum);
}

void ShowWorkShift(Employee* data)
{
	printf("%5s", data->name);
}
