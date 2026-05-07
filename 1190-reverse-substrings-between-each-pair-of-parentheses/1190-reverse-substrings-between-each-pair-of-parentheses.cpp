class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";

        int n = s.length();

        stack<char> st;
        for(int i = 0; i < n; i += 1){
            if(s[i] != ')')
                st.push(s[i]);
            else{
                string part = "";
                while(st.top() != '('){
                    part += st.top();
                    st.pop();
                }
                st.pop();

                for(int j = 0;  j < part.size(); j+=1) {
                    st.push(part[j]);
                }
            }
        }
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
       reverse(ans.begin() , ans.end());
        return ans;
    }
};