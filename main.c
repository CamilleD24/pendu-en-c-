#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(){

    char nom[20];
    int tentative= 0;
    char mot[50];
    int nbLettres = 0;
    char lettreCache[50];
    char lettreTeste[10];
    char lettre[10];
    char tiret[50];
    char rejouer[2];
    char *image[] = {"|   |______\n|          |\n|__________|\n",
    "  |\n  |\n  |\n  |\n  |\n|   |______\n|          |\n|__________|\n ",
    "   _____\n  |     |\n  |\n  |\n  |\n  |\n|   |______\n|          |\n|__________|\n",
    "   _____\n  |     |\n  |     0\n  |\n  |\n  |\n|   |______\n|          |\n|__________|\n",
    "   _____\n  |     |\n  |     0\n  |    /|\n  |\n  |\n|   |______\n|          |\n|__________|\n",
    "   _____\n  |     |\n  |     0\n  |    /|\\ \n  |     |\n  |\n|   |______\n|          |\n|__________|\n",
    "   _____\n  |     |\n  |     0\n  |    /|\\ \n  |     |\n  |    /\n|   |______\n|          |\n|__________|\n",
    "   _____\n  |     |\n  |     0\n  |    /|\\ \n  |     |\n  |    / \\ \n|   |______\n|          |\n|__________|\n"};


    FILE *ouvrir_fichier = fopen("words.txt", "r"); //Ouvre le fichier word.txt
    if (ouvrir_fichier == NULL) {
        printf("Erreur d'ouverture du fichier words.txt\n");
        return 1;
    }
    srand(time(NULL)); //
    const int nombre_aleatoire = rand() % 835; //limite le nombre aléatoire entre 0 et 834 (inclus).
    for (int i = 0; i <= nombre_aleatoire; i++) { // boucle qui permet de s'arreter sur un mot de la liste en fonction du nb aleatoire généré
        fgets(mot, sizeof(mot), ouvrir_fichier); //sizeof permet d'éviter un dépassement de mémoire en se basant sur motsPendu.
    }
    fclose(ouvrir_fichier);//ferme le fichier

    printf("bonjour, entrez votre prenom: ");
    scanf (" %s", nom);
    printf( "bonjour %s pret(e) a jouer?!\n", nom );

    do {
        tentative = 0;
        memset(lettreTeste, 0, sizeof(lettreTeste));
        while(mot[nbLettres] != '\0') {
            nbLettres++;
        }

        for (int l=0; l < nbLettres; l++) {
            lettreCache[l] = '_';
            tiret[l] = '_';
        }

        lettreCache[nbLettres] = '\0';
        tiret[nbLettres] = '\0';
        printf(" %s\n", lettreCache);

        while (tentative <= 7) {
            bool lettreTrouvee = false;
            printf("une lettre (Majuscule): ");
            scanf(" %s", lettre);


            if(strlen(lettre) > 1 || !isalpha(lettre[0])) {
                printf("Veuillez entrer une lettre \n");
                continue;
            }

            lettre[0] = toupper(lettre[0]);



            for (int t =0; t<=lettreTeste[t]; t++) {
                if (lettre[0] == lettreTeste[t]) {
                    printf("une autre deja teste?! \n");
                    goto fin_boucle;
                }
            }

            for (int i=0; i<=nbLettres; i++) {
                if (lettre[0] == mot[i]) {
                    lettreCache[i] = lettre[0];
                    printf("%s\n",lettreCache);
                    lettreTrouvee = true;
                }
            }
            if(!lettreTrouvee) {
                lettreTeste[tentative] = lettre[0];
                printf("%s\n",lettreCache);
                printf("%s \n", lettreTeste);
                printf("\n%s\n", image[tentative]);
                tentative++;
                printf("vous avez utilise %d tentative(s) sur 8\n", tentative);

            }
            int t=0;
            bool mt= false;
            for ( int o =0 ; o<= nbLettres; o++) {
                if(lettreCache[o] != tiret[o]) {
                    t++;
                }
            }
            if (t== nbLettres) {
                mt = true;
            }
            if (mt == true) {
                printf("bravo , le mot est bien %s\n", mot);
                break;
            }
            if (tentative == 8) {
                printf("defaite, dommage une prochaine fois ?!\n le mot etait %s \n",mot);
                break;
            }
            fin_boucle:;

        }
        printf("voulez vous rejouer ??(o/n):");
        scanf ("%s", rejouer );


    }while (strcmp(rejouer, "n") != 0);
    return 0;
}
