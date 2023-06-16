#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 100

struct pro {
    char p[20];
    int TE;
    int TA;
    int PR;
    int waiting_time;
};

typedef struct pro Processus;





int main()
{
struct pro Proc;
    FILE*F;
		F=fopen("configuration.txt","r");


    Processus p[MAX_PROCESS];
    int c,n, i, j;
    puts(""); printf("\033[1;36m \n");
    puts("   \t\t\t  Fichier de configuration");
    printf("\033[0m");
    puts("  \t\t\t  ========================");


    // printf("Enter total process: ");
    // scanf("%d", &n);
     puts("");
     //printf("\033[1;34m \n");
    puts("+-----------+-----------------+-------------------+-----------------+");
    puts("|\033[1;34m Processus \033[0m|\033[1;34m Temps d'arriver \033[0m| \033[1;34mTemps_d'exécution \033[0m|  \033[1;34m   Priorité   \033[0m |");
    puts("+-----------+-----------------+-------------------+-----------------+");


    while((c=fgetc(F)) != EOF)
	{fscanf(F,"%s ;%d ;%d ;%d \n",Proc.p,&Proc.TA,&Proc.TE,&Proc.PR);
		if(c!='\n')
			{p[i]=Proc;
            n++;
            }

		i++;
	}
	    for(i=0; i<n; i++) {
        printf("|P%2s       |        %2d       |       %2d          |       %2d        |\n"
               , p[i].p, p[i].TA, p[i].TE, p[i].PR );
        puts("+-----------+-----------------+-------------------+-----------------+");
    }

 puts(""); printf("\033[1;36m \n");
    puts("   \t\t\t     Priority");
    printf("\033[0m");
    puts("  \t\t\t    ==========");
int k=n;
Processus Proces[20];
    int current_time = 0,min_pos;
    // En tete du tableau
     puts("");
     //printf("\033[1;34m \n");
    puts("+-----------+-----------------+-------------------+-----------------+");
    puts("|\033[1;34m Processus \033[0m|\033[1;34m Temps d'arriver \033[0m| \033[1;34mTemps_d'exécution \033[0m|  \033[1;34m   Priorité   \033[0m |");
    puts("+-----------+-----------------+-------------------+-----------------+");
//printf("\033[0m");
int l=n;
    for(;n>0;n--){

           for(i=0;i<n;i++){
            if(p[i].TA <= current_time ){
                min_pos = i;
            }
        }
        for(j=0;j<n;j++){
            if(p[j].TA <= current_time && p[j].PR >= p[min_pos].PR){
                min_pos = j;
            }
        }


        // Ligne du tableau
       //printf("TA %s TE %d\n",p[min_pos].p, p[min_pos].TE);
        printf("|  \033[1;37m P%2s    \033[0m|        %2d       |       %2d          |       %2d        |\n"
               , p[min_pos].p, p[min_pos].TA, p[min_pos].TE, p[min_pos].PR );
        puts("+-----------+-----------------+-------------------+-----------------+");

Proces[k-n]=p[min_pos];

        current_time += p[min_pos].TE;
        for(j=min_pos;j<n-1;j++){
            p[j] = p[j+1];
        }

    }


  puts(""); // Empty line
    printf("\033[1;36m \n");
    puts("       DIAGRAMME DE GANTT ");
     printf("\033[0m");
    puts("       ****************** \n");


for(i=0;i<l;i++)
    {
       printf("|p%2s ",Proces[i].p);
    }
    printf("|\n");
    printf("0     ");
    for(i=1;i<l;i++)
    {
    int temps = Proces[i].TA;
while(j<=i){

 int temps = temps+Proces[j].TE;
 j++;printf("%d     ",temps);

}

    }
 printf("\n");

}


/*

void calculate_waiting_time(Process p[], int n)
{
    int i;
    total_waiting_time = 0;
    p[0].waiting_time = 0;
    for(i=1; i<n; i++) {
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].TE;
        total_waiting_time += p[i].waiting_time;
    }
}
*/






