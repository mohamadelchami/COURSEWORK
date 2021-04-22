package complete;

public class frenchSalutations extends salutations {

    @Override
    public String salutation(String name, String gender) {
        if (gender.equals("male")){
            return "Cher Mr " + name + ",\n";
        }
        else{
            return "Chere Mme/Melle " + name + ",\n";
        }
    }
}
