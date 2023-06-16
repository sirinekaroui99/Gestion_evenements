#include <stdio.h>
#include <stdlib.h>

//#define MAX_PROCESS 100

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



int SJF(GtkWidget * widget, gpointer  data)
{
///////////////
GtkWidget *win;
char *a_nom;
GtkWidget  *vbox,*view,*aff,*pro;
GtkTextBuffer *buffer;
  GtkTextIter iter;
 win = gtk_window_new(GTK_WINDOW_TOPLEVEL);



gtk_window_set_title(GTK_WINDOW(win), "Execution de l'algorithme SJF");


gtk_window_set_default_size(GTK_WINDOW(win), 400, 100);
  gtk_container_set_border_width(GTK_CONTAINER(win), 15);
  gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);

vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0); 

view = gtk_text_view_new();
gtk_box_pack_start(GTK_BOX(vbox), view, TRUE, TRUE, 0);
buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
 gtk_text_buffer_get_iter_at_offset(buffer, &iter, 0);

//////////////////
gchar *fichier = data;

    FILE*F;
		F=fopen(fichier,"r");

int l;
    Proces p[10];
   Proces P[10];
    int c,n=0, i=0, j;
    int k;
g_print("ffffff %s",fichier);
     puts(""); printf("\033[1;36m \n");
    puts("\t\t\t  Fichier de configuration");
     printf("\033[0m");
    puts("\t\t\t ==========================");

//g_print("ffffff %s",file);

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
gtk_text_buffer_insert(buffer, &iter, "| Processus | Temps d'arriver | Temps_d'exécution |   Priorité  |\n", -1);

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

char *a_afficher,*a_nom;

 
a_afficher = g_strdup_printf ("|P%s       |        %d       |       %d          |       %d        |\n"
               , p[min_pos].p, p[min_pos].TA, p[min_pos].TE, p[min_pos].PR );

aff = gtk_button_new_with_label(a_afficher); 
gtk_box_pack_start(GTK_BOX(vbox),aff,0,0,5);



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

int TF;

int TS = P[0].TA ;
if(TS == 0){
 TF = TS + P[0].TE +1;}else{TF = TS + P[0].TE ;
}

P[0].start = TS;
P[0].finish = TF;

a_nom = g_strdup_printf ("P%s       |  start : %d    |  finish : %d  ", P[0].p,TS,TF);
pro = gtk_button_new_with_label(a_nom); 
gtk_box_pack_start(GTK_BOX(vbox),pro,0,0,0);

for(i=1;i<l;i++){

TS = P[i-1].finish;
TF = TS + P[i].TE;
P[i].finish = TF;

 a_nom = g_strdup_printf ("P%s       |  start : %d    |  finish : %d  ", P[i].p,TS,TF);
pro = gtk_button_new_with_label(a_nom); 
gtk_box_pack_start(GTK_BOX(vbox),pro,0,0,0);
}



 //printf("\n PROCESS %s:-FINISH TIME==> %d \n", p[i].Nom, finish[i] + 1);



    /*
 printf("\033[31m red text\n");
  printf("\033[7;36mbold yellow\n");
  printf("\033[0m");
  printf("Hello");
  printf("\033[0m default colors\n");
*/

     gtk_container_add(GTK_CONTAINER(win),vbox); 
     gtk_widget_show_all(win); 


///////////////

gtk_widget_show_all(win); 


}








