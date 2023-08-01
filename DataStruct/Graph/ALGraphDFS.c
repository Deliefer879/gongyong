#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ALGraphDFS.h"
#include "LinkedListForALGraph.h"
#include "StackForALGraph.h"

void GraphInIt(Graph* pg, int nv)//nv는 정점의 수
{
	int i;

	//정점의 수에 해당하는 길이의 리스트 배열 생성
	pg->adjList = (List*)malloc(sizeof(List) * nv);//간선정보를 저장할 리스트

	pg->numV = nv;		//전달받은 정점의 수를 알려주는 매개변수로 초기화
	pg->numE = 0;		//간선의수는 초기에는 0

	//정점의 수만큼 생성된 리스트 초기화
	for (i = 0; i < nv; i++)
		ListInIt(&(pg->adjList[i]));

	//정점의 수를 길이로 하여 배열을 할당
	pg->vistInfo = (int*)malloc(sizeof(int) * pg->numV);

	//배열의 모든 요소를 0으로 초기화
	memset(pg->vistInfo, 0, sizeof(int) * pg->numV);
}

//그래프의 리소스 해제
void GraphDestroy(Graph* pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList);

	if (pg->vistInfo != NULL)
		free(pg->vistInfo);
}

//간선의 추가
void AddEdge(Graph* pg, int fromV, int toV)//fromV에서 toV로 이어지는 간선(방향 그래프이면) 
{
	LInsert(&(pg->adjList[fromV]), toV);//리스트에 연결된 간선의 정보저장(방향리스트이면 Linsert는 한번 호출)
										//fromV와 toV는 열거형에서 정의되있기때문에 A,B와 같은형식으로 들어오더라도 실제로는 0과1										

	LInsert(&(pg->adjList[toV]), fromV);//무방향 리스트이기 때문에 간선연결시 2번호출

	pg->numE += 1;
}

//간선의 정보 출력
void ShowGraphEdgeInfo( Graph* pg)
{
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++)
	{
		printf("%c 정점에 연결된 정점 : ", i + 65);//문자로 출력하기 위해 65를 더한다(아스키 코드)

		if (LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 65);

			while (LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

//두번째 매개변수로 전달된 이름의 정점에 방문
int VisitVertex(Graph* pg, int visitV)
{
	if (pg->vistInfo[visitV] == 0)//visitV에 처음 방문일때 참
	{
		pg->vistInfo[visitV] = 1;//방문한것을 기록
		printf("%c ", visitV + 65);//방문한 정점이름 출력
		return TRUE; //방문 성공
	}
	return FALSE;//방문 실패
}

//dfs 기반으로 정점의 정보를 출력하는 함수
void DFShowGraphVertex(Graph* pg, int startV)
{
	Stack stack;
	int visitV = startV;
	int nextV;

	StackInIt(&stack);//dfs를 위한 스택 초기화
	VisitVertex(pg, visitV);//시작 정점 방문
	//Push(&stack, visitV);	//시작정점의 정보를 스택으로(스택에 추가하면 lfirst함수호출후 a를 한번더 스택에 추가 pop의 결과를 출력하면 알수 있음 a가 두번 나옴)
							//스택에 넣는 이유는 불명

	//visitV에 담긴 정점과 연결된 정점의 방문을 시도하는 while문
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE)//방문에 성공했다면
		{
			Push(&stack, visitV);
			visitV = nextV;
			visitFlag =TRUE;
		}
		else//방문에 실패했다면, 연결된 다른 정점 탐색
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

		if (visitFlag == FALSE)//추가로 방문한 정점이 없다면
		{
			//스택이 비면 탐색 시작점으로 되돌아온것
			if (StackIsEmpty(&stack) == TRUE)//시작점으로 되돌아온것
				break;
			else
				visitV = Pop(&stack);//길을 되돌아간다

			printf("pop : %c\n", visitV + 65);
		}

	}

	//이후의 탐색을 위한 탐색정보 초기화
	memset(pg->vistInfo, 0, sizeof(int) * pg->numV);
}
