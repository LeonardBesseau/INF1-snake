#include <algorithm>
#include "gameEngine.h"

std::vector<int>
randomizeCoordinate(const int width, const int height, std::vector<std::vector<int>> &obstacles) {
    bool coordinateOK = false;
    std::vector<int> object(2);
    srand(time(NULL));
    do {
        object[0] = rand() % width;
        object[1] = rand() % height;
        if (std::find(obstacles.begin(), obstacles.end(), object) == obstacles.end()) {
            coordinateOK = true;
        }
    } while (!coordinateOK);
    return object;
}

void
fruitSpawn(int &fruitX, int &fruitY, const int width, const int height, std::vector<std::vector<int>> &obstacles) {
    std::vector<int> fruit = randomizeCoordinate(width, height, obstacles);
    fruitX = fruit[0];
    fruitY = fruit[1];
}

void
obstaclesSpawn(std::vector<std::vector<int>> &obstacles, const int width, const int height, const int &NObstacles) {
    srand(time(NULL));
    std::vector<int> firstObstacle = {rand() % width, rand() % height};
    obstacles.push_back(firstObstacle);
    for (int i = 1; i < NObstacles; i++) {
        obstacles.push_back(randomizeCoordinate(width, height, obstacles));
    }
}

void
logic(const int width, const int height, int &snakePosX, int &snakePosY, int &fruitPosX, int &fruitPosY, int &snakeSize,
      int tailX[], int tailY[], const eDirection direction, bool &gameover, std::vector<std::vector<int>> &obstacles) {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = snakePosX;
    tailY[0] = snakePosY;

    for (int i = 1; i < snakeSize; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (direction) {
        case LEFT:
            snakePosX--;
            break;

        case RIGHT:
            snakePosX++;
            break;

        case UP:
            snakePosY--;
            break;

        case DOWN:
            snakePosY++;
            break;
    }

    // Test si la tête du serpent touche un bord.
    if (snakePosX > width || snakePosX < 0 || snakePosY > height || snakePosY < 0) {
        gameover = true;
    }
    // Test si la tête du serpent touche un obstacle.
    std::vector<int> snakePos = {snakePosX, snakePosY};
    if (find(obstacles.begin(), obstacles.end(), snakePos) != obstacles.end()) {
        gameover = true;
    }

    // Test si le serpent se mord la queue
    for (int i = 0; i < snakeSize; i++) {
        if (tailX[i] == snakePosX && tailY[i] == snakePosY)
            gameover = true;
    }

    // Test si le serpent mange un Fruit
    if (snakePosX == fruitPosX && snakePosY == fruitPosY) {
        snakeSize++;
        fruitSpawn(fruitPosX, fruitPosY, width, height, obstacles);
    }
}