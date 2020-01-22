/*
 -----------------------------------------------------------------------------------
 Laboratoire : Snake
 Fichier     : display.h
 Auteur(s)   : Yann Lederrey
 Date        : 20.01.2019
 
 Compilateur : g++ (GCC) 9.2.0

 Brief       : Fonction ayant pour rôle d'afficher des éléments du jeu SNAKE.
 -----------------------------------------------------------------------------------
 */

#ifndef DISPLAY
#define DISPLAY

#include <iostream>
#include <vector>
#include "textConst.h"
#include <vector>

/**
* @brief Fonction affichant les informations du menu au terminal.
* @param score score actuel du joueur.
*/
void displayMenu(int score);

/**
* @brief Fonction affichant les informations des instructions au terminal.
*/
void displayInstructions();

/**
* @brief Fonction affichant le plateau de jeu.
* @param width largeur du plateau de jeu.
* @param height hauteur du plateau de jeu.
* @param snakePosX position X de la tête du serpent.
* @param snakePosY position Y de la tête du serpent.
* @param fruitPosX position X du fruit.
* @param fruitPosY position Y du fruit.
* @param snakeSize longueur du serpent.
* @param tailX tableau de positions X correspondant aux coordonnées X de la queue du serpent
* @param tailY tableau de positions Y correspondant aux coordonnées Y de la queue du serpent
*/
void draw(int width, int height, int snakePosX, int snakePosY, int fruitPosX, int fruitPosY, int snakeSize, int tailX[],
          int tailY[], std::vector<std::vector<int>> &obstacles);

/**
 *
 * @param list
 */
void displayScores(const std::vector<std::string> &list);


/**
 *
 * @param name
 */
void displayName(const std::string &name);

void displayBestScore(int score);

void displayAskForName();

#endif