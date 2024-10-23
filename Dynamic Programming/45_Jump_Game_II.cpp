#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    vector<int>nums{2, 1};
    int n = nums.size();
    vector<int>dp(n, INT_MAX);
    int x = 1;  dp[0] = 0;
    for(int i = 0; i < n - 1; i += 1){
        for(int j = nums[i]; j >= 1; j -= 1)
            dp[min(n - 1, i + j)] = min(dp[min(n - 1, i + j)], dp[i] + 1);
    }

    int ans = dp[n - 1] == INT_MAX?-1: dp[n - 1];
    cout << ans << '\n';
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