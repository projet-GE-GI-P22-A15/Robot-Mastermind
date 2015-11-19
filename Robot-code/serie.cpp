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
	if (write(serial, "#", 1) != 1) {
		fprintf(stderr, "error writing to serial port");
	}
	LCD_Printf("MEssage envoye\n");
}

int Init() {

	int sfd = open("/dev/ttyS1", O_RDWR | O_NOCTTY | O_NDELAY);
	if (sfd == -1) {
		LCD_Printf("Could not open serial port\n");
	}

	if (!isatty(sfd)) {
		LCD_Printf("Opened device is not a TTY?!?\n");
		goto close_and_exit;
	}

	struct termios serconf;
	if (tcgetattr(sfd, &serconf) < 0) {
		LCD_Printf("Could not get port configuration\n");
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
		LCD_Printf("Could not set desired baud rate\n");
		goto close_and_exit;
	}

	if (tcsetattr(sfd, TCSAFLUSH, &serconf) < 0) {
		LCD_Printf("Error setting terminal parameters\n");
		goto close_and_exit;
	}

	LCD_Printf("Success configuring serial port\n");

	char buf[3];
	while (1) {
		//static int count = 0;
		if (read(sfd, buf, sizeof(buf)) == 1) {
			LCD_Printf("%c", buf[0]);
		}
		//buf[0] = count+48;
		sprintf(buf, "OK");
		if (write(sfd, buf, sizeof(buf)) != 1) {
			LCD_Printf("error writing to serial port\n");
		}
		//count++;
		//if(count >= 10)
		//	count = 0;
		fflush(0);
		THREAD_MSleep(1000);
	}

	close_and_exit: close(sfd);
	LCD_Printf("init\n");
	return 0;
}
