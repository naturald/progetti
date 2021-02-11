public class Tabella
{
    public Voci[] contenuto;
    public Tabella(int n_res)
    {
        this.contenuto = new Voci[n_res];
    }
    public void addVoce(int nCirc,String tipoCon,String[] tra_r,float Rxy)
    {
        String segnoI = "=",segnoV = "=";
        if(tipoCon.equals("parallelo"))
            segnoI = "!";
        else
            segnoV = "!";
        contenuto[nCirc] = new Voci(nCirc+1,tipoCon,tra_r,"I"+tra_r[0].replaceFirst("^R","")+" "+segnoI+"= I"+tra_r[1].replaceFirst("^R",""),"V"+tra_r[0].replaceFirst("^R","")+" "+segnoV+"= V"+tra_r[1].replaceFirst("^R",""),Rxy);
    }
    public void stamTab()
    {
        System.out.println("--------------------------------------------------------------------------------------");
        System.out.println("| "+strLen("Circ",4)+" | "+strLen("relazione",10)+" | "+strLen("tra quali R",13)+" | "+strLen("comp I",17)+" | "+strLen("comp V",17)+" | "+strLen("Rxy",6)+" |");
        System.out.println("--------------------------------------------------------------------------------------");
        for(Voci i : contenuto)
        {
            if(i != null)
            {
                System.out.print("| " + strLen(i.nCirc+"",4) + " | " + strLen(i.tipoCon,10) + " | " + strLen(i.tra_r[0] + "," + i.tra_r[1],13)+ " | " + strLen(i.compV ,17)+ " | " + strLen(i.compI,17) + " | " + strLen((Math.floor(i.Rxy * 100) / 100)+"",6) + " | \n");
                System.out.println("--------------------------------------------------------------------------------------");
            }
        }
    }
    public void stamRes(Resistenza[] res)
    {

        System.out.println("o------------o------o");
        System.out.println("| "+strLen("Nome",10)+" | "+strLen("Valo",4)+" |");
        System.out.println("o------------o------o");
        for(Resistenza i : res)
            if(i != null)
            {
                System.out.println("| " + strLen(i.getNome(), 10) + " | " + strLen(i.getValore() + "", 4) + " |");
                System.out.println("o------------o------o");
            }
    }
    public static String strLen(String string, int length) { return String.format("%1$"+length+"s", string); }

}
