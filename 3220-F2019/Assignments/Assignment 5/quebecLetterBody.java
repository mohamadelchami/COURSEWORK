package complete;

public class quebecLetterBody extends letterBody{

    @Override
    public String letterBody(double taxPayable, String province) {
        return "Votre taxe est $" + taxPayable + "\n\n";
    }
}
