#include <stdio.h>

int main()
{
	Graph graph;
	GraphInIt(&graph, 7);

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, D, C);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, F);
	AddEdge(&graph, E, G);

	ShowGraphEdgeInfo(&graph);

	printf("dsf search | ");
	DFShowGraphVertex(&graph, A); printf("\n");

}