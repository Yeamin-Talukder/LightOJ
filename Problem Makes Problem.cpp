#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

class ncr
{
    public : 

    vector<ll> factorial;
    ll mod = 1e9 + 7;

    ncr( ll size)
    {
        factorial.resize(size + 1);
        factorial[0] = 1;

        ll val = 1;
        for (ll i = 1; i <= size; i++)
        {
            val = (val * i) % mod;
            factorial[i] = val;
        }
    }

      ll bigmod(ll a, ll b) {
            ll result = 1;
            while (b > 0) {
                if (b & 1) result = (result * a) % mod;        
                a = (a * a) % mod;
                b >>= 1;              
            }
            return result;
        }

    ll cal( ll n , ll r)
    {
        ll a = factorial[n];
        ll b = (factorial[r] * factorial[n - r]) % mod;
        return ( a * bigmod(b , mod - 2) ) % mod;
    }
};



int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ncr ncr(2e6+10);

ll c = 1;
ll int t; cin >> t;
while(t--) {

ll n,k; cin >> n >> k;
cout  << "Case " << c++  << ": "  << ncr.cal((n+k-1) , k-1) << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}