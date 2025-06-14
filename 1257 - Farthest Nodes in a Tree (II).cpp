#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"


class Diameter
{
public:
    ll ans = 0;
    ll corner_a = 0 , corner_b = 0;
    ll farthestNode = 0;
    vector<vector<pair<ll, ll>>> adj;

    Diameter(ll n, vector<vector<pair<ll, ll>>> &edge)
    {
        adj = edge;
        dfs(0, -1, 0); // first DFS from any node
        corner_a = farthestNode; ans = 0; 
        dfs(farthestNode, -1, 0); // second DFS from farthest node found
        corner_b = farthestNode;
    }

    void dfs(ll node, ll parent, ll distance)
    {
        if (distance > ans)
        {
            ans = distance;
            farthestNode = node;
        }

        for (auto &u : adj[node])
        {
            if (u.first != parent) dfs(u.first, node, distance + u.second);
        }
    }
};


void dfs ( ll node , ll parent , vector<ll> &save , vector<vector<pair<ll,ll>>> &edge)
{
    for(auto &child : edge[node])
    {
        if(child.first != parent)
        {
            save[child.first] = save[node] + child.second;
            dfs(child.first , node , save , edge);
        }
    }
}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;
ll int t; cin >> t;
while(t--) {

ll n; cin >> n;
vector<vector<pair<ll,ll>>> edge(n);


for (ll i = 0; i < n-1; i++)
{
    ll x,y,w; cin >> x >> y >> w;
    edge[x].push_back({y,w});
    edge[y].push_back({x,w});
}

Diameter path(n,edge);

vector<ll> first(n),last(n);
dfs(path.corner_a , -1 , first , edge);
dfs(path.corner_b , -1 , last , edge);

cout << "Case " << c++ << ": " << endl;
for(ll i = 0; i < n; i++)
{
    cout << max(first[i],last[i]) << endl;
}

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}