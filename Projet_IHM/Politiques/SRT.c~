#include <stdio.h>
#include <stdlib.h>

//#define MAX 100



  int SRT(GtkWidget * widget, gpointer  data)
{typedef struct
{
    char Nom[50];
    int TA;
    int TE;
	int PR;
	int Start;
	int Finish;

} Process;

////////////////

GtkWidget *win;
char *a_nom;
GtkWidget  *vbox,*view,*aff,*pro;
GtkTextBuffer *buffer;
  GtkTextIter iter;
 win = gtk_window_new(GTK_WINDOW_TOPLEVEL);



gtk_window_set_title(GTK_WINDOW(win), "Execution de l'algorithme SRT");


gtk_window_set_default_size(GTK_WINDOW(win), 400, 100);
  gtk_container_set_border_width(GTK_CONTAINER(win), 15);
  gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);

vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0); 

view = gtk_text_view_new();
gtk_box_pack_start(GTK_BOX(vbox), view, TRUE, TRUE, 0);
buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
 gtk_text_buffer_get_iter_at_offset(buffer, &iter, 0);

//////////////


gchar *fichier = data;
g_print("ffffff %s",fichier);

FILE*F;
		F=fopen(fichier,"r");
Process Proc;
    Process p[20];
    Process procTrier[20];
    Process permut;
  int max,c,t,n=0, total = 0, i=0, j, small, temp, procs[100], k, waiting[10], finish[10];

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
gtk_text_buffer_insert(buffer, &iter, "Fichier de configuration \n", -1);

gtk_text_buffer_insert(buffer, &iter, "| Processus | Temps d'arriver | Temps_d'exécution |   Priorité  |\n", -1);

     puts("+-----------+-----------------+-------------------+-----------------+");
    puts("|\033[1;34m Processus \033[0m|\033[1;34m Temps d'arriver \033[0m| \033[1;34mTemps_d'exécution \033[0m|  \033[1;34m   Priorité   \033[0m |");
    puts("+-----------+-----------------+-------------------+-----------------+");
char *a_afficher;
    for(i=0; i<n; i++) {


 
a_afficher = g_strdup_printf ("|P%2s       |        %2d       |       %2d          |       %2d        |\n"
               , p[i].Nom, p[i].TA, p[i].TE, p[i].PR );

aff = gtk_button_new_with_label(a_afficher); 
gtk_box_pack_start(GTK_BOX(vbox),aff,0,0,5);

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
p[i].Finish = finish[i] + 1;



g_printf("vvvv %s  %d",p[n].Nom, p[i].Finish );

    wavg = wavg + (((finish[i] + 1) - waiting[i]) - p[i].TA);

    tavg = tavg + ((finish[i] - p[i].TA) + 1);

    t=0;
//printf("%d   ",finish[i]+1);
if(t<=finish[i]+1)
{t = finish[i]+1;
//printf("%d   ",t);
}
printf("%d   ",t);

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
//procTrier[i-1].Finish = procTrier[i].Start;


}
 //printf(" \033[1;34m-> \033[0m[P%s]\033[1;34m <-\033[0m %d",a[i].p,time);
printf("%d -> P%2s <-",procTrier[i].Start, procTrier[i].Nom);

///////////////////// eleminer 2eme occurrance dans le tableau 



//g_print("vv %d",count);

a_nom = g_strdup_printf ("P%s       |  start : %d   ", procTrier[i].Nom,procTrier[i].Start);
pro = gtk_button_new_with_label(a_nom); 
gtk_box_pack_start(GTK_BOX(vbox),pro,0,0,0);



}
a_nom = g_strdup_printf ("------------");
pro = gtk_button_new_with_label(a_nom); 
gtk_box_pack_start(GTK_BOX(vbox),pro,0,0,0);

for(i=0;i<n;i++)
{
a_nom = g_strdup_printf ("P%s        |  finish : %d  ", p[i].Nom,finish[i] + 1);
pro = gtk_button_new_with_label(a_nom); 
gtk_box_pack_start(GTK_BOX(vbox),pro,0,0,0);
}

printf("%d",max+1);
printf("\n");

 gtk_container_add(GTK_CONTAINER(win),vbox); 
     gtk_widget_show_all(win); 


///////////////

gtk_widget_show_all(win); 


  return 0;

}

