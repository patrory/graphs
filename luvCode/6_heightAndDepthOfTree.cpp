#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
bool visited[N];
int depth[N];
int height[N];

bool dfs(int vertex, int parent)
{

    for (int child : graph[vertex])
    {
        if (child == parent)
            continue;
        depth[child] = 1 + depth[vertex];
        dfs(child, vertex);
        height[vertex] = max(height[vertex], 1 + height[child]);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1, 0);
    cout << "depth of tree \n";
    for (int i = 0; i <= n; i++)
        cout << depth[i] << " ";
    cout << "\nheight of tree \n";
    for (int i = 0; i <= n; i++)
        cout << height[i] << " ";
    return 0;
}

/*
Time complexity
    O(V + E)
    for every node dfs will be running
    then total edges it will be visiting not in E^2 they must be E
*/
