#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int m, n;
    string s = "leetcode";
    vector<string>wordDict{"leet", "code"};
    vector<bool>dp(n + 3);
    n = s.length(), m = wordDict.size();
    
    for(int i = 0; i < n; i += 1){
        if(i && !dp[i]) continue;
        for(int j = 0; j < m; j += 1){
            string str = wordDict[j]; 
            if(i + str.length() - 1 >= n) continue;

            bool yes = 1;
            int cnt = i;
            for(int k = 0; k < str.length(); k += 1){
                if(s[cnt] == str[k]) cnt += 1;
                else{
                    yes = 0; break;
                }
            }

            dp[i + str.length()] = dp[i + str.length()] | yes;
        }
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