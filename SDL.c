#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "fonction.h"
#include "menu.h"

static int X = 5;
static SDL_Surface *caro;
static SDL_Surface *car0;
static SDL_Surface *car1;
static SDL_Surface *car2;
static SDL_Surface *car3;
static SDL_Surface *car4;
static SDL_Surface *car5;
static SDL_Surface *car6;
static SDL_Surface *car7;
static SDL_Surface *car8;
static SDL_Surface *boom;
static SDL_Surface *route;
static SDL_Surface *routes;
static SDL_Surface *paysage;
static SDL_Surface *texte1;
static SDL_Surface *texte2;
static SDL_Surface *texte3;
static SDL_Surface *texte4;
static SDL_Surface *d1;
static SDL_Surface *d2;
static SDL_Surface *d3;
static SDL_Surface *d4;
static SDL_Surface *d5;
static SDL_Surface *jauge;
static SDL_Surface *jaugette1;
static SDL_Surface *jaugette2;
static SDL_Surface *ex1;
static SDL_Surface *ex2;
static SDL_Surface *ex3;
static SDL_Surface *ex4;
static SDL_Surface *ex5;


void load()
{
    ex1 = IMG_Load("./obj/exp1.gif");
    ex2 = IMG_Load("./obj/exp2.gif");
    ex3 = IMG_Load("./obj/exp3.gif");
    ex4 = IMG_Load("./obj/exp4.gif");
    ex5 = IMG_Load("./obj/exp5.gif");
    paysage = IMG_Load("./obj/paysage.jpg");
    route = IMG_Load("./obj/route.bmp");
    routes = IMG_Load("./obj/routes.bmp");
    caro  = IMG_Load("./obj/car0/h1.bmp");
    car0 = IMG_Load("./obj/car0/h2.bmp");
    car1 = IMG_Load("./obj/car1/h1.bmp");
    car2 = IMG_Load("./obj/car1/h2.bmp");
    car3 = IMG_Load("./obj/car2/h1.bmp");
    car4 = IMG_Load("./obj/car2/h2.bmp");
    car5 = IMG_Load("./obj/car3/h1.bmp");
    car6 = IMG_Load("./obj/car3/h2.bmp");
    car7 = IMG_Load("./obj/car4/h1.bmp");
    car8 = IMG_Load("./obj/car4/h2.bmp");
    boom = IMG_Load("./obj/exp1.gif");
    d1 = IMG_Load("./obj/decor/1.png");
    d2 = IMG_Load("./obj/decor/2.png");
    d3 = IMG_Load("./obj/decor/3.png");
    d4 = IMG_Load("./obj/decor/4.png");
    d5 = IMG_Load("./obj/decor/5.png");
    jauge = IMG_Load("./obj/jauge.jpg");
    jaugette1 = IMG_Load("./obj/jaugette.jpg");
    jaugette2 = IMG_Load("./obj/jaugette2.jpg");
    if ( !route )printf("Unable to set 640x480 video: %s\n", SDL_GetError());
    if ( !routes )fprintf(stderr, "Unable to set 640x480 video: %s\n", SDL_GetError());
    if ( !car1 )printf("Unable to set 640x480 video: %s\n", SDL_GetError());
    if ( !car2 )printf("Unable to set 640x480 video: %s\n", SDL_GetError());
    if ( !car3 )printf("Unable to set 640x480 video: %s\n", SDL_GetError());
    if ( !car4 )printf("Unable to set 640x480 video: %s\n", SDL_GetError());
    if ( !d1 )printf("Unable to set 640x480 video: %s\n", SDL_GetError());
    if ( !d2 )printf("Unable to set 640x480 video: %s\n", SDL_GetError());
    if ( !d3 )printf("Unable to set 640x480 video: %s\n", SDL_GetError());
    if ( !d4 )printf("Unable to set 640x480 video: %s\n", SDL_GetError());
    if ( !d5 )printf("Unable to set 640x480 video: %s\n", SDL_GetError());
    SDL_SetColorKey(caro, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(car1->format, 255,255,255));
    SDL_SetColorKey(car0, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(car2->format, 255,255,255));
    SDL_SetColorKey(car1, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(car1->format, 255,255,255));
    SDL_SetColorKey(car2, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(car2->format, 255,255,255));
    SDL_SetColorKey(car3, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(car3->format, 255,255,255));
    SDL_SetColorKey(car4, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(car4->format, 255,255,255));
    SDL_SetColorKey(car5, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(car1->format, 255,255,255));
    SDL_SetColorKey(car6, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(car2->format, 255,255,255));
    SDL_SetColorKey(car7, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(car3->format, 255,255,255));
    SDL_SetColorKey(car8, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(car4->format, 255,255,255));

}
void afficherCar(SDL_Surface *screen, liste car, int val)
{
    if (car != NULL)
    {
        if (car->pos.y > 0 && car->pos.y < screen->h)
        {
            if (car->img != 0)
            {
                switch (car->img)
                {
                case 0 :
                    SDL_BlitSurface(boom, NULL, screen, &(car->pos));
                    break;
                case 1 :
                    if (val%2 == 0) SDL_BlitSurface(car1, NULL, screen, &(car->pos));
                    else SDL_BlitSurface(car2, NULL, screen, &(car->pos));
                    break;
                case 2 :
                    if (val%2 == 0) SDL_BlitSurface(car3, NULL, screen, &(car->pos));
                    else SDL_BlitSurface(car4, NULL, screen, &(car->pos));
                    break;
                case 3 :
                    if (val%2 == 0) SDL_BlitSurface(car5, NULL, screen, &(car->pos));
                    else SDL_BlitSurface(car6, NULL, screen, &(car->pos));
                    break;
                case 4 :
                    if (val%2 == 0) SDL_BlitSurface(car7, NULL, screen, &(car->pos));
                    else SDL_BlitSurface(car8, NULL, screen, &(car->pos));
                    break;
                case 5 :
                    if (val%2 == 0) SDL_BlitSurface(caro, NULL, screen, &(car->pos));
                    else SDL_BlitSurface(car0, NULL, screen, &(car->pos));
                    break;
                default :
                    if (val%2 == 0) SDL_BlitSurface(car1, NULL, screen, &(car->pos));
                    else SDL_BlitSurface(car2, NULL, screen, &(car->pos));
                }
            }
            else
            {
                car->depasser++;
                switch (car->depasser)
                {
                    case 1 : SDL_BlitSurface(ex1, NULL, screen, &(car->pos)); break;
                    case 2 : SDL_BlitSurface(ex2, NULL, screen, &(car->pos));
                    case 3 : SDL_BlitSurface(ex3, NULL, screen, &(car->pos));
                    case 4 : SDL_BlitSurface(ex4, NULL, screen, &(car->pos));
                    case 5 : SDL_BlitSurface(ex5, NULL, screen, &(car->pos));
                }
            }
        }
        afficherCar(screen, car->succ, val);
    }
}
void afficherDecor(SDL_Surface *screen, liste decor)
{
    if (decor != NULL)
    {
        if (decor->pos.y > 0 && decor->pos.y < screen->h)
        {
            switch (decor->img)
            {
                case 0 : SDL_BlitSurface(d1, NULL, screen, &(decor->pos)); break;
                case 1 : SDL_BlitSurface(d1, NULL, screen, &(decor->pos)); break;
                case 2 : SDL_BlitSurface(d2, NULL, screen, &(decor->pos)); break;
                case 3 : SDL_BlitSurface(d3, NULL, screen, &(decor->pos)); break;
                case 4 : SDL_BlitSurface(d4, NULL, screen, &(decor->pos)); break;
                case 5 : SDL_BlitSurface(d5, NULL, screen, &(decor->pos)); break;
                default :SDL_BlitSurface(d1, NULL, screen, &(decor->pos));
            }
        }
        afficherDecor(screen, decor->succ);
    }
}
SDL_Rect creerRoute(SDL_Surface *screen, voiture joueur, SDL_Rect poss)
{
    SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 127, 221, 86));
    int i, j = ((poss.y + joueur.vit)%1000 - 2000), k;
    SDL_Rect pos;
    pos.y = (screen->h - route->h) / 2;
    for (i = 0; i < X; i++)
    {
        pos.x = (screen->w - route->w) / 2 - X/2 * 55 + i * 55;
        if (i == 0) {pos.x-=5;SDL_BlitSurface(paysage,0,screen,&pos);pos.x+=5;}
        if (i == X-1) {pos.x+=50;SDL_BlitSurface(paysage,0,screen,&pos);pos.x-=50;}
        poss.x = pos.x - 5;
        k = j;
        poss.y = k;
        while (poss.y < screen->h && i > 0)
        {
            k += 60;
            poss.y = k;
            SDL_BlitSurface(routes, NULL, screen, &poss);
        }
        SDL_BlitSurface(route, NULL, screen, &pos);
    }
    poss.y = j;

    return poss;
}

