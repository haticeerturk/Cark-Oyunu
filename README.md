Çark Oyunu:

Oyuncuların bilgisayara karşı sayi tahmini yaptiği, ve çarkın üzerinde durduğu puana göre puan aldıkları veya puanlarının azaltıldığı bir çarkı felek oyunu tasarlayanız. Oyunun kuralları şu şekilde olmalıdır.<br/>
1- Oyuncu 250 puanla oyuna başlar<br/>
2- Bilgisayar 1-10 arası (1 ve 10 dahil) 4 adet rasgele sayi üretir ve kullanıcıdan çarkın durduğu puana göre bu sayilardan birini veya daha fazlasini tahmin etmesini ister.<br/>
3- Çark üzerinde 50puan, 100puan, 250puan oyuncunun kazanabileceği puanlardır.Bunlara ek olarak Pas, İflas ve Puan azaltma bölümleri vardır.<br/>
4- Kullanıcı ilgili tahmini yapmak için 4 adet sayi girer.<br/>
5- 50 puan için bilgisayarın ürettiği 4 adet rasgele sayidan sadece 1 ini bilmek yeterlidir, aksi halde puan alınmaz<br/>
6- 100 puan için bilgisayarın ürettiği 4 adet rasgele sayidan en az 2 ini bilmek yeterlidir, aksi halde puan alınmaz<br/>
7- 250 puan için bilgisayarın ürettiği 4 adet rasgele sayidan en az 3 ünü bilmek yeterlidir, aksi halde puan alınmaz<br/>
8- Pas da puanda değişiklik olmaz.<br/>
9- İflas durmunda oyuncunun puanları sıfırlanır.<br/>
10- Puan azaltmada oyuncunun puanı %25 azaltılır. Program tasarımı için uyulması gereken kurallar.<br/>
1- Oyun başında kullanıcıya iki seçenek sunulur. Kullanıcı klavyeden “c” harfi girerse oyun başlar, “s” harfi girerse oyun sonlanır. Kullanıcı çarkı her çevirişinden sonra bu şekilde ya oyuna devam eder, ya da oyunu bitirir.<br/>
2- Oyun içerisinde kullanıcının puanı=0 olmuş ise oyun sonlanır.<br/>
3- Kullanıcı çarkı her çevirdiğinde (kalvyeden c girdiğinde):<br/>
  a. Bilgisayar çarkın hangi puan ya da ceza üzerinde duracağını rasgele olarak belirler. Bu işlem cark_cevir adlı fonksiyon tarafından gerçekleştirilmelidir. <br/>
  b. Bilgisayar kullanıcının tahmin etmesi için 1-10 arası (1 ve 10 dahil) 4 adet sayi üretir. Bu işlem sayi_uret adlı fonksiyon tarafından yapılmalıdır.<br/>
4- Kullanıcının tahminlerini girmesi icin tahmin_gir() adlı fonksiyon kullanılmalıdır. Bu fonksiyon kullanıcıdan 4 adet tahmin alir, tahminleri bilgisayarın üretmiş olduğu rasgele sayilar ile karşılaştırır. Doğru tahmin sayısını main fonksiyonuna döndürür.<br/>
5- tahmin_gir() fonksiyonunun döndürdüğü değer, main içerisinde yukarıda verilen oyun kurallarına göre hesaplanır ve kullanıcının aldığı puan hesaplanarak ekrana yazdırılır.<br/>
6- Kullanıcının puanı 0 (sıfır) ise oyun otomatik olarak sonlandırılır
