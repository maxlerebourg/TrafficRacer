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

int longueur(liste *plist)
{
    liste lis = *plist;
    if (lis != NULL)return 1 + longueur(&(lis->succ));
}
void initDecor(liste *pdecor, int pos, char img)
{
    liste decor = *pdecor = malloc(sizeof(voiture));
    decor->vit = 0;
    decor->pos.x = 0;
    decor->pos.y = 0;
    decor->img = 0;
    decor->depasser = 1;
    decor->succ = NULL;
}
void ajouterDecor(liste *pdecor, int pos, char img)
{
    liste decor = *pdecor;
    if (decor->succ != NULL) ajouterDecor(&(decor->succ), pos, img);
    if (decor->succ == NULL)
    {
        decor->succ = malloc(sizeof(voiture));
        decor->succ->vit = 50;
        decor->succ->pos.x = pos;
        decor->succ->pos.y = 0;
        decor->succ->img = img;
        decor->succ->depasser = 1;
        decor->succ->succ = NULL;
    }
}
void suppDecor(liste *pdecor)
{
    if (*pdecor != NULL && (*pdecor)->succ != NULL)
    {
        if ((*pdecor)->succ->pos.y > 1000)
        {
            voiture *decorSucc = (*pdecor)->succ;
            (*pdecor)->succ = (*pdecor)->succ->succ;
            free(decorSucc);
        }
        suppDecor(&(*pdecor)->succ);
    }
}
void avancerDecor(liste *pdecor, voiture joueur)
{
    if (*pdecor != NULL){
        //liste decor = *pdecor;
        if (joueur.vit > (*pdecor)->vit) //decor->pos.y -= (decor->vit - joueur.vit)/20;
        avancer(&((*pdecor)->succ), joueur);
    }
}
void initialisation(liste *pcar,int vitesse, int pos, char img, int in)
{
    liste car = *pcar = malloc(sizeof(voiture));
    car->vit_max = vitesse;
    car->vit = vitesse;
    car->pos.x = in + 55 * pos;
    car->lane = pos;
    car->pos.y = 0;
    car->img = img;
    car->depasser = 0;
    car->succ = NULL;
}
void ajouterVoiture(liste *pcar, int vitesse, int pos, char img, int in)
{
    liste car = *pcar;
    if (car->succ != NULL) ajouterVoiture(&(car->succ),vitesse, pos, img, in);
    if (car->succ == NULL)
    {
        car->succ = malloc(sizeof(voiture));
        car->succ->vit_max = vitesse;
        car->succ->vit = vitesse;
        car->succ->pos.x = in + 55 * pos;
        car->succ->lane = pos;
        car->succ->pos.y = -rand()%500;
        car->succ->img = img;
        car->succ->depasser = 0;
        car->succ->succ = NULL;
    }
}
void ajouterJoueur(liste *pcar, voiture *joueur)
{
    if ((*pcar)->succ != NULL) ajouterJoueur(&((*pcar)->succ), joueur);
    if ((*pcar)->succ == NULL)
    {
        (*pcar)->succ = malloc(sizeof(voiture));
        (*pcar)->succ = joueur;
    }
}
void suppListe(liste *pcar)
{
    if (*pcar != NULL && (*pcar)->succ != NULL)
    {
        if ((*pcar)->succ->img == 0 || (*pcar)->succ->pos.y > 2000 || (*pcar)->succ->pos.y < -900)
        {
            voiture *carSucc = (*pcar)->succ;
            (*pcar)->succ = (*pcar)->succ->succ;
            free(carSucc);
            carSucc = NULL;
        }
        suppListe(&(*pcar)->succ);
    }

}
voiture initJoueur(SDL_Surface *screen, voiture joueur, int vitesse, int pos, SDL_Surface *car1, SDL_Surface *car2)
{
    joueur.vit_max = Vit_Max;
    joueur.vit = vitesse;
    joueur.h1 = car1;
    joueur.h2 = car2;
    joueur.point = 0;
    joueur.lane = 0;
    joueur.depasser = -1;
    joueur.surface = joueur.h1;
    joueur.pos.x = (screen->w - joueur.h1->w) / 2;
    joueur.pos.y = screen->h - 100;
    return joueur;
}
void avancer(liste *pcar, voiture joueur)
{
    if (*pcar != NULL){
        (*pcar)->pos.y -= ((*pcar)->vit - joueur.vit)/10;
        avancer(&((*pcar)->succ), joueur);
    }
}
void accident(liste *pcar, voiture joueur){
    liste car = *pcar, currentCar = car;
    if (car != NULL && currentCar != NULL)
    {
        while (currentCar != NULL && car != NULL)
        {
            while (car != NULL && car != currentCar)
            {
                if (Collision(car->pos, currentCar->pos, joueur.surface) && currentCar->img != 0)
                {
                    car->vit = 0;
                    car->img = 0;
                    car->pos.x -= 10;
                    currentCar->pos.x -= 10;
                    currentCar->vit = 0;
                    currentCar->img = 0;
                }
                car = car->succ;
                //fprintf(stderr,"coc\n");
            }
            currentCar = currentCar->succ;
            car = *pcar;
        }
    }
}

