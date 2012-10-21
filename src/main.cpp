#include <stdio.h>
#include <stdlib.h>

#include "commander.h"

int main(int argc, char** argv)
{
  command_t cmd;
  command_init(&cmd, argv[0], VERSION);
  command_option(&cmd, "-b", "--bootstrap", "Bootstrap network/Start server");
  command_parse(&cmd, argc, argv);
  return 1;
}
