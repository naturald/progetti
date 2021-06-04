public class NumberPalindrome {
    public static boolean isPalindrome(int num)
    {
        int i = 0;
        if(num < 0)
            num *= -1;
        int numCopy = num, reverse = 0,len = 0;
        while (numCopy > 0)
        {
            numCopy /= 10;
            len++;
        }
        numCopy = num;
        while (num > 0)
        {
            int dig = num % 10;
            reverse += (dig * (Math.pow(10,(len-1)-i)));
            num /= 10;
            System.out.println(dig+" "+num+" "+reverse);
            i++;
        }
        if(numCopy == reverse)
            return true;
        else
            return false;
    }
}
