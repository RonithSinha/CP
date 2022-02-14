// C++ program to print DFS traversal from
// a given vertex in a given graph
#include <iostream>
#include <map>
#include <list>
#include <vector>

using namespace std;

string graphType="undirected";

void DFS(int v,vector<vector<int>>& adj,vector<bool>& visited){
    cout<<v<<" ";
    visited[v]=true;
    for(int u:adj[v]){
        if(!visited[u])
            DFS(u,adj,visited);
    }
}

int main(int argc, char const *argv[])
{
    int vertices,edges,u,v;
    cin>>vertices>>edges;
    // edges=vertices-1; //in case of a tree.
    vector<vector<int>> adj(vertices+1); //1-based indexing
    for(int i=0;i<edges;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        if(graphType=="undirected")
            adj[v].push_back(u);
    }
    vector<bool> visited(vertices+1);
    cout<<"DFS Traversal: \n";
    for(int i=1;i<=vertices;i++){
        if(!visited[i])
            DFS(i,adj,visited);
    }   
    cout<<"\n";
    return 0;
}
/*
3
5
10 3 2 7 8
1 1 2 2
6
1 2 3 4 5 6
1 2 3 3 1
15
14 64 23 17 58 53 99 80 42 68 41 70 84 7 106
1 1 1 3 4 4 3 1 9 7 7 12 11 1
*/