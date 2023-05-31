#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int INF = 1e9 + 10;
int n, m, maxa = INT_MIN;
int graph[N][N];
int vis[N][N];
int lev[N][N];

void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vis[i][j] = 0;
            lev[i][j] = INF;
        }
    }
}

vector<pair<int, int>> moves = {
    {1, 0}, {-1, 0}, {0, -1}, {0, 1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

bool valid(int x, int y)
{
    if (x >= n || x < 0)
        return false;
    if (y >= m || y < 0)
        return false;
    return 1;
}
int bfs()
{
    int ans = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maxa == graph[i][j])
            {
                q.push({i, j});
                lev[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (auto i : moves)
        {
            int tx = i.first + x;
            int ty = i.second + y;
            if (!valid(tx, ty))
                continue;
            if (!vis[tx][ty])
            {
                q.push({tx, ty});
                vis[tx][ty] = 1;
                lev[tx][ty] = lev[x][y] + 1;
                ans = max(ans, lev[tx][ty]);
            }
        }
    }
    return ans;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        reset();
        cin >> n >> m;
        maxa = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> graph[i][j];
                maxa = max(maxa, graph[i][j]);
            }
        }
        cout << bfs() << endl;
    }
    return 0;
}