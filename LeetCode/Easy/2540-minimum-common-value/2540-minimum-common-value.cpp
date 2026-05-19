class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();


        for( int a : nums1){
            int index = lower_bound( nums2.begin() , nums2.end() , a ) - nums2.begin();
            if( index < n2 && nums2[index] == a ){
                return a;
            }
        }    
        return -1 ;
    }
};