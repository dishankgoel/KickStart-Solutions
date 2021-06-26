#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll boring_numbers(ll n) { 
    string s = to_string(n);
    ll d = s.size();
    ll ans = 0;
    ans += (5*(pow(5, d - 1) - 1))/4;
    ll dp[d + 1];
    dp[0] = 1;
    for(int i = 1; i < d + 1; i++) {
        int c = 0;
        int dig = s[i - 1] - 48;
        for(int k = 0; k <= dig; k++) {
            if(k%2 == i%2) {
                c++;
            }
        }
        if(dig%2 == i%2) {
            dp[i] = (dp[i - 1] - 1)*5 + c;
        } else {
            dp[d] = (dp[i - 1] - 1)*pow(5, d - i + 1) + c*pow(5, d - i);
            break;
        }
    }
    return ans + dp[d];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        ll l, r;
        cin>>l>>r;
        ll ans = boring_numbers(r) - boring_numbers(l - 1);
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
