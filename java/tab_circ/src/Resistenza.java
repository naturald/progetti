public class Resistenza
{
    private String nome;
    private float valore;
    private boolean usata = false;
    public Resistenza(float valore,String nome)
    {
        this.nome = nome;
        this.valore = valore;
    }
    public float getValore() {return valore;}
    public String getNome() {return nome;}
    public void setStatus() {this.usata =  !this.usata;}
    public boolean getStatus() {return usata;}
}
