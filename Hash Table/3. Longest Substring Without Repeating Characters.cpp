#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    string s; cin >> s;
    map<char, int>freq;
    int n = s.length(), ans = 0, last = 0;
    for(int i = 0; i < n; i += 1){
        if(freq[s[i]]){
            ans = max(ans, i + 1 - last);
            last = freq[s[i]];
        } 
        else if(i == n - 1) ans = max(ans, i - last + 2);
        
        freq[s[i]] = i + 1;
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