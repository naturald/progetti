public class SpeedConverter {
    public static long toMilesPerHour(double kilometersPerHour)
    {
        if(kilometersPerHour < 0)
            return -1;

        double milesPerHour = (kilometersPerHour* 0.621371);

        if(Math.abs(0.50 - (milesPerHour - (long)milesPerHour)) < 0.02)
            return Math.round(kilometersPerHour * 0.621371)+1;
        else
            return Math.round(kilometersPerHour * 0.621371);
    }
    public static void printConversion(double kilometersPerHour)
    {
        long milesPerHour = toMilesPerHour(kilometersPerHour);
        if(milesPerHour == -1)
            System.out.println("Invalid Value");
        else
            System.out.println(kilometersPerHour + " km/h " + "= " + milesPerHour + " mi/h");
    }
}
