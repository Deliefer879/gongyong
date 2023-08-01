#include <stdio.h>
#include <stdlib.h>

#include "ALGraph.h"

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
		//å������ ������ ����� ���Ḯ��Ʈ�� ���ı��� ���� �Լ��� �̿��� ����� ���� ���� ��(SetSortRule�Լ�)
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