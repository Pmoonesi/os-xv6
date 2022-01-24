#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

extern int readCount;

int
sys_fork(void)
{
  int pid = fork();
  return pid;
}

int
sys_threadcreate(void)
{
  void* s;

  if(argptr(0, (void*)&s, sizeof(*s)) < 0)
    return -1;

  return threadcreate(s);
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_threadwait(void)
{
  return threadwait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_getProcCount(void)
{
  return getProcCount();
}

int
sys_getReadCount(void)
{
  return readCount;
}

int
sys_setPolicy(void)
{
  int mode;
  if(argint(0, &mode) < 0)
    return -1;
  setPolicy(mode);
  return 0;
}

int
sys_getInformation(void)
{
  int mode;
  if(argint(0, &mode) < 0)
    return -1;
  return getInformation(mode);
}
