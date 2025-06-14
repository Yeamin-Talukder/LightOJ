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


vector<bool> seive(1e2+10);
vector<ll> prime;
make_prime(seive,prime);

ll c = 1;

ll int t; cin >> t;
while(t--) {


ll n; cin >> n;

map<ll,ll> store;

for(auto u : prime)
{
    if(u > n) break;

    ll x = u;
    ll count = 0;
    while ( x <= n)
    {
        count += n / x;
        x *= u;
    }
    if(count > 0) store[u] = count;
}

ll first = 1;

cout << "Case " << c++ << ": " << n << " = ";
for(auto u : store)
{
    if(first) first = 0;
    else cout << " * "; 
    cout << u.first << " " << "(" << u.second << ")";
}
cout << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}