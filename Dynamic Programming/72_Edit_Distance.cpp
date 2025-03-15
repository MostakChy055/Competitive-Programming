#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    string word1, word2; cin >> word1 >> word2;
    int n = word1.length(), m = word2.length();
    vector<vector<int>>dp(n + 1, vector<int>(m + 1, INT_MAX));
    for(int i = 0; i < n + 1; i += 1) dp[i][0] = i;
    for(int j = 0; j < m + 1; j += 1) dp[0][j] = j;
    for(int i = 1; i < n + 1; i += 1){
        for(int j = 1; j < m + 1; j += 1){
            if(word1[i - 1] != word2[j - 1]) dp[i][j] = min(dp[i][j], min(dp[i - 1][j - 1] + 1, dp[i][j - 1] + 1, dp[i - 1][j] + 1));
            else dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
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