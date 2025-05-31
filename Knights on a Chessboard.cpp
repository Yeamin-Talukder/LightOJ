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

ll m,n; cin >> m >> n;

if(m < n) swap(m, n);

if(n == 1) {cout << "Case " << c++ << ": " << m << endl; continue;}
else if( n == 2 ) {cout << "Case " << c++ << ": " << (4 * (m/4)) + (2 * min( 2LL , m%4)) << endl; continue;}

ll x = m * (n/2);

cout << "Case " << c++ << ": " << x + ((n % 2 == 0)? 0 :  (m+1)/2) << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}