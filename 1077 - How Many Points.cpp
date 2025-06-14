#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

ll c = 1;
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll int t; cin >> t;
while(t--) {


ll a1,b1,a2,b2; cin >> a1 >> b1 >> a2 >> b2; 

cout << "Case " << c++ << ": "  << __gcd(abs(a2-a1) , abs(b2-b1)) + 1 << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}