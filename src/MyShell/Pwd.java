package MyShell;

import java.util.concurrent.BlockingDeque;
import java.util.concurrent.LinkedBlockingDeque;
import java.util.concurrent.LinkedBlockingQueue;

public class Pwd extends ConcurrentFilter {
	
	public Pwd(String command) {
		this.command = command;
		if (command.split(" ").length > 1) {
			error(Messenger.CANNOT_HAVE_PARAMETER);
		}
	}
	
	@Override
	public void run() {
		String pwd = MyShell.currentWorkingDirectory;
		try {
			if(output == null) {
				output = new LinkedBlockingQueue<String>();
			}
			System.out.println(pwd);
			output.offer(pwd);
			finish();
		} catch (Exception ex) {
			System.out.println(ex);
		}
	}
	
	@Override
	protected String processLine(String line) {
		return null;
	}
	
	@Override
	public void setPrevFilter(Filter f) {
		error(Messenger.CANNOT_HAVE_INPUT);
	}
}
