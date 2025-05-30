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

if(n % 2 == 1) {cout << "Case " << c++ << ": " << "Impossible" << endl; continue;}

ll even = 1;
while (n % 2 == 0) 
{
    even *= 2;
    n /= 2;
}

cout << "Case " << c++ << ": " << n << " " << even << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}