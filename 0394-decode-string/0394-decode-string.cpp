class Solution {
public:
    bool isDigit(string s) {
        if (s[0] >= '0' && s[0] <= '9') {
            return true;
        }
        return false;
    }
    string decodeString(string s) {

        int n = s.size();

        stack<string> st;
        int i = 0;
        while (i < n) {
            char c = s[i++];

            if (c != ']') {
                st.push(string(1, c));
            } else {
                string cur = "";
                int a;
                while (st.top() != "[") {
                    cur += st.top();
                    st.pop();
                }
                st.pop();

                string num = "";

                while (!st.empty() && isDigit(st.top())) {
                    num += st.top();
                    st.pop();
                }
                reverse(num.begin(), num.end());

                a = stoi(num);

                string newstring = "";
                for (int i = 0; i < a; i++)
                    newstring += cur;
                st.push(newstring);
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};