#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>


 char* algorithme(int num)
   {
      DIR *dp=NULL;
      struct dirent *fp=NULL;
      FILE *fa=NULL;
      char* chaine=NULL;
      dp=opendir("politiques" );
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
   {
   	FILE*F;

   	int algo=0;
   	char* chaine=NULL;
      DIR *dp=NULL;
      struct dirent *fp=NULL;
      FILE *fa=NULL;

      dp=opendir("politiques" );
      fp=readdir(dp);
      fp=readdir(dp);
      int i=1;
      printf(" \n                             -------------------------------\n");
    printf("                              ALGORITHMES D'ODONNANCEMENT  \n");
    printf("                             -------------------------------\n");
      while ((fp=readdir(dp))!= NULL)
      {

     chaine= fp->d_name;
 printf("                               %d . %s                   \n",i,fp->d_name);

        i++;

      }

     printf("                               %d . Quitter                 \n",i);
    printf("                             -------------------------------\n");
    printf("\n");
      do{
		printf("\t\t\t\t\tVotre Choix : ");

	scanf("%d",&algo);
		}while(algo<1 || algo>i);

			chaine=algorithme(algo);
	printf("Execution de l'algorithme  %s",chaine);

		F=fopen("configuration.txt","r");




      return 0;
   }




