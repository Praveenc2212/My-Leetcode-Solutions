class Solution {
public:
    string convertToBase7(int num) {

        if( num == 0 ) return "0";

        vector<int> rem;

        int a = abs( num ); 
        while( a > 0 ) {
            int r = a % 7 ;
            a = a / 7;
            rem.push_back( r );
        }      
        string ans = "";
        if( num < 0 ) ans += "-";
        reverse( rem.begin() , rem.end() );
        for( int a : rem ) ans += to_string(a) ;
        return ans ;
    }
};