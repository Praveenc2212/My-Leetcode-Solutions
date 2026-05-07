class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {

        int n = s.size();

        map<int,int> mp;
        int j = 0 , ans= 0  ;
        for(int i = 0 ; i < n;i++){

                if( mp.find( s[i] ) == mp.end()){
                    mp[s[i]]++;
                }
                else{
                    while( j < i && mp.find(s[i]) != mp.end() ){
                        mp[s[j]]--;

                        if( mp[s[j]] == 0  ){
                            mp.erase( s[j] );
                        }
                        j++;
                    }
                    mp[s[i]]++;
                    // cout<<"CUrrent : " << s.substr(j , i - j + 1 )<<endl; 
                }
               
                ans = ans < mp.size() ? mp.size() : ans ;
        }    
        return ans;
    }
};