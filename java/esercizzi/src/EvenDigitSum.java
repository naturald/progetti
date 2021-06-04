public class EvenDigitSum {
    public static int getEvenDigitSum(int num)
    {
        if(num < 0)
            return -1;
        int sum = 0,dig;
        while(num > 0)
        {
            dig =  num % 10;
            if(dig % 2 == 0)
                sum += dig;
            num /= 10;
        }
        return sum;
    }

}
