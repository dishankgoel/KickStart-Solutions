#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll test_case() {
    ll n,s;cin>>n>>s;
    ll a[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        vector<ll> types((int)1e5 + 1, 0);
        vector<ll> consider((int)1e5 + 1, 1);
        ll curr_ans = 0;
        for(int j = i; j < n; j++) {
            types[a[j]] += 1;
            if(consider[a[j]]) {
                if(types[a[j]] > s) {
                    consider[a[j]] = 0;
                    curr_ans -= s;
                } else {
                    curr_ans++;
                }
            }
            ans = max(ans, curr_ans);
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
