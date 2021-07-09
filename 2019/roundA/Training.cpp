#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll test_case() {
    ll n,p; cin>>n>>p;
    ll s[n];
    ll presum[n];
    for(int i = 0; i < n; i++) {
        cin>>s[i];
    }
    sort(s, s + n);
    presum[0] = s[0]; 
    for(int i = 1; i < n; i++) {
        presum[i] = presum[i - 1] + s[i];
    }
    ll ans = 2e9;
    for(int i = p - 1; i < n; i++) {
        if(i == p - 1) {
            ans = min(ans, s[i]*p - (presum[i]));
        } else {
            ans = min(ans, s[i]*p - (presum[i] - presum[i - p]));
        }
    }
    return ans;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        ll ans = test_case();
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
