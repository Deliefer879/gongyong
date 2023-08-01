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

//������ �ùķ��̼� ����

int main()
{
	Queue que;//����
	int sec = 0,makeTerm =0;
	int che=0, bul=0, dub=0;

	QueueInit(&que);
	srand(time(NULL));

	//queue�� ���̿����� �������� �ٸ�
	for (sec = 1; sec < 3601; sec++)
	{
		if (sec % 15 == 0)//15�ʸ��� �ֹ�
		{
			switch (rand()%3)//�ֹ��ϴ� �ܹ����� ���� ����
			{
			case CHE_BUR:
				EnQueue(&que, CHE_TERM);//�ֹ��� ���Ƿ� �̵�(queue���� ���Ÿ� ����� �ð�����)
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

		if (makeTerm <= 0 && !QueueIsEmpty(&que))//���Ŵ� ����½ð��� 0�̰�(makeTerm�� 0���� ���ų� �۰�)����ϴ� ����� ������(queue�� ���� ������)
			makeTerm = DeQueue(&que);//���ǿ��� �����»���� ���Ÿ� ����� �ð��� dequeue

		makeTerm--;//���Ÿ� ����½ð��� 1�ʾ� ����
	}

	printf("�Ѽ�����          : %5d\n",che+bul+dub);
	printf("ġ�����   �ֹ��� : %5d\n", che);
	printf("�Ұ����� �ֹ��� : %5d\n", bul);
	printf("�������   �ֹ��� : %5d\n", dub);
	printf("���� ������     : %5d\n", QUEUE_LEN);

}