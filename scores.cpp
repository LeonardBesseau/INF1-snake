/* ---------------------------
Laboratoire : 10
Fichier : scores.cpp
Auteur(s) : Besseau
Date :  21.01.2020

But :

Remarque(s) :

Compilateur : g++ 7.4.0

--------------------------- */

#include "scores.h"

using namespace std;


void sortScore(std::vector<std::string> &list) {
    // Multimap to sort list keeping the name and score associated
    multimap<int, string> scores;
    for (const string &s : list) {
        size_t pos = s.find(DELIMITER);
        scores.emplace(stoi(s.substr(pos + 1)), s.substr(0, pos));
    }

    size_t index = 0;

    for (pair<int, string> a: scores) {
        list.at(index) = a.second + DELIMITER + to_string(a.first);
        ++index;
    }
}

void modifyScore(vector<string> &list, const string &name, int score) {
    string input = name + DELIMITER + to_string(score);
    if (list.end() == find(list.begin(), list.end(), input)) {
        list.push_back(input);
    }
}


int getBestScore(const std::vector<std::string> &list, const std::string &name) {
    multimap<string, int> scores;

    // fill in map with data
    for (const string &s : list) {
        size_t pos = s.find(DELIMITER);
        scores.emplace(s.substr(0, pos), stoi(s.substr(pos + 1)));
    }
    // get all element with the demanded name as key
    std::pair<mapIterator, mapIterator> result = scores.equal_range(name);

    // if distance == 0 no element has been found otherwise return highest value of the interval
    return distance(result.first, result.second) ?
           max_element(result.first, result.second)->second : -1;

}