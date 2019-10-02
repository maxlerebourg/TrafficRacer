#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

#define Vit_Max 250

typedef struct voiture {
    int vit;
    int vit_max;
    int lane;
    SDL_Rect pos;
    SDL_Surface *surface;
    SDL_Surface *h1;
    SDL_Surface *h2;
    char img;
    int point;
    char depasser;
    struct voiture *succ;
} voiture;
typedef voiture *liste;

void ajouterJoueur(liste *pcar, voiture *joueur);
void suppListe(liste *pcar);
void initialisation(liste *pcar,int vitesse, int pos, char img, int in);
void ajouterVoiture(liste *pcar, int vitesse, int pos, char img, int in);
voiture initJoueur(SDL_Surface *screen, voiture joueur, int vitesse, int pos, SDL_Surface *car1, SDL_Surface *car2);
void avancer(liste *pcar, voiture joueur);
void accident(liste *pcar, voiture joueur);
int Collision(SDL_Rect R1 , SDL_Rect R2, SDL_Surface *surface);
int carrambolage (liste car, voiture joueur);
int point(liste car, voiture joueur);
voiture automates(liste car, voiture joueur, int X, int in);
int compare(voiture v1, voiture v2);

void initDecor(liste *pdecor, int pos, char img);
void ajouterDecor(liste *pdecor, int pos, char img);
void suppDecor(liste *pdecor);
void avancerDecor(liste *pdecor, voiture joueur);