void automatique(liste car, int in)
{
    liste carComplet = car;
    while(car != NULL)
    {
        voiture *car2 = car;
        (*car2) = automates(carComplet,(*car2), X, in);
        car = car->succ;
    }
    free(carComplet);
}
char *bestScore(char bs[5], int i)
{
    if (i==1)
    {
        FILE *fic = fopen("./obj/BestScore.txt", "r");
        if (fic != NULL)
        {
            fgets(bs, 6, fic);
            fclose(fic);
        }
        return bs;
    }
    else
    {
        FILE *fic = fopen("./obj/BestScore.txt", "w+");
        if (fic != NULL)
        {
            fputs(bs, fic);
            fclose(fic);
        }
    }
    return "0";
}
void afficherJauge(SDL_Surface *screen, SDL_Rect pos1, voiture joueur)
{
    int i, j = joueur.vit_max / 27, k = jauge->w / 27;
    for(i = 0; i < 27; i++)
    {
        pos1.x = 10 + k * i;
        if(joueur.vit > j * i)
        {
            if(i*k > 200) SDL_BlitSurface(jaugette2, 0, screen, &pos1);
            else SDL_BlitSurface(jaugette1, 0, screen, &pos1);
        }
    }
}
int main (int argc, char** argv )
{

    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    // create a new window
    SDL_Surface* screen = SDL_SetVideoMode(500,500, 8, SDL_HWSURFACE);
    if ( !screen )
    {
        printf("Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }
    SDL_WM_SetCaption("Traffic Racer", NULL);
    SDL_EnableKeyRepeat(100, 40);

    //initialize SDL_TTF
    if(TTF_Init() == -1) fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    TTF_Font *police = TTF_OpenFont("./obj/renogare.ttf", 40);
    TTF_Font *police2 = TTF_OpenFont("./obj/renogare.ttf", 20);
    TTF_Font *police3 = TTF_OpenFont("./obj/renogare.ttf", 30);
    SDL_Color couleurNoire = {20,20,20};
    SDL_Rect poss;
    SDL_Rect pos1; pos1.x = 10; pos1.y = 10;
    SDL_Rect pos2; pos2.x = 0; pos2.y = 50;
    SDL_Rect pos3; pos3.x = 0; pos3.y = screen->h - 20;
    SDL_Rect pos4; pos4.x = 0; pos4.y = 100;
    char text1[100],text2[100],text3[100], text4[100];

    //Initialisation de l'API Mixer
    /*if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) printf("%s", Mix_GetError());
    Mix_AllocateChannels(10);
    Mix_Chunk *acc = Mix_LoadWAV("./obj/accelerer.wav");
    if (!acc) fprintf(stderr, "Son Accélération raté.");
    Mix_Music *music = Mix_LoadMUS("./obj/music.mp3");
    Mix_PlayMusic(music, -1);
    Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
    Mix_VolumeChunk(acc, MIX_MAX_VOLUME);*/


    // make sure SDiL cleans up before exit
    atexit(SDL_Quit);


    // load images
    load();

    // initilisation des variables
    srand(time(NULL));
    int in = (screen->w - route->w) / 2 - X/2 * 55 + (route->w - car1->w) / 2;
    int perso = 1;
    perso = Menu(screen, &perso, police3);
    if (perso==0)exit(-1);
    voiture joueur;
    if (perso == 1) joueur = initJoueur(screen, joueur, 100, X/2, caro, car0);
    else if (perso == 2) joueur = initJoueur(screen, joueur, 100, X/2, car1, car2);
    else if (perso == 3) joueur = initJoueur(screen, joueur, 100, X/2, car3, car4);
    else if (perso == 4) joueur = initJoueur(screen, joueur, 100, X/2, car5, car6);
    else if (perso == 5) joueur = initJoueur(screen, joueur, 100, X/2, car7, car8);

    joueur.lane = (joueur.pos.x - in + 20) / 55;


    liste car = NULL;
    liste decors = NULL;
    initialisation(&car, 50, 0, 4, in);
    initDecor(&decors, 0, 1);

    char bs[5]; bestScore(bs, 1);
    sprintf(text4, "Best Score : %d", atoi(bs));
    texte4 = TTF_RenderText_Solid(police2, text4, couleurNoire);
    int h = 0, i = 1, j = 1, k = 0, autom = 0, pause = 0, adieux = 0;
    double temps1 = SDL_GetTicks(), temps2 = 0, temps3 = 0, temps4 = -2^32;
    // program main loop

    while (i > 0)
    {
        if (temps1 - temps3 > 100 && pause != 1)
        {
            temps3 = temps1;
            if (rand()%100 < 5) ajouterDecor(&decors, rand()%2*55+in+55*X, rand()%5 +1);
            if (rand()%100 < 10) ajouterDecor(&decors, rand()%2 *55, rand()%5 +1);
            suppListe(&car);
            suppDecor(&decors);
            j++;
            if (j%2 == 0 && joueur.depasser != 1) joueur.surface = joueur.h1;
            if (j%2 == 1 && joueur.depasser != 1) joueur.surface = joueur.h2;
            if (joueur.depasser == 1)
            {
                k++;
                switch (k)
                {
                    case 1 : joueur.surface = ex1; break;
                    case 2 : joueur.surface = ex2; break;
                    case 3 : joueur.surface = ex3; break;
                    case 4 : joueur.surface = ex4; break;
                    case 5 : joueur.surface = ex5; break;
                }
            }
            if(joueur.vit > 0) joueur.vit -= 2;
            in = (screen->w - route->w) / 2 - X/2 * 55 + (route->w - car1->w) / 2;
        }
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                perso = 0;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        perso = 0;
                    if (event.key.keysym.sym == SDLK_UP && joueur.vit < 250 && pause != 1){
                        //Mix_PlayChannel(2, acc, 0);
                        if (joueur.vit < 100) joueur.vit += 6;
                        else if (joueur.vit < 150) joueur.vit += 4;
                        else if (joueur.vit < 200) joueur.vit += 3;
                        else if (joueur.vit < 250) joueur.vit += 2;
                        if (joueur.vit > 250) joueur.vit = 250;
                    }
                    if (event.key.keysym.sym == SDLK_DOWN && joueur.vit > 1 && pause != 1){
                       	if (joueur.vit < 100) joueur.vit -= 5;
                        else if (joueur.vit < 150) joueur.vit -= 10;
                        else if (joueur.vit < 200) joueur.vit -= 15;
                        else if (joueur.vit <= 250) joueur.vit -= 20;
                        if (joueur.vit < 1 ) joueur.vit = 1;
                    }
                    if (event.key.keysym.sym == SDLK_LEFT && joueur.pos.x > in && pause != 1){
                        joueur.pos.x -= 0.1 * joueur.vit;
                        joueur.lane = (joueur.pos.x - in + 20) / 55;
                    }
                    if (event.key.keysym.sym == SDLK_RIGHT && joueur.pos.x < in + (X-1) * 55 && pause != 1){
                        joueur.pos.x += 0.1 * joueur.vit;
                        joueur.lane = (joueur.pos.x - in + 20) / 55;
                    }
                    if (event.key.keysym.sym == SDLK_SPACE && pause != 1){
                        //Automatic
                        if (autom == 1) autom = 0;
                        else autom = 1;
                    }
                    if (event.key.keysym.sym == SDLK_BACKSPACE){
                        if (pause == 0) pause = 1;
                        else pause = 0;
                    }
                    if (event.key.keysym.sym == SDLK_CAPSLOCK){
                        if (adieux == 0) adieux = 1;
                        else adieux = 0;
                    }
                    break;
                }
            } // end switch
        } // end of message processing

        SDL_FillRect(screen, 0, 0);
        temps1 = SDL_GetTicks();
        bestScore(bs, 1);
        sprintf(text4, "Best Score : %d", atoi(bs));
        texte4 = TTF_RenderText_Solid(police2, text4, couleurNoire);
        if (temps1-temps4 > 500)
        {
            //temps4 = temps1;
            if (perso == -1)
                perso = 0;
        }
        if (temps1 - temps2 > 20 && pause != 1)
        {
            temps2 = temps1;
            if (rand()%100 < X) ajouterVoiture(&car, (rand()%100) + 100, rand()%X, (rand()%5) + 1, in);
            avancer(&car, joueur);
            avancerDecor(&decors, joueur);

            poss = creerRoute(screen, joueur, poss);

            h = longueur(&decors);
            if (h > 0)
            sprintf(text1, "Vitesse : %3d", joueur.vit);
            sprintf(text2, "Points : %5d", joueur.point);
            sprintf(text3, "Auto not actif (Space), Pause (BackSpace)");
            if (autom == 1)
            {
                sprintf(text3, "Auto actif (Space), Pause (BackSpace)");
                joueur = automates(car, joueur, X, in);
            }
            if (adieux == 1) automatique(car, in);

            //SDL_SetColorKey(joueur.surface, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB((joueur.surface)->format, 255,255,255));
            texte1 = TTF_RenderText_Solid(police, text1, couleurNoire);
            texte2 = TTF_RenderText_Solid(police, text2, couleurNoire);
            texte3 = TTF_RenderText_Solid(police2, text3, couleurNoire);

            SDL_BlitSurface(jauge, 0, screen, &pos1);
            afficherJauge(screen, pos1, joueur);
            SDL_BlitSurface(texte2, 0, screen, &pos2);
            SDL_BlitSurface(texte3, 0, screen, &pos3);
            SDL_BlitSurface(texte4, 0, screen, &pos4);
            SDL_BlitSurface(joueur.surface, 0, screen, &(joueur.pos));
            afficherCar(screen, car, j);
            afficherDecor(screen, decors);
            joueur.point = point(car, joueur);
            accident(&car, joueur);
            if(!carrambolage(car, joueur) && joueur.depasser != 1)
            {
                temps4 = SDL_GetTicks();
                perso = -1;
                joueur.depasser = 1;
                joueur.surface = ex1;
                SDL_BlitSurface(joueur.surface, 0, screen, &(joueur.pos));
            }
            // DRAWING ENDS HERE

            // finally, update the screen :)
            SDL_Flip(screen);

            // best score maj
            if (joueur.point > atoi(bs))
            {
                sprintf(bs, "%d", joueur.point);
                bestScore(bs, 0);
            }

            // partie perdu, envoie du menu
            if (perso == 0)
            {
                autom = 0;
                i=1;
                k=0;
                adieux = 0;
                perso = Menu(screen, &perso, police);
                if (perso == 0) exit(-1);
                if (perso == 1) joueur = initJoueur(screen, joueur, 100, X/2, caro, car0);
                else if (perso == 2) joueur = initJoueur(screen, joueur, 100, X/2, car1, car2);
                else if (perso == 3) joueur = initJoueur(screen, joueur, 100, X/2, car3, car4);
                else if (perso == 4) joueur = initJoueur(screen, joueur, 100, X/2, car5, car6);
                else if (perso == 5) joueur = initJoueur(screen, joueur, 100, X/2, car7, car8);
                car = NULL;
                decors = NULL;
                initialisation(&car, 150, 1, 4, in);
                initDecor(&decors, 0, 1);

            }
        }

    } // end main loop

    // free loaded bitmap

    TTF_CloseFont(police);
    TTF_CloseFont(police2);
    TTF_CloseFont(police3);
    TTF_Quit();
    //Mix_CloseAudio();

    // all is well ;)
    printf("Exited cleanly\n");
    return 0;
}
