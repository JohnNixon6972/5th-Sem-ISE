// import java.util.*;
import java.io.*;
public class byteio {
    public static void main(String args[])throws IOException{
        byte[] data = new byte[10];
        System.out .println("Enter some Characters ");
        int numRead = System.in.read(data);
        System.out.println("You Entered");
        for(int i=0;i<numRead;++i){
            System.out.println((char)data[i]);
        }
    }
}
