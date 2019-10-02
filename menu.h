#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

int Menu(SDL_Surface *screen, int *quit, TTF_Font *police);
void affiche_texte_centre (int bouton, SDL_Surface* screen, TTF_Font *police, SDL_Surface *t_etatA, SDL_Surface *t_etatB, SDL_Surface *texte);
void affiche_perso (TTF_Font *police, int bouton, SDL_Surface* screen, SDL_Surface *fond, SDL_Surface *car0, SDL_Surface *car1, SDL_Surface *car2, SDL_Surface *car3, SDL_Surface *car4, SDL_Surface *texte);
