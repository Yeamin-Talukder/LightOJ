#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

vector<ll> vis(110);
ll a = 0 , b = 0;
void dfs(ll node , ll parent , vector<vector<tuple<ll,ll,ll>>> &edge)
{
    if(vis[node] == 1) return;
    vis[node] = 1;

    for( auto [child , x , y] : edge[node])
    {
        if(child != parent) 
        {
            a += x;
            b += y;
            dfs(child , node , edge);
        }
        if(parent == -1) break;
    }

}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;

ll int t; cin >> t;
while(t--) {

ll n; cin >> n;

vector<vector<tuple<ll,ll,ll>>> edge(n+1);

for (ll i = 0; i < n; i++)
{
    ll a,b,c; cin >> a >> b >> c;
    edge[a].push_back({b,0,c});
    edge[b].push_back({a,c,0});
}

dfs(1,-1,edge);
cout << "Case " << c++ << ": " << min(a,b) << endl;

a = b = 0;
vis.assign(110,0);

}
// Time Complexcity  : O(n) 
// Space Complexcity : O(n) 
}