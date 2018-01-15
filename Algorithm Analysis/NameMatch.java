import java.util.regex.*;

public class NameMatch
{
public static void main(String[] args)
{
        String text = "fkdlsjkjf342lkjsdf92";
        String pattern = "^([A-z\\'\\.\\-]*(\\s))+[A-z\\'\\.\\-]*$";
        Pattern p = Pattern.compile(pattern);
        Matcher m = p.matcher(text);
        System.out.println(m.matches());
}
}
