#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll test_case() {
    ll n, q; cin>>n>>q;
    string blocks; cin>>blocks;
    vector<vector<int>> dp(n, vector<int>(26, 0));
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            dp[0][blocks[0] - 'A'] = 1;
        } else {
            dp[i] = dp[i - 1];
            dp[i][blocks[i] - 'A'] = dp[i][blocks[i] - 'A'] + 1; 
        }
    }
    ll ans = 0;
    for(int i = 0; i < q; i++) {
        ll l, r; cin>>l>>r;
        l--; r--;
        ll num_odd = 0;
        for(int j = 0; j < 26; j++) {
            int freq;
            if(l == 0) {
                freq = dp[r][j];
            } else {
                freq = dp[r][j] - dp[l - 1][j];
            }
            if(freq%2 == 1) {
                num_odd++;
            }
        }
        if(num_odd <= 1) {
            ans++;
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
