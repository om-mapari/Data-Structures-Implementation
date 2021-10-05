/* Assignment 8 : DSA 
*
* NAME : OM MAPARI
* ROLL NO : 23245 (G10)
* PROBLEM STATEMENT :
Represent a graph of city using adjacency matrix /adjacency list. Nodes should represent the various
landmarks and links should represent the distance between them. Find the shortest path using
Dijkstra's algorithm from single source to all destination.

*/
#ifndef SHORTESTPATH_H_
#define SHORTESTPATH_H_
#include <string>

class ShortestPath {
private:
	int vertices, edges;
	std::string city[20];
	std::string path[20];
	bool visited[20];
	int distance[20];
	int wtMatrix[20][20];
	void create();
	void print(int i);
	int getIndex(std::string str);
public:
	ShortestPath();
	~ShortestPath();
	void dijktras();
};

#endif /* SHORTESTPATH_H_ */