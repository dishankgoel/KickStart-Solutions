#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool compare(pair<ll, ll> a, pair<ll, ll> b) {
    if(a.first < b.first) {
        return true;
    } else if(a.first > b.first) {
        return false;
    } else {
        if(a.second < b.second) {
            return true;
        } else {
            return false;
        }
    }
} 


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        ll n,X; cin>>n>>X;
        vector<ll> a(n);
        vector<pair<ll, ll>> ans;
        for(ll i = 0; i < n; i++) {
            cin>>a[i];
            ll times = ceil((float)a[i]/(float)X);
            ans.push_back(make_pair(times, i + 1));
        }
        sort(ans.begin(), ans.end(), compare);
        cout<<"Case #"<<case_no+1<<": ";
        for(ll i = 0; i < n; i++) {
            cout<<ans[i].second<<" ";
        }
        cout<<"\n";
    }
}
