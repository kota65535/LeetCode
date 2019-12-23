#ifndef _10_AUTOMATON_H
#define _10_AUTOMATON_H

#include <vector>

class Automaton {
public:
    Automaton();
    void Connect(int from, int to, char c);
    bool Accept(std::string s);
private:
    int Transition(int from, char c);
    int getIndex(char c);

    std::vector<std::vector<int>> matrix;

};

#endif //_10_AUTOMATON_H
