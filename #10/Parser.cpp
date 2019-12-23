#include "Parser.h"

Automaton Parser::Parse(std::string s) {
    Automaton atm;

    int n_state = 0;
    for (int i = 0 ; i <s.size() ; i++) {
        if (isAlpha(s[i])) {
            atm.Connect(n_state, n_state + 1, s[i]);
            n_state++;
        } else if (s[i] == '.') {
            for (char c = 'a' ; c <= 'z' ; c++) {
                atm.Connect(n_state, n_state + 1, c);
            }
            n_state++;
        } else if (s[i] == '*') {
            if (s[i - 1] == '.') {
                for (char c = 'a' ; c <= 'z' ; c++) {
                    atm.Connect(n_state - 1, n_state - 1, c);
                }
            } else {
                atm.Connect(n_state - 1, n_state - 1, s[i-1]);
            }
            n_state--;
        }
    }
    return atm;
}

bool Parser::isAlpha(char c) {
    return 'a' <= c && c <= 'z';
}

