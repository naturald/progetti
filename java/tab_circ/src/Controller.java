import java.util.Scanner;

public class Controller
{
    private Scanner input = new Scanner(System.in);
    public ModelRela modelRela;
    public ModelRes modelRes;
    public ViewRela viewRela;
    public ViewRes viewRes;

    public Controller(ModelRela modelRela,ModelRes modelRes,ViewRela viewRela,ViewRes viewRes)
    {
        this.modelRela = modelRela;
        this.modelRes = modelRes;
        this.viewRela = viewRela;
        this.viewRes = viewRes;
    }
    public void addRelazione()
    {
        if(modelRes.resAve() < 2)
        {
            System.out.println("non ci sono abbastanza resistenze libere per creare una nuova relazione ");
            return;
        }
        String tipoRela;
        String[] R = new String[2];
        boolean err = false;
        for(int i = 0;i<2;i++)
            do
            {
                if(err == true)
                {
                    System.out.println("la resistenza non esiste rimetti o e fia stata usata");
                    err = false;
                }
                System.out.print("metti nome "+(i+1)+"° resistenza : R");
                R[i] = "R"+input.next();
                if(modelRes.ValByNome(R[i]) == -1 || modelRes.getStatusByNome(R[i]))
                    err = true;
            }
            while(err == true);
        do
        {
            if(err == true)
            {
                System.out.println("mettere serie o parallelo non saranno accetati altri valori");
                err = false;
            }
            System.out.print("indicare il tipo di relazione (serie o parallelo) : ");
            tipoRela = input.next();
            if(!tipoRela.equals("serie") && !tipoRela.equals("parallelo"))
                err = true;
        }
        while(err == true);
        float Rxy = modelRes.rEqi(tipoRela,R);
        modelRela.addVoce(tipoRela,R,Rxy,modelRes.ValByNome(R[0]),modelRes.ValByNome(R[1]));
        modelRes.addRes(R,Rxy,modelRela.getNcirc());
        modelRes.setStatusByNome(R[0]);
        modelRes.setStatusByNome(R[1]);
    }
    public void remRelazione()
    {
        int nCircToRem;
        boolean err = false;
        do
        {
            if(err)
            {
                err = false;
                System.out.println("non esiste questo circuito metti un circuito valido");
            }
            System.out.print("specifice il numero del circuito che vuoi rimuovere : ");
            nCircToRem = input.nextInt();
            if(!modelRela.voceExist(nCircToRem))
                err = true;
        }
        while(err);
        String[] traR = modelRela.getTraRByNcirc(nCircToRem);
        modelRes.remRes("R"+traR[0].replaceFirst("^R","")+traR[1].replaceFirst("^R",""));
        modelRes.setStatusByNome(traR[0]);
        modelRes.setStatusByNome(traR[1]);
        modelRela.remVoce(nCircToRem);
    }
    public void printTab()
    {
        viewRela.printRela(modelRela.getAllVoci());
    }
    public void printRes()
    {
        viewRes.printRes(modelRes.getAllRes());
    }
}
