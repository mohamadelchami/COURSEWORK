package complete;

public class ontarioDateAddress extends dateAddress {

    @Override
    public String displayAddress(myDate today, String address, String province) {
        return today.toString()+"\n"+address+"\n"+province+"\n";
    }
}
