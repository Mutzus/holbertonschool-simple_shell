Simple Shell
This repository contains the source code for a simple Unix shell implementation, developed as part of the curriculum at Holberton School. The shell is capable of executing commands, both built-in and external, and supports interactive and non-interactive modes of operation.

Features
Supports executing commands with arguments.
Implements built-in shell commands such as cd and exit.
Handles PATH resolution to find executable binaries.
Parses command line arguments and handles input/output redirection.
Provides error handling and proper exit status reporting.
Usage
Clone the repository:
bash
Copy code
git clone https://github.com/Mutzus/holbertonschool-simple_shell.git
Compile the shell:
c
Copy code
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
Run the shell:
bash
Copy code
./hsh
Example
Interactive mode:

shell
Copy code
$ ./hsh
($) /bin/ls
README.md shell.c
($) exit
$
Non-interactive mode:

shell
Copy code
$ echo "/bin/ls" | ./hsh
README.md shell.c
Documentation
For more detailed information, refer to the man page (man ./man_1_simple_shell) and the AUTHORS file.
Issues
If you encounter any issues or have suggestions for improvement, please open an issue on the GitHub repository.
