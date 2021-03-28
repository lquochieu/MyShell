package MyShell;

public enum Messenger {
	WELCOME("Welcome to the MyShell command line!"),
	NEW_COMMAND("> "),
	GOODBYE("Thank you for using the MyShell command line. Goodbye!"),
	COMMAND_NOT_FOUND("The command [%s] was not recognized.\n"),
	CANNOT_HAVE_PARAMETER("The command [%s] cannot have parameters.\n"),
	CANNOT_HAVE_OUTPUT("The command [%s] cannot have an output.\n"),
	CANNOT_HAVE_INPUT("The command [%s] cannot have an input.\n");
	private final String messenger;
	private Messenger(String messenger) {
		this.messenger = messenger;
	}
	public String getMessenger() {
		return messenger;
	}
	
	public String with_parameter(String parameter) {
		if(this == WELCOME || this == NEW_COMMAND || this == GOODBYE ) {
			return getMessenger();		
			}
		else {
			return String.format(this.messenger, parameter.trim());
		}
	}
	
}
