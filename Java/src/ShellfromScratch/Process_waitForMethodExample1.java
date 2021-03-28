package Shellfromscratch;

public class Process_waitForMethodExample1 {
	public static void main(String[] args) {  
        try {  
            // creating a new process.  
            System.out.println("Ms Paint will run.");  
            Process p = Runtime.getRuntime().exec("mspaint.exe");  
            // waits for the process until you terminate.  
            p.waitFor();  
            // when you manually close Ms Paint.exe program will continue here  
            System.out.println("You have exited from Ms paint.");  
        } catch (Exception ex) {  
            System.out.println("exception is:"+ex);  
        }  
    }  
}
