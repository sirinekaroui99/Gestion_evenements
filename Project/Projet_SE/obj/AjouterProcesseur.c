
#include<stdio.h>
#include<stdlib.h>



void AjouterProcesseur(){
	struct Process
{
	int TA;
	int TE;
	int PR;
	char Nom[50];
	
	
};
struct Process Proc;

	FILE*F;
	int nb;
	int i=0;
	F=fopen("configuration.txt","w+");
	printf(" Nombre des processus : ");
		scanf("%d",&nb);

while(nb !=0)
		{
	printf("\n Entrer le temps d'arriver du processus : ");
	scanf("%d",&Proc.TA);
	fflush(stdin);
	
		printf("\n Entrer le temps d'execution du processus : ");
scanf("%d",&Proc.TE);
	fflush(stdin);
		printf("\n Entrer la priorite du precessus : ");
	scanf("%d",&Proc.PR);
	fflush(stdin);
		fprintf(F,"p(%d) ;%d ;%d ;%d \n",i+1,Proc.TA,Proc.TE,Proc.PR);

		
		nb = nb-1;	
		i=i+1;
}
	fclose(F);
	
}
