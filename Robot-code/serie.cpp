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
#include "serie.h"

// Global Functions
int serial;
/*
 void ecrireSurMatrice(char buf[9]) {
 if (write(serial, "#", 1) != 1) {
 fprintf(stderr, "ERREUR\n");
 }
 LCD_Printf("MEssage envoye\n");
 }
 */

int Init() {

	int sfd = open("/dev/ttyS1", O_RDWR | O_NOCTTY | O_NDELAY);
	if (sfd == -1) {
		LCD_Printf("Could not open serial port");
	}

	if (!isatty(sfd)) {
		LCD_Printf("Opened device is not a TTY?!?");
		goto close_and_exit;
	}

	struct termios serconf;
	if (tcgetattr(sfd, &serconf) < 0) {
		LCD_Printf("Could not get port configuration");
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
		LCD_Printf("Could not set desired baud rate");
		goto close_and_exit;
	}

	if (tcsetattr(sfd, TCSAFLUSH, &serconf) < 0) {
		LCD_Printf("Error setting terminal parameters");
		goto close_and_exit;
	}

	LCD_Printf("Success configuring serial port\n");

	while (1) {
		static int count = 0;
		char buf[1] = { 'N' };
		if (read(sfd, buf, 1) == 1) {
			LCD_Printf("%c", buf[0]);
		}
		LCD_Printf("Recu: %c\n", buf[0]);
		buf[0] = '#';
		if (write(sfd, buf, 1) != 1) {
			fprintf(stderr, "error writing to serial port");
		}
		LCD_Printf("Envoye: %c\n", buf[0]);

		fflush(0);
		THREAD_MSleep(1000);
	}

	close_and_exit: close(sfd);

	return 0;
}

void Init2() {
	int dev_handle;
	int adresse = 0x32;
	unsigned char buf = '1';
	armus::i2c_RegisterDevice(adresse, 100000, 1000, dev_handle);

	int i = 0;
	while (1) {
		i = ++i % 10;
		buf = i-  '0';
		armus::i2c_Write(dev_handle, 1, &buf);

		THREAD_MSleep(1000);
	}
}
