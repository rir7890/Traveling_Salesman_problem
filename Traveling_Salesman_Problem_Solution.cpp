


#include <bits/stdc++.h>
using namespace std;

int tsp(vector<pair<int, int>> adj[], int V, int S)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> visited(V, 0);
    int ans = 0;
    pq.push({S, 0});
    visited[S] = 1;
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            int vertice = it.second;
            int weight = it.first;
            if (!visited[vertice])
            {
                pq.push({weight, vertice});
            }
            else if (visited[S] == 1 && i == V - 1)
            {
                visited[S]++;
                pq.push({weight, vertice});
            }
        }
        pair<int, int> p = pq.top();
        pq.pop();
        while (!pq.empty())
        {
            pq.pop();
        }
        if (visited[S] == 1)
        {
            visited[p.second] = 1;
        }
        ans += p.first;
    }
    return ans;
}
int main()
{
    vector<pair<int, int>> adj[]{
        {{10, 1}, {20, 2}, {15, 3}},
        {{25, 2}, {10, 0}, {35, 3}},
        {{20, 0}, {25, 1}, {30, 3}},
        {{30, 2}, {35, 1}, {15, 0}}};
    cout << tsp(adj, 4, 0);
    return 0;
}


////Solution of travel salesman person in O(n2) time complexity and O(V+E) space complexity 
