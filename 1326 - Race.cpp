#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

// Fubini Number || Ordered Bell Number
// This  make group/split of n elements + Rank Each Group All possible ways (No Two Group Can tie) 
class Fubini 
{
    public :

    vector<vector<ll>> s; // Stirling Number
    vector<ll> factorial;
    ll mod = 10056;

    Fubini(ll range)
    {
        s.resize(range+2 , vector<ll>(range+2 , -1));
        factorial.resize(range+2 , 1);

        for (ll i = 1; i < range+1; i++)
        {
            factorial[i] = (factorial[i-1] * i) % mod;
        }

    }

    ll stirling( ll n , ll k) // Rule : s(n,k) = k * s(n-1,k) + s(n-1,k-1)
    {
        if(n == k || k == 1) return 1;
        if(n == 0 || k <= 0 || k > n ) return 0;

        if(s[n][k] != -1) return s[n][k];
        return s[n][k] = ( ( k * stirling(n-1 , k) ) % mod + stirling(n-1 , k-1)) % mod;
    }

    // Here we take k! Because of each group Ranking(permutation) 
    ll cal( ll n) // Rule : Sum of All (Stirling Nuber * k!) in (1 to n) 
    {
        ll ans = 0;
        
        for (ll i = 1; i <= n; i++)
        {
            ans = (ans + (stirling(n,i) * factorial[i]) % mod ) % mod;
        }
        return ans;
    }
};

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

Fubini f(1000);

ll c = 1;
ll int t; cin >> t;
while(t--) {

ll n; cin >> n;
cout << "Case " << c++ << ": " << f.cal(n) << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}