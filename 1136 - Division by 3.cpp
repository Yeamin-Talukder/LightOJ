#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<ll> save = {0 , 0 , 1 , 2 , 2 , 3 , 4 , 4 , 5 , 6};

ll c = 1;
ll int t; cin >> t;
while(t--) {

ll a,b; cin >> a  >> b;

ll x = b/9;
x *= 6;
x += save[b%9];

a--;
ll y = a/9;
y *= 6;
y += save[a%9];

cout << "Case " << c++ << ": " << (x - y) << endl;  

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}