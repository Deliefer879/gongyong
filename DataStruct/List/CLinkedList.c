#include <stdio.h>
#include <stdlib.h>

#include "CLinkedList.h"

void ListInIt(List* plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data)
{
	Node* newData = (Node*)malloc(sizeof(Node));
	newData->data = data;

	if (plist->tail == NULL)
	{
		newData->next = newData;
		plist->tail = newData;
	}
	else
	{
		newData->next = plist->tail->next;
		plist->tail->next = newData;
		plist->tail = newData;
	}
	(plist->numOfData)++;
}

void LInsertFront(List* plist, Data data)
{
	Node* newData = (Node*)malloc(sizeof(Node));
	newData->data = data;

	if (plist->tail == NULL)
	{
		newData->next = newData;
		plist->tail = newData;
	}
	else
	{
		newData->next = plist->tail->next;
		plist->tail->next = newData;
	}
	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata)
{
	if (plist->tail == NULL)
	{
		printf("데이터 없음 \n");
		return FALSE;
	}
	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, Data* pdata)
{
	if (plist->tail == NULL)
	{
		printf("데이터 없음 \n");
		return FALSE;
	}
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List* plist)
{
	if (plist->cur == plist->tail)
	{
		if (plist->tail == plist->tail->next)
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

	Data data = plist->cur->data;
	plist->before->next = plist->cur->next;
	free(plist->cur);
	plist->cur = plist->before;
	(plist->numOfData)--;

	return data;
}

int LCount(List* plist)
{
	return plist->numOfData;
}

//문제 5-1 (해더파일이 중복되서 여기에 정의(책에서는 메인함수에 정의))
//void FindWorkShift(char* name, int date, List* list)
//{
//	Data employee;
//	int i = 0;
//	if (LFirst(list, &employee))
//	{
//		if (!strcmp(employee->name, name))
//		{
//			for (i = 0; i < date; i++)
//				LNext(list, &employee);
//
//			printf("%s 근무자의 %d일 후 당직자 : %s\n", name,date, employee->name);
//			return;
//		}
//		while (LNext(list, &employee))
//		{
//			if (!strcmp(employee->name, name))
//			{
//				for (i = 0; i < date; i++)
//					LNext(list, &employee);
//
//				printf("%s 근무자의 %d일 후 당직자 : %s\n",name ,date, employee->name);
//				return;
//			}
//		}
//	}
//}