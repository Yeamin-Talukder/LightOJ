#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

ll count_five( ll n)
{
    ll count = 0;
    ll val = 5;
    while( n >= val)
    {
        count += n / val;
        val *= 5;
    }
    return count;
}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c  = 1;
ll int t; cin >> t;
while(t--) {

ll n; cin >> n;

ll l = 5 , r = 1e9;

ll ans = -1;

while(l <= r)
{
    ll mid = (l + r)/2;

    ll count = count_five(mid);

    if( count > n) r = mid - 1;
    else if( count < n) l = mid + 1;
    else {ans = mid; r = mid - 1;}
}

cout << "Case " << c++ << ": " << ((ans == -1)? "impossible" : to_string(ans)) << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}