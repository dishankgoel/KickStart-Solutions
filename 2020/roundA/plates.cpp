#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        int n,k,p; cin>>n>>k>>p;
        vector<vector<int>> plates;
        for(int i = 0; i < n; i++) {
            vector<int> a;
            int su = 0;
            for(int j = 0; j < k; j++) {
                int in; cin>>in;
                su += in;
                a.push_back(su);
            }
            plates.push_back(a);
        }
        int dp[n + 1][p + 1];
        for(int i = 0; i < n + 1; i++) {
            dp[i][0] = 0;
        }
        for(int j = 1; j < p + 1; j++) {
            dp[0][j] = INT_MIN;
        }
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < p + 1; j++) {
                dp[i][j] = 0;
                for(int picked = 0; picked < k + 1; picked++) {
                    if(picked == 0) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                    } else if(j - picked >= 0) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - picked] + plates[i - 1][picked - 1]);
                    }
                }
            }
        } 
        
        cout<<"Case #"<<case_no+1<<": "<<dp[n][p]<<"\n";
    }
}
