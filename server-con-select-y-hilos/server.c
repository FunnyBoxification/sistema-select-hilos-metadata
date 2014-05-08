/*
 * server.c
 *
 *  Created on: 08/05/2014
 *      Author: utnso
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
#include <netdb.h>

#define PUERTO "8547"


int main(int argc, char** argv) {

	struct addrinfo hints, *serverInfo;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_flags = AI_PASSIVE;
	hints.ai_socktype = SOCK_STREAM;


	if( getaddrinfo(NULL, PUERTO,&hints, &serverInfo) != 0) {
		puts("Error en getaddrinfo");
	}

	int server_socket;
	if ((server_socket = socket(serverInfo->ai_family, serverInfo->ai_socktype, serverInfo->ai_protocol)) < 0) {
		puts("Error seteando socket de server");
		return -1;
	}

	if( bind(server_socket, serverInfo->ai_addr, serverInfo->ai_addrlen) < 0) {
		puts("Error bindeando socket");
		return -1;
	}
	freeaddrinfo(serverInfo);

	if( listen(server_socket, 5) < 0) {
		puts("Error en el listen");
		return -1;
	}

	char salir = 0;
	fd_set readSockSet;
	fd_set writeSockSet;

	FD_ZERO(readSockSet);
	FD_ZERO(writeSockSet);


	while (!salir) {

	}






}
