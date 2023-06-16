#include<stdio.h>
#include<stdlib.h>

struct process
{
       int TA,TE,wtt,tat,rnt,PR;
       char p[20];
};


void sortTA(struct process a[],int nb)
{
       int i,j;
       struct process temp;
       for(i=0;i<nb;i++)
       {
              for(j=i+1;j<nb;j++)
              {
                     if(a[i].TA > a[j].TA)
                     {
                           temp = a[i];
                           a[i] = a[j];
                           a[j] = temp;
                     }
              }
       }
       return;
}

int main()
{
        FILE*F;
		F=fopen("configuration.txt","r");


       int c,j,nb,time,remain,flag=0,q;
       int i = 0;
       struct process a[100];

       struct process Proc;
       float avgwt=0,avgtt=0;

      puts(""); printf("\033[1;36m \n");
    puts("\t\t\t  Fichier de configuration");
    printf("\033[0m");
    puts("\t\t\t ==========================");




    //    printf("Enter Number Of Processes : ");
    //    scanf("%d",&nb);

       while((c=fgetc(F)) != EOF)
	{fscanf(F,"%s ;%d ;%d ;%d \n",Proc.p,&Proc.TA,&Proc.TE,&Proc.PR);
		if(c!='\n')
			{a[i]=Proc;

            a[i].rnt = a[i].TE;
            nb++;
            }

		i++;
	}
 puts("");
     puts("+-----------+-----------------+-------------------+-----------------+");
    puts("|\033[1;34m Processus \033[0m|\033[1;34m Temps d'arriver \033[0m| \033[1;34mTemps_d'exécution \033[0m|  \033[1;34m   Priorité   \033[0m |");
    puts("+-----------+-----------------+-------------------+-----------------+");

    for(i=0; i<nb; i++) {
        printf("|P%2s       |        %2d       |       %2d          |       %2d        |\n"
               , a[i].p, a[i].TA, a[i].TE, a[i].PR );
        puts("+-----------+-----------------+-------------------+-----------------+");
    }

       remain=nb;
    //    for(i=0;i<nb;i++)
    //    {
    //           printf("Enter arrival time and Burst time for Process P%d : ",i);
    //           scanf("%d%d",&a[i].TA,&a[i].TE);

    //           //Nom du processus
    //           a[i].p = i;

    //           a[i].rnt = a[i].TE;
    //    }
       sortTA(a,nb);


       printf("\033[1;33m  Entrer le Quantum : \033[0m");
       scanf("%d",&q);
puts(""); printf("\033[1;36m \n");
    puts("\t\t\t  ROUND ROBIN");
    printf("\033[0m");
    puts("\t\t\t ==============");

      puts("");
     puts("+-----------+-----------------+-------------------+-----------------+");
    puts("|\033[1;34m Processus \033[0m|\033[1;34m Temps d'arriver \033[0m| \033[1;34mTemps_d'exécution \033[0m|  \033[1;34m   Priorité   \033[0m |");
    puts("+-----------+-----------------+-------------------+-----------------+");

       for(i=0;i<nb;i++)
       {

               printf("|P%2s       |        %2d       |       %2d          |       %2d        |\n"
               ,a[i].p,a[i].TA,a[i].TE, a[i].PR );
        puts("+-----------+-----------------+-------------------+-----------------+");

       }
       printf("\n");

printf("\033[1;36m \n");
       printf("\t     DIAGRAMME DE GANTT");
       printf("\033[0m");
        printf("\n             ******************\n\n");
       printf("0");
       for(time=0,i=0;remain!=0;)
       {
              if(a[i].rnt<=q && a[i].rnt>0)
              {
                     time = time + a[i].rnt;
                     printf(" \033[1;34m-> \033[0m[P%s] \033[1;34m <-\033[0m %d",a[i].p,time);
                     a[i].rnt=0;
                     flag=1;
              }
              else if(a[i].rnt > 0)
              {
                     a[i].rnt = a[i].rnt - q;
                     time = time + q;
                     printf(" \033[1;34m-> \033[0m[P%s]\033[1;34m <-\033[0m %d",a[i].p,time);
              }
              if(a[i].rnt==0 && flag==1)
              {
                     remain--;
                     a[i].tat = time-a[i].TA;
                     a[i].wtt = time-a[i].TA-a[i].TE;
                     avgwt = avgwt + time-a[i].TA-a[i].TE;
                     avgtt = avgtt + time-a[i].TA;
                     flag=0;
              }
              if(i==nb-1)
                     i=0;
              else if(a[i+1].TA <= time)
                     i++;
              else
                     i=0;
       }

printf("\n\n");
       avgwt = avgwt/nb;
       avgtt = avgtt/nb;
       printf("\033[1;33m Temps d'attente moyen :\033[0m %.2f\n",avgwt);
       printf("\033[1;33m Temps de rotation moyen :\033[0m %.2f\n",avgtt);
       return 0;
}

