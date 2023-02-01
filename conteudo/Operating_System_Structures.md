# Operating-System Structures

# Operating-System Services

An operating system provides an environment for the execution of programs. It provides certain services to programs and to the users of those programs.

### Help the user

**User interface**: 

→ **Command-line interface (CLI)**, which uses text commands and a method for entering them. 

→ **Batch interface**, in which commands and directives to control those commands are entered into files, and those files are executed. 

→ **Graphical user interface (GUI)** is used. Here the interface is a window system with a pointing device to direct I/O, choose from menus, and make selections and a keyboard to enter text.

**Program execution**:

The system must be able to load a program into memory and to run that program. The program must be able to end its executions, either normally or abnormally (indicating error).

**I/O operations:**

A running program may require I/O, which may involve a file or an I/O device. For specific devices, special functions may be resired. For efficiency and protection, users usually cannot control I/O devices directly.

**File-system manipulation:**

Programs need to read and write files and directories. They also need to create and delete them by name, search for a given file, and list file information.

**Communications:**

Communication may occur between processes that are executing on the same computer or between processes that are executing on different computer system tied together by a computer network.

Communications may be implemented via shared memory, in which two or more processes read and write to a shared sections of memory, or message passing, in which packets of information in predefined formats are moved between processes by the operating system.

**Error detection:**

Errors may occur in the CPU and memory hardware, in I/O devices, and in the user program. For each type of error, the operating system should take the appropriate action to ensure correct and consistent computing,

### Ensure efficient operation of the system

**Resource allocation:**

When there are multiple users or multiple jobs running at the same time, resources must be allocated to each of them.

**Accounting:**

Keep track of which users use how much and what kinds of computer resources. Usage statistics may be a valuable tool for researchers who wish to reconfigure the system to improve computing services.

**Protection and security:**

When several separate processes execute concurrently, it should not be possible for one process to interfere with the others or with the operating system itself. Protection involves ensuring that all access to system resources is controlled.

# User and Operating-System Interface

Two fundamental approaches for users to interface with the operating system.

### Command Interpreters

The main function of the command interpreter is to get and execute the next user-specified command. Many of the commands given at this level manipulate files: create, delete, list, print, copy, execute, and so one.

In one approach, the command interpreter itself contains the code to execute the command. An alternative approach implements most commands through system programs.

## System Calls

Provide an interface to the services made available by an operating system. These calls are generally available as routines written in C and C++, althogh certain low-level tasks (for example, tasks where hardware must be accessed directly) may have to be written useing assembly-language instruction.

# Types of System Calls

→ Process control

→ File manipulation

→ Device manipulation

→ Information maintenance

→ Communications

→ Protection

# System Programs

System programs, also Known as system utilities, provide a convenient environment for program development and execution.

**File management**:

Create, delete, copy, rename, print, dump, list, and generally manipulate files and directories

**Status information**:

→ Provide the date, time, amount of available memory or disk space, number of users.

→ Provide detailed performance, logging, and debugging information.

**File modification**:

Text editors may be available to create and modify the content of files stored on disks or other storage devices.

**Programming-language support**:

Compilers, assemblers, debuggers, and interpreters for common programming languages (C, C++, Java, PERL).

**Program loading and execution**:

Provide absolute loaders, relocatable loaders, linkage editors, and overlay loaders. Debugging systems for either higher-level languages or machine language are needed as well.

**Communications**:

Provide the mechanism for creating virtual connections among processes, users, and computer system.

**Background services**:

All general-purpose systems have methods for launching certain system-program processes at boot time. Some of the processes terminate after completing their tasks, while other continue to run until the system is halted.

The view of the operating system seen by most users is defined by the application and system programs, rather than by the actual system calls.

# Operating-System Design and Implementation

### Design Goals

**User goals:**

Users want certain obvious properties in a system. The system should be convenient to use, easy to learn and to use, reliable, safe, and fast.

**System goals**

The system should be easy to design, implement, and maintain; and it should be flexible, reliable, error free, and efficient.

### Mechanisms and Policies

Mechanisms determine how to do something.

Policies determine what will be done.

This separation allows maximum flexibility if policy decisions are to be changed later.

# Operating-System Structure

**Simple Structure**

**Layered Approach**

**Micro-kernels**

**Modules**

**Hybrid System**

A system as large and complex as a modern operating system must
be engineered carefully. Modularity is important. Designing a system as a
sequence of layers or using a microkernel is considered a good technique. Many
operating systems now support dynamically loaded modules, which allow
adding functionality to an operating system while it is executing. Generally,
operating systems adopt a hybrid approach that combines several different
types of structures.

# System Boot

The procedure of starting a computer by loading the kernel is known as booting the system. On most computer, a small piece of code known as the bootstrap program or bootstrap loader locates the kernel, loads it into main memory, and starts its execution. Some computer systems, such as PCs, use a two-step process in which a simple bootstrap loader fetches a more complex boot program from disk, which in turn loads the kernel.

When a CPU receives a reset event—for instance, when it is powered up or rebooted—the instruction register is loaded with a predefined memory location, and execution starts there. At that location is the initial bootstrap program. This program is in the form of read-only memory (ROM), because the RAM is in an unknown state at system startup. ROM is convenient because it needs no initialization and cannot easily be infected by a computer virus.