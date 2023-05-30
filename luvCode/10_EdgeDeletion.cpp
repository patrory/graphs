// subtree operations are solved in backtracking

/*
Given Q qeries , q <== 1e5
in each query given V ,
Print subtree sum of V and no of even numbers
in subtree of V
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];

// value stores the wight of the vertex
int subtree[N];

bool dfs(int vertex, int parent)
{
    // subtree[vertex] += value[vertex];  if value given then this is how the value can be used
    // in this case we are using weight as vertex itself
    subtree[vertex] += vertex;
    for (int child : graph[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex);
        subtree[vertex] += subtree[child];
    }
}

int main()
{
    int n;
    cin >> n;
    // enter the value each vertex hold
    // for (int i = 1; i <= n; i++)
    //     cin >> value[i];

    for (int i = 0; i < n - 1; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1, 0);
    int ans = INT_MIN;
    for (int i = 2; i <= n; i++)
    {
        int part1 = subtree[i];
        int part2 = subtree[1] - subtree[i];
        ans = max(ans, part1 * part2);
    }
    cout << ans;

    return 0;
}

/*
Time complexity
    O(V + E)
    for every node dfs will be running
    then total edges it will be visiting not in E^2 they must be E
*/
