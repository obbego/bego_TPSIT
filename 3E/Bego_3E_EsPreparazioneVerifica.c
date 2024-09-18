/*Scrivere un programma in C che dopo aver inserito una stringa a piacere determini e o verifichi:
1) Il numero di consonanti e vocali contenute;
2) Che contenga solo lettere;
3) Il conteggio di una lettera (se presente) scelta dall’utente;
4) Crei 2 ulteriori stringhe che contengano 1 le lettere di posizione pari; la 2° le lettere di posizione dispari;
5) Verifichi se contiene doppie.

Inserita una 2° stringa determinare:
1) Quale delle 2 è più lunga e più corta;
2) Quale delle 2 stringhe contiene più vocali;
3) Quale delle 2 stringhe contiene più consonanti;
4) Quali sono le lettere contenute in ambedue le stringhe;*/

//IMPORTAZIONE LIBRERIE
#include <stdio.h>
#include <string.h>  //Importazione libreria stringhe
#include <stdbool.h> // Importazione libreria boolean

void main() {
    //dichiarazione variabili
    int dim1=0, dim2 = 0,vocali1=0, consonanti1=0, vocali2=0, consonanti2=0, conteggioLettera=0, j=0, k=0;
    bool tutteLettere = true, contaDoppie = true;
    bool alfabeto1 [26], alfabeto2 [26]; 
    char lettera;
   
    // Inizializzazione degli array alfabeto1 e alfabeto2
    for (int i = 0; i < 26; i++) 
    {
        alfabeto1[i] = true;
        alfabeto2[i] = true;
    }
    
   do  //ciclo per assicurarsi che la dimensione degli array sia un numero valido (>0)
   {
      printf("Inserisci la dimensione della 1 stringa\n");
      scanf("%d", &dim1);
      
      //controllo se la dimensione è accettabile
      if (dim1<=0)
      printf("La dimensione della 1 stringa non puo essere <= a 0, Rinserisci\n");
   } while (dim1<=0);
   //condizzione di ripetizione del ciclo
   
   do //ciclo per assicurarsi che la dimensione degli array sia un numero valido (>0)
   {
      printf("Inserisci la dimensione della 2 stringa\n");
      scanf("%d", &dim2);
      
      //controllo se la dimensione è accettabile
      if (dim2<=0)
      printf("La dimensione della 2 stringa non puo essere <= a 0, Rinserisci\n");
   } while (dim2<=0); 
   //condizzione di ripetizione del ciclo
   
   
   
   //dichiarazione stringhe 
   char stringa1[dim1]; 
   char stringa2[dim2];
   char stringaPari[dim1];
   char stringaDispari[dim1];
   
   //popolazione 1 stringa + controllo sia composta da numeri
   do
   {
   tutteLettere = true;
   printf("Inserisci la 1 Stringa: \n");
   scanf("%s", &stringa1);
   
   for (int i = 0; i < strlen(stringa1); i++)
   {
       if ((stringa1[i] < 'a' || stringa1[i] > 'z') && (stringa1[i] < 'A' || stringa1[i] > 'Z'))
       {
           tutteLettere = false;
           //printf("%c", stringa1[i]);
       }
   }
   if (tutteLettere == false)
   {
       printf("La stringa inserita non è composta solo da lettere, RINSERIRE\n");
   }
   }
   while (tutteLettere==false);


    //inserimento lettera da controllare + controllo sia lettera
   do
   {
   tutteLettere = true;
   printf("Inserisci la lettera da controllare la presenza\n");
   scanf("%c", &lettera);
   scanf("%c", &lettera);
   
   if (((lettera < 'a') || (lettera > 'z')) && ((lettera < 'A') || (lettera > 'Z'))) // controllo se non fa parte dei 2 intervalli
       {
           tutteLettere = false;
           //printf("%c", stringa1[i]);
       }
    if (tutteLettere == false)
   {
       printf("La lettera inserita non è una lettera, RINSERIRE\n"); //COMUNICARE L'ERRORE
   }
   }
   while (tutteLettere==false);
   
   
   //popolazione 2 stringa + controllo sia composta da numeri
   do
   {
   tutteLettere = true;
   printf("Inserisci la 2 Stringa: \n");
   scanf("%s", &stringa2);
   for (int i = 0; i < strlen(stringa2); i++)
   {
       if ((stringa2[i] < 'a' || stringa2[i] > 'z') && (stringa2[i] < 'A' || stringa2[i] > 'Z'))
       {
           tutteLettere = false;
           //printf("%c", stringa1[i]);
       }
   }
   if (tutteLettere == false)
   {
       printf("La stringa inserita non è composta solo da lettere, RINSERIRE\n");
   }
   }
   while (tutteLettere==false);
   
   
   
   //controllo condizioni 1 punto
   for (int i = 0; i < strlen(stringa1); i++)
   {
      //controllo se la lettera è una vocale
       if (stringa1[i] == 'a' || stringa1[i] == 'e' || stringa1[i] == 'i' || stringa1[i] == 'o' || stringa1[i] == 'u' || stringa1[i] == 'A' || stringa1[i] == 'E' || stringa1[i] == 'I' || stringa1[i] == 'O' || stringa1[i] == 'U' )
       vocali1++;
       
       //in qualsiasi altro caso è una consonante
       else
       consonanti1++;
       
       //controllo se la lettera scelta dall'utente compare nell'array e quante volte
       if (stringa1[i] == lettera)
       conteggioLettera++;
       
       //copio nell'array PARI le lettere che hanno indice pari
       if (i % 2 == 0)
       {
         stringaPari[j] = stringa1[i]; 
         j++; //aumento il contatore parallelo che aumenta indipendentemente
       }
       // in qualsiasi altro caso copio nell'array DISPARI le lettere
       else
       {
         stringaDispari[k] = stringa1[i]; 
         k++; //aumento il contatore parallelo che aumenta indipendentemente
       }
       
       if (contaDoppie) //controllo se sono gia state trovate delle doppie per efficentare il codice
       {
       for (int counter = 0; counter < i; counter++) // for dentro il for per controllare la presenza delle doppie
       {
           if (stringa1[counter]==stringa1[i])
           contaDoppie = false;
       }
       }
       
       //rendo false nel array di bool il valore corrispettivo alla lettera
       if (stringa1[i] < 'a' || stringa1[i] > 'z')
       alfabeto1[stringa1[i] -'A'] = false;
       else 
       alfabeto1[stringa1[i] -'a'] = false;
   }
   
  //controllo richieste 2 punto
   for (int i = 0; i < strlen(stringa2);i++)
   {
         //controllo se la lettera è una vocale
        if (stringa2[i] == 'a' || stringa2[i] == 'e' || stringa2[i] == 'i' || stringa2[i] == 'o' || stringa2[i] == 'u' || stringa2[i] == 'A' || stringa2[i] == 'E' || stringa2[i] == 'I' || stringa2[i] == 'O' || stringa2[i] == 'U' )
       vocali2++;
        //in qualsiasi altro caso è una consonante
       else
       consonanti2++;
       
       //rendo false nel array di bool il valore corrispettivo alla lettera
       if (stringa2[i] < 'a' ||  stringa2[i] > 'z')
       alfabeto2[stringa2[i] -'A'] = false;
       else 
       alfabeto2[stringa2[i] -'a'] = false;
   }
   
   //OUTPUT RISULTATI:
   
   printf("\nLa Stringa1 contiene:\n %d VOCALI\n %d CONSONATI", vocali1, consonanti1);
   
   printf("\nLa Stringa1 contiene la lettera: %c ben: %d volte", lettera, conteggioLettera);
   
   printf("\nLa Stringa contenenti le lettere in posizioni DISPARI è composta da: ");
   
   for (int i = 0; i < strlen(stringaPari); i++)
   printf(" %c ", stringaPari[i]);
   printf("\nLa Stringa contenenti le lettere in posizioni PARI è composta da: ");
   
   for (int i = 0; i < strlen(stringaDispari); i++)
   printf(" %c ", stringaDispari[i]);
   
   if (contaDoppie==false)
   printf("\nLa Stringa1 contiene delle doppie");
   else 
   printf("\nLa Stringa1 NON contiene delle doppie");
   
   if (strlen(stringa1) > strlen(stringa2))
   printf("\nLa Stringa1 è più lunga della Stringa2");
   else if (strlen(stringa1) < strlen(stringa2))
   printf("\nLa Stringa2 è più lunga della Stringa1");
   else
   printf("\nLe 2 stringhe sono lunghe uguali");
   
   if (vocali1 > vocali2)
   printf("\nLa Stringa1 contiene più VOCALI della Stringa2");
   else if (vocali1 < vocali2)
   printf("\nLa Stringa2 contiene più VOCALI della Stringa1");
   else
   printf("\nLe 2 stringhe contiene lo stesso numero di VOCALI");
   
   if (consonanti1 > consonanti2)
   printf("\nLa Stringa1 contiene più CONSONATI della Stringa2");
   else if (consonanti1 < consonanti2)
   printf("\nLa Stringa2 contiene più CONSONATI della Stringa1");
   else
   printf("\nLe 2 stringhe contiene lo stesso numero di CONSONATI");
   
   printf("\nLe lettere contenute in entrambe le stringhe sono: ");
   for (int counterAlfabeto = 0; counterAlfabeto < 26; counterAlfabeto++)
   {
       if (alfabeto1[counterAlfabeto]==false && alfabeto2[counterAlfabeto]== false)
       printf("%c", 'a' + counterAlfabeto); // Utilizza %c per stampare il carattere corrispondente
   }
}
