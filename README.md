# File System Design

**File system created in C++ that uses linked list and indexed allocation methods within a text file that acts as a disk drive.**

This project must be ran in C++ 20. A makefile is provided or you can run the following command in your terminal:
```
g++ file_systems.cpp file_systems.h -o file_systems -std=c++20
```

Here is a demo within the console:

<img src="demo.gif">

**Linked List Allocation Description:**

The starting block of the file is stored within the FAT (file allocation table), and a contains pointer towards the following block. Each block has it's own pointer towards another block, and the last block (end of the file) has a -1 indicating a null pointer.

<p align="center">
<img src="linkedlist.jpeg"></p>

```
 Image source/credits: https://www.geeksforgeeks.org/file-allocation-methods/
```
 
 
**Indexed Allocation Description:**

The starting block is still stored within the FAT, however it also stores all the pointers that the file contains. The file is read in order of the stored pointers.

 <p align="center">
 <img src="indexed.jpeg"></p>
 
 ```
 Image source/credits: https://www.geeksforgeeks.org/file-allocation-methods/
 ```
