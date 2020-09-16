#include "Game.h"
#include "Player.h"




Game::Game(void)
{
    install_keyboard();
    set_color_depth(24);
    set_gfx_mode( GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0 );
    install_mouse();

    show_mouse( screen );
    unscare_mouse();
    srand(time(NULL));
    board = Dartboard();

    state = MENU;
}


Game::~Game(void)
{
}
void Game::runGame()
{
    while(state!=END)
    {
        switch (state)
        {
        case GameState::MENU:
            menu();
            break;
        case GameState::GAME:
            game();
            break;
        case GameState::ABOUT:
            about();
            break;
        case GameState::END:

            break;
        }
    }
}


void Game::menu()
{
    BITMAP * bufor = create_bitmap(800,600);
    BITMAP * tlo = create_bitmap(800,600);
    tlo = load_bitmap("bg.bmp",NULL);
    if(tlo== NULL)
        allegro_message("nie udalo sie zaladowac tla");
    clear_bitmap(bufor);
    clear_keybuf();
    while(state == MENU)
    {
        while( !key[ KEY_ESC ] )
        {
            blit(tlo,bufor,0,0,0,0,800,600);

            blit(bufor, screen, 0, 0, 0, 0, 800, 600 );
            clear_bitmap(bufor);
            /*
                SPRAWDZANIE KLINIECIA MYSZKA
            */
            if(mouse_b & 1)
            {
                if(mouse_x>=250 && mouse_x<=550)
                {
                    if(mouse_y>=350 && mouse_y<=390)
                    {
                        state=GAME;
                        break;
                    }
                    else if(mouse_y>=410 && mouse_y<=450)
                    {
                        state=ABOUT;
                        break;
                    }
                    else if(mouse_y>= 470 && mouse_y<=510)
                    {
                        state=END;
                        rest(100);
                        mouse_b | 0;
                        break;

                    }
                }
            }
        }
        if(key[KEY_ESC])
        {
            state=END;
            rest(100);
        }
    }
    destroy_bitmap(tlo);
}



void Game::about()
{
    BITMAP * bufor = create_bitmap( 800, 600 );
    BITMAP * tlo = create_bitmap(800,600);
    tlo = load_bitmap("about.bmp",NULL);
    if(tlo== NULL)
        allegro_message("nie udalo sie zaladowac tla");
    clear_bitmap(bufor);
    clear_keybuf();
    while(state == ABOUT)
    {
        while( !key[ KEY_ESC ] )
        {
            blit(tlo,bufor,0,0,0,0,800,600);

            blit(bufor, screen, 0, 0, 0, 0, 800, 600 );
            clear_bitmap(bufor);

            if(mouse_x>=250 && mouse_x<=550 && mouse_b &1)
            {
                if(mouse_y>= 470 && mouse_y<=510)
                {
                    state=MENU;
                    rest(100);
                    break;

                }
            }

        }
        destroy_bitmap(bufor);
        destroy_bitmap(tlo);

        state = MENU;
        rest(100);
    }
}


