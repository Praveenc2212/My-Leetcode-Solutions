class Solution {
public:
    int numberOfSpecialChars(string s )
    {
        set<char> st ;
        for( char c : s ) st.insert( c );
        
        set<char> vis;
        char a = 'a';
        cout<<char(a - 32)<<endl;
        int cnt = 0 ; 
        for( int i = 0 ;i < s.size()  ; i += 1 ){
            if( s[i] >= 'a' && s[i] <= 'z' && vis.find(s[i] ) ==vis.end()){
                if( st.find(char(s[i]- 32) ) != st.end()){
                    vis.insert( s[i] );
                    cnt++;
                }
            }
        }
        return cnt;

    }
};