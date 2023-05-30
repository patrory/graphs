#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;

// unweighted graphs

// adjacency matrix
int matrix[N][N];

// adjacency list
vector<int> adjacencyList[N];

// weighted graphs

// matrix
int wmatrix[N][N];

// weighted list
// vertice , weight
vector<pair<int, int>> wlist[N];

int main()
{
    //  n = vertices m = edges
    int n, m;
    cin >> n >> m;

    // for unweighted graphs
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        // adding data to matrix
        matrix[v1][v2] = 1;
        matrix[v2][v1] = 1;

        // adding value to adjacency list
        adjacencyList[v1].push_back(v2);
        adjacencyList[v2].push_back(v1);
    }

    // for weighted graphs

    for (int i = 0; i < m; i++)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;

        // filling weight into matrix
        wmatrix[v1][v2] = wt;
        wmatrix[v2][v1] = wt;
        // filling weight into list

        wlist[v1].push_back({v2, wt});
        wlist[v2].push_back({v1, wt});
    }
    return 0;
}

/*
space complexity
1. matrix is O(v^2) v = vertices  maximum v can be of 1e3
2. list is O(V+E) , V = vertices , E = edges  ,   v<= 1e5 and e <= 1e7
*/

/*
accessing the other parameter of connection of weight
1. matrix
    matrix[i][j]
    time complexity O(1)
2. list
    check weight of vertex i->j
    for(pair<int,int> point: list[i]  ){
        if( point.first == j )then weight = point.second
    }
    time complexity O(n) , n = no of connection to the parent node has
*/