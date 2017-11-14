/*
 ============================================================================
 Name        : SendApp.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "program.h"
#include <dlfcn.h>
#include <netinet/in.h>



int main (void) {


	void * Ipv4_lib = malloc(sizeof (void));
	void * TCP_lib = malloc(sizeof (void));

	int *count;
	char *interface;
	unsigned short *datagram;
	unsigned short * (*ipv4) () = malloc (sizeof (unsigned short *));
	void (*tcp) (unsigned char *) = malloc (sizeof(void));

	datagram = malloc (sizeof (4096));
	count = malloc (sizeof (int));
	interface = malloc (sizeof (char)*32);


	int a = Menu (count, interface);

	Ipv4_lib = LoadIpv4();

	ipv4 = dlsym(Ipv4_lib, "CreateIpv4Packet");
	datagram = (*ipv4)();


	if ( a == 2 ){

		TCP_lib = LoadIcmp();

		tcp = dlsym(TCP_lib, "CreateTCPPacket");
		(*tcp) ((unsigned char *) datagram);

	}


	LoadToList( count, (char*) datagram );
	PrintList ();

	SendPacket( interface );

	EXIT_SUCCESS;
}
