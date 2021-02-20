import java.util.Scanner;


public class Main
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int Nres,scelta;
        do
        {
            System.out.print("quanti resistori ci sono (min 2 max 9): ");
            Nres = input.nextInt();
        }
        while(Nres > 9 || Nres < 2);
        ModelRela modelRela = new ModelRela(Nres);
        ModelRes modelRes = new ModelRes(Nres);
        ViewRela viewRela = new ViewRela();
        ViewRes viewRes = new ViewRes();
        Controller controller = new Controller(modelRela,modelRes,viewRela,viewRes);
        do
        {
            System.out.println("-------------------------------------");
            System.out.println("1) stampare tabella relazioni");
            System.out.println("2) stampare tabella resistori");
            System.out.println("3) aggiungere relazione");
            System.out.println("4) rimuovi relazione");
            System.out.println("5) esci");
            System.out.println("-------------------------------------");
            System.out.print("scelta : ");
            scelta = input.nextInt();
            switch (scelta)
            {
                case 1:
                    controller.printTab();
                break;
                case 2:
                    controller.printRes();
                break;
                case 3:
                    controller.addRelazione();
                break;
                case 4:
                    controller.remRelazione();
                break;
            }
        }
        while(scelta != 5);

    }
}
