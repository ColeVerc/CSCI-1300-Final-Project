#include "Player.h"
// Recall we use this preprocessor directive for rand() and srand()
#include <cstdlib>
// Similarly, we use this one for time() (The seed for random)
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

Player::Player(string name, string advisor, int path) {
    playerName = name;
    playerAdvisor = advisor;
    playerPath = path;
}