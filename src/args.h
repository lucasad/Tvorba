#include <stdlib.h>
#include <argp.h>

const char *argp_program_version = "Tvorba " VERSION;
const char *argp_program_bug_address = "/dev/null";

/* Program documentation. */
static char doc[] = "Tvorba - A Peer-to-Peer open world game engine.";

/* A description of the arguments we accept. */
static char args_doc[] = "nodes to bootstrap to";

/* The options we understand. */
static struct argp_option options[] = {
    {"bind",       'b', 0, 0,   "Produce verbose output"   },
    {"bootstrap",  'j', 0, 0,  "Don't produce any output"  },
    {"debug",      'd', 0, 0,  "Enable debuging output"    },
    { 0 }
};

/* Used by main to communicate with parse_opt. */
struct arguments_t
{
    char *ip, *bind;
    bool bootstrap, debug;
};

/* Parse a single option. */
static error_t
parse_opt (int key, char *arg, struct argp_state *state)
{
    /* Get the input argument from argp_parse, which we
          know is a pointer to our arguments structure. */
    struct arguments_t *arguments = (arguments_t*) state->input;

    switch (key)
    {
    case 'b':
        arguments->bind = arg;
        break;

    case 'j':
        arguments->bootstrap = true;
        break;

    case 'd':
        arguments->debug = true;
        break;

    case ARGP_KEY_ARG:
        puts(arg);
        break;

    case ARGP_KEY_END:
        if (state->arg_num < 1) {

            if(!arguments->bootstrap)
                /* Not enough arguments. */
                argp_usage (state);

        }
        break;

    default:
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

/* Our argp parser. */
static struct argp argp = { options, parse_opt, args_doc, doc };
