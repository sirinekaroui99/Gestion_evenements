#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
    char Nom[50];
    int TA;
    int TE;
	int PR;
	int Start;
	int Finish;

} Process;

  int main()
{
FILE*F;
		F=fopen("configuration.txt","r");
Process Proc;
    Process p[MAX];
    Process procTrier[MAX];
    Process permut;
  int max,c,t,n, total = 0, i, j, small, temp, procs[100], k, waiting[10], finish[10];

  float tavg = 0.0, wavg = 0.0;
    while((c=fgetc(F)) != EOF)
	{fscanf(F,"%s ;%d ;%d ;%d \n",Proc.Nom,&Proc.TA,&Proc.TE,&Proc.PR);
		if(c!='\n')
			{p[i]=Proc;
            n++;
            }

		i++;
	}
puts("");printf("\033[1;36m \n");
    puts("\t\t\t  Shortest Remaining Time (SRT)");
    printf("\033[0m");
    puts("\t\t\t ===============================");
puts("\n");
    puts("\t\t\t  Fichier de configuration");
    printf("\033[0m");
    puts("\t\t\t ==========================");

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

  for (i = 0; i < n; i++)

  {
    waiting[i] = 0;

    total += p[i].TE;

  }

  for (i = 0; i < n; i++)

  {

    for (j = i + 1; j < n; j++)

    {

      if (p[i].TA > p[j].TA)

      {

        temp = p[j].TA;

        p[j].TA = p[j].TA;

     p[j].TA = temp;

        temp = p[i].TE;

        p[i].TE = p[j].TE;

        p[j].TE = temp;

      }

    }

  }

  for (i = 0; i < total; i++)

  {

    small = 3200;

    for (j = 0; j < n; j++)

    {

      if ((p[j].TE != 0) && (p[j].TA <= i) && (p[j].TE < small))

      {

        small = p[j].TE;
        //printf(" %d",j);
        k = j;

      }

    }

    p[k].TE--;
    //printf(" %d ",i);
    max = i;
//printf(" %s  ",p[k].Nom);
procTrier[i]=p[k];



if(strcmp(procTrier[i].Nom,procTrier[i+1].Nom) != 0){
procTrier[i].Start=i;
}


    procs[i] = k;

  }

  k = 0;

  for (i = 0; i < total; i++)

  {

    for (j = 0; j < n; j++)

    {

      if (procs[i] == j)

      {

        finish[j] = i;

        waiting[j]++;
      }

    }

  }

  for (i = 0; i < n; i++)

  {

 //   printf("\n PROCESS %s:-FINISH TIME==> %d TURNAROUND TIME==>%d WAITING TIME==>%d\n", p[i].Nom, finish[i] + 1, (finish[i] - p[i].TA) + 1, (((finish[i] + 1) - waiting[i]) - p[i].TA));
printf("\n PROCESS %s:-FINISH TIME==> %d \n", p[i].Nom, finish[i] + 1);

    wavg = wavg + (((finish[i] + 1) - waiting[i]) - p[i].TA);

    tavg = tavg + ((finish[i] - p[i].TA) + 1);

    t=0;
//printf("%d   ",finish[i]+1);
if(t<=finish[i]+1)
{t = finish[i]+1;
//printf("%d   ",t);
}
//printf("%d   ",t);

  }
printf("\n");
printf("\n");

 puts(""); // Empty line
    printf("\033[1;36m \n");
    puts("       DIAGRAMME DE GANTT ");
     printf("\033[0m");
    puts("       ****************** \n");



for(i=0;i<max;i++)
{
if(strcmp(procTrier[i].Nom,procTrier[i-1].Nom) == 0){
//printf("%d",i);
continue;
//printf("%d %s ",procTrier[i].Start, procTrier[i].Nom);

procTrier[i].Start ++;
}
 //printf(" \033[1;34m-> \033[0m[P%s]\033[1;34m <-\033[0m %d",a[i].p,time);
printf("%d -> P%2s <-",procTrier[i].Start, procTrier[i].Nom);

}

printf("%d",max+1);
printf("\n");


  return 0;

}

