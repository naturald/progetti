public class FirstLastDigitSum {
    public static int sumFirstAndLastDigit(int num)
    {
        if(num < 0)
            return -1;
        int sum = num%10;
        while(num > 9)
            num /= 10;
        sum += num;
        return sum;
    }

}
