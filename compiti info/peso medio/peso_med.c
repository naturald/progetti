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
		printf("mettere num alunni: ");
		scanf("%d",&n_stud);
		if(n_stud>=30)
			n_stud=-1;
	}
	while(n_stud<0);
	
	while(i<n_stud)
	{
		do
		{
			printf("mettere peso singolo alunno: ");
			scanf("%d",&peso);
		}
		while(peso<0);
		
		som=som+peso;
		i=i+1;
	}
	media=som/n_stud;//troncato perché è intero
	printf("la media dei pesi e': %d ",media);
}

