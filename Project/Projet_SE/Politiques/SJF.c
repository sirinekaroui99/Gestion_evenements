#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 100

struct proc {
    char p[20];
    int TE;
    int TA;
    int PR;
    int start;
    int finish;
};

typedef struct proc Proces;
struct proc Proc;



int main()
{

    FILE*F;
		F=fopen("configuration.txt","r");

int l;
    Proces p[MAX_PROCESS];
   Proces P[MAX_PROCESS];
    int c,n, i, j;
    int k;
     puts(""); printf("\033[1;36m \n");
    puts("\t\t\t  Fichier de configuration");
     printf("\033[0m");
    puts("\t\t\t ==========================");


    // printf("Enter total process: ");
    // scanf("%d", &n);

    while((c=fgetc(F)) != EOF)
	{fscanf(F,"%s ;%d ;%d ;%d \n",Proc.p,&Proc.TA,&Proc.TE,&Proc.PR);
		if(c!='\n')
			{p[i]=Proc;
            n++;
            }

		i++;
	}

	 puts("");
     puts("+-----------+-----------------+-------------------+-----------------+");
    puts("|\033[1;34m Processus \033[0m|\033[1;34m Temps d'arriver \033[0m| \033[1;34mTemps_d'exécution \033[0m|  \033[1;34m   Priorité   \033[0m |");
    puts("+-----------+-----------------+-------------------+-----------------+");

 for(i=0; i<n; i++) {
        printf("|P%2s       |        %2d       |       %2d          |       %2d        |\n"
               , p[i].p, p[i].TA, p[i].TE, p[i].PR );
        puts("+-----------+-----------------+-------------------+-----------------+");
    }

	puts(""); printf("\033[1;36m \n");
    puts("\t\t\t  SHORTEST JOB FIRST");
     printf("\033[0m");
    puts("\t\t\t ====================");



l=n;
k=n;
    int current_time = 0,min_pos;
    // En tete du tableau
     puts("");
     puts("+-----------+-----------------+-------------------+-----------------+");
    puts("|\033[1;34m Processus \033[0m|\033[1;34m Temps d'arriver \033[0m| \033[1;34mTemps_d'exécution \033[0m|  \033[1;34m   Priorité   \033[0m |");
    puts("+-----------+-----------------+-------------------+-----------------+");

    for(;n>0;n--){
        for(i=0;i<n;i++){
            if(p[i].TA <= current_time ){
                min_pos = i;
                //printf("test TE de min_pos %d current time  %d ",p[min_pos].TE,current_time);
            }
            /*
            if(i==n)
        {   for(j=0;j<n;j++)
        if(p[j].TA > current_time)
            current_time++;
            printf("current-time  %d ",current_time);
        }*/
        }

      //  min_pos = 0;
        for(j=0;j<n;j++){
            if(p[j].TA <= current_time && p[j].TE <= p[min_pos].TE){
                min_pos = j;
            }
        }


        //current_time += (current_time<p[min_pos])?current_time-p[min_pos]+1: ;

        // Ligne du tableau
       //printf("TA %s TE %d\n",p[min_pos].p, p[min_pos].TE);
        printf("|P%2s       |        %2d       |       %2d          |       %2d        |\n"
               , p[min_pos].p, p[min_pos].TA, p[min_pos].TE, p[min_pos].PR );
        puts("+-----------+-----------------+-------------------+-----------------+");
P[k-n]=p[min_pos];
        current_time += p[min_pos].TE;
        for(j=min_pos;j<n-1;j++){
            p[j] = p[j+1];
        }

//printf("ttttt %d", current_time);
/*
if(n!=0){
for(i=0;i<n;i++){

}
}

*/

    }
    puts(""); // Empty line
    printf("\033[1;36m \n");
    puts("       DIAGRAMME DE GANTT ");
     printf("\033[0m");
    puts("       ****************** \n");


for(i=0;i<l;i++)
    {
       printf("|p%2s ",P[i].p);
    }
    printf("|\n");
    printf("0     ");
    for(i=1;i<l;i++)
    {
    int temps = P[i].TA;
while(j<=i){

 int temps = temps+P[j].TE;
 j++;printf("%d     ",temps);

}

    }
 printf("\n");

 //printf("\n PROCESS %s:-FINISH TIME==> %d \n", p[i].Nom, finish[i] + 1);



    /*
 printf("\033[31m red text\n");
  printf("\033[7;36mbold yellow\n");
  printf("\033[0m");
  printf("Hello");
  printf("\033[0m default colors\n");
*/


}








