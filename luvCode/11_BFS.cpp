#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
bool visited[N];
int level[N];
vector<int> sequence;
void bfs(int root)
{

    queue<int> q;
    q.push(root);
    visited[root] = 1;

    while (!q.empty())
    {
        int first = q.front();
        q.pop();
        sequence.push_back(first);
        for (auto i : graph[first])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
                level[i] = 1 + level[first];
            }
        }
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
    bfs(1);
    for (auto i : sequence)
        cout << i << " ";
    cout << "Level \n";
    for (int i = 1; i <= n; i++)
        cout << level[i] << " ";
}

/*
Time complexity
    O(V + E)
    for every node dfs will be running
    then total edges it will be visiting not in E^2 they must be E
*/
