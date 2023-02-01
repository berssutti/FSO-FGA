# Introduction

# What Operating Systems Do

A computer system can be divided into four components:

- **Hardware** → CPU, memory, I/O devices;
- **Operating System** → Controls the hardware and coordinates its use among the various application programs;
- **Application programs** → word processors, spreadsheets, compilers, web browser;
- **Users**.

**User view: ease of use, performance;**

**System view: resource allocator, control program**

The fundamental goal of computer systems is to execute user programs and to make solving user problems easier. The common functions of controlling and allocating resources are brought together into one piece of software: the operating system.

**“Everything a vendor ships when you order an operating system”**

**“The one program running at all times on the computer” é o kernel, além dele tem outro dois tipos de programas: system program ou application program.**

# Computer-System Organization

## Computer-System Operation

**A modern general-purpose computer system consists of one or more CPUs and a number of device controllers connected through a common bus that provides access to shared memory.** Each device controller is in charge of a specific type of device. The CPU and the device controllers can execute in parallel, competing for memory cycles. To ensure orderly access to the shared memory, a memory controller synchronizes access to the memory.

When a computer is powered up or rebooted - it needs to have an initial program to run that (bootstrap program). Typically, it is stored within the computer hardware in read-only memory (ROM) or electrically erasable programmable read-only memory (EEPROM), known by the general term **firmware**.

**The bootstrap program, initializes all aspects of the system, from CPU registers to device controllers to memory content. To accomplish this goal** **it must locate the operating-system kernel and load it into memory**.

**Some services are provided outside of the kernel**, by system programs that are loaded into memory at boot time to become system processes, or system daemons that run the entire time the kernel is running. Once this phase is complete, the system is fully booted.

The occurrence of an event is usually signaled by an interrupt from either the hardware or the software.

- Hardware → any time, by sending a signal to the CPU.
- Software → system call.

When interrupted, the CPU stops what it is doing and transfers execution to a fixed location. The fixed location contains the starting address where the service routine for the interrupt is located.  The interrupt architecture must also save the address of the interrupted instruction.

## Storage Structure

**The CPU can load instructions only from memory, so any programs to run must
be stored there.**

Ideally, **we want the programs and data to reside in main memory permanently**. This arrangement usually is not possible for the following two reasons:

1. Main memory is usually too small
2. Main memory is a volatile storage device that loses its contents when power is turned off or otherwise lost.

Secondary storage works as an extension of main memory, and has to be able to hold large quantities of data permanently.

Registers → Cache → Main memory → Solid-state disk → Magnetic disk → Optical disk → Magnetic tapes.

## I/O Structure

**A device controller maintains some local buffer storage and a set of special-purpose registers. The device controller is responsible for moving the data between the peripheral devices that it controls and its local buffer storage.**

To start a I/O operation, the device driver loads the appropriate registers within the device controller. The device controller, in turn, examines the contents of these registers to determine what action to take. The controller starts the transfer of data from the device to its local buffer. Once the transfer of data is complete, the device controller informs the device driver via an interrupt that it has finished its operation. The device driver then returns control to the operating system, possibly returning the data or a pointer to the data if the operation was a read. For other operations, the device driver returns status information. → produce high overhead when used for bulk data movement

After setting up buffers, pointers, and counters for the I/O device, the device controller transfers an entire block of data directly to or from its own buffer storage to memory, with no intervention by the CPU. → Direct Memory Access (DMA)

# Computer-System Architecture

## Single-Processor Systems

**On a single-processor system, there is one main CPU capable of executing a general-purpose instruction set, including instructions from user processes.** 

Almost all single-processor system have other specio-purpose processors, they may come in the form of device-specif processors, such as disk, keyboard, and graphics controllers.

If there is only one general-purpose CPU, then the system is a single-processor system.

## Multiprocessor Systems

Multiprocessor systems (AKA parallel systems or multi-core systems) **have two or more processors in close communication, sharing the computer bus and sometimes the clock, memory, and peripheral devices.**

3 mains advantages:

1. **Increase throughput** → more work done in less time
2. **Economy of scale** → cost less then equivalent multiple single-processor systems, because they can share peripherals, mass storage ad power supplies.
3. **Increased reliability** → if functions can be distributed properly among several processors, then the failure of one processor will not halt the system, only slow it down.

Two types of multi-processor system in use today:

- **Asymmetric multiprocessing** → Each processor is assigned a specific task
- **Symmetric multiprocessing** → Each processor performs all tasks within the operating system.

Clustered systems differ from the multiprocessor systems described above in that they are composed of two or more individuals systems - or nodes - joined together. Each node may be a single processor system or a multi-core system.

- **Asymmetric clustering** → one machine is in hor-standby mode while the other is running the applications.
- **Symmetric clustering** → two or more hosts are running  applications and are monitoring each other.

# Operating-System Structure

As operating system provides the environment within which programs are executed

Multi-programming is one of the most important aspects of operating systems, it increases CPU utilization by organizing jobs (code and data) so that the CPU always has one to execute.

In time sharing (or multitasking) systems, the CPU executes multiple jobs by switching among them, but the switches accur so frequently that the users can interact with each program while it is running.

