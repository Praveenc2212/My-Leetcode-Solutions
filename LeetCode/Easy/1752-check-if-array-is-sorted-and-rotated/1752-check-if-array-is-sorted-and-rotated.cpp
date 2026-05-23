class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int n = nums.size();
        int cnt = 0 ;

        for( int i =0 ; i < n - 1 ; i += 1 ){
            if( nums[i] <=nums[i+1]){
                continue;
            }
            else{
                cnt++;
            }
        }
        if( cnt != 0 && cnt<= 1 ){
            return nums[0] >= nums[n-1];
        }
        return cnt <= 1 ;
    }
};