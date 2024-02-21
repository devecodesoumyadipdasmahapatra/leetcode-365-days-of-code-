class Solution{
public:
     
    int mod = 1003; 
    int solve(string& s, int i, int j, int isTrue, vector<vector<vector<int>>>& dp){
        if(i>j){
            return 0;
        }
        if(i==j){
            if(isTrue==1){
                return s[i]=='T';
            }
            else{
                return s[i]=='F';
            }
        }
        
        if(dp[i][j][isTrue] != -1){
            return dp[i][j][isTrue];
        }
        
        int ways = 0;
        for(int index=i+1;index<=j-1;index+=2){
            int LT = solve(s, i, index-1, 1, dp)%mod;
            int RT = solve(s, index+1, j, 1, dp)%mod;
            
            int LF = solve(s, i, index-1, 0, dp)%mod;
            int RF = solve(s, index+1, j, 0, dp)%mod;
            
            if(s[index]=='&'){
                if(isTrue==1){
                   ways = (ways + (LT*RT)%mod)%mod; 
                }
                else{
                   ways = (ways + ((LT*RF)%mod + (RT*LF)%mod + (LF*RF)%mod)%mod)%mod;
                }
            }
            else if(s[index]=='|'){
                if(isTrue==1){
                    ways = (ways + ((LT*RF)%mod + (LF*RT)%mod + (LT*RT)%mod)%mod)%mod;
                }
                else{
                    ways = (ways + (LF*RF)%mod)%mod;
                }
            }
            else{
                if(isTrue==1){
                    ways = (ways + ((LT*RF)%mod + (LF*RT)%mod)%mod)%mod;
                }
                else{
                    ways = (ways + ((LT*RT)%mod + (LF*RF)%mod)%mod)%mod;
                }
            }
        }
        
        return dp[i][j][isTrue] = ways;
    }
    
    int countWays(int N, string S){
        int n=S.size();
        int i=0;
        int j=n-1;
        int isTrue = 1;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return solve(S, i, j, isTrue, dp);
    }
};
