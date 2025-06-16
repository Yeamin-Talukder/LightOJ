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

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<bool> seive(1e5+9);
vector<ll> prime;
make_prime(seive,prime);

ll c = 1;
ll int t; cin >> t;
while(t--) {

ll n; cin >> n;
ll tem = n;
n = abs(n);

ll ans = 0;
for(auto u : prime)
{
    if(u > n) break;
    if(n % u == 0)
    {
        ll count = 0;
        while(n % u == 0) { n/=u; count++;}
        ans = __gcd(ans,count);
    }
}

if(n > 1) ans = __gcd(ans,1LL);
if(tem < 0) {while(ans % 2 == 0) ans /= 2;}

cout << "Case " << c++ << ": " << ans << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}