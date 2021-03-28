package MyShell;

import java.util.LinkedList;
import java.util.Queue;

public class JobManager {
	private Queue<Job> jobQueue;
	public JobManager () {
		this.jobQueue = new LinkedList<Job>();
	}
	
	public void add(String command) {
		try {
			Job job = ConcurrentCommandBuilder.createJob(command);
			jobQueue.add(job);
			
			job.start();
			if(!job.isBackground()) {
				job.waitUtilDone();
			}
		} catch (Throwable e) {
			System.out.println(e);
		}
	}
}
