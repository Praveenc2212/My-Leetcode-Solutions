class Solution {
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        stack<int > st ;

        for(int i = 0;i < n ;i++ ){

            int a = num[i] - '0';
            while( st.size() > 0 && st.top() > a && k > 0 ){
                st.pop();
                k--;
            }
            st.push( a );
// 1 4 
        }

        string ans = "";
        while( !st.empty()){
            ans+= to_string(st.top());
            st.pop();
        }
        int i = 0 ;
        reverse(ans.begin() , ans.end());

        for(i = 0 ;i < ans.size() ;i++) if( ans[i] != '0') break;
        ans = ans.substr(i);
        cout<<ans<<endl;
        // if( ans.size()  < k ) return "0";
        ans = ans.substr( 0 , ans.size() - k );
        if(ans.size() == 0 || ans.size() <= k  ) return "0";

        return ans;
    }
};