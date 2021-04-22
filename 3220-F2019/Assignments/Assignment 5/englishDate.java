package complete;

import java.util.StringTokenizer;

public class englishDate extends myDate{

    public englishDate(String inputString)
    {
        StringTokenizer tokenizeDate = new StringTokenizer(inputString, "/");
        this.month = Integer.parseInt(tokenizeDate.nextToken());
        this.day = Integer.parseInt(tokenizeDate.nextToken());
        this.year = Integer.parseInt(tokenizeDate.nextToken());
    }

    @Override
    public String toString() {
        String monthNames[] = {"January", "February", "March", "April", "May",
                "June", "July", "August", "September", "October",
                "November", "December"};

        return ( monthNames[this.month-1] + " " + this.day +  ", " + this.year );
    }
}
