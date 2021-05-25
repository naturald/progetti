public class SumOddRange {
    public static int sumOdd(int start,int end)
    {
        if((start > end) || (start < 1 || end < 1))
            return -1;
        int sum = 0;
        for(int i = start; i<=end; i++)
        {
            if(isOdd(i))
                sum+= i;
        }
        return sum;
    }

    public static boolean isOdd(int number)
    {
        if(number % 2 == 1 && number > 0)
            return true;

        return false;
    }
}
