public class Voci
{
    public int nCirc;
    public String tipoCon;
    public String[] tra_r = new String[2];
    public float Rxy;
    public String compV;
    public String compI;
    public Voci(int nCirc,String tipoCon,String[] tra_r,String compV,String compI,float Rxy)
    {
        this.nCirc = nCirc;
        this.tipoCon = tipoCon;
        this.tra_r = tra_r;
        this.compV = compV;
        this.compI = compI;
        this.Rxy = Rxy;
    }
}
