#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayList.h"
#include "NameCard.h"

#define CNAME "you"
#define CPHONE "won"

int main()
{
	//문제3-1
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
		printf("총합 : %d\n", sum);
	}
	else
		printf("리스트 호출 실패\n");

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

	//문제 3-2
	
	List list;
	NameCard* pnc;
	
	ListInit(&list);

	//입력
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

	//정보 출력
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

	//전화번호 변경
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

	//정보 삭제
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
	//전체 출력
	printf("현제 데이터 수 : %d\n", LCount(&list));
	if (LFirst(&list, &pnc))
	{
		ShowNameCard(pnc);
		while (LNext(&list, &pnc))
			ShowNameCard(pnc);
	}

	return 0;
	
}