/*#ifndef CAPTEURCOULEUR_H_
#define CAPTEURCOULEUR_H_

#define ADJD_S371_QR999_SADR 	0x74
#define CAP_RED					0x6
#define CAP_GREEN				0x7
#define CAP_BLUE				0x8
#define CAP_CLEAR				0x9
#define INTEGRATION_RED			10
#define INTEGRATION_GREEN		12
#define INTEGRATION_BLUE		14
#define INTEGRATION_CLEAR		16
#define ADJD_REG_CTRL			0
#define ADJD_REG_CONFIG			1
#define DATA_RED_LO				64
#define DATA_GREEN_LO			66
#define DATA_BLUE_LO			68
#define DATA_CLEAR_LO			70

#define CTRL_GSSR				0
#define CTRL_GOFS				1

#define CONFIG_TOFS				0


void color_ReadToCalibrate(int& data_red, int& data_blue, int& data_green, int& data_clear);
void color_Read(int& data_red, int& data_blue, int& data_green, int& data_clear);
void led_TurnOn();
void led_TurnOff();
void integrationTime_SetValue(unsigned char address, int time_value);
int integrationTime_GetValue(unsigned char address);
void cap_SetValue(unsigned char cap_address, unsigned char cap_value);
unsigned char cap_GetValue(unsigned char cap_address);
int adjd_ReadRegister16(unsigned char reg);
unsigned char adjd_ReadRegister(unsigned char reg);
void adjd_SetRegister16(unsigned char reg, int val);
void adjd_SetRegister(unsigned char reg, unsigned char val);

int adjd_dev = 0;

#endif // CAPTEURCOULEUR_H_
*/
