/* ---------------------------
Laboratoire : 10
Fichier : scores.h
Auteur(s) : Besseau
Date :  21.01.2020

But :

Remarque(s) :

Compilateur : g++ 7.4.0

--------------------------- */

#ifndef SNAKE_SCORES_H
#define SNAKE_SCORES_H


#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "textConst.h"


void sortScore(std::vector<std::string> &list);

int getBestScore(const std::vector<std::string> &list, const std::string &name);

void modifyScore(std::vector<std::string> &list, const std::string &name, int score);


#endif //SNAKE_SCORES_H
