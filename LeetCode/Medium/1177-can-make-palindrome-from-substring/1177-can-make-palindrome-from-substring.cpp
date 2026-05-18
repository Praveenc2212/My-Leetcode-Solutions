using ll =  long long;
class Solution {
public:
    vector<ll> prefix;
    int n ;
    ll getXor(int l , int r ){

        ll val = prefix[r];
        if( l-1 >=0)
            val = val ^ prefix[l-1];
        return val;
       
    }


    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& qs) 
    {


        n = s.size();
        vector<int>nums;
        prefix.resize( n );
        for( char ch : s ){
            int val = ( 1 << ( ch - 'a' + 1 )  );
            nums.push_back(val);
        }
        prefix[0] = nums[0];
        for(int i =1;i < n;i++) 
        prefix[i] = prefix[i-1] ^ nums[i];

       

        vector<bool> ans;

        for( auto q : qs ){
            int l = q[0];
            int r = q[1];
            int k = q[2];

            ll xorr = getXor(l,r) ;

            int cnt = __builtin_popcount(xorr);
            int len = r - l + 1 ;
            if( len % 2 == 0 ){
                if(cnt/2 <= k) ans.push_back(true);
                else  ans.push_back(false);
            }else{
                if((cnt/2 )   <= k ) ans.push_back(true);
                else  ans.push_back(false);
            }
        }
        return ans;
    }
};