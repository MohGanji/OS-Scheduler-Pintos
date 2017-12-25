#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"

static void syscall_handler (struct intr_frame *);

#define MAX_ARGS 3

void get_arg (struct intr_frame *f, int *arg, int n);

void hello_logic(void);
void io_need_wrap(int dev1, int dev2, int dev3);
void io_request_wrap(int dev, int time);


void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f UNUSED) 
{
  int args[MAX_ARGS];
  switch (* (int *) f->esp)
  {
    case SYS_EXIT:
    {
  		printf("EXIT\n");
      thread_exit ();
  		break;
    }
    case SYS_HELLOWORLD:
    {
    	hello_logic();
    	break;
    }
    case SYS_IONEED:
    {
      get_arg(f, args, 3);
      io_need_wrap(args[0], args[1], args[2]);
      break;
    }
    case SYS_IOREQUEST:
    {
      get_arg(f, args, 2);
      io_request_wrap(args[0], args[1]);
      break;
    }
    default:
    {
		  printf("UNKNOWN: %d\n", (* (int *) f->esp));
    	break;
    }
  }
}


void hello_logic(void){
	printf("This is hello world sys call example :|\n");
	return;
}


void io_need_wrap(int dev1, int dev2, int dev3){
  printf("needed devices: %d %d %d\n", dev1, dev2, dev3);
  thread_add_devices(dev1, dev2, dev3);
  return;
}

void io_request_wrap(int dev, int time){
  
  printf("requested device %d for %d miliseconds\n", dev, time);
}

void get_arg (struct intr_frame *f, int *arg, int n)
{
  int i;
  int *ptr;
  for (i = 0; i < n; i++)
    {
      ptr = (int *) f->esp + i + 1;
      arg[i] = *ptr;
    }
}
