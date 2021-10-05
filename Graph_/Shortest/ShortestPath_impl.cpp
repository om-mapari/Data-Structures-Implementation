#include "ShortestPath.h"
#include <iostream>
using namespace std;

ShortestPath::ShortestPath()
{
    // TODO Auto-generated constructor stub
}

ShortestPath::~ShortestPath()
{
}

void ShortestPath::create()
{
    string c1, c2;
    int i, j, a, b, w;
    cout << "Enter no of Vertices(city places): ";
    cin >> vertices;
    cout << "Enter name of landmarks: ";
    for (i = 0; i < vertices; i++)
    {
        cout << "\n"
             << i + 1 << ". ";
        cin >> city[i];
    }
    cout << "Enter no of Edges(paths): ";
    cin >> edges;
    // for loop for creating a graph
    for (i = 0; i < vertices; i++)
    {
        path[i] = "-";
        visited[i] = false;
        for (j = 0; j < vertices; j++)
            wtMatrix[i][j] = 0;
    }
    cout << "\n\t<--- Enter the details of the graph --->" << endl;
    for (i = 0; i < edges; i++)
    {
        cout << "\n\t\tVertices v1, v2 and weight: ";
        cin >> c1 >> c2 >> w;
        a = getIndex(c1);
        b = getIndex(c2);
        wtMatrix[a][b] = w;
    }
    cout << "Adjacency Matrix is: "
            "\n-----------------------"
         << endl;
    for (i = 0; i < vertices; i++)
    {
        cout << "  ";
        for (j = 0; j < vertices; j++)
            cout << wtMatrix[i][j] << "  ";
        cout << endl;
    }
}

int ShortestPath::getIndex(string str)
{
    for (int i = 0; i < vertices; i++)
    {
        if (str == city[i])
            return i;
    }
    cout << "\n\t>> Invalid landmark name! " << endl;
    return 0;
}

void ShortestPath::print(int i)
{
    if (visited[i])
        cout << "T";
    else
        cout << "F";
    cout << "\t" << distance[i] << "\t" << path[i] << endl;
}

void ShortestPath::dijktras()
{
    int i, j, k, current, min;
    string place;
    create();
    cout << "Enter Starting Place: ";
    cin >> place;
    current = getIndex(place);
    for (i = 0; i < vertices; i++)
    {
        if (wtMatrix[current][i] != 0)
            distance[i] = wtMatrix[current][i];
        else
            distance[i] = 4444;
        path[i] = place;
    }
    cout << "Current Vertex = " << place << endl;
    distance[current] = 0;
    visited[current] = true;
    cout << "\nVisited Distance Path"
            "\n--------------------------"
         << endl;
    for (i = 0; i < vertices; i++)
    {
        print(i);
        cout << endl;
    }
    for (i = 0; i < vertices - 1; i++)
    {
        // finding min distance
        min = 4444;
        for (j = 0; j < vertices; j++)
        {
            if (visited[j] == false)
            {
                if (distance[j] < min)
                {
                    min = distance[j];
                    current = j;
                }
            }
        }
        cout << "\n>>Selected Vertex: " << city[current];
        cout << "\n>>Min : " << min;
        visited[current] = true;
        for (k = 0; k < vertices; k++)
        {
            // finding min distance from current vertex
            if (visited[k] == false)
            {
                if (wtMatrix[current][k] != 0 && (distance[current] + wtMatrix[current][k] < distance[k]))
                {
                    distance[k] = distance[current] + wtMatrix[current][k];
                    path[k] = city[current];
                }
            }
        }
        // print pass wise
        cout << "\nVisited Distance Path"
                "\n--------------------------"
             << endl;
        for (j = 0; j < vertices; j++)
        {
            print(j);
            cout << endl;
        }
    }
    cout << "\n*****Shortest Path from Source to All Destinations*****" << endl;
    cout << "\n\t>> Source is : " << place << endl;
    for (i = 0; i < vertices; i++)
    {
        if (city[i] != place)
        { // if i != source
            cout << "\n\t>> Landmark = \"" << city[i] << "\", Distance = " << distance[i];
            cout << "\n\t>> Path = " << city[i];
            string temp = city[i];
            do
            {
                temp = path[getIndex(temp)];
                cout << " <-- " << temp;
            } while (temp != place);
        }
    }
}