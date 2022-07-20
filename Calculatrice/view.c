#include <stdio.h>
#include <conio.h>
#include "view.h"

void affiche_menu_operateur()
{
    printf("\nChoisir entre les operateurs suivants :\n");
    printf(" 1. Addition\n");
    printf(" 2. Soustraction\n");
    printf(" 3. Multiplication\n");
    printf(" 4. Division\n");
    printf(" 5. Quitter le programme\n");
    printf("---------------------- \n");
}
//*-------------------------Fonction de choix d'operateur----------------------------*/
void choix()
{
    int choix = 0;
    do
    { // forcer l'utilisateur à choisir un nombre entre 1 et 5
        affiche_menu_operateur();
        printf("Faite votre choix >");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            demande_nombre(choix); // Fonction de saisi des nombres pour les operation
            break;
        case 2:
            demande_nombre(choix);
            break;
        case 3:
            demande_nombre(choix);
            break;
        case 4:
            demande_nombre(choix);
            break;
        case 5: // Sortie du programme si l'utilisateur choisi l'option 5
            break;
        }
    } while (choix != 5);
    //-------------------- Fin de forcage --------------------------
}
//*--------------------------- Fonction de saisi de nombre ------------------*/
void demande_nombre(int choix)
{
    float a = 0, b = 0;
    do // Force l'utilisateur à choisi un nombre entre -1000 à 1000
    {
        printf("Saisir un premiere nombre :");
        scanf("%f", &a);
        printf("Saisir un deuxieme nombre :");
        scanf("%f", &b);

        if (a < -1000 || a > 1000 || b < -1000 || b > 1000)
            printf("Saisie incorecte ( choisir des nombres entre -1000 et 1000)\n");
        else
        {
            if (choix == 1)
                addition(a, b);
            else if (choix == 2)
                soustraction(a, b);
            else if (choix == 3)
                multiplication(a, b);
            else if (choix == 4)
                division(a, b);
        }
    } while (a < -1000 || a > 1000 || b < -1000 || b > 1000);
} //----------Fin de forcage------------------------------------
/*----------------------------------------------------------------------------------*/

//*-------------------------------Fonction d'operation-------------------------------*/
void addition(float a, float b)
{
    printf("le resultat est %.1f\n", a + b);
}

void soustraction(float a, float b)
{
    printf("le resultat est %.1f\n", a - b);
}

void multiplication(float a, float b)
{
    printf("le resultat est %.1f\n", a * b);
}

void division(float a, float b)
{
    if (b == 0)
        printf("Forme indeterminee\n");
    else
        printf("le resultat est %.2f\n", a / b);
}
/*----------------------------------------------------------------------------------*/