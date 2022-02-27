#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e4 + 5, INF = 1e9 + 7;

typedef pair<int, int> ii;
priority_queue<ii, vector<ii>, greater<ii> > pq;
string source, destination;
map<string, int> village;
int inf[MAXN], stones[MAXN], total[MAXN];
vector<ii> a[MAXN];
int N, M, k;

int BFS(int x)
{
    queue<int> q;
    q.push(x);
    vector<int> dist(N + 1, -1);
    dist[x] = 0;
    int sum = 0;

    if (k == 0)
        return 0;

    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for(auto next : a[u]) 
            if (dist[next.first] == -1) {
                dist[next.first] = dist[u] + 1;
                sum += inf[next.first];
                if (dist[next.first] < k)
                    q.push(next.first);
            }
    }

    return sum;
    
}

int main()
{
    cin >> N >> M >> k;
    cin >> source >> destination;

    for(int i = 1; i <= N; ++i)
    {
        string s;
        cin >> s >> stones[i] >> inf[i];
        village[s] = i;
    }

    for(int i = 0; i < N; ++i)
    {
        string s, t; int c;
        cin >> s >> t >> c;
        a[village[s]].push_back({village[t], c});
        a[village[t]].push_back({village[s], c});
    }

    
    for(int i = 1; i <= N; ++i)
        total[i] = BFS(i);


    vector<int> distance(N + 1, INF), maxStones(N + 1, 0);
    pq.push({0, village[source]});
    distance[village[source]] = 0;
    maxStones[village[source]] = stones[village[source]];
    
    while (!pq.empty())
    {
        auto u = pq.top(); pq.pop();
        if (u.first != distance[u.second])
            continue;
        
        for(auto next : a[u.second])
        {
            if (distance[next.first] > u.first + total[u.second] + next.second) {
                distance[next.first] = u.first + total[u.second] + next.second;
                maxStones[next.first] = maxStones[u.second] + stones[next.first];
                pq.push({distance[next.first], next.first});
            } else if (distance[next.first] == u.first + total[u.second] + next.second) 
                maxStones[next.first] = max(maxStones[next.first], maxStones[u.second] + stones[next.first]);
        }
    }

    cout << distance[village[destination]] << " " << maxStones[village[destination]];
    return 0;

}
