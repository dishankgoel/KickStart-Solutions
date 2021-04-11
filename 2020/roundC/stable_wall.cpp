#include<bits/stdc++.h>
#define ll long long

using namespace std;


vector<int> G[26];
stack<char> toposort;
vector<int> vis(26);
vector<int> instack(26);

int dfs(int node) {
    if(vis[node] == 1) {
        return 1;
    }
    vis[node] = 1;
    instack[node] = 0;
    int status = 1;
    for(int i = 0; i < G[node].size(); i++) {
        int child = G[node][i];
        if(vis[child] == 1 && instack[child] == 0) {
            return 0;
        }
        status &= dfs(child);
    }
    instack[node] = 1;
    toposort.push(node + 65);
    return status;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    for(int case_no = 0; case_no < t; case_no++) {
        for(int i = 0; i < 26; i++) {
            G[i] = vector<int>();
        }
        vis = vector<int>(26);
        instack = vector<int>(26);
        toposort = stack<char>();
        vector<int> isnode(26);
        vector<int> isdomino(26);
        int r,c;cin>>r>>c;
        char wall[r][c];
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                cin>>wall[i][j];
                isdomino[wall[i][j] - 65] = 1;
            }
        }
        for(int i = r - 1; i > 0; i--) {
            for(int j = c - 1; j >= 0; j--) {
                if(wall[i][j] != wall[i-1][j]) {
                    int u = wall[i][j] - 65;
                    int v = wall[i-1][j] - 65;
                    G[u].push_back(v);
                    isnode[u] = 1;
                    isnode[v] = 1;
                }
            }
        }
        int ifpos = 1;
        for(int i = 0; i < 26; i++) {
            if(isnode[i] == 1) {
                ifpos &= dfs(i);
            }   
        }
        vector<int> done(26);
        if(ifpos) {
            string ans;
            while(!toposort.empty()) {
                char c = toposort.top();
                done[c - 65] = 1;
                ans.push_back(c);
                toposort.pop();
            }
            for(int i = 0; i < 26; i++) {
                if(isdomino[i] == 1 && done[i] != 1) {
                    ans.push_back((char)(i + 65));
                }
            }
            cout<<"Case #"<<case_no+1<<": "<< ans <<"\n";
        } else {
            cout<<"Case #"<<case_no+1<<": "<< -1 <<"\n";
        }
    }
}
