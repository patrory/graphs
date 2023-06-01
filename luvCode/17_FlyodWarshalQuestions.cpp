/*
all pair shortest path algorithm
dynamic algorithm approach
works on directed and undirected


cannot handle -ve weight cycle
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 520;
const int INF = 1e9 + 10;
int dist[N][N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> dist[i][j];
    }
    vector<int> del_order(n);
    for (int i = 0; i < n; i++)
        cin >> del_order[i];
    reverse(del_order.begin(), del_order.end());
    vector<long long> ans;
    for (int k = 0; k < n; k++)
    {
        int u = del_order[k];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][u] + dist[j][u]);
            }
        }
        long long sum = 0;
        for (int i = 0; i <= k; i++)
        {
            for (int j = 0; j <= k; j++)
                sum += dist[del_order[i]][del_order[j]];
        }
        ans.push_back(sum);
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << " ";
}