#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

class BRIDGE
{
    public : 

    vector<ll> vis,discover_time,low_time;
    vector<pair<ll,ll>> bridge_edge;

    BRIDGE(ll n , vector<vector<ll>> &edge)
    {
        vis.resize(n+2);
        discover_time.resize(n+2);
        low_time.resize(n+2);

        ll discover_id = 1;

        for (ll i = 0; i <= n; i++)
        {
            if(vis[i] == 0) dfs(i,-1,discover_id,edge);
        }

    }

    void dfs(ll node , ll parent , ll &discover_id , vector<vector<ll>> &edge)
    {
        vis[node] = 1;
        discover_time[node] = discover_id;
        low_time[node] = discover_id;

        discover_id++;

        for(auto child : edge[node])
        {
            if(child == parent) continue;

            if(vis[child] == 1){ low_time[node] = min(low_time[node],low_time[child]); continue;}
            else dfs(child , node , discover_id , edge);
            
            low_time[node] = min(low_time[node],low_time[child]);
            if(discover_time[child] == low_time[child] ) bridge_edge.push_back({node,child});

        }

    }

};


int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;

ll int t; cin >> t;
while(t--) {

    ll n ; cin >> n;

    vector<vector<ll>> edge(n+1);

    for (ll i = 0; i < n; i++)
    {
        ll x; cin >> x;
        string s; cin >> s;
        string val;
        for (ll i = 1; i <s.size()-1 ; i++)val.push_back(s[i]);
        ll size = stoll(val);

        for (ll j = 0; j < size; j++)
        {
            ll y; cin >> y;
            edge[x].push_back(y);
        }
    }

    BRIDGE bridge(n , edge);

    for(auto &[x,y] : bridge.bridge_edge)
    {
        if(x > y) swap(x,y);
    }

    sort(bridge.bridge_edge.begin(),bridge.bridge_edge.end());

    cout << "Case " << c++ <<  ": "<< endl; 

    cout << bridge.bridge_edge.size()  << " critical links" << endl;

    for(auto u:bridge.bridge_edge) cout<<u.first<< " - " << u.second << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}