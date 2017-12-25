#include <stdio.h>
#include <syscall.h>

int
main (int argc, char **argv)
{
  // int i;

  // for (i = 0; i < argc; i++)
  //   printf ("%s ", argv[i]);
  // printf ("\n");
  hello_world();
  io_need(1, 1, 0);

  io_request(2, 10);


  return EXIT_SUCCESS;
}
