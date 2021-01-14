#include <EEPROM.h>
#include <final.h> /*olusturudugum kutuphanem*/

int addr = 0; /*eeproom için okunacak adres tanımladı */
int val2; /* eepromdaki değerlerin atanması için*/
int pin1=9,pin2=10,pin3=11; /*pin ayaklarımızı belirledik*/
final fin(9,10,11); /*RGB ledin her rengi için de bir pin ayrılmış durumdadır kutuphaneden aldık pinleri*/

const int toprak_sensor=A0; /* toprak nem sensorumuzu ayarladık */
int toprak_veri; /* toprak verisi için degisken tutuk */
unsigned long eskiZaman=0; /*millis zamanlayicisi degiskeni*/
unsigned long yeniZaman; /*millis zamanlayicisi degiskeni*/


char veri;
int su_seviye=A3; /*su seviye ölçme sensörümüzü analog girisini tanımlıyoruz */


void setup() {

  attachInterrupt(0,dis_kesme,FALLING); /*buton için baglıycagımız 2. bacak ,basıldıgındaki calısan fonk. ,pin degisiminde kesme olma işlemi*/
  pinMode(toprak_sensor,INPUT); /*setup kısmında kullanılan pinlerin INPUT - OUTPUT durumları set edilir. Ledler Output, sensörler Input durumundadır */
  Serial.begin(9600);
  Serial.println(EEPROM.read(addr)); /*serial ekranda eepromdaki verileri oku */
    val2 = EEPROM.read(addr);  /*EEPROM'daki ilk baytı oku */
}

void loop() {
  suSeviye(); /*su seviyo fonksiyonu */
  toprak_kontrol(); /*toprak kontrol fonksiyonu */
  delay(500);
}

void toprak_kontrol() {
  toprak_veri=analogRead(toprak_sensor); /* topraktan gelen veriyi oku */
  Serial.print("toprak veri:"); /* serial porta yaz degeri */
  Serial.println(toprak_veri);
  
  /*toprak sensöründen gelen veri if kontrollerine sokulur.Sağladığı aralığa göre RGB Leddinde ayarlanmış olan renk aktif edilir */
  if(toprak_veri > 900) {
    Serial.println("toprak kuru");
      fin.led1_LOW();
      fin.led2_HIGH();/*KIRMIZI yanıyor */
      fin.led3_LOW();  
      EEPROM.write(addr, 1); /*degeri eeproma kaydetme islemi */
      Serial.println(EEPROM.read(addr)); /*serial porttan eepromdaki degeri oku */
      delay(5000);

  }
  if(toprak_veri <= 900 && toprak_veri > 550) { 
    Serial.println("toprak optimum");
      fin.led1_LOW();/*MAVİ yanıyor */
      fin.led2_LOW();
      fin.led3_HIGH();
      EEPROM.write(addr, 2); /*degeri eeproma kaydetme islemi */
     Serial.println(EEPROM.read(addr)); /*serial porttan eepromdaki degeri oku */
     delay(5000);

  }
  if(toprak_veri <= 550) {
    Serial.println("toprak nemli");
      fin.led1_HIGH(); /*YESİL yanıyor*/
      fin.led2_LOW();
      fin.led3_HIGH();
      EEPROM.write(addr, 3); /*degeri eeproma kaydetme islemi */
      Serial.println(EEPROM.read(addr)); /*seri porttanda eepromdaki  degeri oku */
      delay(5000);
  }
 
}

/*dış kesme aktif edildiğinde rgb ledinde random olarak renkler gönderilir. */
void dis_kesme(){ /*kesme fonksiyonuna gir */
  Serial.println("renk degisti");
  int rDeger=random(0,255);
  int gDeger=random(0,255);
  int bDeger=random(0,255);
  fin.degerYak(pin1,rDeger); /*ledlerin kutuphanede tanımladıgımız sekilde yanma durumları */
  fin.degerYak(pin2,gDeger);
  fin.degerYak(pin3,bDeger);
delay(1000);

    
}

/*su ölçme  sensöründen gelen veri if kontrollerine sokulur.Degere göre bidirim verir */
 void suSeviye() {
   yeniZaman = millis();   /* Arduinonun çalışma suresi milisaniye cinsinden alınıyor */
   if(yeniZaman-eskiZaman > 1000){ /* bir önceki turdan itibaren 1000 milisaniye geçmiş mi
  yani yeniZaman ile eskiZaman farkı 1000den büyük mü */
   int seviye=analogRead(su_seviye); /*su seviyeyi ölç */
   Serial.print("su seviye :");
   Serial.println(seviye);
  
   if(seviye <= 300) {
    Serial.print("su seviyesi iyi :");
    Serial.print(seviye);
   }

   if (seviye > 500) {
    Serial.print("su seviyesi fazla, havuz boşaltılıyor :"); 
    Serial.print(seviye);
   } 
   eskiZaman = yeniZaman; /* Eski zaman değeri yeni zaman değeri ile güncelleniyor */
  }
 }
