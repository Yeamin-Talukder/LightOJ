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
cout << "Case " << c++ << ": " ;
for (ll i = 9; i >= 0; i--)
{
    if( (n - i) % 9 == 0) cout << 10 * ((n-i)/9) + i << " ";
}
cout << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}