public class ViewRela
{
    public void printRela(Voci[] contenuto)
    {
        System.out.println("--------------------------------------------------------------------------------------");
        System.out.println("| "+strLen("Circ",4)+" | "+strLen("relazione",10)+" | "+strLen("tra quali R",13)+" | "+strLen("comp I",17)+" | "+strLen("comp V",17)+" | "+strLen("Rxy",6)+" |");
        System.out.println("--------------------------------------------------------------------------------------");
        for(Voci i : contenuto)
        {
            if(i != null)
            {
                String[] traR = i.getTraR();
                System.out.print("| " + strLen(i.getNcirc()+"",4) +
                        " | " + strLen(i.getTipoCon(),10) +
                        " | " + strLen(traR[0] + "," + traR[1],13)+
                        " | " + strLen(i.getCompV() ,17)+ " | " + strLen(i.getCompI(),17) +
                        " | " + strLen((" R1 = " +Math.floor(i.getValR()[0] * 100) / 100),12) + strLen((" R2 = " + Math.floor(i.getValR()[1] * 100) / 100),12) + strLen(("Rxy = " +Math.floor(i.getRxy() * 100) / 100),13) + " | \n");
                System.out.println("--------------------------------------------------------------------------------------");
            }
        }
    }
    public static String strLen(String string, int length) { return String.format("%1$"+length+"s", string);}
}
