import collections
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rowdict=collections.defaultdict(set)
        coldict=collections.defaultdict(set)
        subsquare=collections.defaultdict(set)
        
        for row in range (9):
            for col in range (9):
                #check if its emtpy
                if board[row][col]==".":
                    continue 
                if (board[row][col] in rowdict[row] or 
                    board[row][col] in coldict[col] or 
                    board[row][col] in subsquare[(row//3,col//3)]):
                    return False 
                else:
                    rowdict[row].add(board[row][col])
                    coldict[col].add(board[row][col])
                    subsquare[(row//3,col//3)].add(board[row][col])
        
        return True



                

        