#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


int Menu(SDL_Surface *screen, int *quit, TTF_Font *police)
{
    SDL_Surface *t_etatA = NULL,
                *t_etatB = NULL,
                *texte = NULL,
                *car0 = IMG_Load("./obj/car0/h1.bmp"),
                *car1 = IMG_Load("./obj/car1/h1.bmp"),
                *car2 = IMG_Load("./obj/car2/h2.bmp"),
                *car3 = IMG_Load("./obj/car3/h1.bmp"),
                *car4 = IMG_Load("./obj/car4/h1.bmp"),
                *fond = IMG_Load("./obj/fond.png");

    if ( !car0 )printf("Unable to set 640x480 video: %s\n", SDL_GetError());
    if ( !car1 )printf("Unable to set 640x480 video: %s\n", SDL_GetError());
    if ( !car2 )printf("Unable to set 640x480 video: %s\n", SDL_GetError());
    if ( !car3 )printf("Unable to set 640x480 video: %s\n", SDL_GetError());
    if ( !car4 )printf("Unable to set 640x480 video: %s\n", SDL_GetError());
    int bouton = 0, bouton2 = 0;
    t_etatA = IMG_Load("./obj/etatA.png");
    t_etatB = IMG_Load("./obj/etatB.png");

    if (!t_etatA) printf("ca marche");
    if (!t_etatB) printf("ca marche");

    int menus = 1, i = 1, perso = 0;

    while(menus == 1 && i != 0)
    {
        while (i == 1)
        {

            SDL_Event event;
            while (SDL_PollEvent(&event))
            {

                // Detecte si on clique sur la croix
                switch (event.type)
                {
                case SDL_QUIT :
                //On quitte le programme
                    *quit = 0;
                    break;
                // Detecte si une touche est appuyee
                case SDL_KEYDOWN :
                    if ( event.key.keysym.sym == SDLK_ESCAPE )
                        *quit = 0;
                    else if (event.key.keysym.sym == SDLK_DOWN)
                    {
                        bouton = (bouton+1)%3;
                    }
                    else if (event.key.keysym.sym == SDLK_UP){
                        bouton --;
                        if (bouton < 0) bouton = 2;
                    }
                    else if (event.key.keysym.sym == SDLK_RETURN){
                        if (bouton == 0) return perso+1;
                        else if (bouton == 2) i = 0;
                        else i = bouton+1;
                    }
                    break;
                }
            }
            affiche_texte_centre(bouton, screen, police, t_etatA, t_etatB, texte);
            SDL_Flip(screen);
        }
        while (i == 2)
        {
            SDL_Event event;
            while (SDL_PollEvent(&event))
            {

                // Detecte si on clique sur la croix
                switch (event.type)
                {
                case SDL_QUIT :
                //On quitte le programme
                    *quit = 0;
                    break;
                // Detecte si une touche est appuyee
                case SDL_KEYDOWN :
                    if ( event.key.keysym.sym == SDLK_ESCAPE )
                        *quit = 0;
                    else if (event.key.keysym.sym == SDLK_LEFT)
                    {
                        bouton2--;
                        if (bouton2 < 0) bouton2 = 4;
                    }
                    else if (event.key.keysym.sym == SDLK_RIGHT){
                        bouton2 = (bouton2+1)%5;
                    }
                    else if (event.key.keysym.sym == SDLK_RETURN){
                        switch (bouton2)
                        {
                        case 0 : perso = 0; i = 1; break;
                        case 1 : perso = 1; i = 1; break;
                        case 2 : perso = 2; i = 1; break;
                        case 3 : perso = 3; i = 1; break;
                        case 4 : perso = 4; i = 1; break;
                        }
                    }
                    break;
                }
            }
            affiche_perso(police, bouton2,screen, fond, car0, car1, car2, car3, car4,texte);
            SDL_Flip(screen);
        }
    }
    if (t_etatB!=NULL) SDL_FreeSurface(t_etatB);
    if (t_etatA!=NULL) SDL_FreeSurface(t_etatA);
    return perso;
}

