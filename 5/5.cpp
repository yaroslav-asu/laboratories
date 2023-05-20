#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <filesystem>


void run51() {
    std::string inp;
    std::set<char> marks{',', '.', ';', ':', '?', '!', '-', '(', ')', '"'};
    int counter = 0;
    std::cin >> inp;
    for (char ch: inp) {
        if (marks.count(ch)) {
            counter++;
        }
    }
    std::cout << counter;
}

std::map<char, int> str_letters_count(std::string str) {
    std::map<char, int> letters;
    for (char letter: str) {
        if (letters.count(letter)) {
            letters[letter]++;
        } else {
            letters[letter] = 1;
        }
    }
    return letters;
}

bool has_more_than_three_letters(std::string str) {
    std::map<char, int> letters = str_letters_count(str);
    for (std::pair<char, int> letter_pair: letters) {
        if (letter_pair.second >= 3) {
            return true;
        }
    }
    return false;
}

void run52() {
    setlocale(LC_ALL, "Russian");
    std::ifstream fin(std::filesystem::current_path().string() + "/../5/in.txt");
    std::string inp;
    std::set<std::string> shortest_words;
    short n;
    fin >> n;
    while (fin >> inp) {
        if (has_more_than_three_letters(inp)) {
            shortest_words.insert(inp);
            if (shortest_words.size() > n) {
                shortest_words.erase(--shortest_words.end());
            }
        }
    }
    fin.close();
    std::ofstream fout(std::filesystem::current_path().string() + "/../5/out.txt");
    for (std::string str: shortest_words) {
        fout << str << std::endl;
    }
    fout.close();
}