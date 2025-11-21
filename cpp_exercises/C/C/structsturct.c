#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int mail;
	int ping;
} services;

typedef struct {
	int id;
	char name[64];
	services services;
} host;

void setping(host *host);

int
main(void) {
	host hosts;
	hosts.services.ping = 0;
	hosts.services.mail = 1;
	setping(&hosts);
	if (hosts.services.ping) printf("%d\n", hosts.services.ping); 
	return 0;
}

void
setping(host *hosts) {
	hosts->services.ping = 1;
}
