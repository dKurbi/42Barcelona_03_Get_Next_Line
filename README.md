# 42Barcelona_03_Get_Next_Line
The get_next_line project aims to create a function that reads a text file or standard input line by line. This function is designed to be reusable, providing developers with a useful tool to process text data efficiently.

## Prototype 
> _char *get_next_line(int **fd**);_

**Parameters:** 
> **fd:** _The file descriptor to read from_
## Project Instructions

* Repeated calls to the get_next_line() function allow you to read the text file pointed to by the file descriptor, one line at a time.

* The function returns the line that was read. If there is nothing else to read or if an error occurred, it returns NULL.

* The returned line includes the terminating '\n' character, except when the end of the file was reached and it does not end with an '\n' character.

* To define the buffer size for read(), add the option -D BUFFER_SIZE=n to your compiler call, where n is the desired buffer size.

* The get_next_line() function should be considered to have undefined behavior if the file pointed to by the file descriptor changed since the last call, and read() didn't reach the end of the file.

### Forbidden Actions

* Using your libft library in this project is not allowed.

* The use of lseek() is forbidden.

* Global variables are not allowed.
