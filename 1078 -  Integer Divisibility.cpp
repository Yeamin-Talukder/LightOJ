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

ll n , digit; cin >> n >> digit;

ll ans = 1;
ll val = digit;

while(val % n != 0)
{
    val = (val * 10 + digit) % n;
    ans++;
}

cout << "Case " << c++ << ": " << ans << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}