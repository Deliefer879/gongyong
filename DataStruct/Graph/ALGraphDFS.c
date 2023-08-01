#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ALGraphDFS.h"
#include "LinkedListForALGraph.h"
#include "StackForALGraph.h"

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
	if (pg->adjList != NULL)
		free(pg->adjList);

	if (pg->vistInfo != NULL)
		free(pg->vistInfo);
}

//������ �߰�
void AddEdge(Graph* pg, int fromV, int toV)//fromV���� toV�� �̾����� ����(���� �׷����̸�) 
{
	LInsert(&(pg->adjList[fromV]), toV);//����Ʈ�� ����� ������ ��������(���⸮��Ʈ�̸� Linsert�� �ѹ� ȣ��)
										//fromV�� toV�� ���������� ���ǵ��ֱ⶧���� A,B�� ������������ �������� �����δ� 0��1										

	LInsert(&(pg->adjList[toV]), fromV);//������ ����Ʈ�̱� ������ ��������� 2��ȣ��

	pg->numE += 1;
}

//������ ���� ���
void ShowGraphEdgeInfo( Graph* pg)
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

//�ι�° �Ű������� ���޵� �̸��� ������ �湮
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

//dfs ������� ������ ������ ����ϴ� �Լ�
void DFShowGraphVertex(Graph* pg, int startV)
{
	Stack stack;
	int visitV = startV;
	int nextV;

	StackInIt(&stack);//dfs�� ���� ���� �ʱ�ȭ
	VisitVertex(pg, visitV);//���� ���� �湮
	//Push(&stack, visitV);	//���������� ������ ��������(���ÿ� �߰��ϸ� lfirst�Լ�ȣ���� a�� �ѹ��� ���ÿ� �߰� pop�� ����� ����ϸ� �˼� ���� a�� �ι� ����)
							//���ÿ� �ִ� ������ �Ҹ�

	//visitV�� ��� ������ ����� ������ �湮�� �õ��ϴ� while��
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE)//�湮�� �����ߴٸ�
		{
			Push(&stack, visitV);
			visitV = nextV;
			visitFlag =TRUE;
		}
		else//�湮�� �����ߴٸ�, ����� �ٸ� ���� Ž��
		{
			while (LNext(&(pg->adjList[visitV]), &nextV))
			{
				if (VisitVertex(pg, nextV)==TRUE)
				{
					Push(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE)//�߰��� �湮�� ������ ���ٸ�
		{
			//������ ��� Ž�� ���������� �ǵ��ƿ°�
			if (StackIsEmpty(&stack) == TRUE)//���������� �ǵ��ƿ°�
				break;
			else
				visitV = Pop(&stack);//���� �ǵ��ư���

			printf("pop : %c\n", visitV + 65);
		}

	}

	//������ Ž���� ���� Ž������ �ʱ�ȭ
	memset(pg->vistInfo, 0, sizeof(int) * pg->numV);
}
