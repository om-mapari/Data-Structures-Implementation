#include "SpanningTree.h"
#include <iostream>
#include <string>
using namespace std;

SpanningTree::SpanningTree()
{
}

SpanningTree::~SpanningTree()
{
	// TODO Auto-generated destructor stub
}

// method to get Index of department
int SpanningTree::getIndex(string str)
{
	for (int i = 0; i < vertices; i++)
	{
		if (str == department[i])
			return i;
	}
	cout << "\n\t>> Invalid department name! " << endl;
	return 0;
}

// creating graph for krushkal algorithm
void SpanningTree::Kcreate()
{
	string d1, d2;
	int i;
	float w;
	cout << "Enter no of Vertices(Departments): ";
	cin >> vertices;
	cout << "Enter names of departments: ";
	// taking input for names of departments
	for (i = 0; i < vertices; i++)
	{
		cout << "\n"
			 << i + 1 << ". ";
		cin >> department[i];
	}
	cout << "Enter no of Edges(paths): ";
	cin >> edges;
	cout << "\n\t<--- Enter the details of the graph --->" << endl;
	cout << "\n\t\tVertices(Departments) v1, v2 and weight: ";
	// for loop for creating edge array
	for (int i = 0; i < edges; i++)
	{
		cout << "\n\tEdge " << i + 1 << ": ";
		cin >> d1 >> d2 >> w;
		edgeArray[i].v1 = getIndex(d1);
		edgeArray[i].v2 = getIndex(d2);
		edgeArray[i].wt = w;
	}
}

// creating graph for prims algorithm
void SpanningTree::
Pcreate()
{
	Kcreate();
	int a, b;
	float w;
	// initializing path, visited, and distance arrays
	for (int i = 0; i < vertices; i++)
	{
		path[i] = "-";
		visited[i] = false;
		distance[i] = 4444;
		for (int j = 0; j < vertices; j++)
			wtMatrix[i][j] = 0;
	}
	// allocating values to adjacency Matrix
	for (int i = 0; i < edges; i++)
	{
		a = edgeArray[i].v1;
		b = edgeArray[i].v2;
		w = edgeArray[i].wt;
		wtMatrix[a][b] = wtMatrix[b][a] = w;
	}
	// printing the adjacency matrix
	cout << "Adjency Matrix is" << endl;
	cout << "    ";
	for (int i = 0; i < vertices; i++)
		cout << department[i] << "    ";
	cout << endl;
	for (int i = 0; i < vertices; i++)
	{
		cout << department[i] << "    ";
		for (int j = 0; j < vertices; j++)
			cout << wtMatrix[i][j] << "    ";
		cout << endl;
	}
}

// bubble sort w.r.t weight of the edge
void SpanningTree::minSort()
{
	for (int i = 0; i < edges - 1; i++)
	{
		for (int j = 0; j < edges - 1; j++)
		{
			if (edgeArray[j].wt > edgeArray[j + 1].wt)
			{
				// swapping j and j+1 th edge
				edge temp = edgeArray[j];
				edgeArray[j] = edgeArray[j + 1];
				edgeArray[j + 1] = temp;
			}
		}
	}
}

// method for printing the edge
void SpanningTree::printEdge(edge e)
{
	cout << "\t[" << department[e.v1] << ", " << department[e.v2] << ", " << e.wt << "]";
}

