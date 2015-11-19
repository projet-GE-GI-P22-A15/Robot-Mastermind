/*
 ============================================================================
 Name : testserial.cpp
 Author :
 Version :
 Description : Hello world - Exe source file
 ============================================================================
 */

// Include Files
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <libarmus.h>

// Global Functions
int serial;

void ecrireSurMatrice(char buf[9]) {
	if (write(serial, buf, 9) != 1) {
		fprintf(stderr, "error writing to serial port");
	}
	LCD_Printf("MEssage envoye\n");
}

int Init() {
	int serial = open("/dev/ttyS1", O_RDWR | O_NOCTTY | O_NDELAY);
	if (serial == -1) {
		fprintf(stderr, "Could not open serial port");
	}

	if (!isatty(serial)) {
		fprintf(stderr, "Opened device is not a TTY?!?");
		goto close_and_exit;
	}

	struct termios serconf;
	if (tcgetattr(serial, &serconf) < 0) {
		fprintf(stderr, "Could not get port configuration");
		goto close_and_exit;
	}

	serconf.c_iflag = IGNPAR; //Ignore parity
	serconf.c_oflag = 0;
	serconf.c_cflag = CS8 | CREAD | CLOCAL; //8 bits - Enable receiver - Ignore modem controls
	serconf.c_lflag = ECHO; //Echo on
	serconf.c_cc[VMIN] = 1;
	serconf.c_cc[VTIME] = 0;

	if (cfsetispeed(&serconf, B115200) < 0
			|| cfsetospeed(&serconf, B115200) < 0) {
		fprintf(stderr, "Could not set desired baud rate");
		goto close_and_exit;
	}

	if (tcsetattr(serial, TCSAFLUSH, &serconf) < 0) {
		fprintf(stderr, "Error setting terminal parameters");
		goto close_and_exit;
	}

	fprintf(stdout, "Success configuring serial port");

	/*while (1) {
	 static int count = 0;
	 char buf[4] = "#A!";
	 if (read(serial, buf, 1) == 1) {
	 printf("%c", buf[0]);
	 }
	 buf[0] = '#';
	 buf[1] = 'A';
	 buf[2] = '!';
	 if (write(serial, buf, 3) != 1) {
	 fprintf(stderr, "error writing to serial port");
	 }
	 count++;
	 if (count >= 10)
	 count = 0;
	 fflush(0);
	 THREAD_MSleep(100);
	 }*/

	close_and_exit: close(serial);

	return 0;
}
