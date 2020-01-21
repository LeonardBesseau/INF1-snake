/* ---------------------------
Laboratoire : 10
Fichier : readWriteFile.h
Auteur(s) : Besseau
Date :  21.01.2020

But :

Remarque(s) :

Compilateur : g++ 7.4.0

--------------------------- */
#ifndef SNAKE_READWRITEFILE_H
#define SNAKE_READWRITEFILE_H

#include <fstream>
#include <vector>
#include <string>

/**
 * Read data from files and a vector of string containing the lines
 * @param path a string containing the path to
 * @return
 */
std::vector<std::string> getDataFromFiles(const std::string &path);

bool writeDataToFiles(const std::string &path, const std::vector<std::string> &list);


#endif //SNAKE_READWRITEFILE_H
