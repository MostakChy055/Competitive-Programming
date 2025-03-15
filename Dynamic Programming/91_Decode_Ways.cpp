#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    string s; cin >> s;
    int n = s.length();
    if(s.empty()) return;
    vector<int>dp(n + 1); dp[0] = 1;
    dp[1] = (s[0] != '0');

    for(int i = 2; i < n + 1; i += 1){
        int value1 = (s[i - 1] - '0') + (s[i - 2] - '0') * 10;
        int value2 = (s[i - 1] - '0');
        if(value2 > 0 && value2 < 10) dp[i] += dp[i - 1];
        if(value1 > 9 && value1 < 27) dp[i] += dp[i - 2];
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