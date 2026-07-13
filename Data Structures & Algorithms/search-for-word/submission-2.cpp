class Solution {
public:
    std::unordered_set<string> visited;
    bool exist(vector<vector<char>>& board, string word) {
        for (int r=0; r<board.size();r++){
            for (int c=0; c<board[0].size();c++){
                if (dfs(r,c,0, board,word)){
                    return true;
                }
            }
        }
        return false;  
    }

    bool dfs(int i, int j, int k, vector<vector<char>>& board, string word){
        bool found=false;
        if (k==word.size()){
            return true;
        }
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size()){
            return false;
        }
        // for each step add in visited so you dont reuse the same spot again
        string pos = to_string(i) + "," + to_string(j);
        if (visited.find(pos)!=visited.end()){
            return false;
        }
        visited.insert(pos);
        
        if (board[i][j]==word[k]){
            // only go these paths
            found= dfs(i+1,j,k+1,board,word)|| dfs(i,j+1,k+1,board,word)|| dfs(i-1,j,k+1,board,word)|| dfs(i,j-1,k+1,board,word);
        }
        visited.erase(pos);
        return found;   
    }

    
};
