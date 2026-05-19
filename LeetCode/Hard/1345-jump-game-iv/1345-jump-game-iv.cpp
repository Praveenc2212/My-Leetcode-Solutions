class Solution {
public:
    int n ; 
    
    int dij(map<int,vector<int>> &mp , vector<int>&nums){

        queue<int> q; 
        q.push(0);
        vector<int> vis( n , 0 );
        vis[0] = 1 ;
        int cnt = 0 ;
        while( !q.empty()){
           int sz =  q.size();
           for( int i = 0 ;i < sz ; i+=1){

                int u = q.front();
                q.pop();
                if( u == n-1) {
                    return cnt;
                }

                if( u - 1 >= 0 && !vis[u-1] ){
                    q.push( u-1);
                    vis[u-1] = 1 ;
                }
                if( u + 1 < n && !vis[u+1]){
                    q.push( u + 1 );
                    vis[u + 1 ] = 1 ;
                }

                for( int v : mp[nums[u]]){
                    if(!vis[v]){
                        vis[v] = 1 ;
                        q.push(v);
                    }
                }
                mp.erase( nums[u] );
           }
            cnt++;
        }
        return -1;
    }
    
    int minJumps(vector<int>& arr) 
    {   
        n = arr.size();
        if( n == 1 ) return 0;
       map<int,vector<int>> mp;
       for( int i = 0;i < n; i+=1 )
            mp[arr[i]].push_back(i);

        int res = dij( mp , arr );
        return res;
    }
};