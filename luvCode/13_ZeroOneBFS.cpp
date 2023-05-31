/*
when the weight of edges are not same but have weight zero or one
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<pair<int, int>> graph[N];
vector<int> lev(N, INF);
int n, m;
int bfs(int source)
{
    deque<int> q;
    q.push_back(1);
    lev[1] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        for (auto i : graph[u])
        {
            int child = i.first;
            int wt = i.second;
            if (lev[u] + wt < lev[child])
            {
                lev[child] = lev[u] + wt;
                if (wt == 0)
                    q.push_front(child);
                else
                    q.push_back(child);
            }
        }
    }
    return lev[n] == INF ? -1 : lev[n];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == y)
            continue;
        graph[x].push_back({y, 0});
        graph[y].push_back({x, 1});
    }
    cout << bfs(1);
    return 0;
}