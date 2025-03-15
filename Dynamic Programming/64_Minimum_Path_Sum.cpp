#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    vector<vector<int>>grid{{1, 3, 1},{1, 5, 1}, {4, 2, 1}};
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>>dp(n, vector<int>(m, INT_MAX));
    dp[0][0] = grid[0][0];
    for(int i = 0; i < n; i += 1){
        for(int j = 0; j < m; j += 1){
            if(i + 1 < n) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + grid[i + 1][j]);
            if(j + 1 < m) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + grid[i][j + 1]); 
        }
    }
    cout << dp[n - 1][m - 1] << '\n';
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