int Collision(SDL_Rect R1 , SDL_Rect R2, SDL_Surface *surface)
{
    if ((R1.x + surface->w < R2.x)
      ||(R1.y + surface->h < R2.y)
      ||(R1.x > R2.x + surface->w)
      ||(R1.y > R2.y + surface->h))
        return 0;
    return 1;
}
int carrambolage (liste car, voiture joueur)
{
    int i = 1;
    while (car != NULL){
        if (Collision(joueur.pos, car->pos, joueur.surface)) i = 0;
        car = car->succ;
    }
    return i;
}
int compare(voiture v1, voiture v2)
{
    if (v1.lane == v2.lane && v1.vit == v2.vit) return 0;
    return 1;
}

int point(liste car, voiture joueur)
{
    if (car != NULL)
    {
        if ((car->pos.y + joueur.surface->h > joueur.pos.y)
        &&(car->pos.y < joueur.pos.y + joueur.surface->h)
        && car->depasser != 1)
        {
            car->depasser = 1;
            joueur.point += joueur.vit - car->vit;
        }
        return point(car->succ, joueur);
    }
    return joueur.point;
}
voiture automates(liste car, voiture joueur, int X, int in)
{
    int laned[X], i;
    for (i=0; i<X; i++) laned[i] = 0;
    while (car != NULL)
    {
        if (car->pos.y > joueur.pos.y - 150
        && car->pos.y < joueur.pos.y + 100
        && compare(joueur, *car))
        {
            laned[car->lane] = 1;
        }
        car = car->succ;
    }

    if (laned[joueur.lane] == 0)
    {
        int center = in + 55 * joueur.lane;
        if (joueur.pos.x <= center) joueur.pos.x += 10;
        if (joueur.pos.x >= center) joueur.pos.x -= 10;
        if (joueur.vit < joueur.vit_max) joueur.vit ++;
        return joueur;
    }
    else
    {
        int middle = joueur.lane;
        for (i=0; i<3; i++)
        {
            if (i%2 == 0 && joueur.lane <= X/2){middle = (middle - i); if (middle<0)middle = 1;}
            if (i%2 == 1 && joueur.lane <= X/2){middle = (middle + i); if (middle>=X)middle = X-2;}
            if (i%2 == 0 && joueur.lane > X/2) {middle = (middle + i); if (middle>=X)middle = X-2;}
            if (i%2 == 1 && joueur.lane > X/2) {middle = (middle - i); if (middle<0)middle = 1;};
            if (laned[middle] == 0)
            {
                joueur.vit -= 5;
                if (middle < joueur.lane) joueur.pos.x -= 20;
                if (middle > joueur.lane) joueur.pos.x += 20;
                joueur.lane = (joueur.pos.x - in + 20) / 55;
                return joueur;
            }
            if (i == 2)
            {
                joueur.vit -= 10;
                return joueur;
            }

        }
    }
    return joueur;
}
