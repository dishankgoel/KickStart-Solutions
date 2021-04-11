#include<bits/stdc++.h>
#define ll long long

using namespace std;


bool compare(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.first < b.first) {
        return true;
    } else {
        return false;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        ll n, k; cin>>n>>k;
        vector<pair<ll, ll>> intervals;
        for(ll i = 0; i < n; i++) {
            ll s, e;cin>>s>>e;
            intervals.push_back(make_pair(s, e));
        }
        ll ans = 0;
        ll curr_end = 0;
        sort(intervals.begin(), intervals.end(), compare);
        for(ll i = 0; i < n; i++) {
            ll s = intervals[i].first;
            ll e = intervals[i].second;
            ll start = 0;
            if(curr_end >= e) {
                continue;
            }
            if(curr_end <= s) {
                start = s;
            } else {
                start = curr_end;
            }
            ll to_put = ceil((float)(e - start)/(float)k);
            ans += to_put;
            curr_end = start + to_put*k;
        }
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
