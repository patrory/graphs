#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
bool visited[N];
vector<int> sequence;

void dfs(int vertex)
{
    // before entering the vertex we checked if it visited or not
    if (visited[vertex])
        return;
    // marking the vertex is now visited
    visited[vertex] = 1;
    sequence.push_back(vertex);
    for (int child : graph[vertex])
    {
        dfs(child);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1);
    cout << "printing the sequence \n";
    for (auto i : sequence)
        cout << i << " ";
    return 0;
}

/*
Time complexity
    O(V + E)
    for every node dfs will be running
    then total edges it will be visiting not in E^2 they must be E
*/

/*
understanding structure of dfs

void dfs (int vertex){
    // take action on vertex after entering

    for( int child : graph[vertex]){
        // take action on child before entering the child node
        dfs(child)
        // take action on child after exiting the child node
    }

    // take action on vertex before exiting the vertex
}
*/