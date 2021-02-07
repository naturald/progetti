import java.util.Scanner;


public class Main
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        Controller controller = new Controller();
        int scelta;
        do
        {
            System.out.println("-------------------------------------");
            System.out.println("1) stampare tabella relazioni");
            System.out.println("2) stampare tabella resistori");
            System.out.println("3) aggiungere relazione");
            System.out.println("4) rimuovi relazione");
            System.out.println("5) rimuovi resistore");
            System.out.println("6) esci");
            System.out.println("-------------------------------------");
            System.out.print("scelta : ");
            scelta = input.nextInt();
            switch (scelta)
            {
                case 1:
                    controller.stampaTab();
                break;
                case 2:
                    controller.stampaRes();
                break;
                case 3:
                    controller.addRelazione();
                break;
                case 4:
                    controller.remRes();
                break;
                case 5:

                break;
            }
        }
        while(scelta != 6);

    }
}
