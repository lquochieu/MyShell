package MyShell;

public class CurrentDir {
	private String CurrentDir;
	
	public CurrentDir() {
		CurrentDir = System.getProperty("user.dir");
	}
	
	public String getDir() {
		return CurrentDir;
	}
	
	public void setDir(String destination, boolean append) {
		if(append) {
			CurrentDir = CurrentDir + destination;
		}
		else {
			CurrentDir = destination;
		}
	}
}
