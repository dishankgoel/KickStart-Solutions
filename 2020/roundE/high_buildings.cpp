#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        ll n, a, b, c;
        cin>>n>>a>>b>>c;
        int ans = 0;
        vector<int> vals;
        if(c > 1) {
            for(int i = 0; i < a - c; i++) {
                vals.push_back(1);
            }
            vals.push_back(n);
            for(int i = 0; i < n - (a + b - c); i++) {
                vals.push_back(1);
            }
            for(int i = 0; i < c - 1; i++) {
                vals.push_back(n);
            }
            for(int i = 0; i < b - c; i++) {
                vals.push_back(1);
            }
            ans = (vals.size() == n);
        } else {
            if(n == 1) {
                if(a == 1 && b == 1) {
                    vals.push_back(1);
                    ans = 1;
                } else {
                    ans = 0;
                }
            } else if(n == 2) {
                if((a == 1 && b == 1) || (a == 2 && b == 2)) {
                    ans = 0;
                } else {
                    ans = 1;
                    if(a == 1 && b == 2) {
                        vals.push_back(2);
                        vals.push_back(1);
                    } else if(a == 2 && b == 1) {
                        vals.push_back(1);
                        vals.push_back(2);
                    }
                }
            } else {
                if(a > 1) {
                    for(int i = 0; i < a - 1; i++) {
                        vals.push_back(2);
                    }
                    for(int i = 0; i < n - (a + b - 1); i++) {
                        vals.push_back(1);
                    }
                    vals.push_back(n);
                    for(int i = 0; i < b - 1; i++) {
                        vals.push_back(1);
                    }
                    ans = (vals.size() == n);
                } else {
                    vals.push_back(n);
                    for(int i = 0; i < n - (a + b - 1); i++) {
                        vals.push_back(1);
                    }
                    for(int i  = 0; i < b - 1; i++) {
                        vals.push_back(2);
                    }
                    ans = (vals.size() == n);
                    if(b == 1) {
                        ans = 0;
                    }
                }
            }
        }
        if(ans) {
            cout<<"Case #"<<case_no+1<<": ";
            for(int i = 0; i < n; i++) {
                cout<<vals[i]<<" ";
            }
            cout<<"\n";
        } else {
            cout<<"Case #"<<case_no+1<<": IMPOSSIBLE\n";
        }
        
    }
}
