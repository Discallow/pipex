<h1 align="center">
	Pipex project
</h1>
<p align="center">
	This project helped you? Give it a 🌟!
</p>

## 🕹️ Project overview
Bonus included.
A complete and straightforward implementation of Pipex 42 project.

Pipex is a Unix-based program that replicates the behavior of the shell pipe `|`. It takes two commands and allows the output of the first command to be used as the input to the second command. This project aims to deepen the understanding of process creation and inter-process communication (IPC) using pipes in a Unix environment.

## 🎛️ Features
- **Basic Functionality**: Execute two commands in sequence, where the output of the first command is passed as input to the second command using a pipe.
- **Error Handling**: Comprehensive error handling for invalid commands, file access issues, and other potential runtime errors.
- **Flexible Input/Output Redirection**: Supports redirection of input and output from/to files.
- **Path Management**: Enhanced path management to locate executable commands from the PATH environment variable.

## Usage
To run the program, execute the compiled binary with the following example:

```sh
make
./pipex file1 cmd1 cmd2 file2
```
`file1`: Input file
`cmd1`: First command to execute
`cmd2`: Second command to execute
`file2`: Output file

## Code example
```sh
./pipex file1 cat "wc -l" file2
```
![Game Screenshot]()

- With this example, we will first execute the command cat reading from file1;
- After that, we will redirect the output using pipes to the second command;
- We will execute the second command, and get the result of number of lines from the output of the first command;
- Output that result to file2.

## 🏅 Bonus Features
- Multiple Pipes: Extend the functionality to handle multiple pipes, enabling a chain of commands to be executed in sequence.
- Support `<<` and `>>` when the first parameter is "here_doc".

## Usage

To run this project with the above mentioned bonuses, execute the compiled binary with the following arguments:
```sh
./pipex file1 cmd1 cmd2 cmd3 cmd4 cmd5 file2
```
**Or, if you want to use here_doc:**
```sh
./pipex here_doc LIMITER cmd1 cmd2 file
```
**You can also mix these 2 bonuses**

- In the first bonus and even without the bonus, since `execve` function reads from `stdin` and writes to `stdout`, I'm going to use dup2 to duplicate the `stdin` and `stdout` to the files or respective pipes.

- In the second bonus, we need to:
- Read from stdin using here_doc with `<<` until a DELIMITER is found;
- After that, it will have the same behavior as explained previously with one exception: we will `append` the output of last command to the file.

## 🏷 Credits
This project is part of the 42 school curriculum. Special thanks to the 42 community for their support and resources.
Through this project, I gained a comprehensive understanding of Unix process creation, inter-process communication using pipes, file descriptor manipulation, command execution, error handling, and shell scripting concepts.

For more information about the project requirements, visit the 42 Project Page, since this subject could change.