// letter_count.hpp

#ifndef LETTER_COUNT_HPP
#define LETTER_COUNT_HPP

#include <string>

constexpr int N_CHARS = ('Z' - 'A' + 1); // 26

int char_to_index(char ch);
char index_to_char(int i);
void count(const std::string& s, int counts[]);
void print_counts(const int counts[], int len);

#endif // LETTER_COUNT_HPP
