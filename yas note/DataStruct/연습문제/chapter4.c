#include <stdio.h>
#include <stdlib.h>

#include "DLinkedList.h"
//chapter3 폴더에 Point.h사용
#include "Point.h"

//구조체
/*typedef struct _node{
	int data;
	struct _node* next;
}Node;*/

//기본/문제4-1
/*
	Node * head = NULL;
	Node * tail = NULL;
	Node * cur = NULL;

	Node* newNode = NULL;
	int readData;

	while (1)
	{
		printf("자연수 입력 : ");
		scanf_s("%d", &readData);
		if (readData < 1)
			break;

		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		//데이터 저장
		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;
		
		tail = newNode;

		//데이터를 역순으로 저장
		if (head == NULL)
		{
			tail = newNode;
		}
		else
		{
			newNode->next = head;
		}
		head = newNode;
	}
	printf("\n");

	printf("입력 받은 데이터의 전체 출력 \n");
	if (head == NULL)
		printf("저장된 데이터 없음 \n");
	else
	{
		cur = head;
		printf("%d ", cur->data);

		while (cur->next != NULL)
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");

	if (head == NULL)
		return 0;
	else
	{
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf("%d 삭제\n", delNode->data);
		free(delNode);

		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d 삭제\n", delNode->data);
			free(delNode);
		}
	}*/

//문제4-2
/*Node* dmy = (Node*)malloc(sizeof(Node));

	Node* head = dmy;
	Node* tail = dmy;
	Node* cur = dmy;

	Node* newData = NULL;
	int readData;

	while (1)
	{
		printf("데이터 입력 : ");
		scanf_s("%d", &readData);
		if (readData < 1)
			break;

		newData = (Node*)malloc(sizeof(Node));
		newData->data = readData;
		newData->next = NULL;

		tail->next = newData;
		tail = newData;
	}

	while (1)
	{
		if (cur->next == NULL)
		{
			break;
		}
		cur = cur->next;
		printf("%d ", cur->data);
	}
	printf("\n");

	Node* delData = head->next;
	Node* delNextData = head->next->next;

	while (1)
	{
		if (delData == NULL)
		{
			break;
		}
		printf("%d delete\n",delData->data);
		free(delData);

		delData = delNextData;
		delNextData = delData->next;
	}*/

//문제 4-3
/*
	List list;
	LData data;
	Point compData; SetPointPos(&compData, 2, 2);
	Point *Data;


	ListInIt(&list);
	
	for (int i = 1; i < 6; i++)
	{
		Data = (Point*)malloc(sizeof(Point));
		SetPointPos(Data, i, i); LInsert(&list, Data);
	}

	if (LFirst(&list, &data))
	{
		ShowPointPos(data);
		while (LNext(&list, &data))
		{
			ShowPointPos(data);
		}
	}

	printf("\ntotal data num : %d\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		if (!PointComp(data,&compData))
			LRemove(&list);
		while (LNext(&list, &data))
		{
			if (!PointComp(data, &compData))
				LRemove(&list);
		}
	}

	if (LFirst(&list, &data))
	{
		ShowPointPos(data);

		while (LNext(&list, &data))
			ShowPointPos(data);
	}
	printf("\ntotal data num : %d\n", LCount(&list));
	*/

//사용자가 정렬의 규칙을 정하는 함수
int SortRuleChose(int n1,int n2)
{
	return n1 > n2 ? 0 : 1;
}

int main()
{
	List list;
	LData data;

	ListInIt(&list);
	SetSortRule(&list, SortRuleChose);

	LInsert(&list, 11);
	LInsert(&list, 33);
	LInsert(&list, 22);
	LInsert(&list, 11);
	LInsert(&list, 33);

	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data))
			printf("%d ", data);		
	}

	printf("\ntotal data num : %d\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		if (data == 22)
			LRemove(&list);
		while (LNext(&list, &data))
		{
			if (data ==22)
				LRemove(&list);
		}
	}

	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\ntotal data num : %d\n", LCount(&list));


	return 0;
}