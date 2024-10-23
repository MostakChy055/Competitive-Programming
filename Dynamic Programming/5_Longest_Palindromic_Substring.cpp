#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    string s, mxString; cin >> s;
    int n = s.length(), mx = 1; mxString = s[0];
    vector<vector<bool>>dp(n, vector<bool>(n));
    for(int i = 0; i < n; i += 1){
        dp[i][i] = true;
        for(int j = 0; j < i; j += 1){
            if(s[i] == s[j] && (i - j <= 2 || dp[i - 1][j + 1])){
                dp[i][j] = true;
                if(i - j + 1 > mx){
                    mx = i - j + 1; mxString = s.substr(j, (i - j + 1));
                }
            }
        }
    }
    cout << mxString << '\n';
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