#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

struct tab
{
       int Num;
       char* Nom;
};

 char* algorithme(int num)
   {

      DIR *dp=NULL;
      struct dirent *fp=NULL;
      FILE *fa=NULL;
      char* chaine;
      dp=opendir("Politiques" );
      fp=readdir(dp);

      int i=1;
      while ((fp=readdir(dp))!= NULL && i-1<num)
      {

     chaine= fp->d_name;
        i++;

      }

      closedir(dp);
      return chaine;
   }

   int algo(void)
   { int j;
   	FILE*F;
struct tab T[20];
   	int algo;
   	char* chaine;
char* file;
   	char buffer[150];
char commande[150];

      DIR *dp=NULL;
      struct dirent *fp=NULL;
      FILE *fa=NULL;

      dp=opendir("Politiques" );
      fp=readdir(dp);

      int i=1;
      printf(" \n                             -------------------------------\n");
    printf("                          \033[1;36m    ALGORITHMES D'ODONNANCEMENT \033[0m \n");
    printf("                             -------------------------------\n");
      while ((fp=readdir(dp))!= NULL)
      {

     chaine= fp->d_name;
     if(strstr( fp->d_name, ".c~" ) != NULL  )
     { printf("                            \033[1;33m   %d . \033[0m%s                   \n",i,strtok ( chaine,"."));
        T[i].Num = i;
        T[i].Nom = fp->d_name;
        i++;
     }


      }

     printf("                              \033[1;33m %d .\033[0m Quitter                 \n",i);
    printf("                             -------------------------------\n");
    printf("\n");
      do{
		printf("\t\t\t\t\tVotre Choix : ");

	scanf("%d",&algo);
if(algo==i) exit(0);

		}while(algo<1 || algo>i);


			for(j=1;j<i+1;j++){

			if(T[j].Num==algo)
			chaine = T[j].Nom;
			}

printf("");
	printf("\nExecution de l'algorithme  %s",strtok ( chaine,".") );

file=strcat(chaine,".c");
//char* c =strcpy("d","b");
//printf("dd %s",c);

snprintf(buffer, 150, "cp /home/linux/Desktop/Project/Projet_SE/Politiques/%s /home/linux/Desktop/Project/Projet_SE/",file );


system(buffer);
snprintf(commande, 150, "gcc %s -o %s",file,chaine );

system(commande);

snprintf(buffer, 150, "./%s",chaine );
system(buffer);

		F=fopen("configuration.txt","r");




      return 0;
   }



