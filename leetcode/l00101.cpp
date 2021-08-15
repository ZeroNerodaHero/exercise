class Solution {
public:
    bool dfs(string& s, int n, string& p, int m){
        if(dp[n][m] >= 0){
            return dp[n][m];
        }
        bool ret = 0;
        
        if(p[m-1] == '*'){
            ret = dfs(s,n,p,m-2);
            if(!ret && (p[m-2] == s[n-1] || p[m-2] == '.')){
                ret = dfs(s,n-1,p,m);
            }
        } else{
            if(p[m-1] == s[n-1] || p[m-1] == '.') 
                ret = dfs(s, n-1, p, m-1);
        }
        dp[n][m] = ret;
        return ret;
    }
    bool isMatch(string s, string p) {
        int ns = s.size(), np = p.size();
        memset(dp,-1,sizeof(dp)); dp[0][0] = 1;
        for(int i = 1; i <= ns; i++) dp[i][0] = 0;
        for(int i = 1; i <= np; i++){
            if(p[i-1] == '*') dp[0][i] = dp[0][i-2];
            else dp[0][i] = 0;
        }
        return dfs(s,ns,p,np);  
    }
    int dp[32][32];
};
