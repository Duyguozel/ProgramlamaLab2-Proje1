#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define enFazla 10000000

//dijkstra algoritmasini internetten hazir aldik(iki sehir arasi en kisa yol fonksiyonunda kullandik)
int ikiSehirarasiEnkisa(int mesafeMatrisi[82][82],int plaka1,int plaka2)  // plaka1 merkez , plaka2 hedef plaka
{

    int toplamYol[82],ziyaretEdilenler[82],oncekiMesafe[82];
    char gidilenGuzergah[82];
    int maliyet[82][82];
    int i,min,j;
    int enKisaUzaklik;
    int k,l,d=1,sonraki;

    for(i=1; i<82; i++)
    {
        toplamYol[i]=mesafeMatrisi[plaka1][i];
        oncekiMesafe[i]=plaka1;
        ziyaretEdilenler[i]=0;
    }

    ziyaretEdilenler[plaka1]=1;
    toplamYol[plaka1]=0;

    while(d<82)
    {

        enKisaUzaklik=enFazla;

        for(k=1; k<82; k++)
        {
            if(toplamYol[k] <enKisaUzaklik  && !ziyaretEdilenler[k])
            {
                enKisaUzaklik=toplamYol[k];
                sonraki=k;
            }
        }
        ziyaretEdilenler[sonraki]=1;
        for(k=1; k<82; k++)
        {
            if(!ziyaretEdilenler[k])
                if(enKisaUzaklik+mesafeMatrisi[sonraki][k]<toplamYol[k])
                {
                    toplamYol[k]=enKisaUzaklik+mesafeMatrisi[sonraki][k];
                    oncekiMesafe[k]=sonraki;
                }
        }

        d++;
    }
    plaka1=plaka2;
    return toplamYol[plaka2];
}
int ikiSehirarasiYazdir(int mesafeMatrisi[82][82],int plaka1,int plaka2)  // plaka1 merkez , plaka2 hedef plaka
{

    int toplamYol[82],ziyaretEdilenler[82],oncekiMesafe[82];
    char gidilenGuzergah[82];
    int maliyet[82][82];
    int i,min,j;
    int enKisaUzaklik;
    int k,l,d=1,sonraki;

    for(i=1; i<82; i++)
    {
        toplamYol[i]=mesafeMatrisi[plaka1][i];
        oncekiMesafe[i]=plaka1;
        ziyaretEdilenler[i]=0;
    }

    ziyaretEdilenler[plaka1]=1;
    toplamYol[plaka1]=0;

    while(d<82)
    {

        enKisaUzaklik=enFazla;

        for(k=1; k<82; k++)
        {
            if(toplamYol[k] <enKisaUzaklik  && !ziyaretEdilenler[k])
            {
                enKisaUzaklik=toplamYol[k];
                sonraki=k;
            }
        }
        ziyaretEdilenler[sonraki]=1;
        for(k=1; k<82; k++)
        {
            if(!ziyaretEdilenler[k])
                if(enKisaUzaklik+mesafeMatrisi[sonraki][k]<toplamYol[k])
                {
                    toplamYol[k]=enKisaUzaklik+mesafeMatrisi[sonraki][k];
                    oncekiMesafe[k]=sonraki;
                }
        }

        d++;
    }
    int a,adetPlaka2=0;
    for(i=1; i<82; i++)
    {
        if(i!=plaka1 && i==plaka2)
        {
            //printf("%s => %s arasi = %d",sehirler[i],sehirler[plaka1],toplamYol[i]);
            a=toplamYol[i];
            printf("%d=>",plaka2);
            j=i;

            do
            {
                j=oncekiMesafe[j];
                printf("%d=>",j);
            }
            while(j!=plaka1);

        }
    }
    return a;

}
void sirala(int dizi[50], int boyut)
{

    for(int m=0; m<boyut; m++)
    {
        for(int n=0; n<boyut-m-1; n++)
        {
            if(dizi[n]>dizi[n+1])
            {
                int yedek=dizi[n];
                dizi[n]=dizi[n+1];
                dizi[n+1]=yedek;
            }
        }
    }


}
void birinciYol(int guzergah[82], int toplam, int m,int  count)
{
    for(int a=0; a<count-1; a++)
    {
        ikiSehirarasiYazdir(m,guzergah[a+1],guzergah[a]);
    }
    ikiSehirarasiYazdir(m,41,guzergah[count-1]);
    printf("%d\n",toplam);
}
void ikinciYol(int guzergah2[82], int adet2, int m, int toplam2)
{
    ikiSehirarasiYazdir(m,guzergah2[0],41);
    for(int a=0; a<adet2-1; a++)
    {
        ikiSehirarasiYazdir(m,guzergah2[a+1],guzergah2[a]);
    }
    ikiSehirarasiYazdir(m,41,guzergah2[adet2-1]);
    printf("%d\n",toplam2);
}
void ucuncuYol(int guzergah3[82], int toplam3, int m, int count2, int plakalar2[82])
{
    for(int a=0; a<count2-1; a++)
    {
        ikiSehirarasiYazdir(m,guzergah3[a+1],guzergah3[a]);
    }
    ikiSehirarasiYazdir(m,plakalar2[0],guzergah3[count2-1]);
    ikiSehirarasiYazdir(m,41,plakalar2[0]);
    printf("%d\n",toplam3);
}
void enKisa(int m[82][82])
{
    int adet,plaka;
    int sonuc2,toplam2=0,baslangic=41;
    int sonuc3,toplam3=0,baslangic2=41,baslangic3=41;
    int sonuc,j,tut,tut1,i=1,count=1,count2=1;
    int baslangicPlaka=41;
    int u,toplam=0;
    int toplamSonuclar[82];
    int guzergah[82];
    int guzergah2[82];
    int guzergah3[82];
    int n,boyut;
    guzergah[0]=41;
    guzergah3[0]=41;
    int toplamlar[3],c2=0;

    while(1)
    {
        printf("Kac sehre kargo teslimati yapacaksiniz (1-10 arasi):");
        scanf("%d",&adet);
        if(adet>0 && adet<=10)
        {
            break;
        }
        else
            printf("Lutfen 1-10 arasi bir deger giriniz:\n");
    }
    boyut=adet;
    int adet2=adet;
    int plakalar[adet];
    int plakalar2[adet];
    for(j=0; j<adet; j++)
    {
        printf("%d. plakayi giriniz:",j+1);
        scanf("%d",&plaka);
        plakalar[j]=plaka;
        plakalar2[j]=plaka;

    }
    for(u=0; u<=adet+i; u++)
    {
        for(int k=0; k<adet; k++)
        {
            // printf("***%d\n",plakalar[k]);
        }
        for(int k=0; k<adet; k++)
        {
            sonuc=ikiSehirarasiEnkisa(m,plakalar[k],baslangicPlaka);
            //printf("%d ve %d arasi en kisa mesafe=%d\n",baslangicPlaka,plakalar[k],sonuc);
            toplamSonuclar[k]=sonuc;
        }
        sirala(toplamSonuclar,adet);
        for(int k=0; k<adet; k++)
        {
            //printf("%d\n",toplamSonuclar[k]);
        }
        for(int j=0; j<adet; j++)
        {

            if(toplamSonuclar[0]==ikiSehirarasiEnkisa(m,plakalar[j],baslangicPlaka))
            {
                toplam+=toplamSonuclar[0];
                baslangicPlaka=plakalar[j];
                tut=j;
                guzergah[count]=plakalar[j];
                while(tut<adet)
                {
                    plakalar[tut]=plakalar[tut+1];
                    tut++;
                }
                count++;
                i++;
                adet--;
                //printf("\n");
            }


        }

    }
    int b=ikiSehirarasiEnkisa(m,41,guzergah[count-1]);
    //printf("%d\n",b);
    toplam+=b;
    for(n=0; n<boyut; n++)
    {
        guzergah2[n]=plakalar2[n];
        int sonuc2=ikiSehirarasiEnkisa(m,plakalar2[n],baslangic);
        //printf("%d ve %d arasi =%d\n",baslangic,plakalar2[n],sonuc2);
        toplam2+=sonuc2;
        baslangic=plakalar2[n];
    }
    int b2=ikiSehirarasiEnkisa(m,41,plakalar2[boyut-1]);
    // printf("%d\n",b2);
    toplam2+=b2;

    //printf("toplam=%d\n",toplam2);
    // ikinciYol(guzergah2,boyut,m,toplam2);

    int c=1;
    for(u=0; u<=boyut+c; u++)
    {
        for(int k=0; k<boyut; k++)
        {
            //printf("***%d\n",plakalar2[k]);
        }
        for(int k=0; k<boyut; k++)
        {
            sonuc=ikiSehirarasiEnkisa(m,plakalar2[k],baslangic3);
            //printf("%d ve %d arasi en kisa mesafe=%d\n",baslangic3,plakalar2[k],sonuc);
            toplamSonuclar[k]=sonuc;
        }
        sirala(toplamSonuclar,boyut);
        for(int k=0; k<boyut; k++)
        {
            //printf("%d\n",toplamSonuclar[k]);
        }
        for(int b=0; b<boyut; b++)
        {

            if(toplamSonuclar[1]==ikiSehirarasiEnkisa(m,plakalar2[b],baslangic3))
            {
                toplam3+=toplamSonuclar[1];
                baslangic3=plakalar2[b];
                tut1=b;
                guzergah3[count2]=plakalar2[b];
                while(tut1<boyut)
                {
                    plakalar2[tut1]=plakalar2[tut1+1];
                    tut1++;
                }
                count2++;
                c++;
                boyut--;
                //printf("\n");
            }
        }


    }
    //printf("--------%d\n",plakalar2[0]);
    int b3=ikiSehirarasiEnkisa(m,41,guzergah3[count2-1]);//donus yolu
    for(int f=0; f<count2; f++)
    {
        //printf("%d\n",guzergah3[f]);
    }
    //printf("%d\n",b);
    toplam3+=b3;
    //ucuncuYol(guzergah3,toplam3,m,count2, plakalar2);

   if(toplam<toplam2 && toplam<toplam3 && toplam2<=toplam3)
    {
        printf("   1.GUZERGAH    \n");
        birinciYol(guzergah,toplam,m,count);
        printf("   2.GUZERGAH    \n");
        ikinciYol(guzergah2,adet2,m,toplam2);
        printf("   3.GUZERGAH    \n");
        ucuncuYol(guzergah3,toplam3,m,count2, plakalar2);

    }
    else if(toplam<toplam2 && toplam<toplam3 && toplam2>=toplam3)
    {
        printf("   1.GUZERGAH    \n");
        birinciYol(guzergah,toplam,m,count);
        printf("   2.GUZERGAH    \n");
        ucuncuYol(guzergah3,toplam3,m,count2, plakalar2);
        printf("   3.GUZERGAH    \n");
        ikinciYol(guzergah2,adet2,m,toplam2);

    }
    else if(toplam2<toplam && toplam2<toplam3 && toplam<=toplam3)
    {
        printf("   1.GUZERGAH    \n");
        ikinciYol(guzergah2,adet2,m,toplam2);
        printf("   2.GUZERGAH    \n");
        birinciYol(guzergah,toplam,m,count);
        printf("   3.GUZERGAH    \n");
        ucuncuYol(guzergah3,toplam3,m,count2, plakalar2);
    }
    else if(toplam2<toplam && toplam2<toplam3 && toplam>=toplam3)
    {
        printf("   1.GUZERGAH    \n");
        ikinciYol(guzergah2,adet2,m,toplam2);
        printf("   2.GUZERGAH    \n");
        ucuncuYol(guzergah3,toplam3,m,count2, plakalar2);
        printf("   3.GUZERGAH    \n");
        birinciYol(guzergah,toplam,m,count);

    }
    else if(toplam3<toplam && toplam3<toplam2 && toplam<=toplam2)
    {
        printf("   1.GUZERGAH    \n");
        ucuncuYol(guzergah3,toplam3,m,count2, plakalar2);
        printf("   2.GUZERGAH    \n");
        birinciYol(guzergah,toplam,m,count);
        printf("   3.GUZERGAH    \n");
        ikinciYol(guzergah2,adet2,m,toplam2);


    }
    else if(toplam3<toplam && toplam3<toplam2 && toplam2<=toplam)
    {
        printf("   1.GUZERGAH    \n");
        ucuncuYol(guzergah3,toplam3,m,count2, plakalar2);
        printf("   2.GUZERGAH    \n");
        ikinciYol(guzergah2,adet2,m,toplam2);
        printf("   3.GUZERGAH    \n");
        birinciYol(guzergah,toplam,m,count);

    }


}
int main()
{
    FILE *dosya1 = fopen("sehirPlakalari.txt","r");
    char *plaka; // strtok kullandigimiz icin char alip atoi ile int e ceviricez
    char *sehirAdi;
    char cumle[100];
    char *ayrac=",";
    int sehirSayisi=0;
    char matris[82][82]; // plaka ve sehiradlarini tutmasi icin matris olusturduk
    int sayiPlaka; // char alip cevirdigimiz degeri tutmasi icin
    if(dosya1==NULL)
    {
        printf("Dosya acilamadi.");
        exit(1);
    }
    else
    {

        while(fgets(cumle,100,dosya1)!=NULL)
        {

            plaka=strtok(cumle,ayrac);
            sayiPlaka=atoi(plaka);
            sehirAdi=strtok(NULL,ayrac);
            strcpy(matris[sayiPlaka],sehirAdi);
            printf("%d %s",sayiPlaka,matris[sayiPlaka]); // sayiPlaka index tutar ayni index ve sehir adlarini birbirne bagladik
            sehirSayisi++;

        }


    }
    printf("\n");
    int i;
    for(i=1; i<82; i++)
    {
        //printf("%d %s",i,matris[i]); // plaka ve sehir isimleri matriste tutuluyor
    }
    FILE *dosya2=fopen("mesafeler.txt","r");
    char *sehir1;
    char *sehir2;
    char *uzaklik; // strtok kullandigimiz icin char yaptik daha sonra  atoi ile int e cevirilecek
    int sehir1Plaka;
    int sehir2Plaka;
    int komsuUzaklik;
    int komsulukMatrisi[82][82];
    char *ayrac2="-";
    int tut1;
    int tut2;


    char cumle2[200]; // satir satis okuma yapilacak
    if(dosya2==NULL)
    {
        printf("Dosya acilamadi.");
        exit(1);
    }
    else
    {
        for(int m=1; m<82; m++)
        {
            for(int l=1; l<82; l++)
            {

                komsulukMatrisi[m][l]=enFazla;

            }
        }
        while(fgets(cumle2,200,dosya2)!=NULL)
        {

            sehir1=strtok(cumle2,ayrac2);
            sehir2=strtok(NULL,ayrac2);
            uzaklik=strtok(NULL,ayrac2);
            komsuUzaklik=atoi(uzaklik);

            for(int k=1; k<82; k++)
            {
                if(strstr(matris[k],sehir1)!=NULL)
                {
                    tut1=k;

                }
            }
            for(int l=1; l<82; l++)
            {
                if(strstr(matris[l],sehir2)!=NULL)
                {
                    tut2=l;

                }
            }



            komsulukMatrisi[tut1][tut2]=komsulukMatrisi[tut2][tut1]=komsuUzaklik;// Mesela Adana-Hayat ve Hatay-Adana arasi uzaklik aynidir.
            printf("[%d][%d] = %d\n",tut1,tut2,komsuUzaklik);

        }
    }

    enKisa(komsulukMatrisi);




    fclose(dosya1);
    fclose(dosya2);




    return 0;
}
