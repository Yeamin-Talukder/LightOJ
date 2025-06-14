#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

class DSU
{
    public: 

    vector<ll> parent,size;
    DSU(ll n){
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

ll n; cin >> n;

vector<tuple<ll,ll,ll>> edge(n+1);

for (ll i = 0; i < n; i++)
{
    for (ll j = 0; j < n; j++)
    {
        ll x; cin >> x;
        if(x > 0) edge.push_back({x,i+1,j+1});    
    }
}

sort(edge.begin(),edge.end());

DSU dsu(n);

ll extra = 0;
for(auto [weight , x , y] : edge)
{
    ll a = dsu.find(x);
    ll b = dsu.find(y);

    if(a != b) dsu.merge(a,b);
    else extra += weight;
}

ll count = 0;

for (ll i = 1; i <= n; i++)
{
    if(dsu.parent[i] == i) count++;
}

cout << "Case " << c++ << ": ";
cout << ((count > 1)? -1 : extra) << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}