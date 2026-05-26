class Solution {
public:
    int arrayPairSum(vector<int>& nums) {

        int n = nums.size();
        sort( nums.begin() , nums.end() );

        int sum = 0 ;
        for( int i = 0 ; i < n; i += 2) sum += nums[i];
        return sum;
        
    }
};
//1 2 2 5 6 6 
// 1 2 3 4