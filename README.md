# Simple_Shell 

Welcome to **Simple_Shell**, where the magic of UNIX meets simplicity! This project is your personal gateway to understanding how a basic shell operates. It's lightweight, it's powerful, and it's all yours to explore and expand!

##  What's This All About?

Simple_Shell is a miniature version of the UNIX command-line interface you're probably familiar with. Imagine having your own little bash shell, but it's stripped down to the essentials. Whether you're typing in commands manually or letting a script do the work, Simple_Shell has got you covered.

##  Key Features

- **Interactive Mode:** Just like talking to a friend—type commands one at a time and get instant feedback.
- **Non-Interactive Mode:** Got a list of commands in a file or piping them from another program? Simple_Shell can handle that too, no questions asked.
- **Built-In Commands:** We've included some handy built-ins like `exit`. The basics are here, but you're free to add more!
- **Error Handling:** Oops-proof your shell! We’ve added friendly error messages to help guide you when things go wrong.
- **Memory Management:** Manging the memory to make it more smoother.

##  How Does It Work?

Simple_Shell listens to what you type, breaks it down into bite-sized pieces (commands and arguments), and then gets to work executing them. It keeps going until you tell it to stop with an `exit` command.

###  File Breakdown

- **shell.c**: The brain of the operation. This file handles everything from starting the shell to reading your input.
- **tokenize.c**: The shell’s linguist. It takes your input and splits it into commands and arguments.
- **builtins.c**: Home to built-in commands like `exit`.
- **path.c**: The navigator. This file helps find the right path to your commands using the `PATH` environment variable.
- **memory.c**: The cleanup crew. Keeps memory leaks at bay.
- **main.c**: The entry point—where it all begins.

###  How to Get Started

1. **Clone the repository:**

    ```bash
    git clone https://github.com/Antonious-Awad/simple_shell.git
    ```

2. **Compile the program:**

    ```bash
    gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell
    ```

3. **Run your shell:**

    ```bash
    ./simple_shell
    ```

### Example of Simple_Shell in Action:

```bash
$ ./simple_shell
$ ls -l
$ /bin/echo "Hello, World!"
$ exit


## Contributors

- Tony Awad | [X](https://x.com/Antonious_A/) | [LinkedIn](https://www.linkedin.com/in/antoniousawad/)
- Abdullah El Sopky | [LinkedIn](www.linkedin.com/in/abdallah-elsopky)

## Resources

- [isatty](https://www.man7.org/linux/man-pages/man3/isatty.3.html)
- [get exit code from executed function](https://stackoverflow.com/questions/2667095/how-to-get-the-return-value-of-a-program-ran-via-calling-a-member-of-the-exec-fa)

🚀 Ready to Dive In?
Simple_Shell is your playground. Go ahead, experiment, break things, and then fix them—because that’s what coding is all about!

**Happy coding! May your terminal always be bug-free and your shell scripts ever powerful.**
