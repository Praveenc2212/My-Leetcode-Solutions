class Solution {
public:

    int check( int i ,int j , string& s ){
        int n =  s.size();
        
        while( i < j ){
            if( s[i] != s[j ])
                return false;
            i++;
            j--;
        }
        return 1;
    }
    string longestPalindrome(string s) {

        int n = s.size();
        string ans = "";
        int ans_len = 0;

        for(int i = 0 ;i < n;i += 1 ){
            for(int j = i  ; j < n ; j += 1 ){
                if( check( i , j , s ) && ans_len <  j - i + 1  ){
                    ans_len = j - i + 1 ;
                    ans = s.substr( i ,  ans_len   ) ;
                }
            }
        }
        return ans;
        
    }
};