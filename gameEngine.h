/*
 -----------------------------------------------------------------------------------
 Laboratoire : Snake
 Fichier     : gameEngine.h
 Auteur(s)   : Yann Lederrey
 Date        : 20.01.2019
 
 Compilateur : g++ (GCC) 9.2.0

 Brief       : Fonctions permettant les diverses actions du jeu SNAKE en terminal.
 -----------------------------------------------------------------------------------
 */

#ifndef ENGINE
#define ENGINE

#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <vector>

enum eDirection {
    STOP, LEFT, RIGHT, UP, DOWN
};
std::vector<int> randomizeCoordinate(int width, int height, std::vector<std::vector<int>> &obstacles);
/**
* @brief Fonction calculant la position du prochain FRUIT.
* @param fruitX [out] position X du Fruit.
* @param fruitY [out] position Y du Fruit.
* @param width largeur du jeu.
* @param height hauteur du jeu.
*/
void fruitSpawn(int &fruitX, int &fruitY, const int width, const int height, std::vector<std::vector<int>> &obstacles);

void obstaclesSpawn(std::vector<std::vector<int>> &obstacles, const int width, const int height, const int &NObstacles);


/**
* @brief Fonction modifiant le plateau de jeu et les éléments du jeu.
* @param width largeur du plateau de jeu.
* @param height hauteur du plateau de jeu.
* @param snakePosX [in/out] position X de la tête du serpent.
* @param snakePosY [in/out] position Y de la tête du serpent.
* @param fruitPosX [in/out] position X du fruit.
* @param fruitPosY [in/out] position Y du fruit.
* @param snakeSize [in/out] longueur du serpent.
* @param tailX [in/out] tableau de positions X correspondant aux coordonnées X de la queue du serpent
* @param tailY [in/out] tableau de positions Y correspondant aux coordonnées Y de la queue du serpent
* @param direction direction du mouvement.
* @param gameover [out] boolean définissant si le joueur a perdu
*/
void
logic(const int width, const int height, int &snakePosX, int &snakePosY, int &fruitPosX, int &fruitPosY, int &snakeSize,
      int tailX[], int tailY[], const eDirection direction, bool &gameover, std::vector<std::vector<int>> &obstacles);

#endif