#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll valid(int i, int j, int r, int c) {
    if(i >= 0 && i < r && j >= 0 && j < c) {
        return 1;
    }
    return 0;
} 


ll test_case() {
    ll r,c; cin>>r>>c;
    string grid[r];
    for(int i = 0; i < r; i++) {
        cin>>grid[i];
    }
    ll max_dist[r][c];
    vector<vector<ll>> vis(r, vector<ll>(c, 0));
    queue<pair<int, int>> Q;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(grid[i][j] == '1') {
                Q.push(make_pair(i, j));
                vis[i][j] = 1;
                max_dist[i][j] = 0;
            }
        }
    }
    while(!Q.empty()) {
        pair<int, int> curr = Q.front(); int i = curr.first, j = curr.second;
        if(valid(i + 1, j, r, c) && !vis[i + 1][j]) {
            vis[i + 1][j] = 1;
            max_dist[i + 1][j] = max_dist[i][j] + 1;
            Q.push(make_pair(i + 1, j));
        }
        if(valid(i - 1, j, r, c) && !vis[i - 1][j]) {
            vis[i - 1][j] = 1;
            max_dist[i - 1][j] = max_dist[i][j] + 1;
            Q.push(make_pair(i - 1, j));
        }
        if(valid(i, j + 1, r, c) && !vis[i][j + 1]) {
            vis[i][j + 1] = 1;
            max_dist[i][j + 1] = max_dist[i][j] + 1;
            Q.push(make_pair(i, j + 1));
        }
        if(valid(i, j - 1, r, c) && !vis[i][j - 1]) {
            vis[i][j - 1] = 1;
            max_dist[i][j - 1] = max_dist[i][j] + 1;
            Q.push(make_pair(i, j - 1));
        }
        Q.pop();
    }
    ll b = 0, e = r + c, ans = r + c;
    while(b <= e) {
        ll mid = b + (e - b)/2;
        int max_su = -1e7, min_sub = 1e7, max_sub = -1e7, min_su = 1e7;
        ll possible = 1;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(max_dist[i][j] > mid) {
                    max_su = max(max_su, i + j);
                    min_sub = min(min_sub, i - j);
                    max_sub = max(max_sub, i - j);
                    min_su = min(min_su, i + j);
                    possible = 0;
                }
            }
        }
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(max(max(max(abs(max_su - (i + j)), abs(min_sub - (i - j))), abs(max_sub - (i - j))), abs(min_su - (i + j))) <= mid) {
                    possible = 1;
                    break;
                }
            }
        }
        if(possible) {
            ans = mid;
            e = mid - 1;
        } else {
            b = mid + 1;
        }
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
