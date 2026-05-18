class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& qs ) 
    {
        int n = s.size();
        
        vector<int> prev( n );
        vector<int> next( n );

        prev[0] = (s[0] == '|') ? 0 : -1  ;
        for( int i = 1 ;i < n ; i +=  1 ) {
            if(s[i] == '|' )
                prev[i] = i;
            else 
                prev[i] = prev[i-1];
        }
 
        next[n-1] = (s[n-1] == '|') ? n-1 : -1 ; 

        for( int i = n-2 ;i >= 0 ; i -=1 ){
            if( s[i] == '|' ){ 
                next[i] = i ; 
            }
            else{
                next[i] = next[i+1];
            }
        }

        vector<int> prefix( n ) ;
        prefix[0] =( s[0] == '*') ? 1 : 0;
        for(int i = 1 ; i < n ; i += 1){
            if(s[i] == '*')
               prefix[i] = prefix[i-1] + 1 ;
            else 
                prefix[i] = prefix[i-1];
        }

        vector<int>ans;


        for(auto &q : qs ){
            int l = q[0];
            int r = q[1];
            
            int left = next[l];
            int right = prev[r];

            if( left == -1 || right == -1 || left >= right ){
                ans.push_back(0);
            }
            else{
                int cnt = prefix[right] - prefix[left];
                ans.push_back(cnt);
            }

        }

        return ans;
    }
};