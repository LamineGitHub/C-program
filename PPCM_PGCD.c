#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void affiche_le_menu_de_choix();
void choix();
void PPCM();
void PGCD();

//*_____Fontion principale_________________*/
int main(int argc, char const *argv[])
{
    choix();

    getch();
    return 0;
}

/**
 * Cette fonction affiche le menu des choix à l'utilisateur
 */
void affiche_le_menu_de_choix()
{
    printf("\nChoisir entre les opperations  suivantes :\n");
    printf(" 1. PPCM\n");
    printf(" 2. PGCD\n");
    printf(" 3. Quitter le programme\n");
    printf("---------------------- \n");
}


/**
 * Il affiche un menu, demande à l'utilisateur de choisir une option, puis appelle la fonction
 * appropriée
 */
void choix()
{
    int choix = 0;
    do
    { // forcer l'utilisateur à choisir un nombre entre 1 et 3
        affiche_le_menu_de_choix();
        printf("Faite votre choix >");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            PPCM(); // Fonction de saisi des nombres pour les operation
            break;
        case 2:
            PGCD();
            break;
        case 3: // Sortie du programme si l'utilisateur choisi l'option 3
            break;
        }
    } while (choix != 3);
    //-------------------- Fin de forcage --------------------------
}


/**
 * Il prend deux nombres, les additionne jusqu'à ce qu'ils soient égaux, puis imprime le résultat
 */
void PPCM()
{
    int nbr1 = 0, nbr2 = 0, som1 = 0, som2 = 0;

    do
    {
        printf("\nSaisir des nombres positifs et differents de 0\n");
        printf("Saisir le premiere nombre : ");
        scanf("%d", &nbr1);
        printf("Saisir le deuxieme nombre : ");
        scanf("%d", &nbr2);

    } while (nbr1 <= 0 || nbr2 <= 0);

    som1 = nbr1;
    som2 = nbr2;

    while (som1 != som2)
    {
        if (som1 > som2)
            som2 += nbr2; // som2 = som2 + nbr2;
        else
            som1 += nbr1; // som1 = som1 + nbr1;
    }
    printf("le PPCM des deux nombres est : %d\n", som2);

    getch();
}
/*------------------------------------------------------------------------------*/
/**
 * La fonction demande à l'utilisateur d'entrer deux entiers positifs, puis elle calcule le plus grand
 * commun diviseur des deux nombres
 */
void PGCD()
{
    int dividende = 0, diviseur = 0, reste = 0;

    do
    {
        printf("\nSaisir des nombres positifs et differents de 0\n");
        printf("Saisir la dividende : ");
        scanf("%d", &dividende);
        printf("Saisir le diviseur : ");
        scanf("%d", &diviseur);
    } while (dividende <= 0 || diviseur <= 0);

    do
    {
        reste = dividende % diviseur;
        dividende = diviseur;
        diviseur = reste;
        reste = dividende % diviseur;

    } while (reste != 0);

    printf("le PGCD des deux nombres est : %d\n", diviseur);

    getch();
}