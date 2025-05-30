#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

class dsu
{
    public: 

    vector<ll> parent,size;
    dsu(ll n){
        parent.resize(n+2);
        size.resize(n+2,1);
        for(ll i = 1 ; i <= n ; i++) parent[i] = i;
    }

    ll find(ll x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void merge(ll x , ll y)
    {
        ll a = find(x);
        ll b = find(y);

        if(a != b)
        {
            if(size[a] > size[b]) swap(a,b);
            parent[a] = b;
            size[b] += size[a];
        }

    }

};


int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;
ll int t; cin >> t;
while(t--) {


ll n,m,a; cin >> n >> m >> a;

vector<tuple<ll,ll,ll>> edge;

for (ll i = 0; i < m; i++)
{
    ll x,y,w; cin >> x >> y >> w;
    edge.push_back({w,x,y});
}

sort(edge.begin(), edge.end());

dsu dsu(n); 

ll ans = 0;
for(auto [weight , u , v]  : edge)
{
    ll parent_a = dsu.find(u);
    ll parent_b = dsu.find(v);

    if(parent_a != parent_b && weight < a)
    {
        dsu.merge(u,v);
        ans += weight;
    }
}

ll count = 0;

for (ll i = 1; i <= n; i++)
{
    if(dsu.parent[i] == i) count++;
}

cout << "Case " << c++  << ": " << ans + (a * count) << " " << count << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}