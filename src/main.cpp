#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <argp.h>

#include <config.h>
#include "dht.h"
#include "args.h"

struct arguments_t settings;

int main(int argc, char** argv)
{
  char* bootstrap_host;
  int bootstrap_port;

  /* Default values. */
  settings.bootstrap = 0;
  settings.debug = 0;
  settings.bind = NULL;

  /* Parse our arguments; every option seen by parse_opt will
     be reflected in arguments. */
  argp_parse (&argp, argc, argv, 0, 0, &settings);

#ifdef DEBUG
  fprintf (stderr, "binding to = %s\n"
   "bootstrap = %s\n debug = %s\n",
   settings.bind,
   settings.bootstrap ? "yes" : "no",
   settings.debug ? "yes" : "no");
#endif

  DHT *network = new DHT(settings);


  return 1;
}
