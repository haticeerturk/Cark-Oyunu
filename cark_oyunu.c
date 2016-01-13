#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int puan = 250;//Oyuncunun oyuna basladigi puan.
int sansli1, sansli2, sansli3, sansli4;//Bilgisayarin random sectigi sayiları tutuyorlar
int tahmin1, tahmin2, tahmin3, tahmin4; //Benim sayi tahmini için girdigim sayilar.
int bilinen = 0;//Oyuncunun dogru tahmin sayisini tutar.

int devam_mi(){//Oyuncuya oyuna devam edip etmeyeceginin soruldugu fonksiyon.
    char cevap;

    printf("Yeni bir oyun oynamak istiyorsanız 'c',oyundan çıkmak istiyorsanız 's' harfine basınız...\n");
    cevap=getchar();
    scanf(" %c", &cevap);

    if(cevap == 'c'){
        return cark_cevir();
    }
    else{
        return 0;
    }
}

int sayi_uret(){

    srand(time(NULL));
    sansli1 = random()%10 + 1; //Ilk sayi oldugu icin donguye gerek yok. Cunku karsilastirilacak sayi yok.

    sansli2 = random()%10 + 1; //Ikıncı sayi secilir.
    while(sansli1 == sansli2) { //Ikınci sayinin ilk sayi ile ayni olup olmadigi kontrolu yapilir.
    	sansli2 = random()%10 + 1; //Eger ayni ise tekrardan dongu devam eder yani ayni olmayana kadar dongu devam eder.
    }

    sansli3 = random()%10 + 1; //Ucuncu sayi cekilir.
    while(sansli3 == sansli1 || sansli3 == sansli2) { //Diger iki sayi ile ayni olmayana kadar tekrardan cekilir.
    	sansli3 = random()%10 + 1;
    }

    sansli4 = random()%10 + 1;
    while(sansli4 == sansli1 || sansli4 == sansli2 || sansli4 == sansli3) {
    	sansli4 = random()%10 + 1;
    }
}

int tahmin_gir(){

    //Oyuncudan puan kazanmak icin sayi tahminleri aliniyor...
    printf("1-10 sayıları arasından(1 ve 10 dahil) 1.tahmininizi giriniz: \n");
    scanf("%d",&tahmin1);
    while(tahmin1 >10 || tahmin1 < 1){
        printf("Lütfen 1-10 arasında sayı tahmin ediniz...\n");
        scanf("%d",&tahmin1);
    }

    printf("1-10 sayıları arasından(1 ve 10 dahil) 2.tahmininizi giriniz: \n");
    scanf("%d",&tahmin2);
    while(tahmin2 > 10 || tahmin2 < 1 || tahmin2 == tahmin1){
        printf("Lütfen 1-10 arasında ve önceki tahminlerinizden farklı bir tahmin giriniz: \n");
        scanf("%d", &tahmin2);
    }

    printf("1-10 sayıları arasından(1 ve 10 dahil) 3.tahmininizi giriniz: \n");
    scanf("%d", &tahmin3);
    while(tahmin3 > 10 || tahmin3 < 1 || tahmin3==tahmin2 || tahmin3 == tahmin1){
        printf("Lütfen 1-10 arasında ve önceki tahminlerinizden farklı bir tahmin giriniz: \n");
        scanf("%d", &tahmin3);
    }

    printf("1-10 sayıları arasından(1 ve 10 dahil) 4.tahmininizi giriniz: \n");
    scanf("%d", &tahmin4);
    while(tahmin4 > 10 || tahmin4 < 1 || tahmin4==tahmin3 || tahmin4 == tahmin2 || tahmin4 == tahmin1){
        printf("Lütfen 1-10 arasında ve önceki tahminlerinizden farklı bir tahmin giriniz: \n");
        scanf("%d", &tahmin4);
    }
    system("clear");
}

