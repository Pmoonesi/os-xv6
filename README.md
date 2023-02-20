# os-xv6
This is the main project for the course Operating Systems - Fall 2021, Dr. Javadi

## xv6
XV6 is a simple unix-like teaching operating system which is publicly available for students to work around and learn how things work in an operating system in their very basic form. You can learn more about this operating system in [here](https://pdos.csail.mit.edu/6.828/2012/xv6.html).

## phase 1
In the first phase of the project, we had to learn how to run xv6 in qemu, which is a light emulator. After that, we started to see xv6's most important files to understand how simple things such as process initiation work. After we understood some basic functions of the operating system, we had to add some system calls and then, add test functions to be able to call those system calls. We have access to the test functions as xv6 commands (use ls to list the available commands).

## how to run (with qemu)
```bash
git clone https://github.com/Pmoonesi/os-xv6
cd os-xv6
git checkout master
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

## phase 2 & 3
You can find out about the second phase of this project in `os-threads` branch of this repo ([link](os-xv6/tree/os-threads/)). Also, you can find out about the third phase of this project in `os-scheduling` branch of this repo ([link](os-xv6/tree/os-scheduling/)).