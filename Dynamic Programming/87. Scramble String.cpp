class Solution {
    public:
        bool isScramble(string s1, string s2) {
            if(s1 == s2) return 1;
            int len = s1.length();
            vector<vector<vector<bool>>>dp(len + 1, vector<vector<bool>>(len + 1, vector<bool>(len + 1, false)));
    
            for(int i = 0; i < len; i += 1){
                for(int j = 0; j < len; j += 1) dp[i][j][1] = s1[i] == s2[j];
            }
    
            for(int k = 1; k <= len; k += 1){
                for(int i = 0; i + k < len + 1; i += 1){
                    for(int j = 0; j + k < len + 1; j += 1){
                        if(k == 1){
                            dp[i][j][k] = (s1[i] == s2[j]); continue;
                        }
                        for(int q = 1; q < k && !dp[i][j][k]; q += 1){
                            if((dp[i][j][q] && dp[i + q][j + q][k - q]) || (dp[i][j + k - q][q] && dp[i + q][j][k - q])) dp[i][j][k] = 1;
                        }
                    }
                }
            }
    
            return dp[0][0][len];
        }
    };