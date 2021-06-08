#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll test_case(vector<vector<int>> grid) {
    int n = grid.size();
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll temp1 = 0, temp2 = 0;
        for(int j = 0; j < n; j++) {
            if(i + j < n) {
                temp1 += grid[i + j][j];
                temp2 += grid[j][i + j];
            }
        }
        ans = max(temp1, ans);
        ans = max(temp2, ans);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        int n; cin>>n;
        vector<vector<int>> grid(n , vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin>>grid[i][j];
            }
        }
        ll ans = test_case(grid);
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
