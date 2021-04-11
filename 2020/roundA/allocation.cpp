#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        int n,b; 
        cin>>n>>b;
        vector<int> house;
        for(int i = 0; i < n; i++) {
            int cost;
            cin>>cost;house.push_back(cost);
        }
        sort(house.begin(), house.end());
        int ans = 0;
        int curr = 0;
        for(int i = 0; i < n; i++) {
            curr += house[i];
            if(curr > b) {
                break;
            }
            ans++;
        }
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
