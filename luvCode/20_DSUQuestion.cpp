/*
used to find connected component
has 3 function
make - add new node to group
parent find the root of graph
union connect 2 graph component


*/

/*
Q to find the diffrence of min and maximum sizes of componensts after the union operation*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int parent[N];
int size[N];
multiset<int> sizes;
void merge(int a, int b)
{
    sizes.erase(sizes.find(size[a]));
    sizes.erase(sizes.find(size[b]));
    sizes.insert(size[a] + size[b]);
}
void make(int v)
{
    parent[v] = v;
    size[v] = 1;
    sizes.insert(1);
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
        merge(a, b);
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
        int ma = *(sizes.begin());
        int mi = *(--sizes.end());
        cout << ma - mi << endl;
    }
    // number of parent = index == parent[index]

    return 0;
}

/*
time complexity  O(alpha(n))
reverse ackernmoan function
amotorized operation

over a number of operation the time complexity is const
*/