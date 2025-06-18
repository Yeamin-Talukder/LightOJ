#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

class Inclusion_Exclusion
{
    public : 

    vector<ll> sub;
    ll ans = 0;

    Inclusion_Exclusion(ll n , vector<ll> &v )
    {
        for (ll i = 1; i < (1LL << v.size()); i++)
        {
            ll x = __builtin_popcount(i);

            bitset<32>bit(i);
            ll lcm = 1;
            for (ll j = 0; j < (ll)(log2(i)+1); j++)
            {
                if(bit[j] == 1) lcm = (lcm * v[j] ) / __gcd(lcm , v[j]);
                if(lcm > n) break;
            }
            if(lcm <= n) ((x % 2 == 0)? ans -= n/lcm : ans += n/lcm);
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

vector<ll> v; 
for (ll i = 0; i < m; i++)
{
    ll x; cin >> x;
    if( x <= n) v.push_back(x);
}

Inclusion_Exclusion set(n , v);
cout << "Case " << c++ << ": " << n - set.ans << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}