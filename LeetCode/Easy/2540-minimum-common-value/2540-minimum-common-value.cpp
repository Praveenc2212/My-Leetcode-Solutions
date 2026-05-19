class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        set<int> st( nums2.begin() , nums2.end());
        for( int a : nums1){
            if(st.find( a) != st.end())
                return a;
        }    
        return -1 ;
    }
};