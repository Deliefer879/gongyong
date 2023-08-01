#ifndef __SLOT_H__
#define __SLOT_H__

//닫힌 어드레싱 방법의 슬롯은 열거형을 이용해 슬롯의 상태를 표현

#include "Person.h"

typedef int Key; //주민등록 번호 Person.ssn
typedef Person* Value;

enum SlotStatus {EMPTY,DELETED,INUSE};

typedef struct _slot
{
	Key key;
	Value val;
	enum SlotStatus status;
}Slot;

#endif