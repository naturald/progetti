public class DecimalComparator {
    public static boolean areEqualByThreeDecimalPlaces(double n1,double n2)
    {
        if(Math.abs(n1 - n2) < 0.0009)
            return true;
        return false;
    }
}
