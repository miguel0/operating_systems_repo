#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char **argv)
{
  if(argc != 2){
    printf(2, "usage: wrong number of arguments.\n");
    exit();
  }

  sleep(atoi(argv[1]));
  exit();
}
