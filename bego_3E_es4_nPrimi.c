/*Dato un numero N intero positivo, stampare 
la somma dei primi N numeri primi alternati 
(uno si, e uno no)*/

/*Given a positive integer N, print the sum of the 
first N prime numbers alternated (one yes, and one no).*/

#include <stdio.h>
  
void main  () 
{
//variable declaration  
int num = 0, contaPrimi = 0, i, j, nPrimo, somma, controllo = 0, qtaPrimi=0;
  
//data input 
printf ("inserire un numero >=0: ");
scanf ("%d", &num);
//check validity of the entered number  
while (num<0)
{
	printf ("numero <0");
	printf ("inserire un numero >=0: ");
scanf ("%d", &num);
  }  
//determine if a number is prime or not'
while (qtaPrimi<num)    
{
for (j = 1; j <= nPrimo; j++)
	{
	  
if (nPrimo % j == 0)
	    
	    {    
contaPrimi++;	    
}	
//check to sum alternate numbers
}
if ((controllo == 1) && (contaPrimi == 2)) 
	
	{
	  
controllo = 0;
	
}
      
 
      else if ((contaPrimi == 2) && (controllo == 0))
	
	{
//sum of the numbers	  
somma = somma + nPrimo;
qtaPrimi++;	  
controllo++;
	
}
      
contaPrimi = 0;
      
j = 1;
      
nPrimo++;
    
 
}
  //output
printf ("\nSommma dei numeri primi: %d", somma);

}
