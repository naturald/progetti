public class prove
{
    public static void main(String[] args)
    {
        System.out.println( pointsCount(true,1000,10));
        System.out.println( pointsCount(false,100,100));
        displayHighscorePosition("marco",1);
        System.out.println(highScore(pointsCount(true,100,100)));
    }

    public static void displayHighscorePosition(String name, int pos)
    {
        System.out.println(name + " e arrivato alla pos: " + pos);
    }

    public static int highScore(double score)
    {
        int pos = 4;
        if (score >= 1000)
        {
            pos =  1;
        }
        else if (score >= 500)
        {
            pos =  2;
        }
        else if (score >= 100)
        {
            pos = 3;
        }

        return pos;

    }

    public static double pointsCount(boolean gameover, double points, int level)
    {
        if(gameover)
        {
            return points*level;
        }
        return -1;
    }
}
