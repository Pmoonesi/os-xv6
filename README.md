# os-xv6
This is the main project for the course Operating Systems - Fall 2021, Dr. Javadi

## xv6
XV6 is a simple unix-like teaching operating system which is publicly available for students to work around and learn how things work in an operating system in their very basic form. You can learn more about this operating system in [here](https://pdos.csail.mit.edu/6.828/2012/xv6.html).

## phase 3
In the third phase of this project, we had to implement round-robin, non-preemptive priority scheduling, multi-layered queue and dynamic multi-layered queue scheduling algorithms. So, most of the work is done in scheduling part of the xv6. All we had to do was to define scheduling modes and priority for each process and finally behave as requested in scheduling function. For preemptiveness we had to check for better priority processes on every clock tick. We provided system calls to change scheduling algorithms and to change a process's priority. We also wrote some test for each scheduling algorithm but unfortunately, its output is beyond anybody's understanding and is not reliable.

## how to run (with qemu)
```bash
git clone https://github.com/Pmoonesi/os-xv6
cd os-xv6
git checkout os-scheduling
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

## phase 1 & 2
You can find out about the first phase of this project in `master` branch of this repo ([link](os-xv6/tree/master/)). Also, you can find out about the scond phase of this project in `os-threads` branch of this repo ([link](os-xv6/tree/os-threads/)).