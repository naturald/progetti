import java.util.Scanner;

public class Controller
{
    private Scanner input = new Scanner(System.in);
    private Model model;
    private Tabella tabella;
    private int nCirc;

    public Controller()
    {
        System.out.print("quanti resistori ci sono : ");
        int n_res = input.nextInt();
        this.model = new Model(n_res);
        this.tabella = new Tabella(n_res);
    }
    public void addRelazione()
    {
        String Rx,Ry,tipoRela;
        float Rxy;
        boolean err = false;
        do
        {
            if(err == true)
            {
                System.out.println("la resistenza non esiste rimetti o e fia stata usata");
                err = false;
            }
            System.out.print("metti nome prima resistenza : ");
            Rx = input.next();
            if(model.ValByNome(Rx) == -1 || model.getStatusByNome(Rx))
                err = true;
        }
        while(err == true);
        do
        {
            if(err == true)
            {
                System.out.println("la resistenza non esiste rimetti o e fia stata usata");
                err = false;
            }
            System.out.print("metti nome seconda resistenza : ");
            Ry = input.next();
            if(model.ValByNome(Ry) == -1 || model.getStatusByNome(Ry))
                err = true;
        }
        while(err == true);

        do
        {
            if(err == true)
            {
                System.out.println("mettere o serie o parallelo non saranno accetati altri valori");
                err = false;
            }
            System.out.print("indicare il tipo di relazione (serie o parallelo) : ");
            tipoRela = input.next();
            if(!tipoRela.equals("serie") && !tipoRela.equals("parallelo"))
                err = true;
        }
        while(err == true);

        if(tipoRela.equals("serie"))
            Rxy = serie(model.ValByNome(Rx),model.ValByNome(Ry));
        else
            Rxy =parallelo(model.ValByNome(Rx),model.ValByNome(Ry));

        String[] traR = new String[] {Rx,Ry};
        tabella.addVoce(nCirc,tipoRela,traR,Rxy);
        model.addRes(traR,Rxy,nCirc);
        model.setStatusByNome(Rx);
        model.setStatusByNome(Ry);

        this.nCirc++;
    }
    public void stampaTab() {tabella.stamTab();}
    public void stampaRes() {tabella.stamRes(model.resiostori);}
    public void remRes()
    {
        System.out.print("nome resistenza da rimuovere: ");
        String resName = input.next();
        model.remRes(resName);
    }
    private float serie(float Rx,float Ry) { return Rx + Ry;}
    private float parallelo(float Rx,float Ry) { return (Rx * Ry)/(Rx + Ry);}
}
