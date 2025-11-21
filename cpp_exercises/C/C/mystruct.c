#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct service {
	int id;
	char name[50];
};

struct service server;

void func(struct service *server);

int main() {
	struct server *server_p;
	server_p = &server;
	server.id = 1;
	strcpy(server.name, "se7en.accenture.lv");
	func(server_p);
	printf("Server id: %d name: %s\n", server.id, server.name);
	exit(EXIT_SUCCESS);
}

void func(struct service *server) {
	printf("Server id: %d name: %s\n", server->id, server->name);
	strcpy(server->name, "ns2.rule.lv");
}