void affiche_texte_centre (int bouton, SDL_Surface* screen, TTF_Font *police, SDL_Surface *t_etatA, SDL_Surface *t_etatB, SDL_Surface *texte)
{
    SDL_FillRect(screen,0, SDL_MapRGB(screen->format, 0, 0, 0));
    SDL_Color couleurNoire = {255,255,255};
    char str[100];
    int hauteur = t_etatA->h, i;
    int longueur = t_etatA->w;
    int posx = screen->w/2 -longueur/2;
    SDL_Rect rect;
    for (i = 0; i < 3; i++)
    {
        rect.x = posx;
        rect.y = i*screen->h/5-hauteur/2 + 100;
        if (bouton == i) SDL_BlitSurface (t_etatA, 0, screen, &rect);
        else SDL_BlitSurface (t_etatB, 0, screen, &rect);
        rect.x += 20;
        rect.y += 40;
        switch (i)
        {
            case 0 :
                sprintf(str, "Jouer");
                texte = TTF_RenderText_Solid(police, str, couleurNoire);
                SDL_BlitSurface (texte, 0, screen, &rect);
                break;
            case 1 :
                sprintf(str, "Personnage");
                texte = TTF_RenderText_Solid(police, str, couleurNoire);
                SDL_BlitSurface (texte, 0, screen, &rect);
                break;
            case 2 :
                sprintf(str, "Quitter");
                texte = TTF_RenderText_Solid(police, str, couleurNoire);
                SDL_BlitSurface (texte, 0, screen, &rect);
                break;
        }
    }
}
void affiche_perso (TTF_Font *police, int bouton, SDL_Surface* screen, SDL_Surface *fond, SDL_Surface *car0, SDL_Surface *car1, SDL_Surface *car2, SDL_Surface *car3, SDL_Surface *car4, SDL_Surface *texte)
{
    SDL_Color couleurNoire = {255,255,255};
    SDL_FillRect(screen,0, SDL_MapRGB(screen->format, 0, 0, 0));
    char str[100];
    int i;
    int longueur = car0->w;
    int posx = screen->w/2 - (longueur/2 ) * 7 ;
    SDL_Rect rect;rect.y = 200;rect.x = posx + 55 + 1;
    SDL_Rect rect2;rect2.y = 195;rect2.x = posx + 55*bouton - 3;
    SDL_Rect rect3;rect3.y = screen->h/2 + 50;rect3.x = screen->w/2 - 50;
    SDL_BlitSurface(fond, 0, screen, &rect2);
    for (i = 0; i < 5; i++)
    {
        rect.x = posx + (i) * 55 + 1;

        switch (i)
        {
            case 0 :
                if (i==bouton)sprintf(str, "Wario");
                SDL_SetColorKey(car0, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(car0->format, 255,255,255));
                SDL_BlitSurface (car0, 0, screen, &rect);
                break;
            case 1 :
                if (i==bouton)sprintf(str, "Luigi");
                SDL_SetColorKey(car1, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(car1->format, 255,255,255));
                SDL_BlitSurface (car1, 0, screen, &rect);
                break;
            case 2 :
                if (i==bouton)sprintf(str, "Donkey K.");
                SDL_SetColorKey(car2, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(car2->format, 255,255,255));
                SDL_BlitSurface (car2, 0, screen, &rect);
                break;
            case 3 :
                if (i==bouton)sprintf(str, "Mario");
                SDL_SetColorKey(car3, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(car3->format, 255,255,255));
                SDL_BlitSurface (car3, 0, screen, &rect);
                break;
            case 4 :
                if (i==bouton)sprintf(str, "Yoshi");
                SDL_SetColorKey(car4, SDL_SRCCOLORKEY|SDL_RLEACCEL, SDL_MapRGB(car4->format, 255,255,255));
                SDL_BlitSurface (car4, 0, screen, &rect);
                break;
        }
        texte = TTF_RenderText_Solid(police, str, couleurNoire);
        SDL_BlitSurface(texte, 0, screen, &rect3);
    }
}


