# Monty Program

The Monty program is a command-line interpreter for the Monty language. It allows you to execute Monty code files, which consist of a series of instructions, and observe the behavior of a stack-queue-based virtual machine.

## Usage

To use the Monty program, you need to have a Monty code file that contains the instructions you want to execute. You can run the Monty program by executing the following command:

```
./monty <file>
```

Replace `<file>` with the path to your Monty code file.

## Monty Language

The Monty language is a simple, stack-based programming language that operates on a stack/queue data structure. It provides a set of instructions that allow you to manipulate the stack and perform various operations.

The Monty program reads the instructions from your Monty code file and executes them one by one. It maintains a stack data structure in memory and performs operations such as pushing elements onto the stack, popping elements from the stack, performing arithmetic operations, and more.

## Monty Code File

A Monty code file is a plain text file that contains Monty instructions. Each instruction is written on a separate line. Comments can also be included in the file using the `#` symbol.

Here's an example of a Monty code file:

```
push 1
push 2
add
pall
```

In this example, the code file pushes the values 1 and 2 onto the stack, performs an addition operation, and then prints the contents of the stack using the `pall` instruction.

## Features

The Monty program provides several built-in instructions that you can use in your Monty code files. Some of the key features include:

- **Stack Manipulation**: You can push elements onto the stack, pop elements from the stack, swap the positions of elements, and more.
- **Arithmetic Operations**: The program supports basic arithmetic operations such as addition, subtraction, multiplication, and division.
- **Control Flow**: You can use control flow instructions such as conditional jumps (`jmp`, `jz`, `jnz`) to change the program's execution flow based on certain conditions.
- **Input/Output**: The program allows you to print the contents of the stack (`pall`, `pint`), print characters (`pchar`), and print strings (`pstr`).

## Error Handling

The Monty program performs various error checks to ensure the correct usage of instructions and the integrity of the stack. If an error is encountered during the execution of instructions, the program will display an error message with relevant information.

## Example

Here's an example of a Monty code file and its expected output:

**Monty code file (`example.m`):**
```
push 1
push 2
add
pall
```

**Command:**
```
./monty example.m
```

**Output:**
```
3
```
