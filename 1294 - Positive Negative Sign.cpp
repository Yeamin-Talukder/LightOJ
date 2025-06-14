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

ll n , m; cin >> n >> m;

ll x = ((2*m) * ((2*m) + 1)) / 2;
ll y = (m * (m + 1)) / 2;

x = x - y;
ll gap = (x - y);

cout << "Case " << c++ << ": " << (gap * (n/(2*m))) << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}