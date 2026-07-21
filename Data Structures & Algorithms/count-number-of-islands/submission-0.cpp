class Solution {
public:
    set<pair<int, int>> visited;
    int numIslands(vector<vector<char>>& grid) {
        int total=0;
        for (int r=0; r<grid.size();r++){
            for (int c=0; c<grid[0].size();c++){
                if (visited.find({r,c})==visited.end() && grid[r][c]=='1'){
                    total+=1;
                    dfs(grid,r,c);
                }
            }
        }
        return total;
        
    }

    void dfs(vector<vector<char>>& grid, int i, int j){
        if (visited.find({i,j})!=visited.end()){
            return;
        }
        if (i<0 || i>=grid.size() || j<0 || j>=grid[0].size()){
            return;
        }
        if (grid[i][j]=='1'){
            visited.insert({i,j});
        }
        vector<vector<int>> directions={{1,0},{-1,0},{0,-1},{0,1}};
        for (auto dir:directions){
            int r=dir[0];
            int c= dir[1];

            int new_row=i+r;
            int new_col= j+c;
            if (new_row>=0 && new_row<grid.size() && new_col>=0 && new_col<grid[0].size()&&visited.find({new_row,new_col})==visited.end() && grid[new_row][new_col]=='1'){
                dfs(grid,new_row,new_col);
            }
        }
    }
};
