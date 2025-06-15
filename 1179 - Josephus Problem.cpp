#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

ll solve(ll n , ll k)
{
    if(n == 1) return 0;
    return (solve(n-1,k) + k) % n;
}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;
ll int t; cin >> t;
while(t--) {

ll n,k; cin >> n >> k;
cout << "Case " << c++ << ": "  << solve(n,k)+1 << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}