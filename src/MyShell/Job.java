package MyShell;

import java.util.LinkedList;


public class Job {
	private String command;
	private LinkedList<Thread> chain;
	private Thread finalThread;
	private boolean isBackground;
	
	public Job(String command) {
		this.command = command;
	}
	
	public void setChain(LinkedList<Thread> chain) {
		this.chain = chain;
		this.finalThread = chain.get(chain.size() - 1);
	}
	
	public boolean isALive() {
		return finalThread.isAlive();
	}
	
	public boolean isBackground() {
		return this.isBackground;
	}
	
	public void start() {
		Thread.UncaughtExceptionHandler eHandler = new Thread.UncaughtExceptionHandler() {
			
			@Override
			public void uncaughtException(Thread t, Throwable e) {
				// TODO Auto-generated method stub
				System.out.println(e.getMessage());
				for(Thread t1 : chain) {
					t1.interrupt();
					}
				}
		};
		for(Thread t2 : chain) {
			t2.setUncaughtExceptionHandler(eHandler);
			t2.start();
		}
	}
	
	public void waitUtilDone() {
		try {
			for(Thread t3 : chain) {
				t3.join();
			}
		} catch (InterruptedException e) {
			// TODO: handle exception
		}
		
	}
}
