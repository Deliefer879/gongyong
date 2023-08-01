#include <stdio.h>
#include <stdlib.h>

#include "ALGraph.h"

//그래프 초기화
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
		//책에서는 기존에 사용한 연결리스트의 정렬기준 설정 함수를 이용해 출력을 보기 좋게 함(SetSortRule함수)
}

//그래프의 리소스 해제
void GraphDestroy(Graph* pg)
{
	//책에서 나온 해제
	/*if (pg->adjList != NULL)
		free(pg->adjList);*/

	//직접 구현
	int i;
	int vx;//LFirst,LNext함수 호출후 반환된 데이터,LRemove함수 호출후 반환된 데이터를 저장할 장소(포인터가 데이터일시)

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

//간선의 추가
void AddEdge(ALGraph* pg, int fromV, int toV)//fromV에서 toV로 이어지는 간선(방향 그래프이면) 
{
	LInsert(&(pg->adjList[fromV]), toV);//리스트에 연결된 간선의 정보저장(방향리스트이면 Linsert는 한번 호출)
										//fromV와 toV는 열거형에서 정의되있기때문에 A,B와 같은형식으로 들어오더라도 실제로는 0과1										

	LInsert(&(pg->adjList[toV]), fromV);//무방향 리스트이기 때문에 간선연결시 2번호출
	
	pg->numE += 1;
}

//간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph* pg)
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