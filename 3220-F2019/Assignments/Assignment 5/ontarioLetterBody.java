package complete;

public class ontarioLetterBody extends letterBody {

    @Override
    public String letterBody(double taxPayable, String province) {
        return "Your tax is $" + taxPayable + "\n\n";
    }
}
