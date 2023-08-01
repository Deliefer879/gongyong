#include <stdio.h>
#include <stdlib.h>

#include "DBLinkedList.h"

//���� 5-1
/*List list;
	Data employee;
	int i = 0;

	ListInIt(&list);

	employee = SetEmployeeInfo("1��", 1);
	LInsert(&list, employee);
	employee = SetEmployeeInfo("2��", 2);
	LInsert(&list, employee);
	employee = SetEmployeeInfo("3��", 3);
	LInsert(&list, employee);
	employee = SetEmployeeInfo("4��", 4);
	LInsert(&list, employee);
	employee = SetEmployeeInfo("5��", 5);
	LInsert(&list, employee);

	if (LFirst(&list, &employee))
	{
		ShowEmployeeInfo(employee);
		for(i=0;i<4;i++)
		{
			LNext(&list, &employee);
			ShowEmployeeInfo(employee);
		}
	}
	
	printf("\n%5s%5s%5s%5s%5s%5s%5s \n", "��", "ȭ", "��", "��", "��", "��", "��");
	if (LFirst(&list, &employee))
	{
		ShowWorkShift(employee);
		i = 1;
		for (i; i < 31; i++)
		{
			if (i % 7 == 0)
				printf("\n");
			LNext(&list, &employee);
			ShowWorkShift(employee);
		}
	}
	printf("\n\n");

	FindWorkShift("4��", 7,&list);*/

int main()
{
	List list;
	Data data;

	ListInIt(&list);

	for (int i = 1; i < 9; i++)
		LInsert(&list, i);

	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n������ �� : %d\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		if (data % 4 == 0)
			LRemove(&list);
		
		while (LNext(&list, &data))
		{
			if (data % 4 == 0)
				LRemove(&list);
		}
	}

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n������ �� : %d\n", LCount(&list));

}