#include <stdio.h>
#include <stdlib.h>

#include <chimera.h>

#include <config.h>
#include "commander.h"

static void bind_ip(command_t *self)
{
  fprintf(stderr, "Binding to ip %s", "");
};

static void bootstrap_chimera(command_t *self)
{
  fputs("Starting new network", stderr);
};

int main(int argc, char** argv)
{
  char* bootstrap_host;
  int bootstrap_port;

  command_t cmd;
  command_init(&cmd, argv[0], VERSION);
  command_option(&cmd, "-j", "--bootstrap", "Bootstrap network/Start server", bootstrap_chimera);
  command_option(&cmd, "-b", "--bind <ip>", "Binds to specified ip (implies --bootstrap)", bind_ip);
  command_parse(&cmd, argc, argv);
  for (int i = 0; i < cmd.argc; ++i) {
    sscanf(argv[i], "%s:%d", bootstrap_host, &bootstrap_port);
    fprintf(stderr, "Adding bootstrap node with hostname: %s, port %d", bootstrap_host, bootstrap_port);
  }
  return 1;
}
