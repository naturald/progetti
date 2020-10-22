//marco schiavello 15/10/2020
//peso medio
#include <stdio.h>
#include <conio.h>//SERVE IL 2 PER TEXTCOLOR(COLOR_NAME)
#include <windows.h>//system ("cls")

int main()
{
	int n_stud,som=0,peso,i=0,media;
	
	do
	{
		system("cls");
		printf("mettere num alunni (min 3 max 33): ");
		scanf("%d",&n_stud);
	}
	while(n_stud<3||n_stud>33);
	
	while(i<n_stud)
	{
		do
		{
			printf("mettere peso singolo alunno %d (min 11 max 200): ",i+1);
			scanf("%d",&peso);
		}
		while(peso<11||peso>200);
		
		som=som+peso;
		i=i+1;
	}
	media=som/n_stud;//troncato perché è intero

	printf("la media dei pesi e': %d \n",media);
	printf("la somma dei pesi e': %d \n",som);
	getch();
}

