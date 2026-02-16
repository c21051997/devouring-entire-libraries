


Name	Data Type	Path Search?	Environment?	Use Case
execl	List	    No	            No	            Quick scripts where you know the args.
execv	Vector	    No	            No	            Standard for most systems programming.
execvp	Vector	    Yes	            No	            Writing a Shell (like your project!).
execve	Vector	    No	            Yes	            The actual System Call the Kernel uses.