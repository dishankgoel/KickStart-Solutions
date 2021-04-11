#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        ll n, k; cin>>n>>k;
        string s; cin>>s;
        ll ans = 0;
        ll eq = 0;
        ll noteq = 0;
        for(int i = 0; i < n/2; i++) {
            if(s[i] != s[n - (i + 1)]) {
                noteq++;
            }
        }
        ans = abs(k - noteq);
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
