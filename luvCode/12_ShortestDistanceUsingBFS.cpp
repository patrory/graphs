#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int level[N][N], visited[N][N];

int getX(string s)
{
    return (s[0] - 'a') + 1;
}
int getY(string s)
{
    return s[1] - '0';
}
vector<pair<int, int>> movements = {{-1, 2}, {1, 2}, {-1, -2}, {1, -2}, {2, 1}, {2, -1}, {-2, -1}, {-2, 1}};

bool valid(int x, int y)
{
    if (x > 8 || x < 1)
        return false;
    if (y > 8 || y < 1)
        return false;
    return true;
}
int bfs(string s1, string s2)
{
    queue<pair<int, int>> q;
    int sx = getX(s1);
    int sy = getY(s1);
    int dx = getX(s2);
    int dy = getY(s2);
    q.push({sx, sy});
    visited[sx][sy] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (auto mov : movements)
        {
            int tx = x + mov.first;
            int ty = y + mov.second;

            if (!valid(tx, ty))
                continue;
            if (!visited[tx][ty])
            {

                q.push({tx, ty});
                visited[tx][ty] = 1;
                level[tx][ty] = 1 + level[x][y];
            }
        }
    }
    return level[dx][dy];
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << bfs(s1, s2) << '\n';
    }
    return 0;
}