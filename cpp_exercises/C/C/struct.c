#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int id;
	char name[255];
} hosts;

void print_hosts(int count, hosts *array);

int main(void) {
	int hosts_count = 2;
	hosts host[10]; 
	host[0].id = 0;
	host[1].id = 1;
	strcpy(host[0].name, "ns1.dtc.lv");
	strcpy(host[1].name, "mx2.dtc.lv");
	print_hosts(hosts_count, host);
	printf("host %d name: %s\n", host[2].id, host[2].name);
	return 0;
}

void print_hosts(int count, hosts *array) {
	int i;
	for(i = 0; i < count; i++) {
		printf("host %d name: %s\n", array[i].id, array[i].name);
	}
	array[2].id = 2;
	strcpy(array[2].name,"mail.dtc.lv");
}
