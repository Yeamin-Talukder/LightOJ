#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

class Dijkstra
{
public:

    vector<ll> dis;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    Dijkstra(ll n, ll root, vector<vector<pair<ll, ll>>> &adj , ll target)
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
                if ( max(distance , u.first) < dis[u.second])
                {
                    dis[u.second] = max(distance , u.first);
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

vector<vector<pair<ll,ll>>> adj(n);

for (ll i = 0; i < m; i++)
{
    ll x,y,w; cin >> x >> y >> w;
    adj[x].push_back({w,y});
    adj[y].push_back({w,x});
}


ll target; cin >> target;
Dijkstra path(n,target,adj,target);

cout << "Case " << c++ << ": " << endl;

for (ll i = 0; i < n; i++)
{
    if(path.dis[i] == LLONG_MAX) cout << "Impossible" << endl;
    else cout << path.dis[i] << endl;
}


}
// Time Complexcity  : O((n+m) * log n) 
// Space Complexcity : O(n + m) 
}