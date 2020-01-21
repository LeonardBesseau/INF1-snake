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
    multimap<unsigned, string> scores;
    for (const string &s : list) {
        size_t pos = s.find(DELIMITER);
        scores.emplace(stoi(s.substr(pos + 1)), s.substr(0, pos));
    }

    size_t index = 0;

    for (pair<unsigned, string> a: scores) {
        list.at(index) = a.second + ',' + to_string(a.first);
        ++index;
    }
}

