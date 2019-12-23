#include <iostream>
#include "Automaton.h"
#include "Parser.h"


int main() {

    Parser p;
    Automaton a = p.Parse(".*");

    bool r = a.Accept("acud");

    std::cout << r << std::endl;
    return 0;
}