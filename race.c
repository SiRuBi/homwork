#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void charatatime ( char * str ) {
	char * ptr ;
	int c ;
	setbuf ( stdout , NULL ) ; /* set unbuffered */
	for ( ptr = str ; (c = * ptr++) != 0; )
		putc ( c , stdout ) ;
}
int main( void) {
	pid_t pid ;
	if( ( pid = fork ( ) ) < 0) perror ( " fork error " ) ;
	else if ( pid == 0) {
		charatatime ( "output from chi ld\n" ) ;
	} else {
		charatatime ( "output from parent\n" ) ;
	}
	exit ( EXIT_SUCCESS);
} // end of race . c

