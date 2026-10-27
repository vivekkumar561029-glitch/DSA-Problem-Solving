class Solution {
public:

    long long helper(vector<vector<int>>&matrix,long long i,long long j,vector<vector<int>>&dp){
        long long n=matrix[0].size();

     
        if(j < 0 || j>=n) return INT_MAX;

        if(i==0) return matrix[0][j];
           if(dp[i][j]!=-106) return dp[i][j];

        long long up=matrix[i][j] + helper(matrix,i-1,j,dp);
        long long ld=matrix[i][j] + helper(matrix,i-1,j-1,dp);
        long long rd=matrix[i][j] + helper(matrix,i-1,j+1,dp);

        return dp[i][j] = min(up,min(ld,rd));
    }
    long long minFallingPathSum(vector<vector<int>>& matrix) {
        long long  n=matrix.size();

        vector<vector<int>>dp(n,vector<int>(n,-106));

       
       long long ans=INT_MAX;
       for(long long j=0;j<n;j++){
        ans=min(ans,helper(matrix,n-1,j,dp));
       } 
       return ans;
    }
};