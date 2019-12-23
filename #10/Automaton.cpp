#include <string>
#include "Automaton.h"

const int NUM_ALPHAS = 26;

Automaton::Automaton(): matrix(0, std::vector<int>(NUM_ALPHAS, -1)) {
}

void Automaton::Connect(int from, int to, char c) {
    int max = std::max(from, to) + 1;
    if (matrix.size() < max) {
        matrix.resize(max, std::vector<int>(NUM_ALPHAS, -1));
    }
    matrix[from][getIndex(c)] = to;
}

int Automaton::Transition(int from, char c) {
    return matrix[from][getIndex(c)];
}

bool Automaton::Accept(std::string s) {
    int state = 0;
    for (char c: s) {
        state = Transition(state, c);
        if (state == -1) {
            return false;
        }
    }
    return state == matrix.size() - 1;
}

int Automaton::getIndex(char c) {
    return c - 'a';
}


