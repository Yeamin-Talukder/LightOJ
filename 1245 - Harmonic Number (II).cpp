#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll int t; cin >> t;
ll c = 1;
while(t--) {

ll n; cin >> n;

ll low = LLONG_MAX;

ll sum = 0;
for (ll i = 1; i <= sqrt(n) ; i++)
{
    ll x = (n/i);
    ll y = (n/(i+1))+1;

    sum  += ((x - y + 1) * i);
    low = min(low , y);
}

for (ll i = 1; i < low; i++) sum  += (n/i);

cout << "Case " << c++ << ": " << sum << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}