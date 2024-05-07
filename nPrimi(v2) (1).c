/*Dato un numero N intero positivo, stampare 
la somma dei primi N numeri primi alternati 
(uno sì, e uno no)*/
//Seconda Versione (Prima versione errata per interpretazione sbagliata della consegna)
#include <stdio.h>
  void
main () 
{
  
int num = 0, contaPrimi = 0, i, j, nPrimo, somma, controllo = 0, qtaPrimi=0;
  
 
printf ("inserire un numero: ");
  
scanf ("%d", &num);
  
//copiaNum = num;
  
 
//for (i = 0; i < num; i++)
while (qtaPrimi<num)    
    {
      
 
for (j = 1; j <= nPrimo; j++)
	
	{
	  
if (nPrimo % j == 0)
	    
	    {
	      
contaPrimi++;
	    
}
	
}
      
 
if ((controllo == 1) && (contaPrimi == 2))
	
	{
	  
controllo = 0;
	
}
      
 
      else if ((contaPrimi == 2) && (controllo == 0))
	
	{
	  
somma = somma + nPrimo;
qtaPrimi++;	  
controllo++;
	
}
      
contaPrimi = 0;
      
j = 1;
      
nPrimo++;
    
 
}
  
printf ("\nSommma dei numeri primi: %d", somma);

}
