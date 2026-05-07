class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0 ;

        for( int i =0 ;i < row ;i +=1 ){
            for( int j = 0 ;j < col ; j += 1  ){
                if( grid[i][j] == 1){
                    ans+=4;
                    if( i + 1 < row && grid[i+1][j] == 1 )  ans--;
                if( i - 1 >= 0 && grid[i-1][j] == 1 ) ans--;
                if( j + 1 < col && grid[i][j+1] == 1 ) ans -=1 ;
                if( j - 1 >= 0 && grid[i][j-1] == 1) ans -=1 ;
                }

                
            }
        }
        return ans;
    }
};