class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0) return 0;
        int len=0;
        vector<vector<int>> dp(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        for(int i=1;i<=matrix.size();++i){
            for(int j=1;j<=matrix[0].size();++j){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
                    len=max(len,dp[i][j]);
                }
            }
        }
        return len*len;
    }
};