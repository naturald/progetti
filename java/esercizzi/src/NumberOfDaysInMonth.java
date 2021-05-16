public class NumberOfDaysInMonth {
    public static boolean isLeapYear(int year)
    {
        if(year < 1 || year > 9999)
            return false;
        if(year%4 == 0)
        {
            if(year%100 == 0)
                if(year%400 == 0)
                    return true;
                else
                    return false;
            else
                return true;
        }

        return false;
    }
    public static int getDaysInMonth(int month,int year)
    {
        int ret;
        if(year < 1 || year > 9999)
            return -1;
        switch (month)
        {
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                ret = 31;
            break;
            case 4:case 6:case 9:case 11:
                ret = 30;
            break;
            case 2:
                if(isLeapYear(year))
                    ret = 29;
                else
                    ret = 28;
            break;
            default:
                ret = -1;
            break;
        }

        return ret;
    }

}
