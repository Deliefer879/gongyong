#include <stdio.h>
#include <stdlib.h>

#include "Person.h"
#include "Table.h"

//�迭����� ������ ���̺�
/*
typedef struct _empInfo
{
	int empNum;
	int age;
}EmpInfo;

int GetHashValue(int empNum)
{
	return empNum % 100;//������ȣ�� 2�ڸ����� ����
}

-----------------

	EmpInfo empInfoArr[100];//�����Ҽ� �ִ� ������ ���� 100��

	EmpInfo emp1 = { 20120003,42 };
	EmpInfo emp2 = { 20130012,33 };
	EmpInfo emp3 = { 20170049,27 };

	EmpInfo r1, r2, r3;

	//Ű�� �ε��� ������ �̿��� ����
	empInfoArr[GetHashValue(emp1.empNum)] = emp1;
	empInfoArr[GetHashValue(emp2.empNum)] = emp2;
	empInfoArr[GetHashValue(emp3.empNum)] = emp3;

	//Ű�� �ε��� ������ �̿��ؼ� Ž��
	r1 = empInfoArr[GetHashValue(20120003)];
	r2 = empInfoArr[GetHashValue(20130012)];
	r3 = empInfoArr[GetHashValue(20170049)];

	printf("��� : %d, ���� : %d\n", r1.empNum, r1.age);
	printf("��� : %d, ���� : %d\n", r2.empNum, r2.age);
	printf("��� : %d, ���� : %d\n", r3.empNum, r3.age);
	*/

int MyHashFunc(Key k)
{
	return k % 100;
}

int main()
{
	Table myTbl;

	Person* np;
	Person* sp;
	Person* rp;

	 

	return 0;
}