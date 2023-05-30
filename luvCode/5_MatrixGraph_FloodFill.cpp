#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &image, int x, int y, int inital, int color)
{
    if (x >= image[0].size() or x <= 0)
        return;
    if (y >= image.size() or y <= 0)
        return;
    // if color is not equal to color to chaneg then return

    if (image[x][y] != inital)
        return;
    image[x][y] = color;
    dfs(image, x + 1, y, inital, color);
    dfs(image, x - 1, y, inital, color);
    dfs(image, x, y + 1, inital, color);
    dfs(image, x, y - 1, inital, color);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    // if new color and old are same then no need to change return image as is
    if (image[sr][sc] != color)
        dfs(image, sr, sc, image[sr][sc], color);
    return image;
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> image(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> image[i][j];
        }
    }
    int sr, sc, color;
    cout << "Enter X and Y and the new color ";
    cin >> sr >> sc >> color;
    floodFill(image, sr, sc, color);
    return 0;
}