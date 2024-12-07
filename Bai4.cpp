#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ifstream file("text.txt");
    if (!file) {
        cerr << "Could not open the file!" << endl;
        return 1;
    }

    map<string, set<int>> wordMap;
    string line;
    int lineNumber = 0;

    while (getline(file, line)) {
        ++lineNumber;
        stringstream ss(line);
        string word;
        while (ss >> word) {
            // Remove punctuation
            word.erase(remove_if(word.begin(), word.end(), ispunct), word.end());
            wordMap[word].insert(lineNumber);
        }
    }

    // Print the word occurrences
    for (const auto& [word, lines] : wordMap) {
        cout << word << " ";
        for (int line : lines) {
            cout << line << " ";
        }
        cout << endl;
    }

    return 0;
}
