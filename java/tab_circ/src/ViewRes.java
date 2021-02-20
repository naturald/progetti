public class ViewRes
{
    public void printRes(Resistenza[] res)
    {

        System.out.println("o------------o--------o");
        System.out.println("| "+strLen("Nome",10)+" | "+strLen("Valo",6)+" |");
        System.out.println("o------------o--------o");
        for(Resistenza i : res)
            if(i != null)
            {
                System.out.println("| " + strLen(i.getNome(), 10) + " | " +strLen((Math.floor(i.getValore()* 100) / 100)+"",6) + " |");
                System.out.println("o------------o--------o");
            }
    }
    public static String strLen(String string, int length) { return String.format("%1$"+length+"s", string); }
}
