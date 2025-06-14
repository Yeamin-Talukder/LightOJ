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

string s,s2; cin >> s >> s2;
vector<ll> a,b;


string tem;
for (ll i = 0; i < s.size(); i++)
{
    if(s[i] != '.') tem.push_back(s[i]);
    else {
        a.push_back(stoll(tem));
        tem.clear();
    }
}

a.push_back(stoll(tem));
tem.clear();


for (ll i = 0; i < s2.size(); i++)
{
    if(s2[i] != '.') tem.push_back(s2[i]);
    else 
    {
        bitset<10> bit(tem);
        tem.clear();
        ll x = bit.to_ullong();
        b.push_back(x);
    }
}

bitset<10> bit(tem);
b.push_back(bit.to_ullong());

cout << "Case " << c++ << ": " << ((a == b )? "Yes" : "No" )<< endl;



}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}