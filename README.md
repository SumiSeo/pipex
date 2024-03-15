# PIPEX
Reanimate unix shell command by reading and writing files
## Create Pipe line between two files
## <unistd.h> library in C exists only in Linux not with windows.

### Fork ? 
Fork creates new execution process(forking excution line)
* Fork returns integer number
* If returned number is 0, it means the process is "Child"
* Else(if is other numbers), it means the process is "Parent" or main.
* FYI, every single process in linux/window has process id 
* While using this information, we can prevent from creation for redundant process
* Each of the process has their own space for memory. Forking seems like using same function and variables, but no. It creates another execution line. 
* The return value from Fork decides many things in the process(main).

### Wait ?
Processing execution could be happened with unorganized way. It is decided by linux system. So need to call a function(Wait) to prevent process confusion. This function allows wait for the until the child process is finished. And then main function continues to execute.
* If wait function returns -1, there is no child process to wait. 
* wait returns a number of child process id that "Wait" for.


### Getpid, Getppid() 
* Identification number for processes
* Every process has id
* Getppid : Get parent process id
* Every process id has its parent id also

### Sleep
* if there is child process, call this slepp function for waiting until the child process finishded.

### Pipe
* Pipe is for communication among many processes
* If fork() can save each memory value, why pipe is worth for use it ? Because even after there was successful change between many process, it is possible to have extra data information between processes. In this case, pipe()allows to send data information after forking. So it is important to use both on the correct timing.
