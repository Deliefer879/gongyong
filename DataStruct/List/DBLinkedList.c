#include <stdio.h>
#include <stdlib.h>

#include "DBLinkedList.h"

void ListInIt(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));

	plist->head->prev = NULL;
	plist->head->next = plist->tail;

	plist->tail->prev = plist->head;
	plist->tail->next = NULL;

	plist->numOfData = 0;
}

void LInsert(List* plist, Data data)//꼬리에 노드 추가
{
	Node* newData = (Node*)malloc(sizeof(Node));
	
	//tail을 옮기면서 추가
	//newData->next = NULL;
	//newData->prev = plist->tail;
	//plist->tail->next = newData;
	//plist->tail->data = data;
	//plist->tail = newData;
	
	//tail을 옮기지 않고 추가
	plist->tail->prev->next = newData;
	newData->prev = plist->tail->prev;

	newData->next = plist->tail;
	plist->tail->prev = newData;

	newData->data = data;

	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pData)
{
	if (plist->head->next == plist->tail)
		return FALSE;

	plist->cur = plist->head->next;
	*pData = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, Data* pData)
{
	if (plist->cur->next == plist->tail)
		return FALSE;

	plist->cur = plist->cur->next;
	*pData = plist->cur->data;
	return TRUE;
}

Data LRemove(List* plist)
{
	if (plist->head->next == plist->tail)//책에는 없음 임의로 삽입
		return;
	Node* delNode = plist->cur;
	Data delData = delNode->data;

	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;

	plist->cur = plist->cur->prev;

	free(delNode);
	(plist->numOfData)--;

	return delData;//포인터 변수가 데이터일시 반환하여 메인에서 해제
}

int LCount(List* plist)
{
	return plist->numOfData;
}