#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    string s1, s2, s3; cin >> s1 >> s2 >> s3;
    int n = s1.length(), m = s2.length();
    vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1;
    for(int i = 1; i < n + 1; i += 1) dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
    for(int i = 1; i < m + 1; i += 1) dp[0][i] = dp[0][i - 1] && (s2[i - 1] == s3[i - 1]);

    for(int i = 1; i < n + 1; i += 1){
        for(int j = 1; j < m + 1; j += 1)
            dp[i][j] = ((dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]));
    }
    cout << (dp[n][m]?"True\n": "False\n");
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