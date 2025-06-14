#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

class Dijkstra
{
public:

    vector<ll> dis;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    Dijkstra(ll n, ll root, vector<vector<pair<ll, ll>>> &adj)
    {
        dis.resize(n + 1, LLONG_MAX);
        pq.push({0, root});
        dis[root] = 0;

        while (!pq.empty())
        {
            ll node = pq.top().second;
            ll distance = pq.top().first;

            pq.pop();

            if (distance > dis[node]) continue;

            for (auto u : adj[node])
            {
                if (distance + u.first < dis[u.second])
                {
                    dis[u.second] = distance + u.first;
                    pq.push({dis[u.second], u.second});
                }
            }
        }
    }
};


int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;

ll int t; cin >> t;
while(t--) {


ll n,m; cin >> n >> m;

vector<vector<pair<ll,ll>>> edge(n+1);

for (ll i = 0; i < m; i++)
{
    ll x,y,w; cin >> x >> y >> w;
    edge[x].push_back({w,y});
    edge[y].push_back({w,x});
}

Dijkstra path(n,1,edge);

cout << "Case " << c++ << ": " ;
if(path.dis[n] == LLONG_MAX ) cout << "Impossible" << endl;
else cout << path.dis[n] << endl;


}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}