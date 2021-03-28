package MyShell;

import java.util.Scanner;

public class MyShell {
	static final String EXIT_COMMAND = "exit";
	static String currentWorkingDirectory;
	static CurrentDir dir = new CurrentDir();
	public static void main(String[] args) {
		System.out.println(Messenger.WELCOME);
		
		Scanner read = new Scanner(System.in);
		currentWorkingDirectory = dir.getDir();
		JobManager jobs = new JobManager();
		
		while(true) {
			System.out.println(Messenger.NEW_COMMAND);
			String commandLine = read.nextLine().trim();
			if(commandLine.equals(EXIT_COMMAND)) {
				System.out.println(Messenger.GOODBYE);
				break;
			}
			else {
				jobs.add(commandLine);
			}
		}
	}
}
