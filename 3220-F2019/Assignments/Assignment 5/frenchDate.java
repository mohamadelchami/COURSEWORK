package complete;

import java.util.StringTokenizer;

public class frenchDate extends myDate{

    public frenchDate(String inputString){
        StringTokenizer tokenizeDate = new StringTokenizer(inputString, "/");
        this.day = Integer.parseInt(tokenizeDate.nextToken());
        this.month = Integer.parseInt(tokenizeDate.nextToken());
        this.year = Integer.parseInt(tokenizeDate.nextToken());
    }

    @Override
    public String toString() {
        String monthNames[] = {"janvier", "fevrier", "mars",
                "avril", "mai", "juin", "juillet", "aout",
                "septembre", "octobre", "novembre", "decembre"};

        return ( this.day + " " + monthNames[this.month-1] +  ", " + this.year );
    }

}
