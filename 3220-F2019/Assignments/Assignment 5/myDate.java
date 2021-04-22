package complete;


import java.text.SimpleDateFormat;
import java.util.Calendar;

public abstract class myDate {

    int day;
    int month;
    int year;

    public static String current(String date){
        Calendar cal = Calendar.getInstance();
        SimpleDateFormat sdf = new SimpleDateFormat(date);
        return sdf.format(cal.getTime());
    }

    public abstract String toString();


}