int cark_cevir(){
    system("clear");
    int cark;// Cark cevrildiginde nerede duracagini rastgele tutan degisken.
    /*
     * 0 = 50 puan için temsil ediliyor.
     * 1 = 100 puan için temsil ediliyor.
     * 2 = 250 puan için temsil ediliyor.
     * 3 = Pas için temsil ediliyor.
     * 4 = İflas için temsil ediliyor.
     * 5 = Puan Azaltma için temsil ediliyor.
    */
    srand(time(NULL));
    cark = rand()%6;

    sayi_uret();

    switch(cark){
        case 0:
            printf("50 Puanı kazanmak için yarışıyorsunuz.\n\n");
            tahmin_gir();
        	return cark;
        case 1:
            printf("100 Puanı kazanmak için yarışıyorsunuz.\n\n");
            tahmin_gir();
            return cark;
        case 2:
            printf("250 Puanı kazanmak için yarışıyorsunuz.\n\n");
            tahmin_gir();
            return cark;
        case 3:
            printf("Hak Aksi! PAS geldi.\n\n");
            printf("Sakın korkma! Puanın değişmedi.\n\n");
            printf("Puanın : %d\n\n",puan);
            devam_mi();
            break;
        case 4:
            printf("Kötü talih ahbap! İFLAS ettin!\n\n");
            puan = 0;
            printf("Ne yazık ki puanın %d .\n\n",puan);
            if(puan == 0){
                return cark;
            }

            break;
        case 5:
            printf("Puan Azaltmaya denk geldin! Ve puanın azaltılıyor...\n\n");
            puan -= (puan*25)/100;
            printf("Yeni puanın : %d \n\n",puan);
            if(puan == 0){
                return 0;
            }
            devam_mi();
            break;
    }

}

int main()
{
    char cevap;//Kullanıcıdan gelen oyun oynayıp oynamayacağını tutacak olan değişken.
    int _cark;
    printf("\t\t\tÇARK OYUNU'na Hoşgeldiniz!\n\n");

    //Kullanıcıya oyun oynayıp oynamayacağı soruluyor...
    while(1) {

	    printf("Yeni bir oyun oynamak istiyorsanız 'c',oyundan çıkmak istiyorsanız 's' harfine basınız...\n");
		scanf(" %c", &cevap);

	    if(cevap == 's'){
	        return 0;
	    }
	    else if(cevap != 'c'){
	    	printf("Gecersiz bir secim yaptiniz.\n");
	    }
	    else{
	        _cark = cark_cevir();

			bilinen = 0;

		    if(tahmin1 == sansli1 || tahmin1 == sansli2 || tahmin1 == sansli3 || tahmin1 == sansli4){
		        bilinen++;
		    }
		    if(tahmin2 == sansli1 || tahmin2 == sansli2 || tahmin2 == sansli3 || tahmin2 == sansli4){
		        bilinen++;
		    }
		    if(tahmin3 == sansli1 || tahmin3 == sansli2 || tahmin3 == sansli3 || tahmin3 == sansli4){
		        bilinen++;
		    }
		    if(tahmin4 == sansli1 || tahmin4 == sansli2 || tahmin4 == sansli3 || tahmin4 == sansli4){
		        bilinen++;
		    }

		    if(_cark == 0) {
			    if(bilinen >= 1){
			        printf("Tebrikler! %d sayı bildiniz!\n\n",bilinen);
			        puan += 50;
			        printf("Yeni puanınız %d\n",puan);
			    }
			    else{
			        printf("%d sayı bildin.\nNe yazık ki 50 puanı alamadınız.\nPuanınız %d.\n\n",bilinen,puan);
			    }
		    }
		    else if(_cark == 1) {
		        if(bilinen >= 2){
		            printf("Tebrikler! %d sayı bildiniz!\n\n",bilinen);
		            puan += 100;
		            printf("Yeni puanınız %d\n\n",puan);
		        }
		        else{
		            printf("%d sayı bildin.\nNe yazık ki 100 puanı alamadınız.\nPuanınız %d.\n\n",bilinen,puan);
		        }
		    }
		    else if(_cark == 2) {
		        if(bilinen >= 3){
		            printf("Tebrikler! %d sayı bildiniz!\n\n",bilinen);
		            puan += 250;
		            printf("Yeni puanınız %d\n\n",puan);
		        }
		        else{
		            printf("%d sayı bildin.\nNe yazık ki 250 puanı alamadınız.\nPuanınız %d.\n\n",bilinen,puan);
		        }
		    }

		    if(puan == 0){
		        return 0;
		    }

		    printf("Bilgisayarın Ürettiği Sayılar : \n" "%d-%d-%d-%d\n",sansli1,sansli2,sansli3,sansli4);
		    printf("Sizin Tahmin Ettiğiniz Sayılar : \n" "%d-%d-%d-%d\n\n",tahmin1,tahmin2,tahmin3,tahmin4);

    	}
	}

    return 0;
}
