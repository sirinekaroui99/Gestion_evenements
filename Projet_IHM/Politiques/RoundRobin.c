#include<stdio.h>
#include<stdlib.h>
struct process
{
       int TA,TE,wtt,tat,rnt,PR;
       char p[20];
int TF;
int TS;
};
gchar* quantum;
gint i = 0;
int q=0;
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

int LireQuantum(GtkWidget * widget, gpointer  data){

quantum = data;
i = atoi(data);
q= i;
//printf("ssssss %s",quantum);

return q;

}


int RoundRobin(GtkWidget * widget, gpointer  data)
{//printf("iiiiiiiiii %d",q);

gchar *fichier = data;


////////////////////////

GtkWidget *window;

GtkWidget *quantumLabel;
    GtkWidget *quantumVal;
GtkWidget *pro;
char *a_nom;
GtkWidget  *vbox,*view,*aff;
GtkTextBuffer *buffer;
  GtkTextIter iter;
 window = gtk_window_new(GTK_WINDOW_TOPLEVEL);



gtk_window_set_title(GTK_WINDOW(window), "Execution de l'algorithme Round_Robin");


gtk_window_set_default_size(GTK_WINDOW(window), 400, 100);
  gtk_container_set_border_width(GTK_CONTAINER(window), 15);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0); 

view = gtk_text_view_new();
gtk_box_pack_start(GTK_BOX(vbox), view, TRUE, TRUE, 0);
buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
 gtk_text_buffer_get_iter_at_offset(buffer, &iter, 0);

//////////////
g_print("ffffff %d",q);



        FILE*F;
		F=fopen(fichier,"r");


       int c,j,nb=0,time=0,remain,flag=0;
       int i = 0;
       struct process a[100];
struct process ProcTrier[100];

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


     //  printf("\033[1;33m  Entrer le Quantum : \033[0m");



//////////////////////inserer un champs de texte
    // scanf("%d",&q);
//sscanf(quantum, "%d", &q)
//printf("aaaaaaa %d",q);

puts(""); printf("\033[1;36m \n");
    puts("\t\t\t  ROUND ROBIN");
    printf("\033[0m");
    puts("\t\t\t ==============");

      puts("");
gtk_text_buffer_insert(buffer, &iter, "| Processus | Temps d'arriver | Temps_d'exécution |   Priorité  |\n", -1);

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
int tempsPrec = 0;
       for(time=0,i=0;remain!=0;)
       {	
              if(a[i].rnt<=q && a[i].rnt>0)
              {
                     time = time + a[i].rnt;
ProcTrier[i]=a[i];
ProcTrier[i].TS = ProcTrier[i-1].TF;

a_nom = g_strdup_printf (" [P%s] |start %d  | Finish : %d",a[i].p,tempsPrec,time);

pro = gtk_button_new_with_label(a_nom); 
gtk_box_pack_start(GTK_BOX(vbox),pro,0,0,0);
                     printf(" [P%s] | Finish : %d",a[i].p,time);
                     a[i].rnt=0;
                     flag=1;
tempsPrec = time;
              }
              else if(a[i].rnt > 0)
              {
                     a[i].rnt = a[i].rnt - q;
                     time = time + q;


ProcTrier[i]=a[i];
ProcTrier[i].TS = ProcTrier[i-1].TF;

a_nom = g_strdup_printf (" [P%s] | start %d | Finish : %d",a[i].p,tempsPrec,time);
pro = gtk_button_new_with_label(a_nom); 
gtk_box_pack_start(GTK_BOX(vbox),pro,0,0,0);

                     printf(" [P%s] | Finish : %d",a[i].p,time);
tempsPrec = time;
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

for(i=0;i<nb;i++){
printf(" P %s   |start %d  | FINISH  %d  ",ProcTrier[i].p,ProcTrier[i].TS,ProcTrier[i].TF);
}

       avgwt = avgwt/nb;
       avgtt = avgtt/nb;
       printf("\033[1;33m Temps d'attente moyen :\033[0m %.2f\n",avgwt);
       printf("\033[1;33m Temps de rotation moyen :\033[0m %.2f\n",avgtt);



     gtk_container_add(GTK_CONTAINER(window),vbox); 
     gtk_widget_show_all(window); 
gtk_main();

///////////////

       return 0;
}

