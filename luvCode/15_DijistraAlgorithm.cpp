/*
Dijkstra algorithm is greedy algo
used priority  queue is used instead of normal queue
priority queue is basically a heap

initially all distances are infinity
take one source mark his distance as zero
the from queue take out min weight node
if the weight of child node is less then its current cost then modify the cost
cannot work for negative edges

single source
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int N = 1e5 + 10;
int dijkstra(int source, int n, vector<pair<int, int>> g[])
{
    vector<int> dist(N, INT_MAX);
    vector<bool> vist(N, false);
    set<pair<int, int>> st;
    // first == weight second == vertex
    dist[source] = 0;
    st.insert({0, source});
    while (st.size() > 0)
    {
        auto node = *st.begin();
        st.erase(st.begin());
        int vertex = node.second, wt = node.first;
        if (vist[vertex])
            continue;
        vist[vertex] = 1;
        for (auto i : g[vertex])
        {
            int childVertex = i.first, childWt = i.second;
            if (dist[childVertex] > wt + childWt)
            {
                dist[childVertex] = wt + childWt;
                st.insert({dist[childVertex], childVertex});
            }
        }
    }
    int ans = 0;
    // cout << "dist\n";
    for (int i = 1; i <= n; i++)
    {
        // cout << dist[i] << " ";
        if (dist[i] == INT_MAX)
            return -1;
        ans = max(ans, dist[i]);
    }
    return ans;
}

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{

    vector<pair<int, int>> graph[n + 1];
    for (auto v : times)
    {
        graph[v[0]].push_back({v[1], v[2]});
    }
    int ans = dijkstra(k, n, graph);
    return ans;
}
int main()
{
    int n, m, k;
    cin >> m >> n >> k;
    vector<vector<int>> times;
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(3);
        for (int j = 0; j < 3; j++)
            cin >> temp[j];
        times.push_back(temp);
    }
    int ans = networkDelayTime(times, n, k);
    cout << ans;
}