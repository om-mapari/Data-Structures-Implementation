#include <bits/stdc++.h>
using namespace std;
#define V 5

class prism
{

    int parent[V];
    int nofV;

public:
    int selectMinVertex(vector<int> &weight, vector<bool> &setMST);
    void findMST(int graph[V][V]);
    void display(int graph[V][V]);
};
int prism ::selectMinVertex(vector<int> &weight, vector<bool> &setMST)
{
    int minimum = INT_MAX;
    int vertex;
    for (int i = 0; i < V; ++i)
    {
        if (setMST[i] == false && weight[i] < minimum)
        {
            vertex = i;
            minimum = weight[i];
        }
    }
    return vertex;
}

void prism ::findMST(int graph[V][V])
{

    vector<int> weight(V, INT_MAX);
    vector<bool> setMST(V, false);

    parent[0] = -1;
    weight[0] = 0;

    for (int i = 0; i < V - 1; ++i)
    {

        int U = selectMinVertex(weight, setMST);
        setMST[U] = true;

        for (int j = 0; j < V; ++j)
        {
            if (graph[U][j] != 0 && setMST[j] == false && graph[U][j] < weight[j])
            {
                weight[j] = graph[U][j];
                parent[j] = U;
            }
        }
    }
}
void prism ::display(int graph[V][V])
{
    //Print MST
    for (int i = 1; i < V; ++i)
        cout << "U->V: " << i << "->" << parent[i] << "  weight = " << graph[parent[i]][i] << "\n";
}
int main()
{
    prism p;
    int graph[V][V] = {{0,4,1,0,0},
                       {4,0,2,0,4},
                       {1,2,0,4,0},
                       {0,0,4,0,4},
                       {0,4,0,4,0}};
    
    p.findMST(graph);
    p.display(graph);
    return 0;
}