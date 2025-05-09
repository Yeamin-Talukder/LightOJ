#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void BFS( ll node , vector<ll> &depth , vector<vector<ll>> &edge )
    {
        queue<ll> q;
        q.push(node);
        
        depth[node] = 0;

        while(!q.empty()) 
        {
            node = q.front(); q.pop();

            for(auto child : edge[node]) 
            {    if(depth[child] == -1) 
                {
                    q.push(child); 
                    depth[child] = depth[node] + 1;
                }
            }
        }

    }

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;

ll int t; cin >> t;
while(t--) {

    ll n,m; cin >> n >> m;

    vector<vector<ll>> edge(n);
    for (ll i = 0; i < m; i++)
        {
            ll x,y; cin >> x >> y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }   

    ll start,end; cin >> start >> end;

    vector<ll> first(n,-1),last(n,-1);

    BFS(start,first,edge);
    BFS(end,last,edge);

    ll ans = 0;
    for (ll i = 0; i < n; i++)
        {
            ans = max(ans, first[i] + last[i]);
        }

    cout << "Case " << c++ << ": " << ans << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}