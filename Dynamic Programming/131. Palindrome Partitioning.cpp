#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    string s; cin >> s;
    int n = s.length();
    vector<bool>khela(n); khela[0] = 1;
    vector<vector<bool>>dp(n, vector<bool>(n));
    for(int i = 0; i < n; i += 1) dp[i][i] = 1;

    for(int i = 0; i < n; i += 1){
        for(int j = 0; j < i + 1; j += 1){
            if(s[i] == s[j]) dp[i][j] = 1;
            else if(s[i] == s[j] && dp[i - 1][j + 1]) dp[i][j] = 1;

            if(dp[i][j] && j - 1 >= 0)  khela[i] = khela[i] | khela[j - 1];
        }
    }
    
    vector<string>vs;
    vector<vector<string>>ans;

    function<void(int index)> dfs = [&](int index){
        if(index < 0){
            ans.emplace_back(vs);
            return;
        }

        for(int i = index; i >= 0; i -= 1){
            for(int j = 0; j < i + 1; j += 1){
                if(dp[i][j] && ((j - 1 >= 0 && khela[j - 1]) || j - 1 < 0)){
                    vs.push_back(s.substr(j, i - j + 1));
                    dfs(j - 1);
                    vs.pop_back();
                }
            }
        }
    };
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i += 1)
        solve();

    return 0;
}