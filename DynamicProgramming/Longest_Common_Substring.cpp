int fun(string &str1, string &str2,vector<vector<int>> &dp,int idx1,int idx2,int &res){
    if (idx1 >= str1.size() || idx2 >= str2.size()) return 0;
    if (dp[idx1][idx2] != -1) return dp[idx1][idx2];
    int len = 0;
    if(str1[idx1] == str2[idx2]){
        len = 1 + fun(str1,str2,dp,idx1+1,idx2+1,res);
        res = max(res,len);
    }
    int a = fun(str1,str2,dp,idx1+1,idx2,res);
    int b = fun(str1,str2,dp,idx1,idx2+1,res);
    return dp[idx1][idx2] = len;
}
int lcs(string &str1, string &str2){
    int res = 0;
    vector<vector<int>> dp(str1.size(),vector<int>(str2.size(),-1));
    int ans = fun(str1,str2,dp,0,0,res);
    return res;
}