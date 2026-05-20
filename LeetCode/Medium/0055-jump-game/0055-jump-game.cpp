class Solution {
public:
    int n;
    int dp[100000];
    bool rec(int index , vector<int>&nums)
    {   

        if(index >= n)
            return false;
        if( index == n-1 ){
            return dp[index]=true;
        }
            if(dp[index]!=-1)
                    return dp[index];
            for(int i=1;i<=nums[index] ; i++){
            
           if(rec(index+i,nums))
                return dp[index]=true;
        }
        return dp[index]=false;
    }
    bool canJump(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,nums);
        
    }
};