Time sharing requires an interactive computer system, which provides direct communication between the user and the system. The user gives instructions to the operating system or to a program directly, using a input instructions to the operating system or to a program directly, using a device such as a keyboard, mouse, touch pad…

→ A time-shared operating system allows many users to share the computer simultaneously.

→ A time-shared operating system uses CPU scheduling and multi-programing to provide each user with a small portion of a time-shared computer.

→ Time sharing and multi-programming require that several jobs be kept simultaneously in memory.

→ In time-sharing system, the operating system must ensure reasonable response time.

→ A time-sharing system must also provide a file system.

# Operating-System Operations

## Dual-Mode and Multi-mode Operation

The dual mode provides us with the mean for protecting the operating system from errant users - and errant users from one another. We accomplish this protection by designing some of the machine instructions that may cause harm as privileged instructions.

The hardware allows privileged instructions to be executed only in kernel mode. If an attempt is made to execute a privileged instruction in user mode, the hardware does not execute the instruction but rather treats it as illegal and traps it to the operating system.

## Timer

A timer can be set to interrupt the computer after a specific period. The period may be fixed or variable.

A variable timer is generally implemented by a fixed-rate clock and a counter. The operating system sets the counter. Every time the clock ticks, the counter is decremented. When the counter reaches 0, an interrupt occurs. 

# Process Management

A program in execution is a process. A time-shared user program such as a compiler is a process.

For now, a process is a job or a time-shared program.

A process needs certain resources - including CPU time, memory, files, and I/O devices - to accomplish its task. These resources are either given to the process when it is created or allocated to it while it is running.

A process is the unit of work in a system. A system consists of a collection of process, some of which are operating-system process and rest of which are user process.

The operating system is responsible for the following activities in connection with process management:

- Scheduling process and threads on the CPUs
- Creating and deleting both user and system process
- Suspending and resuming process
- Providing mechanisms for process synchronization
- Providing mechanisms for process communication

# Memory Management

A memory is a large array of bytes, ranging in size from hundreds of thousands to billions.

The operating system is responsible for the following actividies in connection with memory management:

- Keeping track of which parts of memory are currently being used and who is using them
- Deciding which process (or parts of processes) and data to move into and out of memory
- Allocating and deallocating memory space as needed

# Storage Management

## File-System Management

A file es a collection of related information defined by its creator.

The operating system is responsible for the following activities in connection with file management:

- Creating and deleting files;
- Creating and deleting directories to organize files;
- Supporting primitives for manipulating files and directorie;
- Mapping files onto secondary storage Backing up files on stable (nonvolatile) storage media.

## Mass-Storage Management

The operating system is responsible for the following activities in connection with disk management:

- Free-space management
- Storage allocation
- Disk scheduling

## Chaching

Information is normally kept in some storage system. As it is used, it is copied into a faster storage system - the cache - on a temporary basis. When we need a particular piece of information, we first
check whether it is in the cache. If it is, we use the information directly from the cache. If it is not, we use the information from the source, putting a copy in the cache under the assumption that we will need it again soon.

## I/O Systems

The I/O subsystem consists of several components:

- A memory-management component that includes buffering, caching, and spooling
- A general device-driver interface
- Driver for specific hardware devices

Only the device driver knows the peculiarities of the specific device to which it is assigned

# Protection and Security

**Protection is any mechanism for controlling the access of processes or users to the resources defined by a computer system.** This mechanism must provide means to specify the controls to be imposed and to enforce the controls

**It is the job of security to defend a system from external and internal attacks.**

Protection and security require the system to be able to distinguish among all its users. Most operating systems maintain a list of user names and associated user identifiers (user IDs). In Windows parlance, this is a security ID (SID). These numerical IDs are unique, one per user. When a user logs in to the system, the authentication stage determines the appropriate user ID for the user. That user ID is associated with all of the user’s processes and threads. When an ID needs to be readable by a user, it is translated back to the user name via the user name list.

# Kernel Data Structures

## Lists, Stacks, and Queues

A **list** represents a collection of data values as a sequence.

- Singly linked list, each item points to its successor;
- Doubly linked list, a given item can refer either to its predecessor or to its successor;
- Circularly linked list, the last element in the list refers to the first element, rather than to null.

A **stack** is a sequentially ordered data structure that uses the last in, first out (LIFO) principle for adding and removing items, meaning that the last item proced onto the stack is the first item removed.

A **queue** is a sequentially ordered data structure that uses the first in, first out (FIFO) principle.

## Trees

A tree is a data structure that can be used to represent data hierarchically. Data values in a tree structure are linked through parent–child relationships. In a general tree, a parent may have an unlimited number of children. A binary search tree additionally requires an ordering between the parent’s two children in which lef t child <= right child.

## Hash Functions and Maps

A hash function takes data as its input, performs a numeric operation on this data, and returns a numeric value. This numeric value can then be used as an index into a table to quickly retriece the data.

One use of a hash function is to implement a hash map, which associates (or maps) [key:value] pairs using a hash function.

## Bitmaps

A bitmap is a string of n binary digits that can be used to represent the status of n items.