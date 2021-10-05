#ifndef SPANNINGTREE_H_
#define SPANNINGTREE_H_

#include<string>

struct edge{
	int v1, v2;
	float wt;
};

class SpanningTree {
private:
	int matrixGraph[20][20];
	int vertices;
	int edges;
	edge edgeArray[20];	// array of struct edge
	std::string department[20];
	float wtMatrix[20][20];
	bool visited[20]; // visited or not array
	float distance[20];
	std::string path[20];
	int getIndex(std::string str);
	void minSort();
	void printEdge(edge e);
	void print(int i);
public:
	SpanningTree();
	~SpanningTree();
	void Pcreate();
	void Kcreate();
	void krushkal();
	void prim();
};

#endif /* SPANNINGTREE_H_ */
