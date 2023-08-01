#ifndef __AL_GRAPH_H__
#define __AL_GRAPH_H__

#include "LinkedListForALGraph.h"//연결 리스트

//열거형을 이용하여 정점의 이름을 상수화
enum {A,B,C,D,E,F,G,H,I,J};

typedef struct _ual
{
	int numV; //정점의 수
	int numE; //간선의 수
	List * adjList //간선의 정보
}ALGraph;

typedef ALGraph Graph;

//그래프 초기화
void GraphInIt(Graph *pg,int nv);//nv는 정점의 수

//그래프의 리소스 해제
void GraphDestroy(Graph* pg);

//간선의 추가
void AddEdge(ALGraph* pg, int fromV, int toV);//fromV에서 toV로 이어지는 간선(방향 그래프이면)

//간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph* pg);

#endif