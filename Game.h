#ifndef GAME_H
#define GAME_H

#include "dartboard.h"
class Game
{
public:
    Game(void);
    ~Game(void);
    void runGame();
    Dartboard board;
protected:
    /*!
    * Typ wyliczeniowy okreslajacy wszystkie stany gry.
    */
    enum GameState {MENU,GAME,ABOUT,END};
    GameState state;/**< Pole okreslajace obecny stan gry. */

private:
    void menu();
    void about();
    void game();
};

#endif // GAME_H
