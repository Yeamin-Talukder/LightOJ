#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

ll leap_year(ll year)
{
    return (year / 4) - (year / 100) + (year / 400);
}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

map<string , ll> month;

month["January"] = 1;
month["February"] = 2;
month["March"] = 3;
month["April"] = 4;
month["May"] = 5;
month["June"] = 6;
month["July"] = 7;
month["August"] = 8;
month["September"] = 9;
month["October"] = 10;
month["November"] = 11;
month["December"] = 12;

ll ca = 1;

ll int t; cin >> t;
while(t--) {


string a,b,c; cin >> a >> b >> c;

string tem = {b[0] ,b[1]};
ll day1 = stoll(tem);
ll month1 = month[a];
ll year1 = stoll(c);

cin >> a >> b >> c;

tem = {b[0] ,b[1]};

ll day2 = stoll(tem);
ll month2 = month[a];
ll year2 = stoll(c);

pair<ll,ll> x = {month2 , day2};
pair<ll,ll> leap = {2,29};

if( x < leap ) year2--;

day1--;
x = {month1 ,  day1};
if( x < leap ) year1--;


ll ans = leap_year(year2) - leap_year(year1);
cout << "Case " << ca++ << ": " << ans << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}