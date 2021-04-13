public class Voci
{
    private int nCirc;
    private String tipoCon;
    private String[] traR;
    private float Rxy;
    private String compV;
    private String compI;
    private float[] valR = new float [2];
    public Voci(int nCirc,String tipoCon,String[] tra_r,String compV,String compI,float Rxy,float R1,float R2)
    {
        this.nCirc = nCirc;
        this.tipoCon = tipoCon;
        this.traR = tra_r;
        this.compV = compV;
        this.compI = compI;
        this.Rxy = Rxy;
        this.valR[0] = R1;
        this.valR[1] = R2;
    }
    public int getNcirc() {return this.nCirc;}
    public String getTipoCon() {return this.tipoCon;}
    public String[] getTraR() {return this.traR;}
    public String getCompV() {return this.compV;}
    public String getCompI() {return this.compI;}
    public float getRxy() {return this.Rxy;}
    public void setNcirc(int nCirc) {this.nCirc = nCirc;}
    public float[] getValR() {return this.valR;}


}
