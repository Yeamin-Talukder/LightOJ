#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void make_prime(vector<bool> &seive,vector<ll> &prime)
{
    seive[0] = 1;
    seive[1] = 1;
    
    ll size = seive.size();
    for (ll i = 2; i*i < size; i++)
    {
        if(seive[i] == 0)
        {
            for (ll j = i*i; j < size; j+=i) seive[j] = 1;
        }
    }

    for (ll i = 2; i < size; i++) if(seive[i] == 0) prime.push_back(i);
    
}

ll mod = 1e9+7;

  ll bigmod(ll a, ll b) {
        ll result = 1;
        while (b > 0) {
            if (b & 1) result = (result * a) % mod;        
            a = (a * a) % mod;
            b >>= 1;              
        }
        return result;
    }

    ll Sum_of_Divisor( ll n , ll m,  unordered_map<ll,ll> &factor) 
    {
        ll ans = 1; 
        for(auto u : factor)
        {
            ll x = (bigmod(u.first,(u.second*m+1)) - 1 + mod) % mod;
            ll y = bigmod(u.first - 1 , mod - 2);
            ans = (ans * ((x*y)%mod) ) % mod ; // Rule : (p^(a + 1) - 1) / (p - 1) * ...
        }
        return ans;
    }

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<bool> seive(46340+10);
vector<ll> prime;
make_prime(seive,prime);

ll c = 1;
ll int t; cin >> t;
while(t--) {

    ll n,m; cin >> n >> m;

    unordered_map<ll,ll> factor;
    ll tem = n;
    for(auto &u : prime)
    {
        if( u * u > tem) break;
        while(tem % u == 0) 
        {
            factor[u]++;
            tem /= u;
        }
    }

    if(tem > 1) factor[tem]++;
    cout << "Case " << c++ << ": " << Sum_of_Divisor(n,m,factor) << endl;
    
}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}