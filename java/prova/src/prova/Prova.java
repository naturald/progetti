package prova;
import java.util.Scanner;

class Motorino
{
    private String colore;
    private String tipo;
    private double velocita;
    private boolean antifurto=false;
    public Motorino(String colore_,String tipo_,double velocita_)
    {
        this.colore=colore_;
        this.tipo=tipo_;
        this.velocita=velocita_;
    }
    public double getVelocita()
    {
        return this.velocita;
    }
    public void accelera(double add_vel)
    {
        if(this.antifurto==true)
        {
            System.out.println("non puoi accelerare se c'e' l'anti furto attivo pero puoi rubarlo");
        }
        else
        {
            System.out.println("la tua velocita' era: " +this.velocita);
            this.velocita += add_vel;
            System.out.println("la tua velocita' e': " +this.velocita);
        }
    }
    public void switchAntifurto()
    {
        if(this.antifurto==true)
        {
            this.antifurto=false;
            System.out.println("antifurto tolto");
        }
        else
        {
            this.antifurto=true;
            System.out.println("antifurto messo");
        }
    }
     public void stampaDati()
    {
        System.out.println("colore : "+this.colore);
        System.out.println("tipo : "+this.tipo);
        System.out.println("velocita : "+getVelocita());
        System.out.println("antifurto : "+this.antifurto);
    }
}
class GestioneGarage
{
    Scanner scan=new Scanner(System.in);
    private double add_vel,velocita;
    private String colore, tipo;
    private int n_mot;
    private Motorino[] garage;
    
    public GestioneGarage(int n_mot)
    {
        this.n_mot=n_mot;
        this.garage=new Motorino[n_mot];
        for(int i=0;i<this.n_mot;i++)
        {
            System.out.print("Scegli colore macchina "+i+": ");
            this.colore=scan.next();
            System.out.print("Scegli tipo macchina "+i+": ");
            this.tipo=scan.next();
            System.out.print("Scegli velocita iniziale macchina "+i+": ");
            this.velocita=scan.nextDouble();
            this.garage[i]=new Motorino(this.colore,this.tipo,this.velocita);
        }
        
    }
    public void vediMoto(int scelta_moto)
    {
        this.garage[scelta_moto].stampaDati();
    }
    public void Antifurto(int scelta_moto)
    {
        this.garage[scelta_moto].switchAntifurto();
    }
    public void accellera(int scelta_moto)
    {
        System.out.print("Di quanto vuoi accelerare: ");
        this.add_vel=scan.nextDouble();
        this.garage[scelta_moto].accelera(add_vel);
    }
}

public class Prova 
{


    public static void main(String[] args) 
    {
        Scanner scan=new Scanner(System.in);
        int scelta,scelta_moto;
        boolean fine=false;
        System.out.print("Quanti motorini nel garage: ");
        int n_mot=scan.nextInt();
        GestioneGarage garage= new GestioneGarage(n_mot);
        
        do
        {  
            System.out.println("---------------------------------------------------");
            System.out.println("1) Scegli motorino");
            System.out.println("2) Termina il programma.");
            System.out.println("---------------------------------------------------\n");
            do
            {
                System.out.print("Scegli un opzione: ");
                scelta=scan.nextInt();
            }
            while(scelta<0||scelta>2);
            if(scelta==2)
            {
                fine=true;
            }
            else
            {
                do
                {
                    System.out.print("Scegli motorino: ");
                    scelta_moto=scan.nextInt();
                }
                while(scelta_moto<0||scelta_moto>=n_mot);
                System.out.println("---------------------------------------------------");
                System.out.println("1) Vedi dati motorino");
                System.out.println("2) Inserisci/togli l'antifurto ad un motorino.");
                System.out.println("3) Accelera con un motorino.");
                System.out.println("---------------------------------------------------\n");
                do
                {
                    System.out.print("Scegli un opzione: ");
                    scelta=scan.nextInt();
                }
                while(scelta<0||scelta>3);
                System.out.print("\n");
                switch(scelta)
                {
                    case 1:
                       garage.vediMoto(scelta_moto);
                    break;
                    case 2:
                        garage.Antifurto(scelta_moto);
                    break;
                    case 3:
                       garage.accellera(scelta_moto);
                    break;
                    
                }
            }
        }
        while(fine!=true);
    }
    
}
