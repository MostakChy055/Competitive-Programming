#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    string s; cin >> s;
    int n = s.length(), ans = 0;
    vector<int>dp(n);
    deque<int>prev;
    for(int i = 0; i < n; i += 1){
        if(s[i] == '(') prev.push_back(i);
        else if(!prev.empty()){
            int index = prev.back(); prev.pop_back();
            ans = max(ans, (index - 1 >= 0? dp[index - 1]: 0) + (i - index + 1));
            dp[i] = (index - 1 >= 0? dp[index - 1]: 0) + (i - index + 1);
        }
    }
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