#ifndef _IO_H
#define _IO_H 

#include "stdint.h" 

/* The I/O ports */
#define FB_COMMAND_PORT 0x3D4
#define FB_DATA_PORT 	0x3D5 


/* The I/O port commands */ 
#define FB_HIGH_BYTE_COMMAND 0x0E 
#define FB_LOW_BYTE_COMMAND  0x0F 

uint8_t inb(uint16_t port);
void outb(uint16_t port, uint8_t val);
uint8_t scan(void); 

void move_cursor(int row, int col);
void printprompt(void); 
#endif