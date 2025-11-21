#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <netdb.h>

float get_ping_output(char *line);

int main(void)
   {
	struct hostent *ip;
	char name[] = "portal.accenture.lv";
	ip = gethostbyname(name);
   FILE *fp;
   char line[300];			/* line of data from unix command*/
	char *grep = " | grep \/"; 
   char command[100] = "ping -c 3 -q -t 5 "; 
	char *command_p = command;
	strncat(command_p, ip->h_addr, sizeof(ip->h_addr));
	strncat(command_p, grep, 11); 
	printf("Command is %s\n", command);
   fp = popen("ping -c 3 -q -t 5 portal.accenture.lv | grep \/", "r");		/* Issue the command.		*/
	if (!fp) {
		printf("command failed\n");
		return 0;
	}
					/* Read a line			*/
	bzero(line, 300);
   while ( fgets( line, sizeof line, fp))
      {
      /* printf("%s", line); */
      }
   pclose(fp);
	get_ping_output(line);
	return 0;
}

float get_ping_output(char *line) {
	printf("%s", line);
	int i = 0; /* pointer offset */
	int j = 0; /* helps to get right data */
	char result[6];
	bzero(result, 6);
	while(line[i] != '=') {
		i++;
		if (i > 50) return 0;
	}
	while(line[i] != '/') {
		i++; if (i > 50) return 0;
	}
	i++;
	while(line[i] != '/') {
		if (i > 50) return 0;
		result[j] = line[i];
		i++;
		j++;
	}
	/* result[j] = '\0'; */
	printf("result: [%s], i: %d, j: %d\n", result, i, j);
	return 0;
}
