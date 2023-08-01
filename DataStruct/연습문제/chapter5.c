#include <stdio.h>
#include <stdlib.h>

#include "DBLinkedList.h"

//문제 5-1
/*List list;
	Data employee;
	int i = 0;

	ListInIt(&list);

	employee = SetEmployeeInfo("1번", 1);
	LInsert(&list, employee);
	employee = SetEmployeeInfo("2번", 2);
	LInsert(&list, employee);
	employee = SetEmployeeInfo("3번", 3);
	LInsert(&list, employee);
	employee = SetEmployeeInfo("4번", 4);
	LInsert(&list, employee);
	employee = SetEmployeeInfo("5번", 5);
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
	
	printf("\n%5s%5s%5s%5s%5s%5s%5s \n", "월", "화", "수", "목", "금", "토", "일");
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

	FindWorkShift("4번", 7,&list);*/

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
	printf("\n데이터 수 : %d\n", LCount(&list));

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
	printf("\n데이터 수 : %d\n", LCount(&list));

}