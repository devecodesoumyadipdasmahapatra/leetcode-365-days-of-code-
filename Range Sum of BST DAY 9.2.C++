//1st : all passed 
bool purple(string &s) {
    if(s.size()<2) return false;
    int r = 0, b=0;

    for(int i = 0 ; i<s.size() ; i++){
        if(s[i]=='R') r++;
        else b++;
    }

    if(min(r,b)>=1) return true;
    return false;
}


//2nd: all passed 
long long kJumps(int n, int k, vector <int> &a) {
     vector<int> dp(n,0);
      long long ans = 0 ;
     for(int i = 0 ; i<n ; i++){
        if(i-k>=0) dp[i]=a[i]+dp[i-k];
        else dp[i]=a[i];
        
        if(dp[i]>ans) ans = dp[i];
     }

     return ans;
}
    
    
//3rd: all passed 

int solve(int index , int n , int k , string &s , char ch, vector<vector<int>> &dp ){
    if(index>=n) return 0;

    if(dp[index][ch]!=-1) return dp[index][ch];
    map<char,int> frq;
    for(int i = index ; i<index+k ; i++){
            frq[s[i]]++;
    }

   int mini = INT_MAX;
   for(auto it : frq){
       if(ch==it.first) continue;

       int temp = solve(index+k,n,k,s,it.first,dp) ;
       mini = min(mini, temp+abs(it.second-k));
   }
   return dp[index][ch]=mini;
}


int differenceInConsecutive(int n, int k, string s) {
   vector<vector<int>> dp(n+1, vector<int>(256,-1));
   return solve(0,n,k,s,'-',dp);
}


//4th: 10/11 passed… optimise and reply to this if anyone can 

vector<int> findMagicalNumbers(int n, int k, vector<int> a) {

   vector<int> ans;

   set<int> s;

   unordered_set<int> check;

   int sum=0;

   for(int i = 0 ; i<n ; i++){

       sum+=a[i];

       check.insert(sum);

   }

   sum = 0;

   for(int i = 0 ; i<n ; i++){

      sum+=a[i];

      check.insert(sum);

      if(sum!=a[i+1] && sum<=k ){

         for(int j = sum ; j<=k ; j++){

         if(check.find(sum+j)!=check.end()) break;

            s.insert(j);

        }

      }  

   }

   for(auto it:s) ans.push_back(it);

   return ans;

}
