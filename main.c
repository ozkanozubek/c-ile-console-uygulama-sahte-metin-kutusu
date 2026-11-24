#include <stdio.h>
#include <stdlib.h> /* system() fonksiyonu için gerekli */

/* Ýmleci ekranda istediðimiz X ve Y koordinatýna götüren fonksiyon */
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

int main() {
    int vizeNotu = 0;
    int finalNotu = 0;
    double ortalama = 0.0;

    /* Windows 10 terminaline modern ANSI renk/yönlendirme kodlarýný öðretiyoruz */
    system("printf ''"); 

    /* EKRAN BOYUTUNU SABÝTLEME: Ekraný 45 sütun geniþliðe ve 20 satýr yüksekliðe ayarlar */
    system("mode con: cols=45 lines=20");

    /* Ekraný tamamen temizler */
    printf("\033[H\033[J");

    /* 1. RENKLÝ EKRAN ARAYÜZÜNÜ ÇÝZÝYORUZ */
    /* \033[1;33m -> Sarý Çerçeve | \033[1;34m -> Mavi Baþlýk | \033[0m -> Rengi Sýfýrla */
    printf("\033[1;33m==========================================\033[0m\n");
    printf("\033[1;33m=\033[0m        \033[1;34mNOT HESAPLAMA SISTEMI\033[0m           \033[1;33m=\033[0m\n");
    printf("\033[1;33m==========================================\033[0m\n\n");
    
    printf(" Vize Notu Giriniz:  [        ] \n\n");
    printf(" Final Notu Giriniz: [        ] \n\n");
    
    printf("\033[1;33m==========================================\033[0m\n");

    /* 2. Vize Notunu Alýyoruz */
    gotoxy(23, 5);
    if (scanf("%d", &vizeNotu) != 1) vizeNotu = 0;

    /* 3. Final Notunu Alýyoruz */
    gotoxy(23, 7);
    if (scanf("%d", &finalNotu) != 1) finalNotu = 0;

    /* 4. Ortalama Hesaplama (Vize %40, Final %60) */
    ortalama = (vizeNotu * 0.4) + (finalNotu * 0.6);

    /* 5. Sonucu Alt Tarafa Yazdýrýyoruz */
    gotoxy(1, 10); 
    printf("--- HESAPLAMA SONUCU ---\n");
    printf("Yýl Sonu Ortalamanýz: %.2f\n", ortalama);
    
    if (ortalama >= 50 && finalNotu >= 50) {
        /* Dersi geçtiyse YEÞÝL yazdýr */
        printf("Ders Durumu         : \033[1;32mGEÇTÝ\033[0m \n");
    } else {
        /* Dersi kaldýysa KIRMIZI yazdýr */
        printf("Ders Durumu         : \033[1;31mKALDI\033[0m \n");
    }

    return 0;
}

/*
?? Eklenen Satýrlarýn Ýzahý
• system("mode con: cols=42 lines=14");
Açýklama: Windows iþletim sistemine doðrudan komut gönderir.
Konsol penceresinin boyutunu (sütun ve satýr sayýsýný) sýnýrlandýrýr.
Program açýldýðý an pencere otomatik olarak bu küçük, þýk boyuta bürünür ve kullanýcý tarafýndan yeniden boyutlandýrýlamaz.
• \033[1;34mNOT HESAPLAMA SISTEMI\033[0m
Açýklama: Baþlýk yazýsýnýn rengini Kalýn Mavi yapar. Yazý biter bitmez \033[0m ile rengi sýfýrlarýz ki çerçevenin 
devamý maviye boyanmasýn.
• \033[1;33m
Açýklama: Çerçeveyi oluþturan eþittir (=) çizgilerini Kalýn Sarý/Turuncu renge boyayarak baþlýðýn ve alt sýnýrýn 
daha belirgin durmasýný saðlar.
F11'e bastýðýnýzda pencerenin otomatik olarak küçülüp sabitlendiðini ve sarý-mavi renklerin ekrana geldiðini gördük
*/
