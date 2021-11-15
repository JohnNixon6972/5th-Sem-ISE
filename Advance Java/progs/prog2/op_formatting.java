//WAP Java program to demonstrate formatting of the output using java I/O.

import java.util.*;

public class op_formatting {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter A Float Number :: ");
        float num = scan.nextFloat();
        System.out.printf("%.1f", num);
        scan.close();
    }
}