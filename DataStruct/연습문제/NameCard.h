#ifndef __NAME_CARD_H__
#define __NAME_CARD_H__

#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct __NameCard
{
	char name[NAME_LEN];
	char phone[PHONE_LEN];
}NameCard;

NameCard* MakeNameCard(char* name, char* phone);

void ShowNameCard(NameCard* pcard);

int NameCompare(NameCard* pcard, char* name);

void ChangePhoneNum(NameCard* pcard, char* phone);

#endif // !1