// krushkal algorithm for MST
void SpanningTree::krushkal()
{
	int i, k;
	// calling sort method to sort edges
	minSort();
	// printing sorted edges
	cout << "\nSorted Edges: "
			"\n--------------------";
	for (i = 0; i < edges; i++)
	{
		cout << "\n";
		printEdge(edgeArray[i]);
	}
	edge MST[edges];
	edge currEdge;
	int conn[edges]; // vertices connected values array
	for (i = 0; i < edges; i++)
		conn[i] = 0; // initially none of vertices is connected
	int val = 1;
	int count = 0; // no of edges in MST
	int smallTemp, largeTemp;
	smallTemp = largeTemp = 0;
	k = 0; // edge array iterator
	// while all vertices are considered in spanning tree
	while (count < edges - 1 && k < edges)
	{
		currEdge = edgeArray[k];
		// if both vertices are not visited
		if (conn[currEdge.v1] == 0 && conn[currEdge.v2] == 0)
		{
			cout << "\nEdge Selected: ";
			printEdge(currEdge);
			MST[count] = currEdge;
			conn[currEdge.v1] = conn[currEdge.v2] = val;
			val++;
			count++;
		}
		// if both vartice's values are not equal
		else if (conn[currEdge.v1] != conn[currEdge.v2])
		{
			cout << "\nEdge Selected: ";
			printEdge(currEdge);
			MST[count] = currEdge;
			// if both have been visited
			if (conn[currEdge.v1] != 0 && conn[currEdge.v2 != 0])
			{
				// if connected value of first vertex is less than second
				if (conn[currEdge.v1] < conn[currEdge.v2])
				{
					smallTemp = conn[currEdge.v1];
					largeTemp = conn[currEdge.v2];
				}
				else
				{
					largeTemp = conn[currEdge.v1];
					smallTemp = conn[currEdge.v2];
				}
				// replace larger value with smaller one
				for (i = 0; i < edges; i++)
					if (conn[i] == largeTemp)
						conn[i] = smallTemp;
			}
			// if either vertex is visited but not both
			else
			{
				// when first vertex is not visited
				if (conn[currEdge.v1] == 0)
					conn[currEdge.v1] = conn[currEdge.v2];
				// when second vertex is not visited
				else if (conn[currEdge.v2] == 0)
					conn[currEdge.v2] = conn[currEdge.v1];
			}
			count++;
		}
		// if both vertices has same connected value / reject edge condition
		else
		{
			cout << "\nEdge Rejected: ";
			printEdge(currEdge);
		}
		k++;
	}
	cout << "\n>> Minimun Spanning Tree :" << endl;
	float cost = 0;
	for (i = 0; i < count; i++)
	{
		printEdge(MST[i]);
		cout << endl;
		cost = cost + MST[i].wt;
	}
	cout << ">> Total Cost of MST is : " << cost << endl;
	;
}

// printing the passwise output for index i
void SpanningTree::print(int i)
{
	if (visited[i])
		cout << "T";
	else
		cout << "F";
	cout << "\t" << distance[i] << "\t" << path[i] << endl;
}

// prims algorithm
void SpanningTree::prim()
{
	int current, count, i;
	float mincost;
	string dept;
	// taking input for source vertex
	cout << "Enter Starting department: ";
	cin >> dept;
	current = getIndex(dept);
	distance[current] = 0;
	count = 1;
	visited[current] = true;
	while (count != vertices)
	{
		cout << "\nCurrent: " << department[current] << endl;
		cout << "Total visited : " << count << endl;
		cout << "\nVertex  Visited  Cost  Previous"
				"\n============================="
			 << endl;
		// updating min distance array
		mincost = 4444;
		for (i = 0; i < vertices; i++)
		{
			if (wtMatrix[current][i] != 0 && distance[i] > wtMatrix[current][i])
			{
				distance[i] = wtMatrix[current][i];
				path[i] = department[current];
			}
			cout << department[i] << "\t";
			print(i);
		}
		// finding minimum distance from known vertices
		for (i = 0; i < vertices; i++)
		{
			// if vertex is known
			if (visited[i] == false)
			{
				if (distance[i] < mincost)
				{
					mincost = distance[i];
					current = i;
				}
			}
		}
		visited[current] = true;
		count++;
	}
	cout << "\nTotal visited : " << count << endl;
	cout << "Current: " << department[current] << endl;
	cout << "Status of MST is : " << endl;
	cout << "\nVertex  Visited  Cost  Previous"
			"\n============================="
		 << endl;
	mincost = 0;
	for (i = 0; i < vertices; i++)
	{
		cout << department[i] << "\t";
		print(i);
		mincost = mincost + distance[i];
	}
	cout << "Total cost is: " << mincost << endl;
}