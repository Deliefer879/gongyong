#ifndef __SLOT_H__
#define __SLOT_H__

//���� ��巹�� ����� ������ �������� �̿��� ������ ���¸� ǥ��

#include "Person.h"

typedef int Key; //�ֹε�� ��ȣ Person.ssn
typedef Person* Value;

enum SlotStatus {EMPTY,DELETED,INUSE};

typedef struct _slot
{
	Key key;
	Value val;
	enum SlotStatus status;
}Slot;

#endif