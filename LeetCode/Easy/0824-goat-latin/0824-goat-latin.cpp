class Solution {
public:
    bool startwithvowe(string s ){
        if(s[0]=='a'||s[0] == 'u' || s[0] == 'o' || s[0] == 'i' || s[0] == 'e')
            return 1;
        if(s[0]=='A'||s[0] == 'U' || s[0] == 'O' || s[0] == 'I' || s[0] == 'E')
            return 1;
        
        return 0; 
    }
    string toGoatLatin(string sentence) 
    {
        int n = sentence.size();
        stringstream ss(sentence);
        vector<string> arr;
        string s;
        while( getline(ss , s , ' ' )){
            arr.push_back( s );
        }
            string add = "a";
        for( string &s : arr ) {

            if(startwithvowe(s)){
                s+= "ma";
            }else{
                s = s.substr(1) + s[0] ;
                s += "ma";
            }
            s += add;
            add += "a";
        }
        string ans = "";
        n = arr.size();
        for(int i = 0 ;i < n;i +=1 ){
            ans += arr[i];
            if(i != n-1){

                ans += " ";
            }
        }
        return ans ;

    }
};