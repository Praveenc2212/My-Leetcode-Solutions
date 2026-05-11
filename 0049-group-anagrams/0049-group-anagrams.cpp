class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<string,vector<string> > mp;

        int n = strs.size();

        for( string s : strs ){
            string tem = s;
            sort(tem.begin() ,tem.end());
            mp[tem].push_back(s);
        }

        vector<vector<string>> ans;
        int i = 0 ;
        for( auto &it : mp ){
            
            ans.push_back( it.second);

        }
        return ans;
        
    }
};