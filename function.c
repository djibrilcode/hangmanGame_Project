#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void rechercheLettreMasque(char* recherche, char* motSecret, char* userInput, int* nbreLettreTrouvee, int* nombreEssai,char* motTrouve, int lengthMotSecret) 
{
  recherche = strchr(motSecret, userInput[0]);
    if (recherche != NULL)
    {
      (*nbreLettreTrouvee)++;
      printf("Bravo, vous avez devinez une lettre : ");
      for (int i = 0; i < lengthMotSecret; i++)
      {
        if(motSecret[i] == userInput[0]){
          motTrouve[i] = motSecret[i];
        }
        if (motTrouve[i] == motSecret[i])
        {
          printf("%c", motSecret[i]);
        }          
        else 
        {
            printf("*");
        }
      } 
      printf("\n");
    }
    else
    {
      (*nombreEssai)--;
      printf("Lettre non trouvee dans le mot secret.\n");
      printf("il ne vous reste plus que  %d essai \n",*nombreEssai);
    }
}