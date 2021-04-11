#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll p = 1000000000;


pair<ll, ll> solve(string s, ll repeat) {
    int n = s.size();
    int i = 0;
    ll delta_x = 0;
    ll delta_y = 0;
    unordered_map<ll, ll> ending;
    stack<int> st;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            st.push(i);
        } else if(s[i] == ')') {
            int e = st.top();
            ending[e] = i;
            st.pop();
        }
    }
    while(i < n) {
        if(s[i] > '1' && s[i] <= '9') {
            int e = ending[i + 1];
            string sub(s.substr(i + 2, (e - 1) - (i + 2) + 1 ));
            pair<ll, ll> sub_ans = solve(sub, s[i] - 48);
            delta_x = ((delta_x + sub_ans.first%p)%p + p)%p;
            delta_y = ((delta_y + sub_ans.second%p)%p + p)%p;
            i = e + 1;
        } else {
            if(s[i] == 'N') {
                delta_y = ((delta_y - 1)%p + p)%p;
            } else if (s[i] == 'S') {
                delta_y = ((delta_y + 1)%p + p)%p;
            } else if(s[i] == 'E') {
                delta_x = ((delta_x + 1)%p + p)%p;
            } else {
                delta_x = ((delta_x - 1)%p + p)%p;
            }
            i++;
        }
    }
    pair<ll, ll> ans = make_pair(delta_x*repeat, delta_y*repeat);
    return ans;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        string s;
        cin>>s;
        pair<ll, ll> ans = solve(s, 1); 
        cout<<"Case #"<<case_no+1<<": "<<(ans.first%p + p)%p + 1<<" "<<(ans.second%p + p)%p + 1<<"\n";
    }
}
