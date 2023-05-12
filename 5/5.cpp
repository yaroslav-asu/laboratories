#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <filesystem>

using namespace std;

void run51() {
    string inp;
    set<char> marks{',', '.', ';', ':', '?', '!', '-', '(', ')', '"'};
    int counter = 0;
    cin >> inp;
    for (char ch: inp) {
        if (marks.count(ch)) {
            counter++;
        }
    }
    cout << counter;
}

map<char, int> str_letters_count(string str) {
    map<char, int> letters;
    for (char letter: str) {
        if (letters.count(letter)) {
            letters[letter]++;
        } else {
            letters[letter] = 1;
        }
    }
    return letters;
}

bool has_more_than_three_letters(string str) {
    map<char, int> letters = str_letters_count(str);
    for (pair<char, int> letter_pair: letters) {
        if (letter_pair.second >= 3) {
            return true;
        }
    }
    return false;
}

void run52() {
    setlocale(LC_ALL, "Russian");
    ifstream fin(filesystem::current_path().string() + "/../5/in.txt");
    string inp;
    set<string> shortest_words;
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
    ofstream fout(filesystem::current_path().string() + "/../5/out.txt");
    for (string str: shortest_words) {
        fout << str << endl;
    }
    fout.close();
}