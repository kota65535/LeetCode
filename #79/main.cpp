#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::pair<int, int>> dirs = {
            {0, 1},     // right
            {1, 0},     // down
            {0, -1},    // left
            {-1, 0}     // up
    };

    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        for (int i = 0 ; i < board.size() ; i++) {
            for (int j = 0 ; j < board[i].size() ; j++) {
                if (board[i][j] == word[0]) {
                    std::vector<std::vector<char>> next_board(board);
                    next_board[i][j] = '-';
                    if (exist_recursive(next_board, word.substr(1), i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool exist_recursive(std::vector<std::vector<char>>& board, std::string word, int a, int b) {
        if (word.empty()) {
            return true;
        }
        for (auto dir : dirs) {
            int next_a = a + dir.first;
            int next_b = b + dir.second;
            // check range
            if (next_a < 0 || board.size() <= next_a
                || next_b < 0 || board[next_a].size() <= next_b) {
                continue;
            }
            // does the next char match?
            if (board[next_a][next_b] != word[0]) {
                continue;
            }
            std::vector<std::vector<char>> next_board(board);
            next_board[a][b] = '-';
            if (exist_recursive(next_board, word.substr(1), next_a, next_b)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<char>> board = {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
    };

    std::cout << s.exist(board, "ABCB") << std::endl;
    return 0;
}