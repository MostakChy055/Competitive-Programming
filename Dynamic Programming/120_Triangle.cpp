#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n; cin >> n;
    vector<vector<int>>vc(n, vector<int>(n)), dp(n + 1, vector<int>(n + 1));
    for(int i = 0; i < n; i += 1){
        for(int j = 0; j < i + 1; j += 1) cin >> vc[i][j];
    }
    for(int i = 0; i < n; i += 1) dp[n - 1][i] = vc[n - 1][i];
    for(int i = n - 2; i >= 0; i -= 1){
        for(int j = 0; j < i + 1; j += 1) dp[i][j] = vc[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
    }
    cout << dp[0][0] << '\n';
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