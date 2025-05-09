#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

vector<ll> vis;
void dfs(ll node, ll type , ll &ans , vector<vector<ll>> &edge , vector<ll> &fre)
{
    if(type == 1) fre[node]++;
    else ans++;
    
    vis[node] = 1;
    for(auto child : edge[node])
    {
        if(vis[child] == -1) dfs(child,type,ans,edge,fre);
    }

}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;

ll int t; cin >> t;
while(t--) {

ll k,n,m; cin  >> k >> n >> m;

vector<ll> start(k); for(auto &u:start) cin>>u;

vector<vector<ll>> edge(n+1);

for (ll i = 0; i < m; i++)
{
    ll x,y; cin >> x >> y;
    edge[x].push_back(y);
}

vector<ll> fre(n+1);

ll ans = 0;

for(auto u:start)
{
    vis.clear();
    vis.resize(n+1,-1);
    dfs(u,1,ans,edge,fre);
}

   
for(auto u:start)
{
    if(fre[u] == k )
    {
        vis.clear();
        vis.resize(n+1,-1);

        dfs(u,2,ans,edge,vis);
        break;
    }
}

cout << "Case " << c++ << ": " << ans << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}