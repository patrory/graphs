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
int subtree[N], even[N], value[N];

bool dfs(int vertex, int parent)
{
    // subtree[vertex] += value[vertex];  if value given then this is how the value can be used
    // in this case we are using weight as vertex itself
    subtree[vertex] += vertex;
    even[vertex] += ((vertex & 1) == 0);
    for (int child : graph[vertex])
    {
        if (child == parent)
            continue;
        dfs(child, vertex);
        subtree[vertex] += subtree[child];
        even[vertex] += even[child];
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

    int query;

    //  if query given
    /*
    cin >> query;
    while (query--)
    {
        int v;
        cin >> v;
        cout << subtree[v] << " " << even[v] << endl;
    }
    */

    // printing the subtree sum array and even count
    for (int i = 1; i <= n; i++)
        cout << subtree[i] << " " << even[i] << "\n";

    return 0;
}

/*
Time complexity
    O(V + E)
    for every node dfs will be running
    then total edges it will be visiting not in E^2 they must be E
*/
