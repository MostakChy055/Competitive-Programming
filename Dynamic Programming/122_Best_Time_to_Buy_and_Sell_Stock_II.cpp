#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n, N = 1e4 + 5, ans = 0; cin >> n;
    vector<int>prices(n), dp(n + 1), lastChilo(N);
    for(int &i: prices) cin >> i;
    for(int i = 0; i < n; i += 1){
        dp[i + 1] = dp[i];
        for(int j = prices[i] - 1; j >= 0; j -= 1){
            int index = lastChilo[j];
            if(index) dp[i + 1] = max(dp[i + 1], prices[i] - j + dp[index - 1]);
        }
        lastChilo[prices[i]] = i + 1;
    }
    cout << dp[n] << '\n';
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