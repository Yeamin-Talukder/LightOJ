#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

ll count_five(ll n)
{
    ll count = 0;
    ll val = 5;
    while( n >= val)
    {
        count += (n/val);
        val *=5;
    }
    return count;
}

ll count_two(ll n)
{
    ll count = 0;
    ll val = 2;
    while(n >= val)
    {
        count += (n/val);
        val *= 2;
    }
    return count;
}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;
ll int t; cin >> t;
while(t--) {


ll n,r,p,q; cin >> n >> r >> p >> q;

ll five = count_five(n);
five -= (count_five(r) + count_five(n-r));

ll two = count_two(n);
two -= ( count_two(r) + count_two(n-r));

ll ans = min(five,two);

five -= ans; two -= ans;

ll two_p = 0;
ll five_p = 0;

ll tem = p;

while(tem % 2 == 0 || tem % 5 == 0)
{
    if(tem % 2 == 0) {two_p++; tem /= 2;}
    if(tem % 5 == 0) {five_p++; tem /= 5;}
}

five += (five_p * q);
two += (two_p * q);

ans += min(five , two); 

cout << "Case " << c++ << ": "  << ans << endl;


}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}