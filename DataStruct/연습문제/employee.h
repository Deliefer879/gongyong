#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#define NAME_LEN 20

typedef struct _employee
{
	char name[NAME_LEN];
	int eNum;
}Employee;

Employee* SetEmployeeInfo(char *name,int eNum);
void ShowEmployeeInfo(Employee* data);
void ShowWorkShift(Employee* data);

#endif