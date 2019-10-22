#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char **argv)
{
  if(argc != 2) {
    printf(2, "error: sleep can only have one parameter.\n");
  } else {
    int num = atoi(argv[1]) * 100;

    if(num > 0) {
        printf(2, "Sleep starting.\n");
        sleep(num);
        printf(2, "Finished sleeping.\n");
    } else {
        printf(2, "Only positive numbers for sleep.\n");
    }
  }
  exit();
}
