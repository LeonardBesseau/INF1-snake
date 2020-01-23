/* ---------------------------
Laboratoire : 10
Fichier : scores.h
Auteur(s) : Besseau
Date :  21.01.2020

But : Gérer un système de score avec tri et recherche du meilleur score

Remarque(s) : le score est toujours positif

Compilateur : g++ 7.4.0

--------------------------- */

#ifndef SNAKE_SCORES_H
#define SNAKE_SCORES_H


#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "textConst.h"


typedef std::multimap<std::string, int>::const_iterator mapIterator;

/**
 * Sort the list of name and score by score
 * @param list a vector of string containing the data
 * @details the data must be formatted as following
 * name:score
 * name is the name of the player
 * : is the delimiter (Can be modified in constant)
 * score
 */
void sortScore(std::vector<std::string> &list);

/**
 * Get the best score for a given user
 * @param list a vector of string containing the name and the score formatted as follow name: delimiter
 * where : is the delimiter
 * @param name a string with the name of the user to find
 * @return the score of the user or -1 if no user is found.
 */
int getBestScore(const std::vector<std::string> &list, const std::string &name);

/**
 * Get the best score for all user
 * @param list a vector of string containing the name and the score formatted as follow name: delimiter
 * where : is the delimiter
 * @return a list with only the best score of all user
 */
std::vector<std::string> getListBestScore(const std::vector<std::string> &list);

/**
 * Add a new score to the list if it doesn't exist
 * @param list a vector of string containing the name and the score formatted as follow name: delimiter
 * where : is the delimiter
 * @param name a string with the name of the user to find
 * @param score a integer with score of the user
 */
void addScore(std::vector<std::string> &list, const std::string &name, int score);


#endif //SNAKE_SCORES_H
