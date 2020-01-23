/*
 -----------------------------------------------------------------------------------
 Laboratoire : Snake
 Fichier     : main.cpp
 Auteur(s)   : Yann Lederrey
 Date        : 20.01.2019
 
 Compilateur : g++ (GCC) 9.2.0

 Brief       : Implémentation d'un jeu de snake en console
 Sources     : https://code.sololearn.com/c8ubSKG6fX73/#cpp
 -----------------------------------------------------------------------------------
 */

#include <string>
#include <cstring>
#include <unistd.h>
#include <stdio.h>
#include <limits>
#include <cstdlib>

#include "sysFunc.h"
#include "display.h"
#include "gameEngine.h"
#include "scores.h"
#include "readWriteFile.h"

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;
const int START_POS_X_SNAKE = WIDTH / 2;
const int START_POS_Y_SNAKE = HEIGHT / 2;
const int SPEED = 500000;
const int N_OBSTACLES = 10;

/**
* @brief Fonction affichant le menu et supprimant l'affichage du terminal.
* @param score score actuel du joueur.
*/
void restart(int score);

/**
* @brief Fonction affichant le menu d'instructions et supprimant l'affichage du terminal.
* Cette fonction permet aussi de quitter le menu d'instructions.
* @param score score actuel du joueur.
*/
void getInstructions(int score);

/**
* @brief Fonction faisant la traduction entre la direction entrée par l'utilisateur et la direction du serpent.
* @param direction direction proposée par l'utilisateur
* @param oldDirection Direction actuelle du serpent
* @param gameover [out] définis si l'utilisateur arrête la partie.
* @return nouvelle direction du serpent.
*/
eDirection manageDirection(char direction, eDirection oldDirection, bool &gameover);

/**
* @brief Fonction remettant les variables de jeu par défaut.
* @param posSnakeX [out] position X de la tête du serpent.
* @param posSnakeY [out] position Y de la tête du serpent.
* @param direction [out] direction initiale du serpent.
* @param gameover [out] définis si le joueur arrête ou perd la partie.
*/
void reload(int &posSnakeX, int &posSnakeY, int &length, eDirection &direction, bool &gameover);

/**
 * Function displaying the scores of all the players and clearing the terminal
 * @param score actual score of the player
 * @details based on scores stored in scores.txt
 */
void getScores(int score);

/**
 * Change the name of the player
 * @param name a string in which to store the name of the user
 * @attention No delimiter is allowed in the name. A single q is not allowed either
 */
void changeName(string &name);

/**
 * Add the score of the user to the records
 * @param name a string containing the name of the user
 * @param score an integer representing the score of the user
 */
void setScore(const string &name, int score);

/**
 * Function managing the research best score menu.
 * @param score actual player score
 */
void menuBestScore(int score);


