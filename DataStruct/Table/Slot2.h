#ifndef __SLOT2_H__
#define __SLOT2_H__

#include "Person.h"

// 열린 어드레싱 방법에서는 슬롯의 상태를 표현하기위한 열거형 불필요(충동하더라도 어처피 그자리에 저장)

typedef int Key;
typedef Person* Value;

typedef struct _slot
{
	Key key;
	Value val;
}Slot;

#endif