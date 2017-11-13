/*
 ============================================================================
 Name        : SendApp.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <netinet/tcp.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned short checksum(unsigned short *buf, unsigned size)
{
	unsigned sum = 0;
	int i;

	/* Accumulate checksum */
	for (i = 0; i < size - 1; i += 2)
	{
		unsigned short word16 = *(unsigned short *) &buf[i];
		sum += word16;
	}

	/* Handle odd-sized case */
	if (size & 1)
	{
		unsigned short word16 = (unsigned char) buf[i];
		sum += word16;
	}

	/* Fold to get the ones-complement result */
	while (sum >> 16) sum = (sum & 0xFFFF)+(sum >> 16);

	/* Invert to get the negative in ones-complement arithmetic */
	return ~sum;
}

void createTCPPacket ( unsigned char *buf, unsigned size ) {

	unsigned short iphdrlen;

	struct iphdr *iph = (struct iphdr *)buf;
	iphdrlen = iph->ihl*4;

	struct tcphdr *tcph=(struct tcphdr*)(buf + iphdrlen);

	char input [32];

	iph->protocol = IPPROTO_TCP;	//change protocol to tcp
	memset( buf + sizeof ( struct iphdr ), 0, iph -> tot_len );	//clean data field to save icmp packet
	iph->tot_len = sizeof ( struct iphdr ) + 8;	//calculate total length
	//iph -> tot_len = 28;

	printf ("\nTCP source (0): ");
		fgets (input, 32, stdin);
			if (atoi(input)== 0)
				tcph->th_sport = 0;	//TCP source
			else
				tcph->th_sport = atoi (input);
	printf ("\nTCP destination port (0): ");
		fgets (input, 32, stdin);
			if (atoi(input)== 0)
				tcph->th_dport = 0;	//TCP destination
			else
				tcph->th_dport = atoi (input);
	printf ("\nTCP sequence number (0): ");
		fgets (input, 32, stdin);
			if (atoi(input)== 0)
				tcph->th_seq = 0;	//TCP sequence
			else
				tcph->th_seq = atoi (input);
	printf("\nTCP ACK (0);");
		fgets(input, 32, stdin);
			if (atoi(input)== 0)
				tcph->th_ack = 0;	//TCP ack
			else
				tcph->th_ack = atoi (input);
			printf("\nTCP x2 (0);");
					fgets(input, 32, stdin);
						if (atoi(input)== 0)
							tcph->th_x2 = 0;	//TCP x2
						else
							tcph->th_x2 = atoi (input);
				printf("\nTCP off (0);");
					fgets(input, 32, stdin);
						if (atoi(input)== 0)
							tcph->th_off = 0;	//TCP off
						else
							tcph->th_off = atoi (input);
			    printf("\nTCP win (0);");
					fgets(input, 32, stdin);
						if (atoi(input)== 0)
							tcph->th_win = 0;	//TCP win
						else
							tcph->th_win = atoi (input);
				printf("\nTCP urp (0);");
					fgets(input, 32, stdin);
						if (atoi(input)== 0)
							tcph->th_urp = 0;	//TCP urp
						else
							tcph->th_urp = atoi (input);

	//Dalej....

	printf ("\nTCP checksum will be calcuated... \n");
	tcph->th_sum = 0;
	tcph->th_sum = checksum( (unsigned short *) (buf + sizeof ( struct iphdr ) ), 4);	//TCP checksum


}

