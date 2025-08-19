#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "function.h"

int main(int argc, char *argv[])
{
  // Mot à deviner (mot secret)
  char motSecret[5] = "CHAT";
  // Compteur du nombre de lettres trouvées
  int nbreLettreTrouvee = 0;
  // Tableau pour stocker les lettres trouvées (mot masqué)
  char motTrouve[5];
  // Initialisation du mot trouvé avec des '*' et terminaison par '\0'
  for (int i = 0; i < 4; i++)
  {
    motTrouve[i] = '*';
  }
  motTrouve[4] = '\0';
  // Nombre d'essais restants
  int nombreEssai = 5;
  // Stocke la lettre saisie par l'utilisateur
  char userInput[2] = "";
  // Pointeur pour la recherche de lettre dans le mot secret
  char *recherche = NULL;
  // Taille du mot secret
  size_t lengthMotSecret = strlen(motSecret);
  // Taille du mot trouvé (non utilisé ici, mais peut servir)
  size_t lengthMotTrouve = strlen(motTrouve);

  // Affichage du message d'accueil
  printf("------------------------------ BIENVENUE DANS LE JEU DE PENDU -----------------------------------\n");
  printf("Le mot secret masque comporte %d caractère : ", (int)lengthMotSecret);
  printf("\n");
  printf("Le but de ce jeu ce serait de trouver les lettre du mots une par une. Vous avez 5 essais, c'est partis !!\n\n");

  // Boucle principale du jeu : s'arrête si toutes les lettres sont trouvées ou plus d'essais
  while ((nbreLettreTrouvee < lengthMotSecret) && (nombreEssai > 0))
  {
    // Demande à l'utilisateur de saisir une lettre
    printf("Veuillez entrer une lettre: ");
    scanf("%1s", userInput); // On lit un seul caractère
    // Vérifie si la lettre saisie est en minuscule, redemande tant que ce n'est pas une majuscule
    while (islower(userInput[0]))
    {
      printf("Entrez un caractere en Majuscule s'il vous plait: ");
      scanf("%1s", userInput);
    }

    // Appel de la fonction qui gère la recherche et l'affichage du mot masqué
    rechercheLettreMasque(recherche, motSecret, userInput, &nbreLettreTrouvee, &nombreEssai, motTrouve, lengthMotSecret);
  }

  // Si l'utilisateur n'a plus d'essais
  if (nombreEssai == 0)
  {
    printf("\n\n");
    printf("Desole il ne vous reste plus aucun essai\n\n");
    printf("---------- Merci pour votre participation -----------");
  }

  // Si l'utilisateur a trouvé toutes les lettres
  if (nbreLettreTrouvee == lengthMotSecret)
  {
    printf("\n\n");
    printf(" ------ MAIS QUEL GENIE ----- \n vous avez trouvez le mot secret, BRAVO!!!");
  }

  return 0;
}
