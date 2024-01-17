#include <iostream>
#include <string>
#include "stack.hpp"

int main() {
    Stack stk;
    std::string line;
    while (std::getline(std::cin, line)) {
        push_all(stk, line);
        pop_all(stk);
    }
    return 0;
}
