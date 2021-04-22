package complete;

public class englishSalutations extends salutations{

    @Override
    public String salutation(String name, String gender) {
        if (gender.equals("male")){
            return "Dear Mr " + name + ",\n";
        }
        else{
            return "Dear Ms " + name + ",\n";
        }
    }
}
