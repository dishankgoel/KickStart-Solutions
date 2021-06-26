#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll test_case(ll n, ll k, ll s) {
    return k - 1 + min(n + 1, k - s + n - s + 1);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        ll n,k,s; 
        cin>>n>>k>>s;
        ll ans = test_case(n, k, s);
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
