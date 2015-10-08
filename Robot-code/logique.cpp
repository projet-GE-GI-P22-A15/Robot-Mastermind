#include "logique.h"
#include <libarmus.h>
#include <valeurs.h>

//code pour logique ici
void BumperCommander() {
	int pause = 20;

	int inexecution = 0;
	while (1) {
		THREAD_MSleep(pause);

		inexecution = DIGITALIO_Read(BMP_REAR);
		if (inexecution != 0) {
			LCD_Printf("OK...OK , I'M STOPPING MOFOS\n\n");
			execution = 0;
		}

	}
}
