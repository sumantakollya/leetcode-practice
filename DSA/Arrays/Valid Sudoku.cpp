#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
    
            vector<unordered_set<int>> row(board.size());
            vector<unordered_set<int>> col(board[0].size());
            vector<unordered_set<int>> blk(board.size());
            
            for(int i=0; i<board.size(); i++) {
                for (int j=0; j<board[i].size(); j++) {
                    if (board[i][j] == '.')
                        continue;
                    else {
                        int blk_idx = (i / 3) * 3 + (j / 3);
                        int val = board[i][j]-'0';
                        if (row[i].find(val) != row[i].end())
                            return false;
                            
                        if (col[j].find(val) != col[j].end())
                            return false;
                            
                        if (blk[blk_idx].find(val) != blk[blk_idx].end())
                            return false;
    
                        row[i].insert(val);
                        col[j].insert(val);
                        blk[blk_idx].insert(val);
                    }
                }
            }
    
            return true;
        }
    };