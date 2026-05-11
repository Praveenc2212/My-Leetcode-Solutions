class Solution {
public:
    vector<vector<int>> ans ;
    vector<int> current ;
    int n ;
    void fun(int i , vector<int>&nums){
        if( i == n){
            ans.push_back(current);
            return ;
        }
        current.push_back(nums[i]);
        fun(i + 1 , nums );
        current.pop_back();
        fun( i + 1 , nums );

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        fun(0 , nums );
        return ans;
    }
};