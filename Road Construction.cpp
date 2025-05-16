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

ll n; cin >> n;

unordered_map<string , ll > cheak;
ll id = 1;

vector<tuple<ll,ll,ll>> edge;

for (ll i = 0; i < n; i++)
{
    string a,b; cin >> a >> b;
    ll w; cin >> w;
    if(cheak[a] == 0) cheak[a] = id++; 
    if(cheak[b] == 0) cheak[b] = id++;

    edge.push_back({w,cheak[a] , cheak[b]});
}

sort(edge.begin(),edge.end());

dsu dsu(cheak.size()+1);  
ll ans = 0;

for(auto [w,x,y] : edge)
{
    ll a = dsu.find(x);
    ll b = dsu.find(y);
    if( a != b )
    {
        dsu.merge(a,b);
        ans += w;
    }
}

ll count = 0;

for (ll i = 1; i < id ; i++)
{
    if(dsu.parent[i] == i) count++;
}

cout << "Case " << c++ << ": ";
if(count > 1) cout << "Impossible" << endl;
else cout << ans << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}