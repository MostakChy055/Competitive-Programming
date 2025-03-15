#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int>dx{1, 0}, dy{0, 1};

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>>vc(n, vector<int>(m)), dp(n, vector<int>(m));
    for(int i = 0; i < n; i += 1){
        for(int j = 0; j < m; j += 1) cin >> vc[i][j];
    }
    function<void(int x, int y)> dfs = [&](int x, int y){
        queue<pair<int, int>>q; q.push({x, y});
        while(!q.empty()){
            auto[X, Y] = q.front(); q.pop();
            for(int i = 0; i < 2; i += 1){
                int nwX = X + dx[i], nwY = Y + dy[i];
                if(nwX < n && nwY < m){
                    dp[nwX][nwY] = dp[x][y] + 1; q.push({nwX, nwY});
                }
            }
        }
    };
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