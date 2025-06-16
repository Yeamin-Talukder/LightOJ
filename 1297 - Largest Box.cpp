#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

double cal(double l , double w , double x)
{
    double y = (l - (2*x)) * ( w - (2*x)) * x;
    return y;
}

int main()
{
ios_base::sync_with_stdio(false);cin.tie(NULL);

ll c = 1;
ll  t; cin >> t;
while(t--) {
    
double l,w; cin >> l >> w;

double low = 0.000001 , high = min(l/2,w/2);
double ans = 0;

while (high - low >= 0.000001)
{
    double mid1 = low + (high - low)/3;
    double mid2 = high - (high - low)/3;

    double x = cal(l,w,mid1);
    double y = cal(l,w,mid2);

    if( x < y ) {ans = max(y,ans); low = mid1;}
    else { ans = max(x,ans); high = mid2;}
}

cout << "Case " << c++ << ": " << fixed << setprecision(8) << ans << endl;

}
// Time Complexcity  : O() 
// Space Complexcity : O() 
}