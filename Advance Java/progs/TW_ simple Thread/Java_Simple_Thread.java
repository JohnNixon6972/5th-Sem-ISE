
package java_simple_thread;

import java.lang.Thread;

class SimpleTh extends Thread
{
   String name;
    SimpleTh(String Name)
    {
        name=Name;
    }
    public void run()
    {
        System.out.print(" Thread Running");
    }
}

public class Java_Simple_Thread {

    
    public static void main(String[] args) {
        
        SimpleTh Th=new SimpleTh(" First Thread");
        Th.start();

SimpleTh Th1=new SimpleTh(" second Thread");
        Th1.start();

        
        System.out.println("From Main() ");
        System.out.print(Th.getName());
        
        
    }
    
}
