#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    string s, t; cin >> s >> t;
    int n = s.length(), m = t.length();
    vector<vector<int>>dp(n + 1, vector<int>(m + 1));

    for(int i = 0; i < n + 1; i += 1) dp[i][0] = 1;
    for(int i = 1; i < n + 1; i += 1){
        for(int j = 1; j < m + 1; j += 1){
            dp[i][j] = dp[i - 1][j] + (s[i - 1] == t[j - 1]?dp[i - 1][j - 1]: 0);
        }
    }
    cout << dp[n][m] << '\n';
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