class Solution {
public:
    int n ;
    long long dp[1005];
    long long fun( int i , int target , vector<int>&nums ){

        if( i == n-1 ){
            return   0;
        }
        if( dp[i] != -1 ) return dp[i];
        long long ans = -1e18 ;
        
        for( int j = i + 1 ;j < n ; j += 1  ){
            int diff = nums[j] - nums[i] ;
            if( -target <= diff && diff <= target ){
                ans = max( ans , fun( j , target , nums  ) + 1 );
            }
        }
        return dp[i] =  ans;
    }
    int maximumJumps(vector<int>& nums, int target) 
    {
        n = nums.size();
        memset( dp , -1 , sizeof( dp) ) ;
        long long res = fun( 0 , target ,nums  );
        return res <= 0 ? -1 : res ;
    }
};