
#include <stdio.h>
#include <stdlib.h>
struct kayit
{
    int OgrenciNo;
    int DersKodu;
    int Puan;
};
typedef struct kayit kayit;
struct Indexx
{
    int OgrenciNo;
    int Adres;
};
typedef struct Indexx Indexx;
//Index Dosyasi Olustur Fonksiyonu Veri Dosyasindan Veri Alýp Index Dosyasi Olusturur.
void Index_Dosyasi_Olustur(FILE *dosya,kayit *Veri_Dizisi,Indexx *Index_Dizisi,kayit ara);
//Kayit Ekle Fonksiyonu Veri Dosyasina Ve Index Dosyasina Girilen Ogrenci Numarasini , Dersi Ve Notunu Ekler.
int Kayit_Ekle(FILE *dosya,kayit gir,kayit *Veri_Dizisi,Indexx *Index_Dizisi,kayit ara);
//Kayit Bul Fonksiyonu Veri Dosyasinda Ve Index Dosyasinda Girilen Ogrenci Numarasini Arar.
void Kayit_Bul(FILE *dosya,kayit *Veri_Dizisi,Indexx *Index_Dizisi,kayit ara);
//Kayit Sil Fonksiyonu Veri Dosyasindan Ve Index Dosyasindan Girilen Ogrenci Numarasini Ve Dersi Siler.
void Kayit_Sil(FILE *dosya,kayit ara,kayit *Veri_Dizisi,kayit *Index_Dizisi);
//Kayit Guncelle Fonksiyonu Veri Dosyasindaki Girilen Ogrenci Numarasindaki Ve Dersin Notunu Gunceller.
void Kayit_Guncelle(FILE *dosya,kayit ara,kayit *Veri_Dizisi,kayit *Index_Dizisi);
//Veri Dosyasini Goster Fonksiyonu Veri Dosyasini Acar Ve Ekrana Yazar.
int Veri_Dosyasini_Goster(FILE *dosya,kayit *Veri_Dizisi,kayit ara);
// Index Dosyasini Goster Fonksiyonu Index Dosyasini Acar Ve Ekrana Yazar.
void Index_Dosyasini_Goster(FILE *dosya,Indexx *Index_Dizisi,kayit *Veri_Dizisi,Indexx Index_ara,kayit ara);
//Index Dosyasini Sil Fonksiyonu Index Dosyasini Bellekten Siler.
void Index_Dosyasini_Sil();
//Kisi Sayisini Ogren Fonksiyonu Veri Dosyasindaki Kayitlardan Kac Kayit Oldugunu Bulur.
int Kisi_Sayisi_Ogren(FILE *dosya,kayit *Veri_Dizisi,kayit ara);
//Index Dosyasini Guncelle Fonksiyonu Veri Dosyasindaki Yapýlan Degisikliklerden Sonra Index Dosyasinida Ona Gore Gunceller.
void Index_Dosyasini_Guncelle(FILE *dosya,kayit *Veri_Dizisi,Indexx *Index_Dizisi,kayit ara);
int main()
{
    int secim;
    int kisisayisi;
    kayit gir;
    kayit ara;
    FILE *dosya;
    kayit *Veri_Dizisi;
    Indexx Index_ara;
    Indexx *Index_Dizisi;
    Veri_Dizisi=(kayit*)malloc(sizeof(kayit)*100);
    Index_Dizisi=(Indexx*)malloc(sizeof(Indexx)*100);
    while(1)
    {
        printf("\t\t-------------------  1 - Index Dosyasi Olustur   ---------------------\n");
        printf("\t\t-------------------  2 - Kayit Ekle              ---------------------\n");
        printf("\t\t-------------------  3 - Kayit Bul               ---------------------\n");
        printf("\t\t-------------------  4 - Kayit Sil               ---------------------\n");
        printf("\t\t-------------------  5 - Kayit Guncelle          ---------------------\n");
        printf("\t\t-------------------  6 - Veri Dosyasini Goster   ---------------------\n");
        printf("\t\t-------------------  7 - Index Dosyasini Goster  ---------------------\n");
        printf("\t\t-------------------  8 - Index Dosyasini Sil     ---------------------\n");
        printf("\t\t-------------------  9 - Cikis                   ---------------------\n");
        printf("\t\t-------------------  Lutfen Seciminizi Giriniz : ");
        scanf("%d",&secim);
        printf("\n");
        if(secim==1)
        {
            Index_Dosyasi_Olustur(dosya,Veri_Dizisi,Index_Dizisi,ara);
        }
        else if(secim==2)
        {
            kisisayisi=Kayit_Ekle(dosya,gir,Veri_Dizisi,Index_Dizisi,ara);
        }
        else if(secim==3)
        {
            Kayit_Bul(dosya,Veri_Dizisi,Index_Dizisi,ara);
        }
        else if(secim==4)
        {
            Kayit_Sil(dosya,ara,Veri_Dizisi,Index_Dizisi);
        }
        else if(secim==5)
        {
            Kayit_Guncelle(dosya,ara,Veri_Dizisi,Index_Dizisi);
        }
        else if(secim==6)
        {
            kisisayisi=Veri_Dosyasini_Goster(dosya,Veri_Dizisi,ara);
        }
        else if(secim==7)
        {
            Index_Dosyasini_Goster(dosya,Index_Dizisi,Veri_Dizisi,Index_ara,ara);
        }
        else if(secim==8)
        {
            Index_Dosyasini_Sil();
        }
        else if(secim==9)
        {
            printf("--> Program Bitirildi.\n\n");
            break;
        }
    }
    return 0;
}
void Index_Dosyasi_Olustur(FILE *dosya,kayit *Veri_Dizisi,Indexx *Index_Dizisi,kayit ara)
{
    FILE *dosya1;
    dosya=fopen("Veri_Dosyasi.bin","rb");
    dosya1=fopen("Index_Dosyasi.txt","w");
    int kisisayisi=Kisi_Sayisi_Ogren(dosya,Veri_Dizisi,ara);
    int Tut_Ogrenci_No,Tut_Adres;
    // Veri Dosyasindaki Verileri Alýp Dinamik Diziye Aktarýr.
    while(!feof(dosya))
    {
        fscanf(dosya,"%d , %d , %d",&ara.OgrenciNo,&ara.DersKodu,&ara.Puan);
        if(Veri_Dizisi[kisisayisi-1].OgrenciNo==ara.OgrenciNo && Veri_Dizisi[kisisayisi-1].DersKodu==ara.DersKodu &&Veri_Dizisi[kisisayisi-1].Puan==ara.Puan)
        {
            continue;
        }
        Veri_Dizisi[kisisayisi].OgrenciNo=ara.OgrenciNo;
        Veri_Dizisi[kisisayisi].DersKodu=ara.DersKodu;
        Veri_Dizisi[kisisayisi].Puan=ara.Puan;
    }
    for(int k=0; k<kisisayisi; k++)
    {
        Index_Dizisi[k].OgrenciNo=Veri_Dizisi[k].OgrenciNo;
        Index_Dizisi[k].Adres=&Veri_Dizisi[k].OgrenciNo;
    }
    for(int a=0; a<kisisayisi-1; a++)
    {
        for(int k=0; k<kisisayisi-1; k++)
        {
            if(Index_Dizisi[k].OgrenciNo>Index_Dizisi[k+1].OgrenciNo)
            {
                Tut_Ogrenci_No=Index_Dizisi[k].OgrenciNo;
                Tut_Adres=Index_Dizisi[k].Adres;
                Index_Dizisi[k].OgrenciNo=Index_Dizisi[k+1].OgrenciNo;
                Index_Dizisi[k].Adres=Index_Dizisi[k+1].Adres;
                Index_Dizisi[k+1].OgrenciNo=Tut_Ogrenci_No;
                Index_Dizisi[k+1].Adres=Tut_Adres;
            }
        }
    }
    for(int k=0; k<kisisayisi; k++)
    {
        fprintf(dosya1,"%d , %d\n",Index_Dizisi[k].OgrenciNo,Index_Dizisi[k].Adres);
    }
    fclose(dosya);
    fclose(dosya1);
    printf("--> Index Dosyasi Olusturuldu.\n\n");
}
int Kayit_Ekle(FILE *dosya,kayit gir,kayit *Veri_Dizisi,Indexx *Index_Dizisi,kayit ara)
{
    int kisisayisi;
    kisisayisi=Kisi_Sayisi_Ogren(dosya,Veri_Dizisi,ara);
    if(dosya=fopen("Index_Dosyasi.txt","r"))
    {
        fclose(dosya);
        printf("Eklenecek Ogrencinin Numarasini Giriniz : \n");
        scanf("%d",&gir.OgrenciNo);
        printf("Eklenecek Ogrencinin Ders Kodunu Giriniz : \n");
        scanf("%d",&gir.DersKodu);
        printf("Eklenecek Ogrencinin Puanini Giriniz : \n");
        scanf("%d",&gir.Puan);
        dosya=fopen("Veri_Dosyasi.bin","ab");
        fprintf(dosya,"%d , %d , %d\n",gir.OgrenciNo,gir.DersKodu,gir.Puan);
        fclose(dosya);
        printf("\n--> Kayit Eklendi.\n\n");
        Index_Dosyasini_Guncelle(dosya,Veri_Dizisi,Index_Dizisi,ara);
    }
    else
    {
        printf("\n--> Index Dosyasi Bulunamadigi Icin Kayit Yapilamaz Ilk Once Index Dosyasi Olusturun.\n\n");
    }
    return kisisayisi;
}
void Kayit_Bul(FILE *dosya,kayit *Veri_Dizisi,Indexx *Index_Dizisi,kayit ara)
{
    int Ogrenci_Numarasi_arama;
    int kontrol=0;
    int kisisayisi=Kisi_Sayisi_Ogren(dosya,Veri_Dizisi,ara);
    int sondeger=kisisayisi;
    Indexx *Index_kontrol;
    Index_kontrol=(Indexx*)malloc(sizeof(Indexx)*50);
    if(dosya=fopen("Index_Dosyasi.txt","r"))
    {
        fclose(dosya);
        Index_Dosyasini_Guncelle(dosya,Veri_Dizisi,Index_Dizisi,ara);
        printf("Aramak Istediginiz Ogrenci Numarasini Giriniz.\n");
        scanf("%d",&Ogrenci_Numarasi_arama);
        for(int k=0; k<kisisayisi; k++)
        {
            if(k>sondeger)
            {
                break;
            }
            else
            {
                if(Index_Dizisi[k].OgrenciNo==Ogrenci_Numarasi_arama)
                {
                    kontrol++;
                }
                if(k!=sondeger && Index_Dizisi[sondeger].OgrenciNo==Ogrenci_Numarasi_arama)
                {
                    kontrol++;
                }
            }
            sondeger--;
        }
        if(kontrol==0)
        {
            printf("\n--> Girilen Ogrenci Numarasinda Kayit Bulunamadi.\n\n");
        }
        else
        {
            printf("\n\n\t\t\tBULUNAN KAYITLAR : \n");
            printf("\t_________________________________________________________\n\n");
            printf("\t\tIndex Dosyasinda Ogrenciye Ait Kayitlar : \n");
            printf("\t\t__________________________\n");
            printf("\t\t     Ogrenci  |   Adres  |\n");
            printf("\t\t     Numarasi |          |\n");
            printf("\t\t__________________________\n\n");
            // Index Dosyasinda Kayit Bulma.
            kontrol=0;
            sondeger=kisisayisi;
            for(int k=0; k<kisisayisi; k++)
            {
                if(k>sondeger)
                {
                    break;
                }
                else
                {
                    if(Index_Dizisi[k].OgrenciNo==Ogrenci_Numarasi_arama)
                    {
                        Index_kontrol[kontrol].OgrenciNo=Index_Dizisi[k].OgrenciNo;
                        Index_kontrol[kontrol].Adres=Index_Dizisi[k].Adres;
                        kontrol++;
                        printf("\t\t%d-> %d , %d\n",k+1,Index_Dizisi[k].OgrenciNo,Index_Dizisi[k].Adres);
                    }
                    if(k!=sondeger && Index_Dizisi[sondeger].OgrenciNo==Ogrenci_Numarasi_arama)
                    {
                        Index_kontrol[kontrol].OgrenciNo=Index_Dizisi[sondeger].OgrenciNo;
                        Index_kontrol[kontrol].Adres=Index_Dizisi[sondeger].Adres;
                        kontrol++;
                        printf("\t\t%d-> %d , %d\n",sondeger,Index_Dizisi[sondeger].OgrenciNo,Index_Dizisi[sondeger].Adres);
                    }
                }
                sondeger--;
            }
            // Kayitlari Siraya Sokar.
            printf("\n\t_________________________________________________________\n\n");
            printf("\t\tVeri Dosyasinda Ogrenciye Ait Kayitlar : \n");
            printf("\t\t_________________________\n");
            printf("\t\t  Ogrenci  | Ders | Puan|\n");
            printf("\t\t  Numarasi | Kodu |     |\n");
            printf("\t\t_________________________\n\n");
            Indexx tut;
            for(int a=0; a<kontrol-1; a++)
            {
                for(int k=0; k<kontrol-1; k++)
                {
                    if(Index_kontrol[k].Adres>Index_kontrol[k+1].Adres)
                    {
                        tut.OgrenciNo=Index_kontrol[k].OgrenciNo;
                        tut.Adres=Index_kontrol[k].Adres;
                        Index_kontrol[k].OgrenciNo=Index_kontrol[k+1].OgrenciNo;
                        Index_kontrol[k].Adres=Index_kontrol[k+1].Adres;
                        Index_kontrol[k+1].OgrenciNo=tut.OgrenciNo;
                        Index_kontrol[k+1].Adres=tut.Adres;
                    }
                }
            }
            // Veri Dosyasinda Kayit Bulma.
            int kontrol2=0;
            for(int a=0; a<kontrol; a++)
            {
                for(int k=0; k<kisisayisi; k++)
                {
                    if(Index_kontrol[kontrol2].Adres==&Veri_Dizisi[k].OgrenciNo)
                    {
                        printf("\t\t%d-> %d , %d , %d\n",k+1,Veri_Dizisi[k].OgrenciNo,Veri_Dizisi[k].DersKodu,Veri_Dizisi[k].Puan);
                        if(kontrol2!=kontrol)
                        {
                            kontrol2++;
                        }
                    }
                }
            }
            printf("\n\t_________________________________________________________\n\n");
        }
    }
    else
    {
        printf("--> Index Dosyasi Olusturulmadigi Icin Yapilamaz Ilk Once Index Dosyasi Olusturun.\n\n");
    }
}
void Kayit_Sil(FILE *dosya,kayit ara,kayit *Veri_Dizisi,kayit *Index_Dizisi)
{
    int Ogrenci_Numarasi_arama;
    int Ders_Kodu_arama;
    int kayit_varmi=0;
    int silinecekdeger;
    int kisisayisi=Kisi_Sayisi_Ogren(dosya,Veri_Dizisi,ara);
    if(dosya=fopen("Index_Dosyasi.txt","r"))
    {
        fclose(dosya);
        printf("Silmek Istediginiz Ogrenci Numarasini Giriniz.\n");
        scanf("%d",&Ogrenci_Numarasi_arama);
        printf("Silmek Istediginiz Dersin Kodunu Giriniz.\n");
        scanf("%d",&Ders_Kodu_arama);
        for(int k=0; k<kisisayisi; k++)
        {
            if(Veri_Dizisi[k].OgrenciNo==Ogrenci_Numarasi_arama && Veri_Dizisi[k].DersKodu==Ders_Kodu_arama)
            {
                silinecekdeger=k;
                kayit_varmi++;
            }
        }
        if(kayit_varmi==0)
        {
            printf("Girilen Ogrenci Numarasi Ve Ders Kodunda Kayit Bulunamadi.\n\n");
        }
        else
        {
            dosya=fopen("Veri_Dosyasi.bin","wb");
            for(int k=0; k<kisisayisi; k++)
            {
                if(silinecekdeger!=k)
                {
                    fprintf(dosya,"%d , %d , %d\n",Veri_Dizisi[k].OgrenciNo,Veri_Dizisi[k].DersKodu,Veri_Dizisi[k].Puan);
                }
            }
            fclose(dosya);
            printf("\n--> Kayit Silindi.\n\n");
            Index_Dosyasini_Guncelle(dosya,Veri_Dizisi,Index_Dizisi,ara);
        }
    }
    else
    {
        printf("--> Index Dosyasi Olusturulmadigi Icin Yapilamaz Ilk Once Index Dosyasi Olusturun.\n\n");
    }
}
void Kayit_Guncelle(FILE *dosya,kayit ara,kayit *Veri_Dizisi,kayit *Index_Dizisi)
{
    int Ogrenci_Numarasi_arama;
    int Ders_Kodu_arama;
    int Puan_Degistir;
    int kontrol=0;
    int kisisayisi=Kisi_Sayisi_Ogren(dosya,Veri_Dizisi,ara);
    printf("Kaydini Guncellemek Istediginiz Ogrenci Numarasini Giriniz : \n");
    scanf("%d",&Ogrenci_Numarasi_arama);
    printf("Kaydini Guncellemek Istediginiz Ders Kodunu Giriniz : \n");
    scanf("%d",&Ders_Kodu_arama);
    for(int k=0; k<kisisayisi; k++)
    {
        if(Veri_Dizisi[k].OgrenciNo==Ogrenci_Numarasi_arama && Veri_Dizisi[k].DersKodu==Ders_Kodu_arama)
        {
            printf("%d Numarali Ogrencinin %d Kodlu Dersinin Puani Kac Olarak Duzeltilsin : \n",Ogrenci_Numarasi_arama,Ders_Kodu_arama);
            scanf("%d",&Puan_Degistir);
            Veri_Dizisi[k].Puan=Puan_Degistir;
            kontrol++;
            printf("\n--> Kayit Guncellendi.\n\n");
        }
    }
    if(kontrol==0)
    {
        printf("\n--> Girilen Ogrenci Numarasi Ve Ders Kodunda Kayit Bulunamadi.\n\n");
    }
    else
    {
        dosya=fopen("Veri_Dosyasi.bin","wb");
        for(int k=0; k<kisisayisi; k++)
        {
            fprintf(dosya,"%d , %d , %d\n",Veri_Dizisi[k].OgrenciNo,Veri_Dizisi[k].DersKodu,Veri_Dizisi[k].Puan);
        }
        fclose(dosya);
    }
}
int Veri_Dosyasini_Goster(FILE *dosya,kayit *Veri_Dizisi,kayit ara)
{
    dosya=fopen("Veri_Dosyasi.bin","rb");
    int kisisayisi=0;
    while(!feof(dosya))
    {
        fscanf(dosya,"%d , %d , %d",&ara.OgrenciNo,&ara.DersKodu,&ara.Puan);
        if(Veri_Dizisi[kisisayisi-1].OgrenciNo==ara.OgrenciNo && Veri_Dizisi[kisisayisi-1].DersKodu==ara.DersKodu &&Veri_Dizisi[kisisayisi-1].Puan==ara.Puan)
        {
            continue;
        }
        Veri_Dizisi[kisisayisi].OgrenciNo=ara.OgrenciNo;
        Veri_Dizisi[kisisayisi].DersKodu=ara.DersKodu;
        Veri_Dizisi[kisisayisi].Puan=ara.Puan;
        kisisayisi++;
    }
    printf("  Listede %d Kayit Var\n",kisisayisi);
    printf("  _________________________\n");
    printf("    Ogrenci  | Ders | Puan|\n");
    printf("    Numarasi | Kodu |     |\n");
    printf("  _________________________\n\n");
    for(int a=0; a<kisisayisi; a++)
    {
        printf("  %d-> %d , %d , %d \n",a+1,Veri_Dizisi[a].OgrenciNo,Veri_Dizisi[a].DersKodu,Veri_Dizisi[a].Puan);
    }
    fclose(dosya);
    return kisisayisi;
}
void Index_Dosyasini_Goster(FILE *dosya,Indexx *Index_Dizisi,kayit *Veri_Dizisi,Indexx Index_ara,kayit ara)
{
    Indexx Index_Yazdirma;
    int kisisayisi=Kisi_Sayisi_Ogren(dosya,Veri_Dizisi,ara);
    dosya=fopen("Index_Dosyasi.txt","r");
    if(dosya!=0)
    {
        printf("  Listede %d Kayit Var\n",kisisayisi);
        printf("  __________________________\n");
        printf("       Ogrenci  |   Adres  |\n");
        printf("       Numarasi |          |\n");
        printf("  __________________________\n\n");
        for(int k=0; k<kisisayisi; k++)
        {
            fscanf(dosya,"%d , %d",&Index_ara.OgrenciNo,&Index_ara.Adres);
            printf("  %d-> %d , %d\n",k+1,Index_ara.OgrenciNo,Index_ara.Adres);
        }
        fclose(dosya);
    }
    else
    {
        printf("Index Dosyasi Bulanamadi.\n\n");
    }
}
void Index_Dosyasini_Sil()
{
    // Girilen Dosyayi Silmek Icin Kullanilan Ozel Fonksiyon.
    remove("Index_Dosyasi.txt");
    printf("--> Index Dosyasi Silindi.\n\n");
}
int Kisi_Sayisi_Ogren(FILE *dosya,kayit *Veri_Dizisi,kayit ara)
{
    dosya=fopen("Veri_Dosyasi.bin","rb");
    int kisisayisi=0;
    while(!feof(dosya))
    {
        fscanf(dosya,"%d , %d , %d",&ara.OgrenciNo,&ara.DersKodu,&ara.Puan);
        if(Veri_Dizisi[kisisayisi-1].OgrenciNo==ara.OgrenciNo && Veri_Dizisi[kisisayisi-1].DersKodu==ara.DersKodu &&Veri_Dizisi[kisisayisi-1].Puan==ara.Puan)
        {
            continue;
        }
        Veri_Dizisi[kisisayisi].OgrenciNo=ara.OgrenciNo;
        Veri_Dizisi[kisisayisi].DersKodu=ara.DersKodu;
        Veri_Dizisi[kisisayisi].Puan=ara.Puan;
        kisisayisi++;
    }
    fclose(dosya);
    return kisisayisi;
}
void Index_Dosyasini_Guncelle(FILE *dosya,kayit *Veri_Dizisi,Indexx *Index_Dizisi,kayit ara)
{
    FILE *dosya1;
    dosya=fopen("Veri_Dosyasi.bin","rb");
    dosya1=fopen("Index_Dosyasi.txt","w");
    int kisisayisi=Kisi_Sayisi_Ogren(dosya,Veri_Dizisi,ara);
    int Tut_Ogrenci_No,Tut_Adres;
    while(!feof(dosya))
    {
        fscanf(dosya,"%d , %d , %d",&ara.OgrenciNo,&ara.DersKodu,&ara.Puan);
        if(Veri_Dizisi[kisisayisi-1].OgrenciNo==ara.OgrenciNo && Veri_Dizisi[kisisayisi-1].DersKodu==ara.DersKodu &&Veri_Dizisi[kisisayisi-1].Puan==ara.Puan)
        {
            continue;
        }
        Veri_Dizisi[kisisayisi].OgrenciNo=ara.OgrenciNo;
        Veri_Dizisi[kisisayisi].DersKodu=ara.DersKodu;
        Veri_Dizisi[kisisayisi].Puan=ara.Puan;
    }
    for(int k=0; k<kisisayisi; k++)
    {
        Index_Dizisi[k].OgrenciNo=Veri_Dizisi[k].OgrenciNo;
        Index_Dizisi[k].Adres=&Veri_Dizisi[k].OgrenciNo;
    }
    for(int a=0; a<kisisayisi-1; a++)
    {
        for(int k=0; k<kisisayisi-1; k++)
        {
            if(Index_Dizisi[k].OgrenciNo>Index_Dizisi[k+1].OgrenciNo)
            {
                Tut_Ogrenci_No=Index_Dizisi[k].OgrenciNo;
                Tut_Adres=Index_Dizisi[k].Adres;
                Index_Dizisi[k].OgrenciNo=Index_Dizisi[k+1].OgrenciNo;
                Index_Dizisi[k].Adres=Index_Dizisi[k+1].Adres;
                Index_Dizisi[k+1].OgrenciNo=Tut_Ogrenci_No;
                Index_Dizisi[k+1].Adres=Tut_Adres;
            }
        }
    }
    for(int k=0; k<kisisayisi; k++)
    {
        fprintf(dosya1,"%d , %d\n",Index_Dizisi[k].OgrenciNo,Index_Dizisi[k].Adres);
    }
    fclose(dosya);
    fclose(dosya1);
    printf("--> Index Dosyasi Guncellendi.\n\n");
}
