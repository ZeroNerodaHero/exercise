class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.size(), np = p.size();
        bool dp[ns+1][np+1];
        memset(dp,0,sizeof(dp));
        
        dp[0][0] = 1;
        for(int j = 1; j <= np; j++){
            if(p[j-1] == '*') dp[0][j] = dp[0][j-2];
        }
        for(int i = 1; i <= ns; i++){
            for(int j = 1; j <= np; j++){
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-2];
                    if(!dp[i][j] && (p[j-2] == '.' || p[j-2] == s[i-1])){
                        dp[i][j] |= dp[i-1][j];
                    }
                } else{
                    if(p[j-1] == '.' || p[j-1] == s[i-1]){
                        dp[i][j] = dp[i-1][j-1];
                    }
                }
            }
        }
        return dp[ns][np];   
    }
};
