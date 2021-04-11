#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll num(vector<vector<int>> grid, int r, int c) {
    vector<vector<pair<int, int>>> chain(r, vector<pair<int, int>>(c, make_pair(0, 0)));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(grid[i][j] == 1) {
                if(i == 0 && j == 0) {
                    chain[i][j] = make_pair(grid[0][0], grid[0][0]);
                } else if(i == 0) {
                    chain[i][j] = make_pair(chain[i][j - 1].first + 1, grid[i][j]);
                } else if(j == 0) {
                    chain[i][j] = make_pair(grid[i][j], chain[i - 1][j].second + 1);
                } else {
                    chain[i][j] = make_pair(chain[i][j - 1].first + 1, chain[i - 1][j].second + 1);
                }
            } else {
                chain[i][j] = make_pair(0, 0);
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i < r; i++) {
        for(int j = 1; j < c; j++) {
            if(grid[i][j] == 1) {
                int a = chain[i][j].first, b = chain[i][j].second;
                if(b >= 2) {
                    ans += min(b/2, a) - 1;
                }
                if(a >= 2) {
                    ans += min(a/2, b) - 1;
                }
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        ll r, c; cin>>r>>c;
        ll ans = 0;
        vector<vector<int>> grid(r, vector<int>(c, 0));
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cin>>grid[i][j];
            }
        }
        ans += num(grid, r, c);
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c/2; j++) {
                int temp = grid[i][j];
                grid[i][j] = grid[i][c - 1 - j];
                grid[i][c - 1 - j] = temp;
            }
        }
        ans += num(grid, r, c);
        for(int j = 0; j < c; j++) {
            for(int i = 0; i < r/2; i++) {
                int temp = grid[i][j];
                grid[i][j] = grid[r - 1 - i][j];
                grid[r - 1 - i][j] = temp;
            }
        }
        ans += num(grid, r, c);
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c/2; j++) {
                int temp = grid[i][j];
                grid[i][j] = grid[i][c - 1 - j];
                grid[i][c - 1 - j] = temp;
            }
        }
        ans += num(grid, r, c);
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}