void Game::game()
{
    Player player1 = Player();
    Player player2 = Player();
    BITMAP * bufor = create_bitmap( 800, 600 );
    BITMAP * tlo = create_bitmap(800,600);
    BITMAP * p1 =create_bitmap(150,50);
    BITMAP * p2 =create_bitmap(150,50);
    clear_bitmap(p1);
    clear_bitmap(p2);
    tlo = load_bitmap("gamebg.bmp",NULL);
    if(tlo== NULL)
        allegro_message("nie udalo sie zaladowac tla");
    clear_bitmap(bufor);
    clear_keybuf();
    while(state==GAME)
    {
        int result = 0;
        int result2 = 0;
        int round = 0;
        int mx =0;
        int my =0;
        clear_bitmap(screen);
        clear_bitmap(bufor);
        bool winner = false;
        while( !key[ KEY_ESC ] )
        {

            //player 1
            while(round<3 && !key[ KEY_ESC ])
            {
                clear_bitmap(bufor);
                clear_bitmap(p1);
                clear_bitmap(p2);

                rest(100);
                if(mouse_b & 1)
                {
                    mx=mouse_x;
                    my=mouse_y;
                    result = board.hit(mx,my);
                    player1.update(result);

                    if(player1.getscore()<=0)
                    {
                        winner = true;
                        break;
                    }
                    round++;
                }
                textprintf_ex(p1,font,10,10,makecol(255,255,255),-1,"PLAYER 1: %d",player1.getscore());
                textprintf_ex(p1,font,10,20,makecol(255,255,255),-1,"Rzut: %d",round);
                textprintf_ex(p1,font,10,30,makecol(255,255,255),-1,"Wynik: %d",result);
                textprintf_ex(p2,font,10,10,makecol(255,255,255),-1,"PLAYER 2: %d",player2.getscore());
                textprintf_ex(p2,font,10,30,makecol(255,255,255),-1,"wynik: %d",result2);
                blit(tlo,bufor,0,0,0,0,800,600);
                blit(p1,bufor,0,0,0,0,150,50);
                blit(p2,bufor,0,0,650,0,150,50);
                circlefill(bufor,board.getpoint().getx(),board.getpoint().gety(),3,makecol(0,0,255));
                blit(bufor, screen, 0, 0, 0, 0, 800, 600 );

                clear_keybuf();

            }
            if(winner || key[KEY_ESC]){
            break;
            }
            round = 0;
            rest(100);


            //player2
            while(round<3 && !key[ KEY_ESC ])
            {
                clear_bitmap(bufor);
                clear_bitmap(p1);
                clear_bitmap(p2);
                rest(100);
                if(mouse_b & 1)
                {
                    mx=mouse_x;
                    my=mouse_y;
                    result2 = board.hit(mx,my);
                    player2.update(result2);
                    if(player2.getscore()<=0)
                    {
                        winner=true;
                        break;
                    }
                    round++;
                }
                textprintf_ex(p1,font,10,10,makecol(255,255,255),-1,"PLAYER 1: %d",player1.getscore());
                textprintf_ex(p1,font,10,30,makecol(255,255,255),-1,"Wynik: %d",result);
                textprintf_ex(p2,font,10,10,makecol(255,255,255),-1,"PLAYER 2: %d",player2.getscore());
                textprintf_ex(p2,font,10,30,makecol(255,255,255),-1,"wynik: %d",result2);
                textprintf_ex(p2,font,10,20,makecol(255,255,255),-1,"Rzut: %d",round);
                blit(tlo,bufor,0,0,0,0,800,600);
                blit(p1,bufor,0,0,0,0,150,50);
                blit(p2,bufor,0,0,650,0,150,50);

                                circlefill(bufor,board.getpoint().getx(),board.getpoint().gety(),3,makecol(0,0,255));

                blit(bufor, screen, 0, 0, 0, 0, 800, 600 );

                clear_keybuf();

            }
            if(winner || key[KEY_ESC]){
                break;
            }
            rest(100);
            round = 0;


        }



        clear_bitmap(bufor);
        clear_bitmap(screen);
        clear_bitmap(p1);
        if(player1.getscore()<=0){
            textprintf_ex(p1,font,10,10,makecol(255,255,255),-1,"WINNER: PLAYER1");
            textprintf_ex(p1,font,10,20,makecol(255,255,255),-1,"Press ESC");
        }
        else {
            textprintf_ex(p1,font,10,10,makecol(255,255,255),-1,"WINNER: PLAYER2");
            textprintf_ex(p1,font,10,20,makecol(255,255,255),-1,"Press ESC");
        }

        while(!key[KEY_ESC]){
        blit(tlo,bufor,0,0,0,0,800,600);
        blit(p1,bufor,0,0,0,0,150,50);
        blit(bufor,screen,0,0,0,0,800,600);
        }

        destroy_bitmap(bufor);
        destroy_bitmap(tlo);
        destroy_bitmap(p1);
        destroy_bitmap(p2);
        state=MENU;
        rest(100);
    }

}



