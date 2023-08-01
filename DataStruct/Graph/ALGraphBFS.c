#include <stdio.h>
#include <stdlib.h>

#include "ALGraphBFS.h"
#include "QueueForALGraph.h"

//�׷��� �ʱ�ȭ
void GraphInIt(Graph* pg, int nv)//nv�� ������ ��
{
	int i;

	//������ ���� �ش��ϴ� ������ ����Ʈ �迭 ����
	pg->adjList = (List*)malloc(sizeof(List) * nv);//���������� ������ ����Ʈ

	pg->numV = nv;		//���޹��� ������ ���� �˷��ִ� �Ű������� �ʱ�ȭ
	pg->numE = 0;		//�����Ǽ��� �ʱ⿡�� 0

	//������ ����ŭ ������ ����Ʈ �ʱ�ȭ
	for (i = 0; i < nv; i++)
		ListInIt(&(pg->adjList[i]));

	//������ ���� ���̷� �Ͽ� �迭�� �Ҵ�
	pg->vistInfo = (int*)malloc(sizeof(int) * pg->numV);

	//�迭�� ��� ��Ҹ� 0���� �ʱ�ȭ
	memset(pg->vistInfo, 0, sizeof(int) * pg->numV);
}


//�׷����� ���ҽ� ����
void GraphDestroy(Graph* pg)
{
	//å���� ���� ����
	/*if (pg->adjList != NULL)
		free(pg->adjList);*/

		//���� ����
	int i;
	int vx;//LFirst,LNext�Լ� ȣ���� ��ȯ�� ������,LRemove�Լ� ȣ���� ��ȯ�� �����͸� ������ ���(�����Ͱ� �������Ͻ�)

	for (i = 0; i < pg->numV; i++)
	{
		if (LFirst(&(pg->adjList[i]), &vx))
		{
			LRemove(&(pg->adjList[i]));

			while (LNext(&(pg->adjList[i]), &vx))
				LRemove(&(pg->adjList[i]));
		}
	}

	free(pg->adjList);

}

//������ �߰�
void AddEdge(ALGraph* pg, int fromV, int toV)//fromV���� toV�� �̾����� ����(���� �׷����̸�) 
{
	LInsert(&(pg->adjList[fromV]), toV);//����Ʈ�� ����� ������ ��������(���⸮��Ʈ�̸� Linsert�� �ѹ� ȣ��)
										//fromV�� toV�� ���������� ���ǵ��ֱ⶧���� A,B�� ������������ �������� �����δ� 0��1										

	LInsert(&(pg->adjList[toV]), fromV);//������ ����Ʈ�̱� ������ ��������� 2��ȣ��

	pg->numE += 1;
}

//������ ���� ���
void ShowGraphEdgeInfo(ALGraph* pg)
{
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++)
	{
		printf("%c ������ ����� ���� : ", i + 65);//���ڷ� ����ϱ� ���� 65�� ���Ѵ�(�ƽ�Ű �ڵ�)

		if (LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 65);

			while (LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

int VisitVertex(Graph* pg, int visitV)
{
	if (pg->vistInfo[visitV] == 0)//visitV�� ó�� �湮�϶� ��
	{
		pg->vistInfo[visitV] = 1;//�湮�Ѱ��� ���
		printf("%c ", visitV + 65);//�湮�� �����̸� ���
		return TRUE; //�湮 ����
	}
	return FALSE;//�湮 ����
}

void BFShowGraphVertex(Graph* pg, int startV)
{
	Queue queue;
	int visitV = startV;
	int nextV;

	QueueInIt(&queue);

	VisitVertex(pg, visitV);

	while (LFirst(&(pg->adjList[visitV]), nextV))
	{
		if (VisitVertex(pg, nextV))
		{
			EnQueue(&queue, nextV);
		}

		while (LNext(&(pg->adjList[visitV]), nextV))
		{
			if (VisitVertex(pg, nextV))
				EnQueue(&queue, nextV);
		}

		if (QueueIsEmpty(&queue))
			break;
		else
			visitV = DeQueue(&queue);
	}

	memset(pg->vistInfo, 0, sizeof(int) * pg->numV);
}
