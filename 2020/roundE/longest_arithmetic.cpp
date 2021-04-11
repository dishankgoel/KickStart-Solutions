#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        int n; cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin>>a[i];
        }
        int curr_diff = a[1] - a[0];
        int ans = 2;
        int curr_ans = 2;
        for(int i = 2; i < n; i++) {
            if(a[i] - a[i - 1] == curr_diff) {
                curr_ans++;
            } else {
                curr_ans = 2;
                curr_diff = a[i] - a[i - 1];
            }
            ans = max(ans, curr_ans);
        }
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
