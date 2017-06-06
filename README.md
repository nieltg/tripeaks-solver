# tripeaks-solver

A tool for analyzing and solving Tri-Peaks game using branch-and-bound algorithm.

## Getting Started

### Prerequisites

Ensure that you have installed all the required build tools. This project has been developed with these tools. Lower version may work, but not guaranteed.

- GNU Make 4.1
- clang 3.8

### Compilation

Type this command on the root of project directory. Program will be compiled to `bin/main`.

```
$ make
```

## Running

To test the program, type this command after compilation process.

```
$ bin/main < case/real-2.txt
```

## Development

### Structure

These are some information about internal structure that may help you to understand this project.

- General branch-and-bound algorithm is located on `algorithm/branch_bound.h`.

- Playing card is modeled on `model/Card.h`.

- Tri-Peaks board is modeled on `model/Board.h`.

- Game state which also works as graph node for branch-and-bound algorithm is modeled on `model/State.h`.

- Main program reads board state from standard input, creates initial state, passes it to branch-and-bound algorithm and outputs the result.

### Bugs

Well, this is not perfect yet. There are bugs and some works to do. Pull requests are greatly appreciated. :laughing:

- Some Tri-Peaks board make this program run endlessly.

  Well, I've been waiting about 10 minutes and stopped the program. Memory usage is not increasing and I noticed some duplicate states while debugging.

- Solver produces extraneous steps even though the game has been won in several steps before.

- The command line interface is still ugly.
