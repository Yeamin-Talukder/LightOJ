#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void make_prime(vector<bool> &seive,vector<ll> &prime)
{
    seive[0] = 1;
    seive[1] = 1;
    
    ll size = seive.size();
    for (ll i = 2; i*i < size; i++)
    {
        if(seive[i] == 0)
        {
            for (ll j = i*i; j < size; j+=i) seive[j] = 1;
        }
    }

    for (ll i = 2; i < size; i++) if(seive[i] == 0) prime.push_back(i);
    
}
void make_factor(ll n , vector<ll> &factor , vector<ll> &prime)
{
    ll tem = n;
    for(auto u:prime)
    {
        if(u >= n) break;
        if(tem % u == 0)
        {
            factor.push_back(u);
            while(tem % u == 0) tem /= u;
        }
    }
}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

vector<bool> seive(1002);
vector<ll> prime;
make_prime(seive,prime);

ll c = 1;

ll int t; cin >> t;
while(t--) {

ll a,b; cin >> a >> b;

queue<pair<ll,ll>> q;
q.push({a,0});


ll mn = LLONG_MAX;

map<ll,ll> track;

while(!q.empty())
{
    auto [val , cnt] = q.front(); q.pop();

    if(val == b){mn = min(mn,cnt); continue;}

    vector<ll> factor;
    make_factor(val,factor,prime);

    for(auto x : factor)
    {
       if(val + x <= b && track[val+x] == 0) 
       {
        q.push({val+x, cnt+1});
        track[val+x] = 1;
        }
    }

}

cout << "Case "<< c++  << ": " << (mn == LLONG_MAX ? -1 : mn) << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}