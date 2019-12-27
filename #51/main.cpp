#include <iostream>
#include <vector>
#include <string>
#include <queue>

class Board {
public:
    Board(int n) :
            data(std::vector<std::string>(n, std::string(n, '.'))),
            n_queens(0) {}

    Board(std::vector<std::string> board, int n_queens) {
        this->data = board;
        this->n_queens = n_queens;
    }

    Board *put_queen(int x, int y) const {
        std::vector<std::string> next_data(data);

        // cannot put
        if (data[x][y] == '#' || data[x][y] == 'Q') {
            return nullptr;
        }

        // fill squares where the queen can move
        for (int i = 0 ; i < data.size() ; i++) {
            for (int j = 0; j < data[i].size(); j++) {
                if (i == x              // row
                    || j == y           // column
                    || x - i == y - j   // lower right / upper left
                    || x - i == j - y   // upper right / lower left
                        ) {
                    // found another queen, cannot put
                    if (data[i][j] == 'Q') {
                        return nullptr;
                    }
                    next_data[i][j] = '#';
                }
            }
        }
        next_data[x][y] = 'Q';
        // increment current num of queen
        return new Board(next_data, n_queens + 1);
    }

    std::vector<std::string> show() const {
        std::vector<std::string> next_data(data);
        for (int i = 0 ; i < next_data.size() ; i++) {
            for (int j = 0; j < next_data[i].size(); j++) {
                if (next_data[i][j] == '#') {
                    next_data[i][j] = '.';
                }
            }
        }
        return next_data;
    }

    std::vector<std::string> data;
    int n_queens;
};

class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        Board *initial = new Board(n);
        std::vector<Board*> final_boards = solve(initial, n, 0);
        std::vector<std::vector<std::string>> ret(final_boards.size());
        std::transform(final_boards.begin(), final_boards.end(), ret.begin(), [](const Board *b) { return b->show(); });
        return ret;
    }

    std::vector<Board*> solve(Board *board, int n, int n_current) {
        std::vector<Board*> ret;
        if (n_current == n) {
            return std::vector<Board*>();
        }
        for (int i = 0 ; i < n ; i++) {
            if (board->data[n_current][i] == '.') {
                Board *next_board = board->put_queen(n_current, i);
                if (next_board == nullptr) {
                    continue;
                }
                if (next_board->n_queens == n) {
                    ret.push_back(next_board);
                }
                for (auto b : solve(next_board, n, n_current + 1)) {
                    ret.push_back(b);
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution s;
    for (auto answer : s.solveNQueens(1)) {
        for (auto row : answer) {
            std::cout << row << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}