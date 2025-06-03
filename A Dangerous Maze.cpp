#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;
ll int t; cin >> t;
while(t--) {


ll n; cin >> n;

ll count = 0;
ll total = 0;

for (ll i = 0; i < n; i++)
{
    ll x; cin >> x;
    if( x > 0) count++;
    total += abs(x);
}

ll common = __gcd(count , total);
total /= common;
count /= common;

if(count == 0) cout << "Case " << c++ << ": inf" << endl; 
else cout <<"Case " << c++ << ": " << total << "/" << count << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}