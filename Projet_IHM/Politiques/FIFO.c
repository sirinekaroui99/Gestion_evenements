#include <stdio.h>
#include <stdlib.h>







void FIFO(GtkWidget * widget, gpointer  data)
{
typedef struct
{
    char Nom[50];
    int TA;
    int TE;
	int PR;
    int waiting_time;
    int turnaround_time;
} Process;


////////////////

GtkWidget *win;

GtkWidget  *vbox,*view,*aff;
GtkTextBuffer *buffer;
  GtkTextIter iter;
 win = gtk_window_new(GTK_WINDOW_TOPLEVEL);



gtk_window_set_title(GTK_WINDOW(win), "Execution de l'algorithme FIFO");


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

		FILE*F;
		F=fopen(fichier,"r");
		Process Proc;
		Process permut;
    Process p[100];
    int i=0;

    int j, n=0;
    int c;

g_print("ffffff %s",fichier);
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

gtk_text_buffer_insert(buffer, &iter, "| Processus | Temps d'arriver | Temps_d'exécution |   Priorité  |\n", -1);

//    puts("|\033[1;34m Processus \033[0m|\033[1;34m Temps d'arriver \033[0m| \033[1;34mTemps_d'exécution \033[0m|  \033[1;34m   Priorité   //\033[0m |");
    puts("+-----------+-----------------+-------------------+-----------------+");


    for(i=0; i<n; i++) {






 
char *a_afficher;

 
a_afficher = g_strdup_printf ("|P%s       |        %d       |       %d          |       %d        |\n"
               , p[i].Nom, p[i].TA, p[i].TE, p[i].PR );

aff = gtk_button_new_with_label(a_afficher); 
gtk_box_pack_start(GTK_BOX(vbox),aff,0,0,5);

        printf("|    P%2s       |        %2d       |       %2d          |       %2d        |\n"
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

char *a_gantt, *a_nom,*a_time;
GtkWidget * chart, *pro,*time;
 



a_gantt = g_strdup_printf ("-------- " );
chart = gtk_button_new_with_label(a_gantt); 
gtk_box_pack_start(GTK_BOX(vbox),chart,0,0,5);


  for(i=0; i<n; i++) {printf("-------- ");

    }
    printf("\n|");

    // printing process id in the middle
    for(i=0; i<n; i++) {

        printf("P%2s", p[i].Nom);

//a_nom = g_strdup_printf ("P%s    |", p[i].Nom);
//pro = gtk_button_new_with_label(a_nom); 
//gtk_box_pack_start(GTK_BOX(vbox),pro,0,0,5);



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
//a_time = g_strdup_printf ("%d    |", p[i].turnaround_time);
//time = gtk_button_new_with_label(a_time); 
//gtk_box_pack_start(GTK_BOX(vbox),time,0,0,5);

int time ;


for(i=0; i<n; i++){
time= p[i].turnaround_time -p[i].TE ;
a_nom = g_strdup_printf ("P%s       |  start : %d    |  finish : %d  ", p[i].Nom,time,p[i].turnaround_time);
pro = gtk_button_new_with_label(a_nom); 
gtk_box_pack_start(GTK_BOX(vbox),pro,0,0,0);
}

    }
    printf("\n");
    



     gtk_container_add(GTK_CONTAINER(win),vbox); 
     gtk_widget_show_all(win); 


///////////////

gtk_widget_show_all(win); 

//
//
}


