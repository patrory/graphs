/*
used to find connected component
has 3 function
make - add new node to group
parent find the root of graph
union connect 2 graph component
*/

/*
find the number of connected components
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N];
int size[N];
void make(int v)
{
    parent[v] = v;
    size[v] = 1;
}
int find(int v)
{
    if (v == parent[v])
        return v;
    // path compression
    return parent[v] = find(parent[v]);
}
void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        make(i);
    }
    while (k--)
    {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    // number of parent = index == parent[index]
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == find(i))
            ans++;
    }
    cout << "The number of onnected components is " << ans;
    return 0;
}

/*
time complexity  O(alpha(n))
reverse ackernmoan function
amotorized operation

over a number of operation the time complexity is const
*/