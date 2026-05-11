class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {

        vector<int> ans;

        int n = nums.size();
        for( int i = n-1 ;i >=0 ; i -= 1 ){
            int a = nums[i];

            while( a > 0 ){
                int rem = a %10 ;
                ans.push_back( rem );
                a = a / 10;
            }
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};