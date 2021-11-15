import java.util.*;
public class simpleio{
    public static void main(String args[]){
        Scanner scan = new Scanner(System.in);
        String msg;
        System.out.println("Enter a String");
        msg = scan.nextLine();
        System.out.println("Your message is :: "+msg);
        scan.close();
    }
}