#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll test_case(string s) {
    int n = s.size();
    ll ans = 0;
    ll curr_start = 0;
    for(int i = 4; i < n - 4; i++) {
        if(s.substr(i - 4, 4) == "KICK") {
            curr_start++;
        }
        if(s.substr(i, 5) == "START") {
            ans += curr_start;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        string s; cin>>s;
        ll ans = test_case(s);
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
