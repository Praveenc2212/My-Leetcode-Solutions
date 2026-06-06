class Solution {
public:
    int waysToSplitArray(vector<int>& nums){

        int n = nums.size();
        vector<long long>prev(n),suf(n);

        suf[n-1] = nums[n-1] ;

        prev[0]= nums[0];

        for( int i=  1 ;i < n ;i += 1 ) 
            prev[i] = prev[i-1] + nums[i];
        
        for( int i = n-2 ; i >= 0 ; i -= 1 )
            suf[i] = suf[i+1] + nums[i];
        
    

        int ans = 0 ; 
        for( int i = 0 ;i < n - 1  ; i += 1 ){
            long long left = prev[i];
            long long right = 0 ;
            if( i + 1 < n ) right = suf[i+1];
            if( left >= right){

                ans += 1 ;
            }
        }
        return ans;


        
    }
};