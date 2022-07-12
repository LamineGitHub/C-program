#include <stdio.h>
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
        int annee, mois;

        printf("\n");
        do
        {
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

/* --------------------------------------------------------- */
int jour_du_debut_de_mois(int jour, int mois, int annee)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    annee -= mois < 3;
    return (annee + (annee / 4) - (annee / 100) + (annee / 400) + t[mois - 1] + jour) % 7;
}
/* --------------------------------------------------------- */
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
/* --------------------------------------------------------- */
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
/* --------------------------------------------------------- */
int affichage_du_calendrier(int annee, int mois)
{
    int jour, cpt, i, j, k;

    jour = nbr_de_jour(mois, annee);

    printf("  ---------------------------");
    printf("\n    \t %s   %d\n", nom_du_mois(mois), annee);
    printf("  ---------------------------\n");
    printf("   L   M   M   J   V   S   D\n");

    cpt = jour_du_debut_de_mois(1, mois, annee);
    --cpt;

    for (k = 0; k < cpt; k++)
        printf("    ");

    for (j = 1; j <= jour; j++)
    {
        printf("%4d", j);
        if (++k > 6)
        {
            k = 0;
            printf("\n");
        }
    }

    getch();
    return 0;
}
