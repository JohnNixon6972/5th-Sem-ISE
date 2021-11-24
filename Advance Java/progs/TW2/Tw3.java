
// WAP java prog to convert its primitives into its corresponding wrapper objects and vice versa
import java.util.*;

public class Tw3 {
    // Primary Data Types
    public static void main(String args[]) {
        byte b = 10;
        int i = 20;

        // Primitive to Wrapper Objects
        Byte byteobj = b;
        Integer intobj = i;

        System.out.println("b : "+b);
        System.out.println("i : "+i);

        System.out.println("Primitive to Wrapper Object ");
        System.out.println("Byte object " + byteobj);
        System.out.println("Interger object " + intobj);
        // Wrapper to Primitive
        int intval = intobj;
        byte byteval = byteobj;

        System.out.println("Byte Value " + byteval);
        System.out.println("Interger Value " + intval);
    }

}
