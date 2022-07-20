#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

void boucle_de_jeux();                            // Protocole de la boucle
void les_condition(int nbrentre, int nbrmystere); // Protocole de la condition
void recherche();                                 // Protocole de recherche
void Regle_du_jeux();                             // Protocole de description
/*---------------------------------------------------------------------------*/
int cpt = 0, nbr_mystere = 0, nbr_entre = 0; // variable globale disponible sur tous le programme

int main()
{
    // Intiallisation du nombre mystère par le programme
    srand(time(NULL));
    Regle_du_jeux();  // fonction de description    
    boucle_de_jeux(); // fonction de la boucle

    getch();
    return 0;
}
/*----------------------------------------------------------------------------*/
/**
 * `boucle_de_jeux()` est une fonction qui génère un nombre aléatoire entre 1 et 100, puis invite
 * l'utilisateur à deviner le nombre. Si l'utilisateur devine correctement, le jeu se termine. Si
 * l'utilisateur devine mal, le jeu continue jusqu'à ce que l'utilisateur ait deviné 10 fois ou jusqu'à
 * ce que l'utilisateur devine correctement
 */
void boucle_de_jeux()
{
    const int MAX = 100, MIN = 1;                   // variable local
    nbr_mystere = (rand() % (MAX - MIN + 1)) + MIN; // formule de choix aleatoire du nombre mystère
    do
    {
        printf("\nQuelle est le nombre ?--> ");
        scanf("%d", &nbr_entre); // Saisi du nombre par l'utilisateur

        les_condition(nbr_entre, nbr_mystere); // boucle de comparaison avec le nombre mystère

    } while (cpt != 10 && nbr_entre != nbr_mystere); // conditon de comparaison
    //* tanque le nombre choisi n'est pas égal au nombre mystère, on reste dans la boucle
}

/**
 * Il prend deux entiers comme paramètres, les compare et imprime un message basé sur la comparaison
 * 
 * @param nbrentre Le numéro entré par l'utilisateur
 * @param nbrmystere Le nombre à deviner
 */
void les_condition(int nbrentre, int nbrmystere)
{

    if (nbr_entre != 0)
    {

        if (nbrmystere > nbrentre)
        {
            recherche();
            printf(" Essayez un nombre plus grand !\n");
            Sleep(400); // Ralentir l'execution
        }
        else if (nbrmystere < nbrentre)
        {
            recherche();
            printf(" Essayez un nombre plus petit !\n");
            Sleep(400); // Ralentir l'execution
        }
        else
        {
            recherche();
            printf(" Bravo, vous avez trouve le nombre mystere !!!\n");
            printf("Avec %d tentative.\n", cpt + 1);
        }
        cpt++;
    }
    else
    {
        getch();
        exit(0);
    }
}

void recherche()
{ // fonction de recherche
    for (int i = 0; i <= 3; i++)
    {
        Sleep(700); // Ralentir l'execution
        printf(".");
    }
}

/**
 * Cette fonction imprime les règles du jeu
 */
void Regle_du_jeux()
{ // fonction de description des régles du jeu
    printf("\n\t=== Description du game ===\n\n");
    printf("Le progamme choisi un nombre entre 1 et 100.\n");
    printf("Tentez votre chance pour touver ce nombre (celui choisi par le programme ).\n");
    printf("C'est tres simple ce jeux consiste a faire moins de 10 tentative pour le trouver ou \nSaisir 0 pour quittez le programme.\n");
    printf("Vous etes pret(e) C'est parti  !!!\n");
}