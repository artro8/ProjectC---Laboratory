/*
 * program.h
 *
 *  Created on: Nov 8, 2017
 *      Author: student
 */

#ifndef PROGRAM_H_
#define PROGRAM_H_

struct Node {
	int id;
	char *datagram;
	struct Node *next;
	struct Node *prev;
};


void * LoadIpv4 ();	//function declaration to load IPv4 library
void * LoadTCP ();	//function declaration to load ICMP library

int SendPacket ( char *interface );	//function to send packet from linked list
int Menu ( int *count, char *interface );	//function to show start menu
void LoadToList ( int *count, char *dtgr );	//function to load data to list

struct Node *ReserveMem ( char *datagram );	//function to reserve memory for new list element
void InsertTail ( char *datagram );	//function to put new element at the end of the list
void PrintList ();	//function to print linked list
void DeleteList ();	//function to delete linked list
struct Node * ReturnHead (); //function to return head of the list

#endif /* PROGRAM_H_ */
