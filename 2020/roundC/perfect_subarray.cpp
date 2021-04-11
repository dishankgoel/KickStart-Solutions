#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    scanf("%d", &t);
    // cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        int n;
        scanf("%d", &n);
        // cin>>n;
        vector<int> a(n);
        ll offset = 0;
        for(int i = 0; i < n; i++) {
            // cin>>a[i];
            scanf("%d", &a[i]);
            offset += abs(a[i]);
        }
        ll ans = 0;
        ll curr = 0;
        // unordered_map<ll, ll> seen;
        vector<ll> seen(2*offset + 10);
        seen[offset] = 1;
        for(int i = 0; i < n; i++) {
            curr += a[i];
            for(int j = 0; j*j <= curr + offset; j++) {
                ans += seen[curr + offset - j*j];
            }
            seen[curr + offset]++;
        }
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
