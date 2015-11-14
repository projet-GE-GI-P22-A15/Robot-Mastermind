#include "serie.h"
#include <libarmus.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

// Global Functions

int test() {
	int sfd = open("/dev/ttyS1", O_RDWR | O_NOCTTY | O_NDELAY);
	if (sfd == -1) {
		fprintf(stderr, "Could not open serial port");
	}

	if (!isatty(sfd)) {
		fprintf(stderr, "Opened device is not a TTY?!?");
		goto close_and_exit;
	}

	struct termios serconf;
	if (tcgetattr(sfd, &serconf) < 0) {
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

	if (tcsetattr(sfd, TCSAFLUSH, &serconf) < 0) {
		fprintf(stderr, "Error setting terminal parameters");
		goto close_and_exit;
	}

	fprintf(stdout, "Success configuring serial port");

	while (1) {
		static int count = 0;
		char buf[1];
		if (read(sfd, buf, 1) == 1) {
			printf("%c", buf[0]);
		}
		buf[0] = count + 48;
		if (write(sfd, buf, 1) != 1) {
			fprintf(stderr, "error writing to serial port");
		}
		count++;
		if (count >= 10)
			count = 0;
		fflush(0);
		THREAD_MSleep(100);
	}

	close_and_exit: close(sfd);

	return 0;
}
