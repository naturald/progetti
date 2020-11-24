package com.company;
//package motorino;
import java.util.Scanner;

class Motorino {
    private String tipo;
    private double velocità;
    private String colore;
    private boolean antifurto;

    /**
     *  @param colore
     *  @param tipo
     *  @param velocità
     *  @param antifurto
     */
    public Motorino (String tipo, String colore, double velocità,  boolean antifurto){
        this.tipo=tipo;
        this.velocità=velocità;
        this.colore=colore;
        this.antifurto=false;
    }

    /**
     * @return
     */
    public double getVelocita(){
        return this.velocità;
    }

    /**
     *
     * @param accelerazione
     */
    public void accelera(double accelerazione){
        if(!this.antifurto){
            this.velocità=this.velocità+accelerazione;
        }
    }

    /**
     *
     */
    public void inserisciAntifurto(){
        this.antifurto=!this.antifurto;
    }

    public String stampa(int temp) {
        String a="Dati del motorino "+ temp +": Marca e modello: "+this.tipo+". Colore: "+this.colore+". Velocita': "+this.velocità+" chilometri orari."+" Antifurto: "+ this.antifurto;
        return a;
    }
}
public class Main {

    public static void main(String[] args) {
        Scanner myScan=new Scanner(System.in);
        int scelta;
        int n=leggi("Quanti motorini vuoi mettere nel garage?");
        Motorino[] garage= new Motorino[n];
        GestioneGarage x= new GestioneGarage(garage);
        do{
            System.out.println("");
            System.out.println("Selezionare l'operazione:");
            System.out.println("1)Inserire i dati dei motorini.");
            System.out.println("2)Stampare i dati di un motorino.");
            System.out.println("3)Inserisci/togli l'antifurto ad un motorino.");
            System.out.println("4)Accelera con un motorino.");
            System.out.println("5)Termina il programma.");
            scelta=myScan.nextInt();
            switch(scelta){
                case 1:
                    x.carica();
                    //registro[0].stampa();
                    break;
                case 2:
                    int temp;
                    System.out.println("Di quale motorino vuoi stampare i dati?");
                    temp=myScan.nextInt();
                    while(temp<0||temp>=n){
                        System.out.println("Errore, di quale motorino vuoi stampare i dati?");
                        temp=myScan.nextInt();
                    }
                    System.out.println(garage[temp].stampa(temp));
                    break;
                case 3:
                    int t;
                    System.out.println("A quale motorino vuoi attivare/disattivare l'antifurto?");
                    t=myScan.nextInt();
                    while(t<0||t>=n){
                        System.out.println("Errore, a quale motorino vuoi attivare/disattivare l'antifurto?");
                        t=myScan.nextInt();
                    }
                    garage[t].inserisciAntifurto();
                    break;
                case 4:
                    int temp1;
                    double accelerazione;
                    System.out.println("Con quale motorino vuoi accelerare");
                    temp1=myScan.nextInt();
                    while(temp1<0||temp1>n){
                        System.out.println("Errore, con quale motorino vuoi accelerare");
                        temp1=myScan.nextInt();
                    }
                    System.out.println("Di quanti chilometri orari vuoi accelerare o decelerare?");
                    accelerazione=myScan.nextDouble();
                    garage[temp1].accelera(accelerazione);
                    break;
            }
        }while(scelta!=5);
    }


    public static int leggi(String msg){
        Scanner myScan=new Scanner(System.in);
        System.out.println(msg);
        int val=myScan.nextInt();
        while(val<0||val>9){
            System.out.println("Errore, inserire un numero compreso tra 0 e 9.");
            val=myScan.nextInt();
        }

        return val;
    }

}
class GestioneGarage {
    Scanner myScan=new Scanner(System.in);
    private Motorino[] x;

    public GestioneGarage(Motorino[] x) {
        this.x = x;
    }

    public void carica(){
        for(int i=0;i<x.length;i++){
            System.out.println("Inserisci la marca e il modello del motorino "+ i);
            String tipo=myScan.next();
            System.out.println("Inserisci il colore del motorino "+ i);
            String colore=myScan.next();
            System.out.println("Inserisci la velocità del motorino "+ i);
            double velocità=myScan.nextDouble();
            boolean antiFurto=false;
            x[i]=new Motorino(tipo,colore,velocità,antiFurto);
        }
    }
}