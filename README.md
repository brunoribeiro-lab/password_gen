# Password Generator

This is a simple password generator written in C. It allows the user to specify parameters to customize the type and length of the generated password.

## Compilation

To compile the program, you can use `gcc`:

```bash
gcc init.c -o password_gen
```
# Installation

To make the program globally accessible, you can move it to /usr/local/bin:

```bash

sudo mv password_gen /usr/local/bin/
```

# Usage

To generate a password, simply run:
```bash
password_gen

```
By default, this will generate an 8-character password including digits, uppercase and lowercase letters, and special characters.
Parameters

    -d : Use digits in the password.
    -l : Use lowercase letters in the password.
    -u : Use uppercase letters in the password.
    -sp: Use special characters in the password.
    -s SIZE: Specify the password length. Default is 8.
    -h, -help: Display the help message.

For instance, to generate a 12-character password containing only digits and uppercase letters, you would use:

```bash

password_gen -d -u -s 12

```

# License

Distributed under the MIT license. See LICENSE for more details.
