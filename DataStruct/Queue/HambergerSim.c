#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "CircularQueue.h"

#define CUS_COME_TERM 15

#define CHE_BUR 0
#define BUL_BUR 1
#define DUB_BUR 2

#define CHE_TERM 12
#define BUL_TERM 15
#define DUB_TERM 24

//간단한 시뮬레이션 예제

int main()
{
	Queue que;//대기실
	int sec = 0,makeTerm =0;
	int che=0, bul=0, dub=0;

	QueueInit(&que);
	srand(time(NULL));

	//queue의 길이에따라 성공률이 다름
	for (sec = 1; sec < 3601; sec++)
	{
		if (sec % 15 == 0)//15초마다 주문
		{
			switch (rand()%3)//주문하는 햄버거의 종류 결정
			{
			case CHE_BUR:
				EnQueue(&que, CHE_TERM);//주문후 대기실로 이동(queue에는 버거를 만드는 시간삽입)
				che++;
				break;
			case BUL_BUR:
				EnQueue(&que, BUL_TERM);
				bul++;
				break;
			case DUB_BUR:
				EnQueue(&que, DUB_TERM);
				dub++;
				break;
			}
		}

		if (makeTerm <= 0 && !QueueIsEmpty(&que))//버거는 만드는시간이 0이고(makeTerm이 0보다 같거나 작고)대기하는 사람이 있으면(queue가 비지 않으면)
			makeTerm = DeQueue(&que);//대기실에서 먼저온사람의 버거를 만드는 시간을 dequeue

		makeTerm--;//버거를 만드는시간을 1초씩 감소
	}

	printf("총수문수          : %5d\n",che+bul+dub);
	printf("치즈버거   주문수 : %5d\n", che);
	printf("불고기버거 주문수 : %5d\n", bul);
	printf("더블버거   주문수 : %5d\n", dub);
	printf("대기실 사이즈     : %5d\n", QUEUE_LEN);

}