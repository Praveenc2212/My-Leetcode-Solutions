class Solution {
public:

    int n ; 
    vector<vector<pair<int,int>>> adj;

    bool Check(int mid , int src ,int target , int k  ){

        deque<int> dq ;
        vector<int> vis(n , 0 );
        vis[src] = 1 ;
        dq.push_front( src);
        vector<int> dist(n, 1e9);
        dist[src] = 0 ;

        while( !dq.empty()){
            int u = dq.front();

            dq.pop_front();

            for( auto& [v , w ] : adj[u]){
                vis[v] = 1 ;
                if( dist[v] > dist[u] + ( w > mid) ){
                    dist[v] = dist[u] + ( w > mid);
                    if( w > mid ) {
                        dq.push_back( v );
                    }
                    else
                        dq.push_front( v );
                }
            }
        }
        return dist[target] <= k ;
    }
    
    int minimumThreshold(int nn, vector<vector<int>>& edges, int src, int target, int k) 
        {
        adj.clear();

        if( src == target) return 0;
        
        n = nn;
        int low = 0 , high =  1e9;
        adj.resize(n);

        for( auto e : edges ){
            int u =e[0], v = e[1] , w =e[2];
            adj[u].push_back({v , w });
            adj[v].push_back({u, w });
        }


        int ans = -1 ;
        while( low <= high ){
            int m = low + ( high - low ) / 2 ;
            if(Check(m , src , target , k )){
                ans = m;
                high = m -1 ;
            }
            else low = m + 1 ;
        }
        
        return ans;
        
    }
};