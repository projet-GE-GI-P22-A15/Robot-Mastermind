/*
 * couleuri2c.h
 *
 *  Created on: 2015-10-27
 *      Author: blood
 */

#ifndef COULEURI2C_H_
#define COULEURI2C_H_

void adjd_SetRegister(unsigned char reg, unsigned char val);
void adjd_SetRegister16(unsigned char reg, int val);
unsigned char adjd_ReadRegister(unsigned char reg);
int adjd_ReadRegister16(unsigned char reg);
unsigned char cap_GetValue(unsigned char cap_address);
void cap_SetValue(unsigned char cap_address, unsigned char cap_value);
int integrationTime_GetValue(unsigned char address);
void integrationTime_SetValue(unsigned char address, int time_value);

void led_TurnOff();
void led_TurnOn();
void color_Read(int& data_red, int& data_blue, int& data_green,
		int& data_clear);

void color_ReadToCalibrate(int& data_red, int& data_blue, int& data_green,
		int& data_clear);
int color_Init(int& dev_handle);

#endif /* COULEURI2C_H_ */
