#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        int n, k; cin>>n>>k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin>>a[i];
        }
        int i = 0;
        int check_c = 0;
        int curr_c = k - 1;
        int ans = 0;
        while( i < n) {
            if(check_c) {
                if(a[i] == curr_c) {
                    if(curr_c == 1) {
                        ans++;
                        check_c = 0;
                    } else {
                        curr_c--;
                    }
                    
                } else {
                    check_c = 0;
                }
            }
            if(a[i] == k) {
                check_c = 1;
                curr_c = k - 1;
            }
            i++;
        }
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
