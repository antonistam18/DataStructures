# Data Structures

# 📚 Data Structures Library – Data Structures Coursework 2025

**Authors:**  
Christos Papadopoulos /
Antonios Stamatis

## 🔍 Description

This project implements a modular C++ library that supports five fundamental data structures:

- Min Heap  
- Max Heap  
- AVL Tree  
- Undirected Weighted Graph  
- Hash Table

The program processes commands from a file (`commands.txt`) to perform operations on the structures dynamically, and logs outputs and execution times in `output.txt`.

## 🎯 Project Objectives

- Study and implement classical data structures
- Strengthen programming skills in C++
- Analyze and evaluate algorithmic complexity through execution time measurement

## ⚙️ Program Workflow

### 1️⃣ Input

- `commands.txt`: Includes instructions like `BUILD MINHEAP`, `INSERT AVL`, `SEARCH HASHTABLE`, etc.
- Input files (e.g., `a.txt`, `b.txt`) containing numeric data for the structures.
- The `main` function reads the file line by line, parses each command, and delegates execution to `CommandAction`.

### 2️⃣ Execution

Each data structure supports a tailored set of operations:

#### ✅ Min Heap / Max Heap

- `BUILD`: Constructs the heap by reading numbers from file
- `INSERT`: Adds an element while maintaining heap property
- `DELETE`: Removes min/max value and reheapifies
- `FINDMIN` / `FINDMAX`: Retrieves the root of the heap
- `GETSIZE`: Returns the heap size

#### ✅ AVL Tree

- `BUILD`: Builds a balanced binary search tree
- `INSERT` / `DELETE`: Adds or removes nodes while maintaining balance
- `SEARCH`: Checks if an element exists
- `FINDMIN`: Retrieves the minimum value
- `GETSIZE`: Returns the number of nodes  
- Automatic rebalancing using left/right rotations

#### ✅ Graph

- `BUILD`: Constructs a weighted, undirected graph using an adjacency matrix (up to 3000 nodes)
- `INSERT` / `DELETE`: Adds or removes edges
- `SHORTESTPATH`: Computes shortest path using Dijkstra’s algorithm
- `SPANNINGTREE`: Finds minimum spanning tree using Prim’s algorithm
- `CONNECTEDCOMPONENTS`: Counts connected components using DFS

#### ✅ Hash Table

- `BUILD`: Builds the hash table using linear probing
- `INSERT`: Adds an element using (key % 1000 + i) for collision resolution
- `SEARCH`: Searches for an element
- `GETSIZE`: Returns the number of inserted elements

### 3️⃣ Output

- Outputs are written to `output.txt`
- Execution time (in nanoseconds) is printed next to each result

## 📦 External Libraries

- `<string>`: For handling string operations
- `<fstream>`: For reading input files and writing output
- `<sstream>`: For string parsing using `stringstream`
- `<chrono>`: For measuring execution time of each command

## ⏱️ Timing & Benchmarking

Using `chrono::high_resolution_clock`, the duration of each operation is measured precisely:

```cpp
auto start = chrono::high_resolution_clock::now();
// execute command
auto end = chrono::high_resolution_clock::now();
auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
