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
    for (auto &i : list) {
        size_t pos = i.find(DELIMITER);
        string test = i.substr(0, pos);
        if (test == name && stoi(i.substr(pos + 1)) < score) {
            i = test + DELIMITER + to_string(score);
            break;
        }
    }
    list.push_back(name + DELIMITER + to_string(score));
}

