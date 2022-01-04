
import java.io.*;

import java.io.BufferedReader;

public class tw4_File_IO {
    public static void main(String[] args) {
        String str;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter 'Stop' to quit");
        try {
            FileWriter fw = new FileWriter("test.txt");

            do {

                System.out.println(".");
                str = br.readLine();
                if (str.compareTo("Stop") == 0)
                    break;

                str = str + "\r\n";
                fw.write(str);
            } while (str.compareTo("Stop") != 0);
            fw.close();
        } catch (IOException exc) {
            System.out.println("I/O error:" + exc);
        }

    }
}