//*
int main() {
    // CONFIGURATIONS VARIABLES
    bool gameover = false;
    bool shutDown = false;
    int tailX[400], tailY[400];
    char actualDirection = KEY_UP;

    int posSnakeX;
    int posSnakeY;
    int snakeSize;
    eDirection dir;
    reload(posSnakeX, posSnakeY, snakeSize, dir, gameover);

    vector<vector<int>> obstacles;
    obstaclesSpawn(obstacles, WIDTH, HEIGHT, N_OBSTACLES);

    int posFruitX;
    int posFruitY;
    fruitSpawn(posFruitX, posFruitY, WIDTH, HEIGHT, obstacles);

    string playerName;
    changeName(playerName);

    // BOUCLE DU MENU.
    do {
        restart(snakeSize);

        string input;
        cin >> input;
        if (input.at(0) == KEY_START) {

            reload(posSnakeX, posSnakeY, snakeSize, dir, gameover);

            // BOUCLE DE JEU
            while (!gameover) {

                clearScreen();

                // dessine le pleateau de jeu
                draw(WIDTH, HEIGHT, posSnakeX, posSnakeY, posFruitX, posFruitY, snakeSize, tailX, tailY, obstacles);

                // detecte une entrée sur le clavier et récupère le charactère.
                char newDirection = ' ';
                if (kbhit()) {
                    newDirection = getch();
                }
                if ((newDirection != actualDirection)) {
                    actualDirection = newDirection;
                }

                // Convertis la direction donnée par l'utilisateur pour le serpent.
                dir = manageDirection(actualDirection, dir, gameover);

                // Ordonne le mouvement au serpent et définis si il meurt.
                logic(WIDTH, HEIGHT, posSnakeX, posSnakeY, posFruitX, posFruitY, snakeSize, tailX, tailY, dir,
                      gameover, obstacles);

                // met en pause le système définissant la vitesse du serpent.
                mySleep(SPEED);
            }
            if (actualDirection != KEY_QUIT) {
                setScore(playerName, snakeSize);
            }
        }
            // test si on souhaite afficher le menu
        else if (input.at(0) == KEY_INSTRUCTION) {
            getInstructions(snakeSize);
            // test si on souhaite arrêter de jouer.
        } else if (input.at(0) == KEY_SCORES) {
            getScores(snakeSize);
        } else if (input.at(0) == KEY_NAME) {
            changeName(playerName);
        } else if (input.at(0) == KEY_RESEARCH) {
            menuBestScore(snakeSize);
        } else if (input.at(0) == KEY_QUIT)
            shutDown = true;

    } while (!shutDown);
    return 0;
}

//*/
void restart(int score) {
    clearScreen();
    displayMenu(score);
}

void getInstructions(int score) {
    clearScreen();
    displayInstructions();

    string input;
    cin >> input;
    if (input.at(0) == KEY_MENU)
        restart(score);
}

eDirection manageDirection(char direction, eDirection oldDirection, bool &gameover) {
    eDirection dir;
    bool error = false;
    switch (direction) {
        case KEY_LEFT:
            dir = LEFT;
            break;

        case KEY_UP:
            dir = UP;
            break;

        case KEY_DOWN:
            dir = DOWN;
            break;

        case KEY_RIGHT:
            dir = RIGHT;
            break;

        case KEY_QUIT:
            dir = STOP;
            gameover = true;
            break;
        default:
            dir = oldDirection;
            break;
    }
    return dir;
}

void reload(int &posSnakeX, int &posSnakeY, int &length, eDirection &direction, bool &gameover) {
    posSnakeX = START_POS_X_SNAKE;
    posSnakeY = START_POS_Y_SNAKE;
    length = 0;
    direction = UP;
    gameover = false;
}

void getScores(int score) {
    clearScreen();
    vector<string> list = getDataFromFiles(SCORE_PATH);
//*
    list = getListBestScore(list);
    sortScore(list);
    //*/
    displayScores(list);

    string input;
    cin >> input;
    if (input.at(0) == KEY_MENU)
        restart(score);
}

void changeName(string &name) {
    string input;
    do {
        clearScreen();
        displayName(name);

        getline(cin, input);

        if (count(input.begin(), input.end(), DELIMITER)) {
            input.clear();
        }
    } while (input.empty() || (input.length() == 1 && input.at(0) == KEY_QUIT));
    name = input;
}

void setScore(const string &name, int score) {
    vector<string> list = getDataFromFiles(SCORE_PATH);
    addScore(list, name, score);
    sortScore(list);
    writeDataToFiles(SCORE_PATH, list);
}

void menuBestScore(int score) {
    vector<string> list = getDataFromFiles(SCORE_PATH);
    string input;
    bool exit;
    do {
        if (input.empty()) {
            clearScreen();
            displayAskForName();
        }
        getline(cin, input);
        if (!input.empty()) {
            int result = getBestScore(list, input);
            displayBestScore(result);
        }
        // If exit_Key only
        exit = (input.length() == 1 && input.at(0) == KEY_QUIT);
    } while (!exit);
}