#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NameCard.h"

NameCard* MakeNameCard(char* name, char* phone)
{
	NameCard* pnc = (NameCard*)malloc(sizeof(NameCard));
	strcpy_s(pnc->name,NAME_LEN,name);
	strcpy_s(pnc->phone,NAME_LEN,phone);
	return pnc;
}

void ShowNameCard(NameCard* pcard)
{
	printf("�̸� : %s\n", pcard->name);
	printf("��ȣ : %s\n", pcard->phone);
	printf("\n");
}

int NameCompare(NameCard* pcard, char* name)
{
	return strcmp(pcard->name, name);//������ 0 �ٸ��� 0�� �ƴ� ��
}

void ChangePhoneNum(NameCard* pcard, char* phone)
{
	strcpy_s(pcard->phone, PHONE_LEN, phone);
}
