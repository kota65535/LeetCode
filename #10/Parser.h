#ifndef _10_PARSER_H
#define _10_PARSER_H

#include <string>
#include "Automaton.h"

class Parser {
public:
    Automaton Parse(std::string s);
private:

    static bool isAlpha(char c);
};


#endif //_10_PARSER_H
