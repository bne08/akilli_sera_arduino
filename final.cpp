#include "final.h" //olustrudugumuz header dosyayi cagiriyoruz
#include "Arduino.h"

final::final(int pin,int pin1,int pin2){// final sinifinin icindeki final  fonksiyonuna gir
    pinMode(pin,OUTPUT); // bacaklari girdigimz zaman cikis yapiyor
    pinMode(pin1,OUTPUT);
    pinMode(pin2,OUTPUT);
    _pin=pin; // .h kutupde olsturdugumuz degiskenlere bunlari kaydettirdik
    _pin1=pin1;
    _pin2=pin2;
}
void final::led1_HIGH(){  
    digitalWrite(_pin, HIGH);
}
void final::led2_HIGH(){
    digitalWrite(_pin1,HIGH);
}
void final::led3_HIGH(){ 
    digitalWrite(_pin2,HIGH);
}
void final::led1_LOW(){ 
    digitalWrite(_pin,0);
}
void final::led2_LOW(){
    digitalWrite(_pin1,0);
}
void final::led3_LOW(){
    digitalWrite(_pin2,1);
}
void final::degerYak(int pinx,int siddet){ //kesme işlemi yapıldıgında ledlerin yanması için
    analogWrite(_pinx,_siddet);
    _pinx=pinx;
    _siddet=siddet;
}
