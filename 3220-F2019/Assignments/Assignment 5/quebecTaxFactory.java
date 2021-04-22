package complete;

public class quebecTaxFactory extends IncomeTaxFactory {

    @Override
    public dateAddress createDateAddress() {
        return new quebecDateAddress();
    }

    @Override
    public taxCalculator calculateTax() {
        return new quebecTaxCalculator();
    }

    @Override
    public letterBody createLetterBody() {
        return new quebecLetterBody();
    }

    @Override
    public salutations createSalutation() {
        return new frenchSalutations();
    }

    @Override
    public myDate dateFactory() {
        return new frenchDate(myDate.current("dd/mm/yy"));
    }
}
