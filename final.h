#ifndef final_H
#define final_H

#include <Arduino.h>

class final
{
public:
	final(int pin,int pin1,int pin2);// ledlerin bagliyacagimiz bacaklari tanimla
	void led1_HIGH(); // 1.ledin yanmasi
	void led2_HIGH(); //2.ledin yanmasi
	void led3_HIGH();
	void led1_LOW();// devaminin sonmesi
	void led2_LOW();
	void led3_LOW();
	void degerYak(int pinx,int siddet);
private:
	int _pin; //.cpp icin olusturdugumuz degiskenler
	int _pin1;
	int _pin2;
	int _pinx;
	int _siddet;

};
#endif
