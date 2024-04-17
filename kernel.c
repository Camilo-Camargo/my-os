#include "kernel/tty.h" 
#include "kernel/io.h"
#include "kernel/kbd.h"
#include "libc/include/string.h"
#include <stdint.h>

static char* const VGA_MEMORY=(char*)0xB8000;
static const int VGA_WIDTH=80;
static const int VGA_HEGIHT=25;  


void kernel_early(void){
	terminal_initialize();
} 

__attribute__((noreturn))
 

int main(void *){ 
	char *buff;
	strcpy(&buff[strlen(buff)], ""); 
	printprompt();
	while(1){
		uint8_t  byte; 
		while(byte = scan()){
			if(byte == 0x1C){
				if(strlen(buff) > 0 && strcmp(buff, "exit") == 0){
					printf("\nGoodBye!");
				}
		  printprompt();	 
		  memset(&buff[0],0, sizeof(buff));
		  break;
		}else{
			char c = normalmap[byte]; 
			char *s;
			s = ctos(s,c);
			printf("%s",s); 
			strcpy(&buff[strlen(buff)],s);
		}
			move_cursor(get_terminal_row(),get_terminal_col());
		}
	}
	return 0;
}
