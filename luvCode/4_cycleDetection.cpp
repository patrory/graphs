#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
bool visited[N];

bool dfs(int vertex, int parent)
{
    visited[vertex] = 1;
    bool isLoop = false;
    for (int child : graph[vertex])
    {
        if (visited[child] and child == parent)
            continue;
        if (visited[child])
            return true;

        isLoop |= dfs(child, vertex);
    }
    return isLoop;
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
    }

    bool isLoop = false;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        isLoop |= dfs(i, 0);
    }
    cout << isLoop << endl;
    return 0;
}

/*
Time complexity
    O(V + E)
    for every node dfs will be running
    then total edges it will be visiting not in E^2 they must be E
*/
