/* ---------------------------
Laboratoire : 10
Fichier : readWriteFile.h
Auteur(s) : Besseau
Date :  21.01.2020

But : Ce fichier contient les méthodes permettants de lire et d'écrire
des informations sur des fichiers

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
 * @param path a string containing the path to the file
 * @return a vector of string containing the data
 */
std::vector<std::string> getDataFromFiles(const std::string &path);

/**
 * Write data to file
 * @param path a string containing the path to the file
 * @param list a vector of string each representing a line to be written to the file
 * @attention erase previous data
 * @return true if the operation is successful, false otherwise
 */
bool writeDataToFiles(const std::string &path, const std::vector<std::string> &list);


#endif //SNAKE_READWRITEFILE_H
