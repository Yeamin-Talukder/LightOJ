#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

  ll bigmod(ll a, ll b , ll mod) {
        ll result = 1;
        while (b > 0) {
            if (b & 1) result = (result * a) % mod;        
            a = (a * a) % mod;
            b >>= 1;              
        }
        return result;
    }

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll int t; cin >> t;
ll c = 1;
while(t--) {

ll n,k,mod; cin >> n >> k >> mod;

ll sum = 0;

for (ll i = 0; i < n; i++)
{
    ll x; cin >> x;
    sum = (sum + x) % mod;
}

ll ans = bigmod(n , k-1 , mod);
ans = (ans * k ) % mod;

cout << "Case " << c++ << ": " << ( sum * ans ) % mod << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}