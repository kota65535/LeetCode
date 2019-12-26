#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        return check_rows(board) && check_columns(board) && check_subboxes(board);
    }

    bool check_rows(std::vector<std::vector<char>>& board) {
        for (int i = 0 ; i < board.size() ; i++) {
            std::unordered_map<char, int> map;
            for (int j = 0 ; j < board[i].size() ; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (map.count(board[i][j]) != 0) {
                    return false;
                }
                map[board[i][j]]++;
            }
        }
        return true;
    }

    bool check_columns(std::vector<std::vector<char>>& board) {
        for (int i = 0 ; i < board[0].size() ; i++) {
            std::unordered_map<char, int> map;
            for (int j = 0 ; j < board.size() ; j++) {
                if (board[j][i] == '.') {
                    continue;
                }
                if (map.count(board[j][i]) != 0) {
                    return false;
                }
                map[board[j][i]]++;
            }
        }
        return true;
    }

    bool check_subboxes(std::vector<std::vector<char>>& board) {
        for (int i = 0 ; i < 3 ; i++) {
            for (int j = 0 ; j < 3 ; j++) {
                std::unordered_map<char, int> map;
                for (int x = i*3 ; x < i*3+3 ; x++) {
                    for (int y = j*3 ; y < j*3+3 ; y++) {
                        if (board[x][y] == '.') {
                            continue;
                        }
                        if (map.count(board[x][y]) != 0) {
                            return false;
                        }
                        map[board[x][y]]++;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;

    std::vector<std::vector<char>> board = {
            {'5','3','.','.','6','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','5','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };
//    std::vector<std::vector<char>> board = {
//            {'8','3','.','.','7','.','.','.','.'},
//            {'6','.','.','1','9','5','.','.','.'},
//            {'.','9','8','.','.','.','.','6','.'},
//            {'8','.','.','.','6','.','.','.','3'},
//            {'4','.','.','8','.','3','.','.','1'},
//            {'7','.','.','.','2','.','.','.','6'},
//            {'.','6','.','.','.','.','2','8','.'},
//            {'.','.','.','4','1','9','.','.','5'},
//            {'.','.','.','.','8','.','.','7','9'}
//    };

    std::cout << s.isValidSudoku(board) << std::endl;
    return 0;
}