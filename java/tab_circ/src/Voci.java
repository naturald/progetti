public class Voci
{
    private int nCirc;
    private String tipoCon;
    private String[] traR= new String[2];
    private float Rxy;
    private String compV;
    private String compI;
    public Voci(int nCirc,String tipoCon,String[] tra_r,String compV,String compI,float Rxy)
    {
        this.nCirc = nCirc;
        this.tipoCon = tipoCon;
        this.traR = tra_r;
        this.compV = compV;
        this.compI = compI;
        this.Rxy = Rxy;
    }
    public int getNcirc() {return this.nCirc;}
    public String getTipoCon() {return this.tipoCon;}
    public String[] getTraR() {return this.traR;}
    public String getCompV() {return this.compV;}
    public String getCompI() {return this.compI;}
    public float getRxy() {return this.Rxy;}
    public void setNcirc(int nCirc) {this.nCirc = nCirc;}

}
