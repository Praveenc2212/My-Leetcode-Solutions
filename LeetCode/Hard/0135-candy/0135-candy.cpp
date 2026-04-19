class Solution {
public:
    int candy(vector<int>& nums)
    {
        int n =nums.size();
        vector<int> candy( n , 1  ); 
        

        for( int i = 0 ;i < n - 1 ;i++){
            if( nums[i] < nums[i+1] ){
                candy[i+1] = candy[i] + 1 ;
            }
        }

        for(int i= n-1 ;i > 0 ;i -=1 ){
            if( nums[i] < nums[i-1] && candy[i] >= candy[i-1] ){
                candy[i-1] = candy[i] + 1 ;
            }
        }


        int sum = accumulate( candy.begin() , candy.end() , 0 );
        return sum;
    }
};