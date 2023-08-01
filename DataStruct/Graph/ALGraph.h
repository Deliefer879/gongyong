#ifndef __AL_GRAPH_H__
#define __AL_GRAPH_H__

#include "LinkedListForALGraph.h"//���� ����Ʈ

//�������� �̿��Ͽ� ������ �̸��� ���ȭ
enum {A,B,C,D,E,F,G,H,I,J};

typedef struct _ual
{
	int numV; //������ ��
	int numE; //������ ��
	List * adjList //������ ����
}ALGraph;

typedef ALGraph Graph;

//�׷��� �ʱ�ȭ
void GraphInIt(Graph *pg,int nv);//nv�� ������ ��

//�׷����� ���ҽ� ����
void GraphDestroy(Graph* pg);

//������ �߰�
void AddEdge(ALGraph* pg, int fromV, int toV);//fromV���� toV�� �̾����� ����(���� �׷����̸�)

//������ ���� ���
void ShowGraphEdgeInfo(ALGraph* pg);

#endif