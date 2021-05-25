package MyShell;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class MyShell {
	static final String EXIT_COMMAND = "exit";
	static String currentWorkingDirectory;
	static CurrentDir dir = new CurrentDir();
	public static void main(String[] args) throws IOException {
		System.out.println(Messenger.WELCOME.getMessenger());
		BufferedReader console = new BufferedReader (new InputStreamReader(System.in));
		currentWorkingDirectory = dir.getDir();
		JobManager jobs = new JobManager();
		
		while(true) {
			System.out.print(Messenger.NEW_COMMAND.getMessenger());
			String commandLine = console.readLine().trim();
			if(commandLine.equals(EXIT_COMMAND)) {
				System.out.println(Messenger.GOODBYE.getMessenger());
				break;
			}
			else {
				jobs.add(commandLine);
			}
		}
	}
}
