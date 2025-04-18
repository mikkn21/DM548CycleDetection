# DM548 Assignment 2: Cycle Detection in C

This repository contains an implementation of Kahn’s algorithm for cycle detection in directed graphs, developed as part of the [DM548: Computer architecture and system programming](https://odin.sdu.dk/sitecore/index.php?a=searchfagbesk&internkode=dm548&lang=en) course.

## Assignment Summary

The goal of this assignment is to:

1. **Parse** directed graphs given in an adjacency matrix format.
2. **Store** the graph internally using an adjacency list representation, with both in‑edges and out‑edges maintained for each vertex.
3. **Detect cycles** using **Kahn’s algorithm**, which either produces a topologically sorted order of vertices (if the graph is acyclic) or reports that a cycle exists.

**For full details on the requirements, please see the official assignment description:**

➡️ **[Project description](./assets/desc.pdf)** ⬅️

>[!Note]
> This repository was originally created for submission to a Git server hosted by IMADA (Department of Mathematics and Computer Science, SDU). A CI pipeline was set up using Drone CI to automatically test the solution upon each commit (see [.drone.yml](./.drone.yml). Some commits were made specifically to trigger these automated tests.


## Repository Structure

```
├── assets/
│   └── desc.pdf       # Full assignment specification
├── src/
│   ├── graph.h        # Data structures and function signatures
│   ├── graph.c        # Graph parsing and manipulation
│   ├── detectCycles.c # Main driver implementing Kahn’s algorithm
│   └── Makefile       # Build rules for compiling `detectCycles`
└── README.md          # This file
```

## Building the Project

Navigate to the `src` directory and run:

```bash
cd src
make
```

This will produce the executable:

```bash
./detectCycles
```

## Usage

Run the program with a single argument pointing to a graph file in adjacency matrix format:

```bash
./detectCycles path/to/graphmatrix-1.txt
```

- **If** the graph is a DAG, the program outputs a comma‑separated topological order of vertices, e.g.:
  ```
  4, 0, 1, 3, 2
  ```
- **If** the graph contains a cycle, the program outputs:
  ```
  CYCLE DETECTED!
  ```

All outputs end with a newline character. The program exits with status code `0` in both cases; any other failure (e.g., file not found or memory error) results in a non‑zero exit code.
