#include "Player.h"

Player::Player(){
    score=301;
    }
int Player::getscore(){
return score;
}

void Player::setscore(int newscore){
score = newscore;
}

void Player::update(int points){
score -= points;
}
