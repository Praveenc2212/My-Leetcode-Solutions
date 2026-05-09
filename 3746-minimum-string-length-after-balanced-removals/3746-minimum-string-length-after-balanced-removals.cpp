class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int n = s.length();

        int cnt = 0;
        for(int i = 0; i < n; i += 1)
            cnt += s[i] == 'a' ? +1 : -1;

        return abs(cnt);
    }
};