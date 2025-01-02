#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char AdresGiris();
struct Yemek {
    char ad[100];
    int fiyat;
};
void KartNoAl(char kartNo[16]/*,int *toplamYemekTutarı*/) {
    double kartNoKontrol = 16;
    do {
        strcpy(kartNo,"");
        printf("Kart Numaranizi Giriniz\n");
        scanf("%s",kartNo);
        if (strlen(kartNo)==kartNoKontrol) {
            break;
        }
        printf("Yanlis Kart Bilgisi girdiniz.\n");
    }
    while(1);

}
void YemekSecim(struct Yemek secilenYemekler[100],int *secilenYemekSayisi, int yemekSecim, int yemek1, int yemek2, int yemek3, int yemek4, int yemek5,char yemekIsim1[100], char yemekIsim2[100], char yemekIsim3[100], char yemekIsim4[100], char yemekIsim5[100]) {
    int toplamFiyat = 0;
    int uyariDurdurucu = 0;

    struct Yemek yemekListesi[5];
    strcpy(yemekListesi[0].ad, yemekIsim1);
    yemekListesi[0].fiyat = yemek1;

    strcpy(yemekListesi[1].ad, yemekIsim2);
    yemekListesi[1].fiyat = yemek2;

    strcpy(yemekListesi[2].ad, yemekIsim3);
    yemekListesi[2].fiyat = yemek3;

    strcpy(yemekListesi[3].ad, yemekIsim4);
    yemekListesi[3].fiyat = yemek4;

    strcpy(yemekListesi[4].ad, yemekIsim5);
    yemekListesi[4].fiyat = yemek5;
    do {
        if (yemekSecim >= 1 && yemekSecim <= 5) {
            // Yemek bilgilerini sepete ekle
            secilenYemekler[*secilenYemekSayisi] = yemekListesi[yemekSecim - 1];
            toplamFiyat += yemekListesi[yemekSecim - 1].fiyat;
            (*secilenYemekSayisi)++;

            struct Yemek secilenYemek = yemekListesi[yemekSecim - 1];
            printf("Secilen yemek: %s, Fiyat: %d TL\n", secilenYemek.ad, secilenYemek.fiyat);

            printf("Toplam Sepet: %d TL\n", toplamFiyat);
            printf("Eklemek istediginiz baska yemek varsa tuslayiniz, yoksa 6'yi tuslayiniz.\n");
            scanf("%d", &yemekSecim);
            uyariDurdurucu = 0;
        }
        else {
            uyariDurdurucu++;
            if (uyariDurdurucu == 1) {
                printf("Yanlis tuslama yaptiniz.\n");
            }
            scanf("%d", &yemekSecim);
        }
    } while (yemekSecim != 6);

    int bakiye;
    char kartNo[16];
    AdresGiris(); //
    KartNoAl(kartNo);
    printf("Kartinizda bulunan parayi giriniz\n");
    scanf("%d",&bakiye);
    if (bakiye<toplamFiyat) {
        printf("Yetersiz Bakiye");
    }
    else {
        printf("Siparisiniz Alinmistir.\n");
    }

}
char AdresGiris() {
    char adres[100];
    printf("Adresinizi Giriniz. \n");
    scanf("%s",&adres);
    return adres;
}
int main() {
    int restoranSecim, yemekSecim, secilenYemekSayisi = 0;
    struct Yemek secilenYemekler[100];

    printf("Kullanici adini giriniz: ");
    char kullaniciAdi[100];
    scanf("%s", kullaniciAdi);

    printf("Sifreyi giriniz: ");
    char sifre[100];
    scanf("%s", sifre);

    printf("\n1- Oncu Doner\n");
    printf("2- Cici Doner\n");
    printf("3- Komagene\n");
    printf("3- Komagene\n");
    printf("4- Tatsos\n");
    printf("5- Dominos\n");
    printf("Herhangi bir restorani secmek icin yanindaki sayiyi tuslayiniz.\n");
    scanf("%d", &restoranSecim);

    switch (restoranSecim) {
        case 1:
            printf("Oncu Doneri sectiniz\n");
            printf("1- Tavuk durum: 100 TL\n");
            printf("2- Ekmek arası tavuk doner: 120 TL\n");
            printf("3- Zurna Tavuk durum: 150 TL\n");
            printf("4- Tavuk durum menu: 150 TL\n");
            printf("5- Servis tavuk doner: 170 TL\n");
            printf("Eklemek istediginiz yiyecekleri eklemek icin yanindaki numarayi tuslayiniz\n");
            scanf("%d", &yemekSecim);

            YemekSecim(secilenYemekler, &secilenYemekSayisi, yemekSecim, 100, 120, 150, 150, 170,
                "Tavuk durum","Ekmek arası tavuk doner","Zurna Tavuk","Tavuk durum menu","Servis tavuk doner");
            break;

        case 2:
            printf("Cici Doneri sectiniz\n");
            printf("1- Tavuk durum: 120 TL\n");
            printf("2- Ekmek arası tavuk doner: 140 TL\n");
            printf("3- Zurna Tavuk durum: 170 TL\n");
            printf("4- Tavuk durum menu: 170 TL\n");
            printf("5- Servis tavuk doner: 190 TL\n");
            printf("Eklemek istediginiz yiyecekleri eklemek icin yanindaki numarayi tuslayiniz\n");
            scanf("%d", &yemekSecim);

        YemekSecim(secilenYemekler, &secilenYemekSayisi, yemekSecim, 120, 140, 170, 170, 190,
            "Tavuk durum","Ekmek arası tavuk doner","Zurna Tavuk","Tavuk durum menu","Servis tavuk doner");
            break;

        case 3:
            printf("Komageneyi sectiniz\n");
            printf("1- Cigkofte durum: 70 TL\n");
            printf("2- Mega cigkofte durum: 90 TL\n");
            printf("3- Ultra mega cigkofte durum: 110 TL\n");
            printf("4- Mega cigkofte durum menu: 120 TL\n");
            printf("5- Double cigkofte durum: 130 TL\n");
            printf("Eklemek istediginiz yiyecekleri eklemek icin yanindaki numarayi tuslayiniz\n");
            scanf("%d", &yemekSecim);

        YemekSecim(secilenYemekler, &secilenYemekSayisi, yemekSecim, 70, 90, 110, 120, 130,
            "Cigkofte durum","Mega cigkofte durum","Ultra mega cigkofte durum","Mega cigkofte durum menu","Double cigkofte durum");
            break;

        case 4:
            printf("Tatsosu sectiniz\n");
            printf("1- Tavuk durum: 110 TL\n");
            printf("2- Zurna Tavuk: 140 TL\n");
            printf("3- Bazuka durum: 170 TL\n");
            printf("4- Bazuka durum menu: 200 TL\n");
            printf("5- Bazuka XL durum menu: 230 TL\n");
            printf("Eklemek istediginiz yiyecekleri eklemek icin yanindaki numarayi tuslayiniz\n");
            scanf("%d", &yemekSecim);

        YemekSecim(secilenYemekler, &secilenYemekSayisi, yemekSecim, 110, 140, 170, 200, 230,
        "Tavuk durum","Zurna Tavuk","Bazuka durum","Bazuka durum menu","Bazuka XL durum menu");
            break;

        case 5:
            printf("Dominosu sectiniz\n");
            printf("1- Karisik kucuk boy pizza: 150 TL\n");
            printf("2- Peynirli orta boy pizza: 200 TL\n");
            printf("3- Karisik orta boy pizza: 220 TL\n");
            printf("4- Karisik buyuk boy pizza: 250 TL\n");
            printf("5- Karisik jumbo pizza: 290 TL\n");
            printf("Eklemek istediginiz yiyecekleri eklemek icin yanindaki numarayi tuslayiniz\n");
            scanf("%d", &yemekSecim);

        YemekSecim(secilenYemekler, &secilenYemekSayisi, yemekSecim, 150, 200, 220, 250, 290,
    "Karisik kucuk boy pizza","Peynirli orta boy pizza","Karisik orta boy pizza","Karisik buyuk boy pizza","Karisik jumbo pizza");
            break;

        default:
            printf("Gecersiz restoran secimi.\n");
            break;
    }

    return 0;
}
