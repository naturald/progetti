import javax.crypto.NullCipher;
import javax.lang.model.type.NullType;
import java.util.Scanner;

public class ModelRes
{
    private Scanner input = new Scanner(System.in);
    public Resistenza[] resiostori;
    private int n_res;
    public ModelRes(int n_res)
    {
        this.n_res = n_res;
        float valore;
        String nome;
        resiostori = new Resistenza[n_res*2];
        for (int i = 0; i < n_res; i++)
        {
            System.out.print("metti il valore della resitenza R"+(i+1)+" : ");
            valore = input.nextFloat();
            resiostori[i] = new Resistenza(valore, "R"+(i+1));
        }
    }
    public void addRes(String[] traR,float val,int nCirc)
    {
        String nome = "R"+traR[0].replaceFirst("^R","")+traR[1].replaceFirst("^R","");
        resiostori[n_res+nCirc] = new Resistenza(val,nome);
    }
    public void remRes(String Rnome)
    {
        int index = indexByNome(Rnome);
        resiostori = remResFormArray(resiostori,index);
    }
    public float ValByNome(String Rnome)
    {
        int index = indexByNome(Rnome);
        if(index != -1)
            return resiostori[indexByNome(Rnome)].getValore();

        return -1;
    }
    public boolean getStatusByNome(String Rnome)
    {
        int index = indexByNome(Rnome);
        if(index != -1)
            return resiostori[indexByNome(Rnome)].getStatus();

        return false;
    }
    public void setStatusByNome(String Rnome)
    {
        int index = indexByNome(Rnome);
        if(index != -1)
            resiostori[indexByNome(Rnome)].setStatus();
    }
    private int indexByNome(String Rnome)
    {
        for(int i = 0;i<resiostori.length;i++)
            if(resiostori[i] != null)
                if (resiostori[i].getNome().equals(Rnome))
                    return i;
        return -1;
    }
    public int resAve()
    {
        int nResAve = 0;
        for(Resistenza i : resiostori)
            if(i!= null && !i.getStatus())
                nResAve++;
        return nResAve;
    }
    public float rEqi(String tipoRela,String[] R)
    {
        float Rxy;
        if(tipoRela.equals("serie"))
            Rxy = serie(ValByNome(R[0]),ValByNome(R[1]));
        else
            Rxy =parallelo(ValByNome(R[0]),ValByNome(R[1]));
        return Rxy;
    }
    public Resistenza[] getAllRes() {return resiostori;}
    private float serie(float Rx,float Ry) { return Rx + Ry;}
    private float parallelo(float Rx,float Ry) { return (Rx * Ry)/(Rx + Ry);}
    private Resistenza[] remResFormArray(Resistenza[] res,int index)
    {
        Resistenza[] resCopy = new Resistenza[res.length];
        for(int i = 0, j = 0; i<resCopy.length;i++,j++)
        {
            if(j == index)
                j++;
            if(j != resCopy.length)
                resCopy[i] = res[j];
        }
        return resCopy;
    }
}
