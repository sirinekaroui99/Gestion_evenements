#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 100

struct pro {
    char p[20];
    int TE;
    int TA;
    int PR;
    int waiting_time;
 int start;
    int finish;
};

typedef struct pro Processus;





int Priority(GtkWidget * widget, gpointer  data)
{
struct pro Proc;
////////////////

GtkWidget *win;
char *a_nom;
GtkWidget  *vbox,*view,*aff,*pro;
GtkTextBuffer *buffer;
  GtkTextIter iter;
 win = gtk_window_new(GTK_WINDOW_TOPLEVEL);



gtk_window_set_title(GTK_WINDOW(win), "Execution de l'algorithme Priority");


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


    Processus p[MAX_PROCESS];
    int c,n=0, i=0, j;
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
gtk_text_buffer_insert(buffer, &iter, "| Processus | Temps d'arriver | Temps_d'exécution |   Priorité  |\n", -1);

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

char *a_afficher;

 
a_afficher = g_strdup_printf ("|P%s       |        %d       |       %d          |       %d        |\n"
               , p[min_pos].p, p[min_pos].TA, p[min_pos].TE, p[min_pos].PR);

aff = gtk_button_new_with_label(a_afficher); 
gtk_box_pack_start(GTK_BOX(vbox),aff,0,0,5);

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

int TF;

int TS = Proces[0].TA ;
if(TS == 0){
 TF = TS + Proces[0].TE +1;}else{TF = TS + Proces[0].TE ;
}

Proces[0].start = TS;
Proces[0].finish = TF;

a_nom = g_strdup_printf ("P%s       |  start : %d    |  finish : %d  ", Proces[0].p,TS,TF);
pro = gtk_button_new_with_label(a_nom); 
gtk_box_pack_start(GTK_BOX(vbox),pro,0,0,0);

for(i=1;i<l;i++){

TS = Proces[i-1].finish;
TF = TS + Proces[i].TE;
Proces[i].finish = TF;

 a_nom = g_strdup_printf ("P%s       |  start : %d    |  finish : %d  ", Proces[i].p,TS,TF);
pro = gtk_button_new_with_label(a_nom); 
gtk_box_pack_start(GTK_BOX(vbox),pro,0,0,0);
}


     gtk_container_add(GTK_CONTAINER(win),vbox); 
     gtk_widget_show_all(win); 


///////////////

gtk_widget_show_all(win); 


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






