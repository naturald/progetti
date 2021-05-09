public class TeenNumberChecker {

    public static boolean hasTeen(int a,int b,int c)
    {
        boolean ris = false;
        if(a>=13 && 19>=a)
            ris = true;
        if(b>=13 && 19>=b)
            ris = true;
        if(c>=13 && 19>=c)
            ris = true;

        return ris;
    }

    public static boolean isTeen(int a)
    {
        boolean ris = false;
        if(a>=13 && 19>=a)
            ris = true;

        return ris;
    }
}