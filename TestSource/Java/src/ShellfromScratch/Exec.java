package Shellfromscratch;

import java.io.*;

public class Exec {
  public static void main(String args[]) {
	  try {
		  // kiểm tra ping google.com (gửi 5 gói tin)
		  ProcessBuilder builder = new ProcessBuilder("cmd.exe", "/c", "ping stackjava.com -n 5");
		  // thực thi command line
		  Process p = builder.start();
		  // lấy kết quả trả về trên command line
		  BufferedReader r = new BufferedReader(new InputStreamReader(p.getInputStream()));
		  String line;
		  while (true) {
		    line = r.readLine();
		    if (line == null) {
		      break;
		    }
		    System.out.println(line);
		  }
		} catch (IOException ex) {
		  System.out.println("loi Ping: " + ex.toString());
		}
  }
}
