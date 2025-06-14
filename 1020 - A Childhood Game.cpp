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
string s; cin >> s;

if(s == "Alice" )
{
    if(n % 3 == 1) cout << "Case " << c++ << ": Bob" << endl;
    else cout << "Case " << c++ << ": Alice" << endl;
}

else 
{
    if(n % 3 == 0) cout << "Case " << c++ << ": Alice" << endl;
    else cout << "Case " << c++ << ": Bob" << endl;
}

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}