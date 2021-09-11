#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll test_case() {
    ll n,c; cin>>n>>c;
    unordered_map<ll, ll> additions, subtractions, seen;
    vector<ll> points;
    for(int i = 0; i < n; i++) {
        ll l, r; cin>>l>>r;
        if(additions.find(l) == additions.end()) {
            additions[l] = 1;
        } else {
            additions[l] += 1;
        }
        if(subtractions.find(l) == subtractions.end()) {
            subtractions[l] = 0;
        }
        if(subtractions.find(r) == subtractions.end()) {
            subtractions[r] = 1;
        } else {
            subtractions[r] += 1;
        }
        if(additions.find(r) == additions.end()) {
            additions[r] = 0;
        }
        if(seen.find(l) == seen.end()) {
            points.push_back(l);
            seen[l] = 1;
        }
        if(seen.find(r) == seen.end()) {
            points.push_back(r);
            seen[r] = 1;
        }
    }
    sort(points.begin(), points.end());
    vector<ll> count_overlap(n + 1, 0);
    ll curr_overlaps = additions[points[0]];
    count_overlap[curr_overlaps] += (points[1] - points[0] - 1);
    for(int i = 1; i < points.size() - 1; i++) {
        ll new_overlap = additions[points[i]];
        ll del_overlap = subtractions[points[i]];
        count_overlap[curr_overlaps - del_overlap] += 1;
        curr_overlaps += (new_overlap - del_overlap);
        count_overlap[curr_overlaps] += (points[i + 1] - points[i] - 1);
    }
    ll i = n;
    ll ans = n;
    while(c > 0 && i >= 0) {
        ll take = min(c, count_overlap[i]);
        ans += take*i;
        c -= take;
        i--;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        ll ans = test_case();
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
