package complete;

public class ontarioTaxFactory extends IncomeTaxFactory {

    @Override
    public dateAddress createDateAddress(){
        return new ontarioDateAddress();
    }

    @Override
    public taxCalculator calculateTax() {
        return new ontarioTaxCalculator();
    }

    @Override
    public letterBody createLetterBody(){
        return new ontarioLetterBody();
    }

    @Override
    public salutations createSalutation() {
        return new englishSalutations();
    }

    @Override
    public myDate dateFactory() {
        return new englishDate(myDate.current("MM/dd/yy"));
    }
}
