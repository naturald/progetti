public class ModelRela
{
    public Voci[] contenuto;
    private int nCirc = 0;
    public ModelRela(int n_res)
    {
        this.contenuto = new Voci[n_res];
    }
    public void remVoce(int nCircToRem)
    {
        int index = indexByNcirc(nCircToRem);
        contenuto = remVoceFormArray(contenuto,index);
        for(int i = 0;i<contenuto.length;i++)
            if(contenuto[i] != null)
                contenuto[i].setNcirc(i+1);
        this.nCirc--;
    }
    private int indexByNcirc(int nCirc)
    {
        for(int i = 0;i<contenuto.length;i++)
            if(contenuto[i] != null)
                if (contenuto[i].getNcirc() == nCirc)
                    return i;
        return -1;
    }
    public boolean voceExist(int nCirc)
    {
        for(int i = 0;i<contenuto.length;i++)
            if(contenuto[i] != null)
                if (contenuto[i].getNcirc() == nCirc)
                    return true;
        return false;
    }
    public void addVoce(String tipoRela,String[] R,float Rxy,float R1,float R2)
    {
        String[] traR = new String[] {R[0],R[1]};
        String segnoI = "=",segnoV = "=";
        if(tipoRela.equals("parallelo"))
            segnoI = "!";
        else
            segnoV = "!";
        contenuto[nCirc] = new Voci(nCirc+1,tipoRela,traR,"I"+traR[0].replaceFirst("^R","")+" "+segnoI+"= I"+traR[1].replaceFirst("^R",""),"V"+traR[0].replaceFirst("^R","")+" "+segnoV+"= V"+traR[1].replaceFirst("^R",""),Rxy,R1,R2);
        this.nCirc++;
    }
    public int getNcirc() {return this.nCirc;}
    public Voci[] getAllVoci() {return contenuto;}
    private Voci[] remVoceFormArray(Voci[] voci,int index)
    {
        Voci[] vociCopy = new Voci[voci.length];
        for(int i = 0, j = 0; i<vociCopy.length;i++,j++)
        {
            if(j == index)
                j++;
            if(j != vociCopy.length)
                vociCopy[i] = voci[j];
        }
        return vociCopy;
    }
    public String[] getTraRByNcirc(int nCirc)
    {
        int index = indexByNcirc(nCirc);
        return contenuto[index].getTraR();
    }
}
