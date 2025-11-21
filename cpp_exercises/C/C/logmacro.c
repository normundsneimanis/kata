#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <unistd.h>

int proc_argv(int argc, char **argv);

#define LOG(prio, flist...)    \
    do {    \
    if (debug > 1) {    \
		fprintf(logfile, "%s\n", ##flist); \
    } \
	} while (0)

/* syslog(prio, ##flist);  \ */

FILE *logfile;

int
main(int argc, char ** argv) {
	int debug;
	proc_argv(argc, argv);
	logfile = fopen("log/client.log", "a");
	if (!logfile) {
		printf("Unable to open logfile. Exiting\n");
		return -1;
	}
	debug = 2;
	LOG(2, "Started");
	fclose(logfile);
	return 0;
}

int
proc_argv(int argc, char **argv)
{
    int c;

    while ((c = getopt(argc, argv, "vdsn:p:")) != EOF) {
        switch(c) {
        case 'v':
			printf("setting verbose\n");
            break;
        case 's':
            break;
        case 'n':
			printf("Setting n to %s\n", optarg);
            break;
        case 'p':
			printf("Setting p to %s\n", optarg);
            break;
        default:
            break;
        }
    }
    return 0;
}
