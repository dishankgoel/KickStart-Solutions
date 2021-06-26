#include<bits/stdc++.h>
#define ll long long

using namespace std;


ll test_case(ll xcord[], ll ycord[], ll n) {
    ll ans = 0;
    ll ycost = 0;
    sort(ycord, ycord + n);
    ll yfinal = ycord[n/2];
    for(int i = 0; i < n; i++) {
        ycost += abs(ycord[i] - yfinal);
    }
    ll xcost = 0;
    sort(xcord, xcord + n);
    ll xfirstpossible[n];
    for(int i = 0; i < n; i++) {
        xfirstpossible[i] = xcord[i] - i;
    }
    sort(xfirstpossible, xfirstpossible + n);
    ll xfirst = xfirstpossible[n/2];
    for(int i = 0; i < n; i++) {
        xcost += abs(xcord[i] - (xfirst + i));
    }
    return xcost + ycost;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        ll n; cin>>n;
        ll xcord[n], ycord[n];
        for(int i = 0; i < n; i++) {
            cin>>xcord[i]>>ycord[i];
        }
        ll ans = test_case(xcord, ycord, n);
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
