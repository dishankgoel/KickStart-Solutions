#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll test_case() {
    ll r,c; cin>>r>>c;
    string grid[r];
    for(int i = 0; i < r; i++) {
        cin>>grid[i];
    }
    ll ans = 1e10;
    for(ll posx = 0; posx < r; posx++) {
        for(ll posy = 0; posy < c; posy++) {
            ll orig = grid[posx][posy]; 
            grid[posx][posy] = '1';
            ll cost = 0;
            for(ll currx = 0; currx < r; currx++) {
                for(ll curry = 0; curry < c; curry++) {
                    ll curr_cost = 1e10;
                    if(grid[currx][curry] == '1') {
                        curr_cost = 0;
                    } else {
                        for(ll i = 0; i < r; i++) {
                            for(ll j = 0; j < c; j++) {
                                if(grid[i][j] == '1') {
                                    curr_cost = min(curr_cost, abs(currx - i) + abs(curry - j));
                                }
                            }
                        }
                    }
                    cost = max(cost, curr_cost);
                }
            }
            grid[posx][posy] = orig;
            ans = min(ans, cost);
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
