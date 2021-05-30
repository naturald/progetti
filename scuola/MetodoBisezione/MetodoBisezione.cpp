/*
  Progetto Bisezzione 
  Schiavello, Boanca, Ouertani, Bello
*/
#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

/*
  prende un valore in gradi e lo trsforma in radianti
  Parametri:
    -float x = input
*/
float DegToRad(float x){return (M_PI*x)/180;}

/*
  prende un valore x della funzione e restituisce 
  il ristultato della funzione 
  Parametri:
    -float x = input
*/
float f(float x,int funz)
{
    if(funz == 1)
        return pow(x,3) + (-17*pow(x,2)) + (14*x) + 32;
    else
        return sin(DegToRad(x)) - (2*cos(DegToRad(x)));
}

/*
  prende un numero floatig point e ritorna 
  il suo valore assoluto
  Parametri:
    -float x = input
*/
float absFloat(float num)
{
  if(num < 0)
    return num*=-1;
  else
    return num;
}

/*
  disegna un linea
*/
void linea()
{
  printf("----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

void printVoce(int * nIte,double min,double max,double medio,int funz)
{
   printf("| %5d | %17.10f | %20.10f | %17.10f | %20.10f | %15.10f | %20.10f | %15.10f | \n",
            ++(*nIte),min,f(min,funz),max,f(max,funz),medio,f(medio,funz),absFloat(max-min));
}

int main()
{
  double max,min,medio,tol,x;
  bool xTrov = false,err;
  int funz,maxTruni;

  //scelta funzione
  do
  {
      if(err)
        printf("Metti una scelta valida\n");
      err = false;
      printf("\n");
      printf("Scegliere funzione\n");
      printf("1) x^3 - 17x^2 + 14x + 32\n");
      printf("2) sin(x) - 2cos(x)\n");
      printf("Scegli: ");
      scanf("%d", &funz);
      if(funz > 2 || funz < 1)
        err = true;
  }
  while(err);
 
  //immissione dati dalle 
  printf("metti limite minimo: ");
  scanf("%lf",&min);
  printf("metti limite massimo: ");
  scanf("%lf",&max);
  printf("metti tolleranza: ");
  scanf("%lf",&tol); 
  printf("numero massimo di passi: ");
  scanf("%d",&maxTruni);

  
  if(tol<=0) //controllo tolleranza 
    printf("Tolleranza non valida, errore");
  else if((f(min,funz)>0 && f(max,funz)>0) ||  (f(min,funz)<0 && f(max,funz)<0)) //controllo presenza soluzioni
    printf("non ci possono essere x valide, errore");
  else
  {
      
    if(min>max) //se l'arco di numeri invertito li scambia
    {
        int tmp = max;
        max = min;
        min = tmp; 
    }

    int nIte = 0;

    //_____________intestazione____________

    linea();
    printf("| Passo |    x_sinistro   |      f(x_sinistro)     |     x_destro      |     f(x_destro)      |     x_medio     |       f(x_medio)     |    intervallo   |\n");
    linea();

    //_____________________________________

    //_____________stampa prima riga____________

    //calcolo punto medio
    medio = (min+max)/2;

    printVoce(&nIte,min,max,medio,funz);
    //_____________________________________

    // controllo sui limiti per vedere se sono 0 della funzione
    if(f(min,funz) == 0)
    {
      x = min;
      xTrov = true;
      linea();
    }
    else if(f(max,funz) == 0)
    {
      x = max;
      xTrov = true;
      linea();
    }
    //_____________________________________

    while(absFloat(max-min) > tol && !xTrov)
    {
      //se il numero di passi e arrivato a quello selezionato esce
      if(nIte == maxTruni)
      {
          printf("Timed out");
          return 0;
      }

      linea();

      /*
        controllo del punto medio per vedere 
        se è lo 0 della funzione, solo il punto medio 
        perché poi diventerà o il limite destro o sinistro 
        il controllo per ogni giro si limiterà solo al punto medio
      */
      if(f(medio,funz) == 0)
      {
        x = medio;
        xTrov = true;
      }
      else
      {
        //controlla con che angolazione la retta taglia l'asse delle x
        if(f(min,funz) < f(max,funz))
          if(f(medio,funz) > 0) // decide quelle parte dell'intervallo prendere
            max = medio;
          else
            min = medio;
        else 
          if(f(medio,funz) < 0)
            max = medio;
          else
            min = medio;

        //ricalcolo punto medio
        medio = (min+max)/2;

        //stampa voce tabella
        printVoce(&nIte,min,max,medio,funz);

      }
    }

    // in caso trovato lo 0 della finzione stampa una riga conclusiva speciale
    if(xTrov)
    {
      linea();
      printf("| %5d |    x = %10.5f                                                                                                              |\n",++nIte,x);
    }
    linea();
    
  }

  return 0;
}