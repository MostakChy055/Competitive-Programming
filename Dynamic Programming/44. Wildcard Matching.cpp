#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    string s, p; cin >> s >> p;
    int n = s.length(), m = p.length();
    vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1;
    for(int i = 0; i < m && p[i] == '*'; i += 1) dp[0][i + 1] = 1;

    for(int i = 1; i < n + 1; i += 1){
        for(int j = 1; j < m + 1; j += 1){
            if(p[j - 1] == '*') dp[i][j] =  [i - 1][j] || dp[i][j - 1];
            else dp[i][j] = (dp[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '?'));
        }
    }

    cout << (dp[n][m]?"true": "false");
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    for(int i = 1; i <= t; i += 1)
        solve();

    return 0;
}