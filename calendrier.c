#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/* --------------------------------------------------------- */

int jour_du_debut_de_mois(int jour, int mois, int annee);
char *nom_du_mois(int nbr_du_mois);
int nbr_de_jour(int nbr_du_mois, int annee);
int affichage_du_calendrier(int annee, int mois);

/* --------------------------------------------------------- */

int main(int argc, char const *argv[])
{
    char reponse;

    do
    {
        system("color f0");
        int annee, mois;

        do
        {
            printf("\n");
            printf("!!! Une annee comporte 12 mois pour info !!!\n");
            printf(" Saisir le mois --> ");
            scanf("%d", &mois);

        } while (mois <= 0 || mois > 12);

        do
        {
            printf(" Saisir l'annee --> ");
            scanf("%d", &annee);

        } while (annee <= 0);

        affichage_du_calendrier(annee, mois);

        printf("\n\n Voulez vous continuer ? O/N -->");
        getchar();
        scanf("%c", &reponse);
    } while (reponse == 'o' || reponse == 'O');

    getch();
    return 0;
}

/**
 * > La fonction prend une date en entrée et renvoie le jour de la semaine du premier jour du mois de
 * la date en entrée
 *
 * @param jour Le jour du mois (1-31)
 * @param mois Le mois pour lequel vous souhaitez obtenir le jour de la semaine.
 * @param annee an
 *
 * @return Le jour premiere de la semaine.
 */
int jour_du_debut_de_mois(int jour, int mois, int annee)
{
    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    annee -= mois < 3;
    return (annee + (annee / 4) - (annee / 100) + (annee / 400) + t[mois - 1] + jour) % 7;
}

/**
 * Elle prend un entier comme argument et renvoie une chaîne contenant le nom du mois correspondant à
 * l'entier
 *
 * @param nbr_du_mois Le numéro du mois.
 *
 * @return Le nom du mois.
 */
char *nom_du_mois(int nbr_du_mois)
{
    char *mois = NULL;

    switch (nbr_du_mois)
    {
    case 1:
        mois = "Janvier";
        break;
    case 2:
        mois = "Fevrier";
        break;
    case 3:
        mois = "Mars";
        break;
    case 4:
        mois = "Avril";
        break;
    case 5:
        mois = "Mai";
        break;
    case 6:
        mois = "Juin";
        break;
    case 7:
        mois = "Juillet";
        break;
    case 8:
        mois = "Aout";
        break;
    case 9:
        mois = "Septembre";
        break;
    case 10:
        mois = "Octobre";
        break;
    case 11:
        mois = "November";
        break;
    case 12:
        mois = "Decembre";
        break;
    }
    return mois;
}

/**
 * Il renvoie le nombre de jours dans un mois, étant donné le numéro du mois et l'année
 *
 * @param nbr_du_mois Le numéro du mois (1-12)
 * @param annee an
 *
 * @return Le nombre de jours dans un mois.
 */
int nbr_de_jour(int nbr_du_mois, int annee)
{
    if (nbr_du_mois == 1)
        return (31);

    else if (nbr_du_mois == 2)
    {
        if (annee % 400 || (annee % 4 == 0 && annee % 100 != 0))
            return (29);
        else
            return (28);
    }
    else if (nbr_du_mois == 3)
        return (31);

    else if (nbr_du_mois == 4)
        return (30);

    else if (nbr_du_mois == 5)
        return (31);

    else if (nbr_du_mois == 6)
        return (30);

    else if (nbr_du_mois == 7)
        return (31);

    else if (nbr_du_mois == 8)
        return (31);

    else if (nbr_du_mois == 9)
        return (30);

    else if (nbr_du_mois == 10)
        return (31);

    else if (nbr_du_mois == 11)
        return (30);

    else if (nbr_du_mois == 12)
        return (31);
}

/**
 * Il imprime le calendrier pour l'année et le mois donnés
 *
 * @param annee l'année
 * @param mois mois
 *
 * @return le calendrier.
 */
int affichage_du_calendrier(int annee, int mois)
{
    int jour, cpt, i, j, k;

    jour = nbr_de_jour(mois, annee);
    
    printf("\n\t   ------------------ ------------------ ------------------ \n\n");
    printf("\t \t \t        %s  %d                 \n\n", nom_du_mois(mois), annee);
    printf("\t   ------------------ ------------------ ------------------ \n\n");

    printf("\t    Lun\t    Mar\t    Mer\t    Jeu\t    Ven\t    Sam\t    Dim \n\n\n");

    cpt = jour_du_debut_de_mois(1, mois, annee);
    --cpt;

    for (k = 0; k < cpt; k++)
        printf("\t       ");

    for (j = 1; j <= jour; j++)
    {
        printf("\t  %5d", j);
        if (++k > 6)
        {
            k = 0;
            printf("\n\n\n");
        }
    }

    getch();
    return 0;
}
