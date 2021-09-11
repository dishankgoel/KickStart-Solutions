#include<bits/stdc++.h>
#define ll long long

using namespace std;

int check_ap(ll a, ll b, ll c) {
    if(c - b == b - a) {
        return 1;
    }
    return 0;
}

int set_ans(ll a, ll b, ll c, ll d, ll mid, ll e, ll f, ll g, ll h) {
    int ans = 0;
    if(check_ap(a, b, c)) {ans++;}
    if(check_ap(a, d, f)) {ans++;}
    if(check_ap(f, g, h)) {ans++;}
    if(check_ap(h, e, c)) {ans++;}
    if(check_ap(a, mid, h)) {ans++;}
    if(check_ap(f, mid, c)) {ans++;}
    if(check_ap(d, mid, e)) {ans++;}
    if(check_ap(b, mid, g)) {ans++;}
    return ans;
}

int test_case() {
    int ans = 0;
    ll a,b,c;cin>>a>>b>>c;
    ll d,e;cin>>d>>e;
    ll f,g,h;cin>>f>>g>>h;
    if((a + h)%2 == 0) {
        ans = max(ans, set_ans(a, b, c, d, (a + h)/2 , e, f, g, h));
    }
    if((c + f)%2 == 0) {
        ans = max(ans, set_ans(a, b, c, d, (c + f)/2 , e, f, g, h));
    }
    if((e + d)%2 == 0) {
        ans = max(ans, set_ans(a, b, c, d, (e + d)/2 , e, f, g, h));
    }
    if((g + b)%2 == 0) {
        ans = max(ans, set_ans(a, b, c, d, (g + b)/2 , e, f, g, h));
    }
    return ans;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        int ans = test_case();
        cout<<"Case #"<<case_no+1<<": "<<ans<<"\n";
    }
}
