#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        int n; cin>>n;
        vector<int> h;
        for(int i = 0; i < n; i++) {
            int a; cin>>a;
            h.push_back(a);
        }
        int ans = 0;
        for(int i = 1; i < n - 1; i++) {
            if(h[i] > h[i-1] && h[i] > h[i+1]) {
                ans++;
            }
        }
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
