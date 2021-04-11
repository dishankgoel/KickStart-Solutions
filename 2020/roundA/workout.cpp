#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        double n,k;cin>>n>>k;
        vector<double> minutes;
        for(double i = 0; i < n; i++) {
            double in; cin>>in;
            minutes.push_back(in);
        }
        double b = 1;
        double e = minutes[n - 1] - minutes[0];
        ll ans = e;
        while(b < e) {
            ll mid = b + (e - b)/2;
            // cout<<b<<" "<<e<<" "<<mid<<"\n";
            double req_k = 0;
            for(double i = 1; i < n; i++) {
                double d = minutes[i] - minutes[i-1]; 
                if(d > mid) {
                    req_k += ceil((double)d/(double)mid) - 1;
                }
            }
            if(req_k <= k) {
                e = mid;
                ans = min(ans, mid);
            } else {
                b = mid + 1;
            }
        }
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
