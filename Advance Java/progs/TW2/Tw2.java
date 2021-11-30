import java.util.*;

public class Tw2 {
    public static void main(String args[]){
        byte b =10;
        short s = 20;
        int i =30;
        float f =50.0F;
        long l=40;
        double d = 60.0D;
        char c = 'a';
        boolean b2 = true;

        //Autoboxing : Converting primitives into objects
        Byte byteobj = b;
        Short shortobj = s;
        Integer intobj = i;
        Float floatobj = f;
        Long longobj =l;
        Double doubleobj = d;
        Character charobj = c;
        Boolean boolobj = b2;

        //Printing objects
        System.out.println("---Printing Object Objects---");
        System.out.println("Byte object :: "+byteobj);
        System.out.println("Short object :: "+shortobj);
        System.out.println("Integer object :: "+intobj);
        System.out.println("Float object :: "+floatobj);
        System.out.println("Long object :: "+longobj);
        System.out.println("Character object :: "+charobj);
        System.out.println("Boolean object :: "+boolobj);
        System.out.println("Double object :: "+doubleobj);

        // Unboxing Converting objects into primitives
        int intval = intobj;
        float floatval = floatobj;
        short shortval = shortobj;
        byte byteval = byteobj;
        long longval = longobj;
        double doubleval = doubleobj;
        char charval = charobj;
        boolean boolval = boolobj;

        // Printing Values
        System.out.println("---Printing Primitive Values---");
        System.out.println("Byte Value :: "+byteval);
        System.out.println("Short values :: "+shortval);
        System.out.println("Integer values :: "+intval  );
        System.out.println("Float values :: "+floatval);
        System.out.println("Long values :: "+longval);
        System.out.println("Character values :: "+charval);
        System.out.println("Boolean values :: "+boolval);
        System.out.println("Double values :: "+doubleval);


    }
}
