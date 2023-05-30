#include <iostream>
#include <bits/stdc++.h>
const int N = 1e5 + 10;
using namespace std;

vector<int> graph[N];
int parent[N];

void dfs(int vertex, int par = -1)
{
    parent[vertex] = par;
    for (auto child : graph[vertex])
    {
        if (child == par)
            continue;
        dfs(child, vertex);
    }
}
vector<int> path(int vertex)
{
    vector<int> temp;
    while (vertex != -1)
    {
        temp.push_back(vertex);
        vertex = parent[vertex];
    }
    reverse(temp.begin(), temp.end());
    return temp;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1);
    int x, y;
    // 2 nodes for which to find the LCA
    cin >> x >> y;
    vector<int> pathX = path(x);
    vector<int> pathY = path(y);
    int lca = -1;
    int i = 0;
    for (auto i : pathX)
        cout << i << " ";
    cout << endl;
    for (auto i : pathY)
        cout << i << " ";
    cout << endl;
    while (pathX[i] == pathY[i])
        i++;
    // the pointer reached where they are meeting the point is just behind the i
    lca = pathX[i - 1];
    cout << lca << endl;
    return 0;
}