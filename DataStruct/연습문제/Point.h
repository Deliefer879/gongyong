#ifndef __POINT_H__
#define __POINT_H__


#include <stdio.h>

typedef struct _Point
{
	int xPos;
	int yPos;
}Point;

//구조체 Point에 xpos,ypos 값 설정
void SetPointPos(Point* ppos, int xpos, int ypos);

//구조체 Point에 xpos,ypos 값 출력
void ShowPointPos(Point* ppos);

//2개의 Point비교 x가 같으면1, y가 같으면 2, 둘다 같으면 0, 둘다 다르면 -1
int PointComp(Point* pos1, Point* pos2);

#endif // !