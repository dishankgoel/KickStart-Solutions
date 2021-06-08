#include<bits/stdc++.h>
#define ll long long

using namespace std;

pair<ll, ll> split_direction(ll arr[], ll target, ll N, ll w) {
    ll ans1 = 0, ans2 = 0;
    ll b = 0, e = target;
    while(b <= e) {
        ll mid = b + (e - b)/2;
        if(N - (arr[target] - arr[mid]) < arr[target] - arr[mid]) {
            b = mid + 1;
        } else if(N - (arr[target] - arr[mid]) > arr[target] - arr[mid]) {
            e = mid - 1;
        } else {
            ans1 = mid;
            break;
        }
        ans1 = mid;
    }
    b = target; e = w - 1;
    while(b <= e) {
        ll mid = b + (e - b)/2;
        if(N - (arr[mid] - arr[target]) < arr[mid] - arr[target]) {
            e = mid - 1;
        } else if(N - (arr[mid] - arr[target]) > arr[mid] - arr[target]) {
            b = mid + 1;
        } else {
            ans2 = mid;
            break;
        }
        ans2 = mid;
    }
    return make_pair(ans1, ans2);
}

ll test_case(ll arr[], ll N, ll w) {
    ll ans = w*N; 
    ll presum[w];
    sort(arr, arr + w);
    presum[0] = arr[0];
    for(int i = 1; i < w; i++) {
        presum[i] = presum[i - 1] + arr[i];
    }
    for(int i = 0; i < w; i++) {
        pair<ll, ll> splits = split_direction(arr, i, N, w);
        ll i1 = splits.first, i2 = splits.second;
        ll temp = 0;
        // Add left of i
        temp += ((i - i1)*arr[i]) - (presum[i] - presum[i1]);
        if(i1 != 0) {
            temp += i1*N - (i1*arr[i] - presum[i1 - 1]);
        }
        temp += min(N - (arr[i] - arr[i1]), arr[i] - arr[i1]);
        // Add right of i
        if(i2 != i) {
            temp += (presum[i2 - 1] - presum[i]) - (i2 - 1 - i)*arr[i];
        }
        temp += (w - 1 - i2)*N - ((presum[w - 1] - presum[i2]) - (w - 1 - i2)*arr[i]);
        temp += min(N - (arr[i2] - arr[i]), arr[i2] - arr[i]);
        ans = min(ans, temp);
    }
    return ans;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        ll w, n; cin>>w>>n;
        ll arr[w];
        for(int i = 0; i < w; i++) {
            cin>>arr[i];
        }
        ll ans = test_case(arr, n, w);
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
