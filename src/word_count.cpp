#include "word_count.hpp"
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>

// Converts a string to lowercase.
void to_lowercase(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), 
                   [](unsigned char c){ return std::tolower(c); });
}

// Loads stop words from a stream and returns them as a set.
std::set<std::string> load_stopwords(std::istream& stopwords) {
    std::set<std::string> stopwords_set;
    std::string word;
    while (stopwords >> word) {
        to_lowercase(word);
        stopwords_set.insert(word);
    }
    return stopwords_set;
}

// Counts words in a document stream, excluding the stopwords.
std::map<std::string, int> count_words(std::istream& document, const std::set<std::string>& stopwords) {
    std::map<std::string, int> word_counts;
    std::string word;
    while (document >> word) {
        to_lowercase(word);
        // Remove punctuation from the end of the word
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
        if (stopwords.find(word) == stopwords.end()) {
            word_counts[word]++;
        }
    }
    return word_counts;
}

// Outputs the word counts to an output stream.
void output_word_counts(const std::map<std::string, int>& word_counts, std::ostream& output) {
    for (const auto& pair : word_counts) {
        output << pair.first << ": " << pair.second << '\n';
    }
}
