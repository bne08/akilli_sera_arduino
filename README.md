# akilli_sera_arduino
arduino ile akıllı sera sistemi tasarımı

### PROJENİN AMACI VE HEDEFİ

Bu sera çalışmamda Arduino UNO geliştirme kartı kullanılarak bir sistem oluşturdum. Sera sistemimde sensörlerde okunan bilgilerin değerlendirip belli şartları sağlaması  sonucunda sensörler sayesinde komutların yerine getirilmesi sağlanıyor. Sistemimiz otomatik sensörden gelen değerlerle otomatik çalışabilmektedir. Detaylandıracak olursak ; seramda kullandığım bir adet su ölçme sensörü var. Bu sensör yağış algıladığı zaman veya ortamda var olan suyun miktarini ölçmektedir ve suyumuzun seviyesine göre seviyenin “iyi”,“su seviyesi fazla ,havuz boşaltılıyor” şeklinde bir uyarı verilmektedir.Bir diğer kullandığım sensör ise toprak nem sensörü. Bundan gelen veri bize toprağın nem seviyesi hakkında bilgi veriyor üstelik sistemimde bulunan rgb led ile doğrudan sera içinde bulunduğunuzda bu bilgiyi gözle görebiliyorsunuz. Eğer toprak kuru ise sera aydınlatması kırmızı, optimum seviyede ise mavi ve fazla nemli ise yeşil led yanıyor. Sistemimizi tekrar çalıştırdığımızda ise eeprom hafıza işlemimiz sonucunda kaldığı yerden en son rengi ne ise onunda yanmasını sağlıyor.  Yine bir buton aracılığı ile istersek kesme işlemi yaparak seramızın aydınlatmasını değiştirebiliyoruz.


### Kullanılan Malzemeler
  * arduino uno
  * toprak nem sensörü 
  * su seviye sensörü
  * rgb led
  * direnc
  * breadbbord
  * jumper kablo
  * buton
  
### Projenin Çalışma Adımları
 Tasarladığım sistemde topraktan alınan nem durumuna göre  rgb ledinin  yanmasını sağlıyorum. Toprak kuru ise kırmızı ,optimum ise  mavi, nemli ise yeşil rengin yanmasını sağlıyor. Ledlerimin yanma sönme durumlarını kendi oluşturduğum kütüphanemde  yazdım ve  arduino koduma import ettim. Aynı zamanda buton koydum ve butona basılığında bir süreliğine dış kesme işlemi yaparak ledlerimizin rengini istediğimiz gibi değiştirmemizi sağladı. Toprak nem verisine göre yanan ledlerin yanma durumlarını, yani renklerini kaydetmesi içinde  eeprom kütüphanesini aktif ettim ve sistemi kapattığımızda hangi renkte kaldıysa  sistemi aktif ettiğimde o renkle yanmasını sağladım . Diğer bir kullanığım sensör ile su seviyesi ölçme sensörüydü. Su seviyesini ölçmemi ve seviyelere göre  bildirim uyarı vermesini sağladım bunuda zamanlayıcı millis fonksiyonu kullanarak diğer işleride aksatmadan  1 sn de  işlemini yapmasını sağladım. Seri porttada bu değerlerimi ve durumların gösterilmesini sağladım.
