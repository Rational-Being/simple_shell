This a team project done by Abdul-Lateef Yusuff and Jesse Okoro

In this project we will be joining hands to create a shell, a simple shell precisely

#### Description


This is a simple custom shell implemented in C. The shell provides basic command_line interface where users can execute commands and manage processes. it supports executing both built-in commands and external prorams found in the sysytem's PATH.

## To compile, use the follwoing

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

# Running

./hsh


## Testing

interactive mode:

$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$

But also in non-interactive mode:

$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$

## Usage

ls - list pwd
env: display the current shell
exit: exit the shell

## Error Handling

error messages are printed to stderr

## Contributing

contributions are welcome! Feel free to open isssuess or submit oull requests to improve this shell


# Day One

Creted the prompt
handle ctrl+d
print eroor
some memory management

# Day Two

Implemented the execution process by first creating child process
But execution can only handle path as an argument with no space
