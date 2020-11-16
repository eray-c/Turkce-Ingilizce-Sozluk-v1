#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX 50

void menuYazdir();
void ceviri(int, int, char[][MAX], char[][MAX] );
int sayiOku();

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Turkish");
    
    int kelimeSayisi = sayiOku();
    char turkce[kelimeSayisi][MAX];
    char ingilizce[kelimeSayisi][MAX];
    
    FILE* filePtr = NULL;
    filePtr = fopen("sozluk.txt","r");
    if(filePtr == NULL) {
        printf("Sözcük listesi bulunamadi.\n");
        return 0;
    }
    
    int i;
    for(i=0; i<kelimeSayisi; i++) {
        fscanf(filePtr, "%s %s", turkce[i], ingilizce[i]);
    }
    fclose(filePtr);
    
    char secim;
    
    while(1) {   
    menuYazdir();
    scanf("%s",&secim);
    
    switch(secim) {
        case '1':
            ceviri(1,kelimeSayisi,turkce,ingilizce);
            break;
        case '2':
            ceviri(2,kelimeSayisi,turkce,ingilizce);
            break;
        case '3':
            kelimeEkle(turkce,ingilizce,kelimeSayisi);
            break;
        case '0':
            printf("\n\nÇıkış yapılıyor...");
            exit(0);
            break;
        default:
            printf("Lütfen geçerli bir işlem seçiniz.");
            break;
    }
  }
    return (EXIT_SUCCESS);
}

void menuYazdir() {
    printf("\n\n\n-------[ANA MENÜ]-------\n\n");
    printf("1. İngilizce - Türkçe Çeviri\n");
    printf("2. Türkçe - İngilizce Çeviri\n");
    printf("3. Kelime Ekle\n");
    printf("0. ÇIKIŞ\n\n");
    printf("Yapmak istediğiniz işlemi seçiniz : ");
}

void ceviri(int dil,int kelimeSayisi,char turkce[][MAX],char ingilizce[][MAX]) {

    char aranan[MAX];
    int durum;
    
    printf("Aranacak kelimeyi yazınız : ");
    scanf("%s",aranan);
    
    if(dil==1) {
        int i = 0;
        while(i<kelimeSayisi) {
            if(strcmp(turkce[i],aranan)==0) {
               printf("Aradığınız kelimenin anlamı ==> %s",ingilizce[i]); 
               durum++;
               return;
            }
            i++;
        }   
    }
        
    if(dil==2) {
        int i;
        for(i=0; i<kelimeSayisi; i++) {
            if(strcmp(ingilizce[i],aranan)==0) {
               printf("Aradığınız kelimenin anlamı ==> %s",turkce[i]);
               durum++;
               return;
            }
        }   
    }
    
    if(durum==0) {
        printf("Aradığınız kelime bulunamadi.\n");
    }
}

int sayiOku() {
    int a;
    FILE* filePtr = NULL;
    filePtr = fopen("sayi.txt","r");
    if(filePtr == NULL) {
        printf("Beklenmedik hata oluştu.Lütfen sayı dosyasını kontrol ediniz.\n");
        return 0;
    }
    
    fscanf(filePtr,"%d",&a);
    fclose(filePtr);
    return a;
}
