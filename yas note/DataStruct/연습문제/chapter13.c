#include <stdio.h>
#include <stdlib.h>

#include "Person.h"
#include "Table.h"

//배열기반의 간단한 테이블
/*
typedef struct _empInfo
{
	int empNum;
	int age;
}EmpInfo;

int GetHashValue(int empNum)
{
	return empNum % 100;//직원번호를 2자리수로 가공
}

-----------------

	EmpInfo empInfoArr[100];//저장할수 있는 직원의 수는 100명

	EmpInfo emp1 = { 20120003,42 };
	EmpInfo emp2 = { 20130012,33 };
	EmpInfo emp3 = { 20170049,27 };

	EmpInfo r1, r2, r3;

	//키를 인덱스 값으로 이용해 저장
	empInfoArr[GetHashValue(emp1.empNum)] = emp1;
	empInfoArr[GetHashValue(emp2.empNum)] = emp2;
	empInfoArr[GetHashValue(emp3.empNum)] = emp3;

	//키를 인덱스 값으로 이용해서 탐색
	r1 = empInfoArr[GetHashValue(20120003)];
	r2 = empInfoArr[GetHashValue(20130012)];
	r3 = empInfoArr[GetHashValue(20170049)];

	printf("사번 : %d, 나이 : %d\n", r1.empNum, r1.age);
	printf("사번 : %d, 나이 : %d\n", r2.empNum, r2.age);
	printf("사번 : %d, 나이 : %d\n", r3.empNum, r3.age);
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