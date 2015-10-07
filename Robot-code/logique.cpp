#include "logique.h"
#include <libarmus.h>
#include <valeurs.h>

//code pour logique ici
void BumperCommander()
{
	int pause=200;
	while(1)
	{
		int Inexecution=0;
		Inexecution=DIGITALIO_Read(BMP_REAR);
		 if(Inexecution!=0)
			 {
				 LCD_Printf("OK...OK , I'M STOPPING MOFOS\n\n");
				 execution = 0;
			 }
		THREAD_MSleep(pause);
	}
}
