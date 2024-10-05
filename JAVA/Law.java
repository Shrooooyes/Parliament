/*
 * @author: Shreyash Sawant
 * Roll no.:45
 */
public class Law {
    private String title;
    private String description;

    public Law(String title, String description){
        this.title = title;
        this.description = description;
    }

    public String getLaw(){
        return this.title + " " + this.description;
    }
}
