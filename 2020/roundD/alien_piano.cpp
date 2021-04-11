#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        int n; cin>>n;
        vector<int> notes(n);
        for(int i = 0; i < n; i++) {
            cin>>notes[i];
        }
        int dp[n][4];
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = 0;
        dp[0][3] = 0;
        for(int i = 1; i < n; i++) {
            if(notes[i] > notes[i-1]) {
                dp[i][0] = min(dp[i-1][0], min(dp[i-1][1], min(dp[i-1][2], dp[i-1][3]))) + 1;
                dp[i][1] = min(dp[i-1][0], min(dp[i-1][1], min(dp[i-1][2], dp[i-1][3])) + 1);
                dp[i][2] = min(dp[i-1][0], min(dp[i-1][1], min(dp[i-1][2], dp[i-2][3]) + 1));
                dp[i][3] = min(dp[i-1][0], min(dp[i-1][1], min(dp[i-1][2], dp[i-1][3] + 1)));
            } else if(notes[i] < notes[i-1]) {
                dp[i][0] = min(dp[i-1][0] + 1, min(dp[i-1][1], min(dp[i-1][2], dp[i-1][3])));
                dp[i][1] = min(dp[i-1][0] + 1, min(dp[i-1][1] + 1, min(dp[i-1][2], dp[i-1][3])));
                dp[i][2] = min(dp[i-1][0] + 1, min(dp[i-1][1] + 1, min(dp[i-1][2] + 1, dp[i-1][3])));
                dp[i][3] = min(dp[i-1][0], min(dp[i-1][1], min(dp[i-1][2], dp[i-1][3]))) + 1;
            } else {
                dp[i][0] = min(dp[i-1][0], min(dp[i-1][1], min(dp[i-1][2], dp[i-1][3])) + 1);
                dp[i][1] = min(dp[i-1][1], min(dp[i-1][0], min(dp[i-1][2], dp[i-1][3])) + 1); 
                dp[i][2] = min(dp[i-1][2], min(dp[i-1][1], min(dp[i-1][0], dp[i-1][3])) + 1);
                dp[i][3] = min(dp[i-1][3], min(dp[i-1][1], min(dp[i-1][2], dp[i-1][0])) + 1);
            }
        }
        int ans = min(dp[n-1][0], min(dp[n-1][1], min(dp[n-1][2], dp[n-1][3])));
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
