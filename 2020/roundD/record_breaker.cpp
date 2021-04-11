#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        int n; cin>>n;
        vector<int> v(n);
        int ans = n == 1 ? 1 : 0;
        for(int i = 0; i < n; i++) {
            cin>>v[i];
        }
        int curr_max = v[0];
        for(int i = 1; i < n-1; i++) {
            if(v[i] > curr_max) {
                curr_max = v[i];
                if(v[i] > v[i+1]) {
                    ans++;
                }
            }
        }
        if(n > 1) {
            if(v[0] > v[1]) {
                ans++;
            }
            if(v[n-1] > curr_max) {
                ans++;
            }
        }
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
