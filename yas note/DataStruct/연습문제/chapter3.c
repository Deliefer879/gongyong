#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "NameCard.h"

#define CNAME "you"
#define CPHONE "won"

int main()
{
	//����3-1
	List list;
	int data,i=0,sum =0;

	ListInit(&list);

	for (i = 1; i < 10; i++)
		LInsert(&list, i);

	if (LFirst(&list, &data))
	{
		sum += data;
		while (LNext(&list, &data))
			sum += data;
		printf("���� : %d\n", sum);
	}
	else
		printf("����Ʈ ȣ�� ����\n");

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n");

	if (LFirst(&list, &data))
	{
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data % 2 == 0 || data % 3 == 0)
				LRemove(&list);
		}
	}

	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while (LNext(&list, &data))
			printf("%d ", data);
	}

	//���� 3-2
	
	List list;
	NameCard* pnc;
	
	ListInit(&list);

	//�Է�
	pnc = MakeNameCard("you", "111-111");
	LInsert(&list, pnc);
	pnc = MakeNameCard("won", "222-222");
	LInsert(&list, pnc);
	pnc = MakeNameCard("sock", "333-333");
	LInsert(&list, pnc);
	pnc = MakeNameCard("you", "444-444");
	LInsert(&list, pnc);

	if (LFirst(&list, &pnc))
	{
		ShowNameCard(pnc);
		while (LNext(&list, &pnc))
			ShowNameCard(pnc);
	}
	
	printf("-------------------------------------\n");

	//���� ���
	if (LFirst(&list, &pnc))
	{
		if(strcmp(pnc->name,CNAME) == 0)
			ShowNameCard(pnc);
		while (LNext(&list, &pnc))
		{
			if (strcmp(pnc->name, CNAME) == 0)
				ShowNameCard(pnc);
		}
	}

	//��ȭ��ȣ ����
	if (LFirst(&list, &pnc))
	{
		if (!NameCompare(pnc,CNAME))
			ChangePhoneNum(pnc, "010-123-123");
		while (LNext(&list, &pnc))
		{
			if (strcmp(pnc->name, CNAME) == 0)
				ChangePhoneNum(pnc, "010-123-123");
		}
	}

	//���� ����
	if (LFirst(&list, &pnc))
	{
		if (strcmp(pnc->name, CPHONE) == 0)
		{
			pnc = LRemove(&list);
			free(pnc);
		}
		while (LNext(&list, &pnc))
		{
			if (strcmp(pnc->name, CPHONE) == 0)
			{
				LRemove(&list);
				free(pnc);
			}
		}
	}

	printf("-------------------------------------\n");
	//��ü ���
	printf("���� ������ �� : %d\n", LCount(&list));
	if (LFirst(&list, &pnc))
	{
		ShowNameCard(pnc);
		while (LNext(&list, &pnc))
			ShowNameCard(pnc);
	}

	return 0;
	
}