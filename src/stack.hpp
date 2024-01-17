#ifndef STACK_HPP
#define STACK_HPP

#include <string>
#include <iostream>

constexpr int STK_MAX = 1000;

class Stack {
    int _top;
    char buf[STK_MAX];

public:
    Stack() : _top(-1) {}

    void push(char c) {
        if (!isFull()) {
            buf[++_top] = c;
        } else {
            std::cerr << "Error: Stack is full, cannot push." << std::endl;
        }
    }

    char pop() {
        if (!isEmpty()) {
            return buf[_top--];
        } else {
            std::cerr << "Error: Stack is empty, cannot pop." << std::endl;
            return '@';
        }
    }

    char top() {
        if (!isEmpty()) {
            return buf[_top];
        } else {
            std::cerr << "Error: Stack is empty, cannot retrieve top." << std::endl;
            return '@';
        }
    }

    bool isEmpty() {
        return _top == -1;
    }

    bool isFull() {
        return _top == STK_MAX - 1;
    }
};

void push_all(Stack& stk, const std::string& line) {
    for (char c : line) {
        stk.push(c);
    }
}

void pop_all(Stack& stk) {
    while (!stk.isEmpty()) {
        std::cout << stk.pop();
    }
    std::cout << std::endl;
}

#endif // STACK_HPP
