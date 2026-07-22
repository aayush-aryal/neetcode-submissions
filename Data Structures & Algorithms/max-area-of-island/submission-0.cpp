class Solution {
public:
    set<pair<int,int>> visited;
    int biggest=0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (int r=0; r<grid.size();r++){
            for (int c=0; c<grid[0].size();c++){
                if (grid[r][c]==1 && visited.find({r,c})==visited.end()){
                    biggest=max(biggest,dfs(r,c,grid));
                }
            }
        }
        return biggest;
        
    }

    int dfs(int i, int j, vector<vector<int>>& grid){
        if (visited.find({i,j})!=visited.end()){
            return 0;
        }
        if (i<0 || i>=grid.size()|| j<0 || j>=grid[0].size()){
            return 0;
        }
        if (grid[i][j]==0){
            return 0;
        }

        // new valid island found
        if (grid[i][j]==1){
            visited.insert({i,j});
        }
        return 1+ dfs(i+1,j,grid) + dfs(i-1,j,grid)+ dfs(i,j+1,grid)+dfs(i,j-1,grid);  
    }
};
