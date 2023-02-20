# os-xv6
This is the main project for the course Operating Systems - Fall 2021, Dr. Javadi

## xv6
XV6 is a simple unix-like teaching operating system which is publicly available for students to work around and learn how things work in an operating system in their very basic form. You can learn more about this operating system in [here](https://pdos.csail.mit.edu/6.828/2012/xv6.html).

## phase 2
In the second phase of this project, We first implemented threads for xv6, and then, used those threads to create a tasks and units system. We defined some tasks and provided the users with a system call to create tasks. Then, we defined units which find undone tasks and work on those tasks. Users can call units using a system call we provided for them. To test this mechanism, we created yet another test function called `unitTest` which you can run directly in xv6 environment.

## how to run (with qemu)
```bash
git clone https://github.com/Pmoonesi/os-xv6
cd os-xv6
git checkout os-threads
make
make qemu
```

If you had trouble in the `make qemu` step and faced:
```bash
Error: could not find a working QEMU executable.
```
Please follow [this](https://stackoverflow.com/questions/56507764/error-couldnt-find-a-working-qemu-executable) stack overflow question and you will understand how to resolve that problem.

If you wanted to play around xv6 and change some stuff, do not forget to run:
```bash
make clean
```
before running `make` and `make qemu` again.

## phase 1 & 3
You can find out about the first phase of this project in `master` branch of this repo ([link](os-xv6/tree/master/)). Also, you can find out about the third phase of this project in `os-scheduling` branch of this repo ([link](os-xv6/tree/os-scheduling/)).