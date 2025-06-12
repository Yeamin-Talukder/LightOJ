#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

class Segmented_seive
{
    public : 

    vector<ll> prime;
    vector<bool> seive;

    Segmented_seive(ll size)
    {
        seive.resize(size+10);
        seive[0] = 1; seive[1] = 1;

        for (ll i = 2; i <= size; i++)
        {
            if(seive[i] == 0)
            {
                prime.push_back(i);
                for (ll j = i*i; j <= size; j+=i) seive[j] = 1;
            }
        }
        
    }

    ll range(ll l, ll r)
    {
        ll size = r-l+1;
        vector<bool> mark(size);
        if(l == 1) mark[0] = 1;
        
        for(auto i : prime)
        {
            if(i * i > r) break;
            ll start = max(i * i, ((l + i - 1) / i) * i);
            for (ll j = start ; j <= r; j += i) mark[j-l] = 1;
        }
        
        ll count = 0;
        for(auto u : mark) if(u == 0) count++;
        return count;
    }

};


int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

Segmented_seive prime(5e4);

ll c = 1;
ll int t; cin >> t;
while(t--) {

ll a,b; cin >> a >> b;
cout << "Case " << c++ << ": " << prime.range(a,b) << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}