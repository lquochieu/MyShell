package MyShell;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;



public abstract class ConcurrentFilter extends Filter implements Runnable{
	protected BlockingQueue<String> input;
	protected BlockingQueue<String> output;
	protected String command;
	private Messenger messenger;
	
	public void setPrevFilter(Filter prevFilter) {
		prevFilter.setNextFilter(this);
	}
	
	public void setNextFilter(Filter nextFilter) {
		if(nextFilter instanceof ConcurrentFilter) {
			ConcurrentFilter concurrentFilter = (ConcurrentFilter) nextFilter;
			this.next = concurrentFilter;
			concurrentFilter.prev = this;
			if(this.output == null) {
				this.output = new LinkedBlockingQueue<String>();
			}
			concurrentFilter.next = (Filter) output;
		}
		else {
			throw new RuntimeException("Should not attempt to link dissimilar filter types.");
		}
		
	}
	
	public void run() {
		String line;
		try {
			while((line = input.take()) != PoisonPill.X) {
				String processLine = processLine(line);
				if(processLine != null) {
					output.offer(processLine);
				}
			}
			finish();
		} catch (Exception e) {
		}
	}
	
	public void finish() {
		try {
			if(output != null) {
				output.offer(PoisonPill.X);
			}
		} catch (Exception e) {
			System.out.println(e);
		}
	}
	
	protected void error(Messenger messenger) {
		throw new RuntimeException(messenger.with_parameter(command));
	}
	
	protected abstract String processLine(String line);
}
