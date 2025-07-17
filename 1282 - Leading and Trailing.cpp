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

int t; cin >> t;
ll c = 1;
while(t--) {

ll n,k; cin >> n >> k;

ll last = bigmod( n , k , 1000 );

double x = k * log10(n);
x -= (ll) x;

x  = pow(10,x);
x *= 100;

cout << "Case " << c++ << ": "  << (ll) x  <<  " " <<  setw(3) << setfill('0') << last << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}