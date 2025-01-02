#  Minishell
~~A hell project from 42~~

## 🌟 Features

- Interactive shell with basic prompt functionality
- Execution of binary commands (e.g., `/bin/ls`)
- Built-in commands:
  - `cd`: Change the current working directory
  - `echo`: Display a line of text
  - `env`: Show environment variables
  - `exit`: Exit the shell
  - `export`: Set environment variables
  - `pwd`: Print the current directory
  - `unset`: Remove environment variables
- Input and output redirection (`<`, `>`, `>>`)
- Support for pipes (`|`) to chain commands
- Signal handling for `Ctrl+C`, `Ctrl+D`, and `Ctrl+Z`
- Environment variable expansion (e.g., `$PATH`, `$HOME`)
- Error handling for invalid commands or syntax

## 📂 Project Structure

```plaintext
/minishell
├───inc
|   ├───ft_printf.h
|   ├───get_next_line.h
|   ├───libft.h
|   └───minishell.h
├───libft
|   └───...//soon will publish libft libraries
├───shell
|   ├───builtins
|   |   ├───cd.c
|   |   ├───echo.c
|   |   ├───env.c
|   |   ├───exit.c
|   |   ├───export.c
|   |   ├───pwd.c
|   |   └───unset.c
|   ├───env
|   |   ├───env.c
|   |   ├───get.c
|   |   ├───shlvl.c
|   |   └───sort.c
|   ├───exec
|   |   ├───bin.c
|   |   ├───builtin.c
|   |   └───cmd.c
|   ├───parse
|   |   ├───expansion.c
|   |   ├───line.c
|   |   ├───token.c
|   |   └───token_data.c
|   └───utils
|       ├───expansion.c
|       ├───fd.c
|       ├───free.c
|       ├───gnl.c
|       ├───minishell.c
|       ├───parse.c
|       ├───token.c
|       ├───type.c
|       └───utils.c
├───src
|   ├───main.c
|   ├───rd_cmd.c
|   └───signalling.c
├───Makefile
└───README.md
```

## 🎓 Learning Objectives

- Understanding process creation and management (fork, execve, wait, pipe)
- Mastering file I/O and redirections
- Implementing a custom shell environment
- Handling user input and signal interruptions

## 🤝 Collaborator

[@nizarsyahmi37](https://github.com/nizarsyahmi37) - Main contributor, bash interface designer
[@ninetendo59](https://github.com/ninetendo59) - Create minishell "skeletal" structure, norminette checking, debugging completed code (fixing leaks, uninitialised value, refactor and restructure code), sanity testing.

## What is the difference between Shell and Terminal?

### Terminal
- A window or interface that provides a space to execute commands via a shell.
- Acts as a container for the shell to run.

### Shell
- It is a command interpreter or environment where you execute commands.
- Offers scripting, command history, and access to system features.

## Choice of function for taking input

<table>
  <tr>
    <th>Function</th>
    <th>Pros</th>
    <th>Cons</th>
  </tr>
  <tr>
    <td>
      <code>get_next_line(int fd)</code>
    </td>
    <td><ul>
      <li>zero leaks (if you implement it correctly)</li>
      <li>mutex based</li>
      <li>recycle and minor code modification</li>
      <li>efficient, which designed to be directly take input from fd.</li>
      <li>customisible in terms on BUFFER_SIZE control</li>
    </ul></td>
    <td><ul>
      <li>Unable to use history and require to implement history by your own</li>
      <li>low level control, which may require extra and tedious implementation.</li>
    </ul></td>
  </tr>
  <tr>
    <td><code>readline (const char *prompt)</code></td>
    <td><ul>
      <li>Easy usage.</li>
      <li>high level control, which is user friendly, offers line by line input reading.</li>
      <li>Thread safe, as it handles input buffer internally.</li>
    </ul></td>
    <td><ul>
      <li>Causes leaks (Minishell project does not requires you to handle the leaks, but other leaks that is not caused by this function is not tolerated)</li>
      <li>performance wise may not be optimised for low level or socker i/o.</li>
    </ul></td>
  </tr>
</table>

- In my opinion, using `readline()` is the easiest way to complete your minishell compared to `get_next_line()`.
- If you are perfectionist, why not just go ahead to use `get_next_line()`?

## Leak Check command
`valgrind --leak-check=full ./minishell`

## Further references
<ol>
  <li>https://m4nnb3ll.medium.com/minishell-building-a-mini-bash-a-42-project-b55a10598218</li>
  <li>https://www.youtube.com/watch?v=yTR00r8vBH8</li>
  <li>https://medium.com/@muxanz/how-the-shell-works-internally-when-entering-a-command-42f08458870</li>
  <li>https://medium.com/@nyangaresibrian/simple-shell-b7014425601f</li>
  <li>https://42-cursus.gitbook.io/guide/rank-03/minishell</li>
</ol>
