#ifndef __POINT_H__
#define __POINT_H__


#include <stdio.h>

typedef struct _Point
{
	int xPos;
	int yPos;
}Point;

//����ü Point�� xpos,ypos �� ����
void SetPointPos(Point* ppos, int xpos, int ypos);

//����ü Point�� xpos,ypos �� ���
void ShowPointPos(Point* ppos);

//2���� Point�� x�� ������1, y�� ������ 2, �Ѵ� ������ 0, �Ѵ� �ٸ��� -1
int PointComp(Point* pos1, Point* pos2);

#endif // !