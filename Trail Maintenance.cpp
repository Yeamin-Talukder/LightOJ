#include <bits/stdc++.h>
using namespace std;
#define ll int
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

    void reset(ll n)
    {
       for (ll i = 0; i <= n; i++) parent[i] = i;
       for (ll i = 0; i <= n; i++) size[i] = 1;
    }

};


ll MST(set<tuple<ll,ll,ll>> &edge, ll n , dsu &connect )
{
    ll ans = 0; 
    ll node = 1;
    for(auto [weight , x , y] : edge)
    {
        ll parent_a = connect.find(x);
        ll parent_b = connect.find(y);
        if(parent_a != parent_b)
        {
            connect.merge(x, y);
            ans += weight;
            node++;
        }

        if(node == n) break;
    }

    connect.reset(n);

    if(node != n) return -1; 
    else return ans;
}


int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;
ll  t; cin >> t;
while(t--) {

ll n , w; cin >> n >> w;

cout << "Case " << c++ << ": "<< endl;


set<tuple<ll,ll,ll>> edge;
dsu connect(n);
ll prev = -1;

for (ll i = 0; i < w ; i++)
{
    ll x,y,w; cin >> x >> y >> w;
    
        edge.insert({w,x,y});
        prev = MST(edge , n , connect);
        cout << prev << endl;
}

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}