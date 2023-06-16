#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    char Nom[50];
    int TA;
    int TE;
	int PR;
    int waiting_time;
    int turnaround_time;
} Process;






int main()
{
		FILE*F;
		F=fopen("configuration.txt","r");
		Process Proc;
		Process permut;
    Process p[MAX];
    int i=0;
    int j, n=0;
    int c;

      puts("");printf("\033[1;36m \n");
    puts("\t\t\t Fichier de configuration");
    printf("\033[0m");
    puts("\t\t\t==========================");

    while((c=fgetc(F)) != EOF)
	{fscanf(F,"%s ;%d ;%d ;%d \n",Proc.Nom,&Proc.TA,&Proc.TE,&Proc.PR);
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
               , p[i].Nom, p[i].TA, p[i].TE, p[i].PR );
        puts("+-----------+-----------------+-------------------+-----------------+");
    }
    puts("");
puts("");printf("\033[1;36m \n");
    puts("\t\t\t  FIFO");
    printf("\033[0m");
    puts("\t\t\t ======");
    int sum_waiting_time = 0, sum_turnaround_time;
    // printf("Enter total number of process: ");
    // scanf("%d", &n);


//    printf("Enter burst time for each process:\n");
   for(i=0; i<n; i++) {
       //p[i].Nom = i+1;
//        printf("P[%d] : ", i+1);
//        scanf("%d", &p[i].burst_time);
        p[i].waiting_time = p[i].turnaround_time = 0;
      }
 for(i=0;i<n+1;i++)
for(j=i+1;j<n;j++)
{
if (p[i].TA>p[j].TA)

{
permut=p[i];
p[i]=p[j];
p[j]=permut;
}

}
//    // calculate waiting time and turnaround time
   p[0].turnaround_time = p[0].TE;

    for(i=1; i<n; i++) {
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].TE;
        p[i].turnaround_time = p[i].waiting_time + p[i].TE;
    }

    // calculate sum of waiting time and sum of turnaround time
    for(i=0; i<n; i++) {
            sum_waiting_time += p[i].waiting_time;
            sum_turnaround_time += p[i].turnaround_time;
    }
//
//    // print table
    puts("");
     puts("+-----------+-----------------+-------------------+-----------------+");
    puts("|\033[1;34m Processus \033[0m|\033[1;34m Temps d'arriver \033[0m| \033[1;34mTemps_d'exécution \033[0m|  \033[1;34m   Priorité   \033[0m |");
    puts("+-----------+-----------------+-------------------+-----------------+");

    for(i=0; i<n; i++) {
        printf("|P%2s       |        %2d       |       %2d          |       %2d        |\n"
               , p[i].Nom, p[i].TA, p[i].TE, p[i].PR );
        puts("+-----------+-----------------+-------------------+-----------------+");
    }
    puts(""); // Empty Line
//    printf("Total Waiting Time      : %-2d\n", sum_waiting_time);
//    printf("Average Waiting Time    : %-2.2lf\n", (double)sum_waiting_time / (double) n);
//    printf("Total Turnaround Time   : %-2d\n", sum_turnaround_time);
//    printf("Average Turnaround Time : %-2.2lf\n", (double)sum_turnaround_time / (double) n);
//
   // print Gantt chart
    puts(""); // Empty line
    printf("\033[1;36m \n");
    puts("       DIAGRAMME DE GANTT ");
     printf("\033[0m");
    puts("       ****************** \n");

  for(i=0; i<n; i++) {printf("-------- ");

    }
    printf("\n|");

    // printing process id in the middle
    for(i=0; i<n; i++) {

        printf("P%2s", p[i].Nom);

        printf("    |");
    }
    printf("\n");
    // printing bottom bar

    for(i=0; i<n; i++) {printf("-------- ");

    }
    printf("\n");

    // printing the time line
    printf("\033[1;33m0");
    for(i=0; i<n; i++) {
	printf("       ");
//        for(j=0; j<p[i].TE; j++)
//        if(p[i].turnaround_time > 9) printf(" "); // backspace : remove 1 space
        printf("\033[1;33m%d\033[0m ", p[i].turnaround_time);

    }
    printf("\n");
    return 0;
//}
//
//
}


