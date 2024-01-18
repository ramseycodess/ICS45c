// letter_count.cpp

#include "letter_count.hpp"
#include <iostream>
#include <cctype>

using namespace std;

int char_to_index(char ch) {
    if (isalpha(ch)) {
        return toupper(ch) - 'A';
    }
    return -1; // Return -1 for non-alphabet characters
}

char index_to_char(int i) {
    return 'A' + i;
}

void count(const string& s, int counts[]) {
    for (char ch : s) {
        int index = char_to_index(ch);
        if (index != -1) {
            counts[index]++;
        }
    }
}

void print_counts(const int counts[], int len) {
    for (int i = 0; i < len; ++i) {
        cout << index_to_char(i) << " " << counts[i] << endl;
    }
}

int main() {
    int counts[N_CHARS] = {0};

    string line;
    while (getline(cin, line)) {
        count(line, counts);
    }

    print_counts(counts, N_CHARS);
    return 0;
}
