/*
maximum path length between 2 nodes
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
bool visited[N];
int depth[N];

bool dfs(int vertex, int parent)
{

    for (int child : graph[vertex])
    {
        if (child == parent)
            continue;
        depth[child] = 1 + depth[vertex];
        dfs(child, vertex);
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
    int node = 0, dist = 0;
    for (int i = 0; i <= n; i++)
    {
        if (dist < depth[i])
        {
            node = i;
            dist = depth[i];
        }
        depth[i] = 0;
    }
    dfs(node, -1);
    int ans = 0;
    for (int i = 0; i <= n; i++)
        ans = max(ans, depth[i]);
    cout << "The diamater of the tree is " << ans;
    return 0;
}

/*
Time complexity
    O(V + E)
    for every node dfs will be running
    then total edges it will be visiting not in E^2 they must be E
*/
