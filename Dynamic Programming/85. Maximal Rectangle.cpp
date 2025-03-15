#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    vector<vector<char>>matrix;
    int n = matrix.size(), m = matrix[0].size();
    vector<int>height(m), left(m), right(m, n);
    vector<vector<int>>dp(n, vector<int>(m));
    int ans = 0;
    for(int i = 0; i < n; i += 1){
        for(int j = 0; j < m; j += 1)
            height[j] = (j?height[j - 1]: 0) + (matrix[i][j] == '1');

        int lastLeft = 0, lastRight = m;
        for(int j = 0; j < m; j += 1){
            if(matrix[i][j] == '1') left[j] = max(left[j], lastLeft);
            else left[j] = 0, lastLeft = j + 1;
        }
        for(int j = m - 1; j >= 0; j -= 1){
            if(matrix[i][j] == '1') right[j] = min(right[j], lastRight);
            else right[j] = 0, lastRight = j;
        }
        
        for(int j = 0; j < m; j += 1) ans = max(ans, (right[j] - left[j]) * height[j]);
    }
    cout << ans << '\n';
}

int main(void){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i += 1)
        solve();

    return 0;
}