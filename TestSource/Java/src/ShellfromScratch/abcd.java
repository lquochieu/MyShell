package Shellfromscratch;

import java.io.*;
import java.util.*;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.TimeUnit;
import java.awt.*;  
import javax.swing.*;
import java.awt.event.ActionListener;  
import javax.swing.Timer;  
import java.awt.event.ActionEvent;

import com.sun.jdi.event.MonitorWaitedEvent;

import Shellfromscratch.DigitalClock1.SimpleDigitalClock;
import javaConsole.JavaConsole;
import menu.Menu;
import menu.MenuCallback;

public class abcd {
	private static boolean fContinue = true;
	private static boolean fContinueItem2 = true;
	private static JavaConsole console;
	private static Scanner scanner;
	public static void main(String[] args) {
		console = new JavaConsole();
		scanner = new Scanner(System.in);
		Menu menu = new Menu(console);
		while (true) {
			String command;
			System.out.print(">> ");
			command = scanner.nextLine();
			
			//list
			if (command.equals("help")) {
				System.out.println("Commands            Abilities");
				System.out.println();
				System.out.println("calc                       Open Windows Calculator");
				System.out.println("notepad                Open Windows Notepad");
				System.out.println("exit                       Exit the console");
				System.out.println("time                      Show present time");
			}
			
			//exit
			else if (command.equals("exit")) {
				System.out.println("Bye my friend, see you later!");
				scanner.close();
				try {
					TimeUnit.SECONDS.sleep(1);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				System.exit(0);
			}
			
			//calculator
			else if(command.equals("calc")) {
				Runtime app = Runtime.getRuntime();
				try {
					app.exec("calc");
				} catch (Exception e) {
					System.out.println("Error: " + e.toString());
				}
			}
			
			//notepad
			else if(command.equals("notepad")) {
				Runtime app = Runtime.getRuntime();
				try {
					app.exec("notepad");
				} catch (Exception e) {
					System.out.println("Error: " + e.toString());
				}
			}
			
			else if (command.equals("time")) {
				JFrame frm = new JFrame();  
		        frm.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);  
		        SimpleDigitalClock clock1 = new SimpleDigitalClock();  
		        frm.add(clock1);  
		        frm.pack();  
		        frm.setVisible(true);  
			}
			
			else if(command.equals("cmd")) {
				Runtime rt = Runtime.getRuntime();
				try {
					Process pr = rt.exec("calc /c start");
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			
			else if(command.equals("paint")) {
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
			
			else {
				System.out.println("Illegal command!");
			}
		}
	}
}
