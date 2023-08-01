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
	printf("이름 : %s\n", pcard->name);
	printf("번호 : %s\n", pcard->phone);
	printf("\n");
}

int NameCompare(NameCard* pcard, char* name)
{
	return strcmp(pcard->name, name);//같으면 0 다르면 0이 아닌 값
}

void ChangePhoneNum(NameCard* pcard, char* phone)
{
	strcpy_s(pcard->phone, PHONE_LEN, phone);
}
