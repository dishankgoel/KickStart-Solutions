#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        ll n,d;cin>>n>>d;
        vector<ll> bus;
        for(ll i = 0; i < n; i++) {
            ll a; cin>>a;
            bus.push_back(a);
        }
        // Attempt #1
        // ll ans = d;
        // ll curr = n-1;
        // while (curr >= 0) {
        //     ll gap = bus[curr];
        //     if(ans%gap == 0) {
        //         curr--;
        //     } else {
        //         ans--;
        //     }
        // }
        // Attempt #2
        ll b = 1;
        ll e = d;
        ll ans = 1;
        while(b <= e) {
            ll mid = b + (e - b)/2;
            ll curr_day = mid;
            for(int i = 0; i < n; i++) {
                ll gap = bus[i];
                if(curr_day%gap != 0) {
                    curr_day = curr_day + (gap - curr_day%gap);
                }
            }
            if(curr_day <= d) {
                b = mid + 1;
                ans = max(ans, mid);
            } else {
                e = mid - 1;
            }
        }
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
