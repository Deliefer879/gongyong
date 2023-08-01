#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#include "Point.h"
#include "NameCard.h"

#define TRUE	1
#define FALSE	0

/*** ArrayList의 정의 ****/
#define LIST_LEN	100

//typedef int LData;

//동적할당한 주소를 저장할 포인터 배열로 만들기위해 LData를 구조체의Point의 포인터로 변경
//typedef Point * LData;

//문제 3-2
typedef NameCard * LData;

typedef struct __ArrayList
{
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
} ArrayList;


/*** ArrayList와 관련된 연산들 ****/
typedef ArrayList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

#endif