class Solution {
public:
    int findMiddleIndex(vector<int>& nums){


        int n = nums.size();

        vector<int>pre(n),suf(n);
        pre[0] = nums[0];
        for(int i= 1; i< n ;i +=1 ){
            pre[i] = pre[i-1] + nums[i];
        }
        suf[n-1] = nums[n-1];
        for( int i = n-2 ; i >= 0 ; i -= 1 ){
            suf[i] = suf[i+1] + nums[i];
        }

        for( int i = 0 ; i < n; i += 1 ){
            int left = 0 , right = 0 ;
            if( i-1 >= 0) left = pre[i-1];
            if( i + 1 < n ) right = suf[i+1];
            if( left == right) return i;
        }
        return -1;
    }
};