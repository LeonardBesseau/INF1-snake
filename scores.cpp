/* ---------------------------
Laboratoire : 10
Fichier : scores.cpp
Auteur(s) : Besseau
Date :  21.01.2020

But : Gérer un système de score avec tri et recherche du meilleur score

Remarque(s) : le score est toujours positif

Compilateur : g++ 7.4.0

--------------------------- */

#include "scores.h"

using namespace std;

/**
 * Get the maximum value of a key in a multimap
 * @param map a multimap of string and int
 * @param key a string the key of which to find the maximum value
 * @return an integer : the maximum value of the key. -1 is nothing is found
 */
int getMaxElementInMap(const multimap<string, int> &map, const string &key);

/**
 * Create a string formatted for storage in file
 * @param name a string with the name
 * @param score an integer for the score of the user
 * @return a string formatted as name:score where : is the delimiter
 */
string createStringScore(const string &name, int score, char delimiter);


void sortScore(std::vector<std::string> &list) {
    // Multimap to sort list keeping the name and score associated
    multimap<int, string, greater<int>> scores;
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

void addScore(vector<string> &list, const string &name, int score) {
    string input = createStringScore(name, score, DELIMITER);
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
    return getMaxElementInMap(scores, name);

}

std::vector<std::string> getListBestScore(const std::vector<std::string> &list) {
    multimap<string, int> scores;

    // fill in map with data
    for (const string &s : list) {
        size_t pos = s.find(DELIMITER);
        scores.emplace(s.substr(0, pos), stoi(s.substr(pos + 1)));
    }

    vector<string> output;
    // reserve size
    output.reserve(list.size());

    for (auto i = scores.begin(); i != scores.end();) {
        string key = i->first;
        // add best score to list
        output.push_back(createStringScore(key, getMaxElementInMap(scores, key), DELIMITER));
        // next key
        i = scores.upper_bound(key);
    }
    output.shrink_to_fit();
    return output;
}

int getMaxElementInMap(const multimap<string, int> &map, const string &key) {
    // get all element with the demanded name as key
    std::pair<mapIterator, mapIterator> result = map.equal_range(key);

    // if distance == 0 no element has been found otherwise return highest value of the interval
    return distance(result.first, result.second) ?
           max_element(result.first, result.second)->second : -1;
}

string createStringScore(const string &name, int score, char delimiter) {
    string output = name;
    output += delimiter + to_string(score);
    return output;
}