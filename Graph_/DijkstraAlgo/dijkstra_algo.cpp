#include <iostream>
using namespace std;
#include <vector>
#include <limits.h>

// O(V^2)
void dijkstra(vector<vector<int>> g ,int n,int src)
{
    bool process[n];
    int dis[n];
    for (int i = 0; i < n; i++)
    {
        process[i] = false;
        dis[i] = INT_MAX;
    }
    dis[src]=0;

    for (int i = 0; i < n-1; i++)
    {
        int u = min(process,dis,n);
        process[u]=true;
        for (int v = 0; v < n; v++) //n-1 is best
        {
            if(g[u][v] != 0)//if edge exist
            {
                if(dis[u]+g[u][v] < dis[v])
                {
                    dis[v] = dis[u] + g[u][v];
                }
            }
        }

    }

}
int min(bool process[],int dis[],int n)
{
    int m = INT_MAX;
    int m_index ;
    for (int i = 0; i < n-1; i++)
    {
        if(process[i] == false & dis[i] < m)
        {
            m = dis[i];
            m_index = i;
        }
    }
    return m_index;
}

int main(){
    // cout<<"hello world!!!"<<endl;
    // cout<<"Enter V : ";
    // int n;
    // cin>>n;
    // vector<vector<int>> vec;
    // for (int i = 0; i < n; i++)
    // {
    //     vector<int> temp;
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout<<"Enter "<<i<<" "<<j<<" position : ";
    //         int w;
    //         cin>>w;
    //         temp.push_back(w);
    //     }
    //     vec.push_back(temp);
    //     cout<<endl;
    // }
    // cout<<"Enter Source : ";
    // int s;
    // cin>>s;
    // int *Min_distence = dijkstra(vec,n,s);
    
    // cout<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<"Min_Dis from "<<s<<" to "<<i<<Min_distence[i]<<endl;
    // }
    
    return 0;
}