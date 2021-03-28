package MyShell;

import java.util.LinkedList;
import java.util.List;

import javax.management.RuntimeErrorException;

public class ConcurrentCommandBuilder {
	private static final String[] NO_OUTPUT = {"cd"};
	private String rawCommands;
	private static LinkedList<String[]> commandStrings = new LinkedList<String[]>();
	private static boolean validCommands;
	
	public static Job createJob(String rawCommands) {
		Job job = new Job(rawCommands);
		rawCommands = rawCommands.replace(">", "|>");
        String[] pipeArrays = rawCommands.split("\\|");
        for(int i = 0; i < pipeArrays.length; ++i) {
        	pipeArrays[i] = pipeArrays[i].replaceAll("\\s+", " ");
        	pipeArrays[i] = pipeArrays[i].trim(); 
        }
        
        for(int i = 0; i < pipeArrays.length; ++i) {
        	String[] spaceArrays = pipeArrays[i].split(" ");
        	commandStrings.add(spaceArrays);
        	validCommands = Validate(spaceArrays);
        	if(!validCommands) {
        		break;
        	}
        }
        ConcurrentFilter prev = null;
		LinkedList<Thread> filters = new LinkedList<Thread>();
        if(validCommands) {
        	if(validatePipeOrders()) { 
        		for(int i = 0; i < commandStrings.size(); ++i) {
        			ConcurrentFilter filter = constructFilterFor(commandStrings.get(i));
        			if(prev != null) {
        				filter.setPrevFilter(prev);
        			}
        			filters.add(new Thread(filter));
        			prev = filter;
        		    }
        		}
        }
        job.setChain(filters);
		return job;
       
	}
	 private static ConcurrentFilter constructFilterFor(String[] spaceArray) {
		String j = spaceArray[0];
		if(j.equalsIgnoreCase("pwd")) {
			return new Pwd(spaceArray.toString());
		}
		else {
			throw new RuntimeException(Messenger.COMMAND_NOT_FOUND.with_parameter(spaceArray.toString()));
		}
	}
	public static boolean validatePipeOrders() {
	    	String temp = null;
	    	boolean validOrders = true;
	    	for(int i = 0; i < commandStrings.size(); ++i) {
	    		temp = commandStrings.get(i)[0];
	    		if(temp.equals("exit")) {
	    			System.out.println("invalid pipe order");
	    			validOrders = false;
	    			break;
	    			}
	    	}
	    	return validOrders;
	    }
	    
	    public static boolean validateGroup(String[] temp) {
	    	if(temp.length > 1) {
	    		System.out.println(temp[0] + ": invalid error");
	    	}
	    	
	    	return true;
	    }
	    
	    public static boolean Validate(String[] temp) {
	    	boolean isvalid = true;
	    	if(temp[0].equalsIgnoreCase("pwd")) {
	    		isvalid = validateGroup(temp);
	    	}
	    	
	    	return isvalid;
	    }
	    
	    
}
