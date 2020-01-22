/*
 -----------------------------------------------------------------------------------
 Laboratoire : Snake
 Fichier     : display.cpp
 Auteur(s)   : Yann Lederrey
 Date        : 20.01.2019
 
 Compilateur : g++ (GCC) 9.2.0

 Brief       : Implémentation des fonctions du fichier display.h
 -----------------------------------------------------------------------------------
 */

#include "display.h"
#include <algorithm>

void displayMenu(int score) {
    std::cout << MENU_WELCOME << std::endl;
    std::cout << MENU_START << std::endl;
    std::cout << MENU_QUIT << std::endl;
    std::cout << MENU_INSTRUCTION << std::endl;
    std::cout << MENU_SCORE << std::to_string(score) << std::endl;
}

void displayInstructions() {
    std::cout << INSTR_UP << std::endl;
    std::cout << INSTR_LEFT << std::endl;
    std::cout << INSTR_DOWN << std::endl;
    std::cout << INSTR_RIGHT << std::endl;
    std::cout << INSTR_EXIT << std::endl;
    std::cout << INSTR_MENU << std::endl;
    std::cout << INSTR_SCORES << std::endl;
    std::cout << INSTR_NAME << std::endl;
    std::cout << INSTR_RESEARCH << std::endl;
}

void draw(int width, int height, int snakePosX, int snakePosY, int fruitPosX, int fruitPosY, int snakeSize, int tailX[],
          int tailY[], std::vector<std::vector<int>> &obstacles) {
    std::vector<int> drawPos(2);
    for (int i = 0; i < width + 2; i++) {
        std::cout << BORDER;
    }

    std::cout << std::endl;

    for (int i = 0; i < height; i++) {
        drawPos.at(1) = i;
        for (int j = 0; j < width; j++) {
            drawPos.at(0) = j;
            if (j == 0)
                std::cout << BORDER;

            if (i == snakePosY && j == snakePosX)
                std::cout << SNAKE_HEAD;

            else if (i == fruitPosY && j == fruitPosX)
                std::cout << FRUIT;

            else if (obstacles.end() != find(obstacles.begin(), obstacles.end(), drawPos))
                std::cout << OBSTACLE;

            else {

                bool print = false;

                for (int k = 0; k < snakeSize; k++) {

                    if (tailX[k] == j && tailY[k] == i) {

                        std::cout << SNAKE_TAIL;
                        print = true;
                    }
                }

                if (!print)
                    std::cout << " ";
            }

            if (j == width - 1)

                std::cout << BORDER;
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < width + 2; i++) {
        std::cout << BORDER;
    }

    std::cout << std::endl;

    std::cout << ACTUAL_SCORE << snakeSize << std::endl;
}

void displayScores(const std::vector<std::string> &list) {
    unsigned index = 1;
    for (auto i = list.crbegin(); i != list.crend(); ++i) {
        std::cout << index++ << " " << *i << std::endl;
    }
}

void displayName(const std::string &name) {
    if (name.empty()) {
        std::cout << NAME_ASK << std::endl;
    } else {
        std::cout << NAME_CURRENT << name << std::endl;
        std::cout << NAME_CHANGE << std::endl;
    }
}

void displayBestScore(int score) {
    if (score < 0) {
        std::cout << NO_PLAYER_FOUND << std::endl;
    } else {
        std::cout << BEST_SCORE << " " << score << std::endl;
    }
}