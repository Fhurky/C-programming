#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int i,j,k,karar=0,tmp;
	int matris_boyut,counter=0;
	char metin[5000];
	char harfler[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	
	printf("\n----------HILL SIFRELEME ALGORITMASI!!!----------");
	
	printf("\n\n\tSIFRELEME :1\tDESIFRELEME:0\n");
	scanf("%d", &karar);
	
if(karar==0){
	
//matrisi kullanıcıdan alma 
	printf("\n\nSifresi cozulecek metni girin: \n\n");
	scanf("%s", metin);
	
//harf sayisini hesaplama

	int harf_sayisi=0;	
	while(metin[i]!='\0'){
		i++;
		harf_sayisi++;
	}
//eğer tek sayıda harf varsa en sona bir harf ekleme ve bir sonraki karakteri null yapma	
	if(harf_sayisi%2!=0){
		metin[harf_sayisi]='A';
		metin[harf_sayisi+1]='\0';
		harf_sayisi=harf_sayisi+1;
	}	
//anahtar matrisi kullanicidan alma	
    matris_boyut=2;
	float anahtar_matris[2][2],det=0;
	
//Bundan sonraki aşamada uygun bir matris istenir

 	printf("\nAnahtar kare matrisi giriniz...\n");	
	
	for(i=0;i<matris_boyut;i++){
		for(j=0;j<matris_boyut;j++){
			printf("%d. satir %d.sutun : ",i+1,j+1);
			scanf("%f", &anahtar_matris[i][j]);
		}
	}
	
	det = anahtar_matris[0][0] * anahtar_matris[1][1] - anahtar_matris[1][0] * anahtar_matris[0][1];
	
	float arac;	
//sifre cozmeye uygun matrisin temelini olsuturma islemi	
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			if(i!=j){
				anahtar_matris[i][j] = -1*anahtar_matris[i][j];
			}
		}
	}	
	arac=anahtar_matris[0][0];
	anahtar_matris[0][0] = anahtar_matris[1][1];
	anahtar_matris[1][1] = arac;		
//Uygun matrisin olusturulması için adj. matrisin katsayisini bulma islemi  
    int katsayi=0,k=0;
    
    while(det*katsayi != (26*k+1)){
        if(det<0){
        	if(det*katsayi > (26*k+1)){
        		k++;
			}
			katsayi--;
		}
		else{				
			if(det*katsayi > (26*k+1)){
				k++;
			}
			katsayi++;
		}
	}
//Uygun katsayi bulunduktan sonra temel matrise entegre edilme islemi(Mod almaya benzer bir islem yapılıyor çünkü düz mod alma islemi float değerler icin çalısmıyor)
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			anahtar_matris[i][j]=anahtar_matris[i][j]*katsayi;
			if(anahtar_matris[i][j] > 0){
				while(anahtar_matris[i][j] > 26){
					anahtar_matris[i][j]=anahtar_matris[i][j]-26;
				}
			}
			else{
				while(anahtar_matris[i][j]<0){
					anahtar_matris[i][j] = anahtar_matris[i][j]+26;
				}
			}
		}
	}
//
    char matris_ikili[harf_sayisi/2][2];
	int matris_sayi_ikili[harf_sayisi/2][2];	
	i=0,j=0;
	
	while(metin[i]!='\0'){    	
		matris_ikili[j][0] = metin[i];
		matris_ikili[j][1] = metin[i+1];	
		j=j+1;
		i=i+2;
	}	
	
	for(i=0;i<harf_sayisi/2;i++){
		for(j=0;j<2;j++){
			matris_sayi_ikili[i][j] = matris_ikili[i][j]-65;
		}
	}

//sifreli metnin sayısal karşılığının bulunması
  
  	int sifreli_metin_sayi[harf_sayisi][2];
  	
  	for(i=0;i<harf_sayisi;i++){
  		sifreli_metin_sayi[i][0]=0;
  		sifreli_metin_sayi[i][1]=0;
	}
  	
    for(i=0;i<harf_sayisi/2;i++){
    	for(j=0;j<2;j++){
    		sifreli_metin_sayi[i][j] = matris_sayi_ikili[i][0] * anahtar_matris[0][j] + matris_sayi_ikili[i][1] * anahtar_matris[1][j]; 
			sifreli_metin_sayi[i][j]=sifreli_metin_sayi[i][j]%26;
		}
	}
//sifreli metnin karakter karşılığını ekrana yazdırma işlemi	
	printf("\n\nSifresi cozulmus asil metin :");
	for(i=0;i<harf_sayisi/2;i++){
		for(j=0;j<2;j++){
			printf("%c", harfler[sifreli_metin_sayi[i][j]]);
		}
	}	
}

else if(karar==1){

//metni kullanıcıdan alma

	printf("\n\nSifrelenecek metni giriniz(Bosluksuz ve buyuk harfler ile): \n\n");
	scanf("%s", metin);
	
//harf sayisini hesaplama

	int harf_sayisi=0;	
	while(metin[i]!='\0'){
		i++;
		harf_sayisi++;
	}
//eğer tek sayıda harf varsa en sona bir harf ekleme ve bir sonraki karakteri null yapma	
	if(harf_sayisi%2!=0){
		metin[harf_sayisi]='A';
		metin[harf_sayisi+1]='\0';
		harf_sayisi=harf_sayisi+1;
	}	
//anahtar matrisi kullanicidan alma	
    matris_boyut=2;

	float anahtar_matris[2][2];	
	printf("\nAnahtar kare matrisi giriniz...(Matris determinanti tek sayi ve 26'dan kucuk olmali)\n");	
	
	for(i=0;i<matris_boyut;i++){
		for(j=0;j<matris_boyut;j++){
			printf("%d. satir %d.sutun : ",i+1,j+1);
			scanf("%f", &anahtar_matris[i][j]);
		}
	}
	
	char matris_ikili[harf_sayisi/2][2];
	float matris_sayi_ikili[harf_sayisi/2][2];
//Gerekli aracı matrisleri olusturma islemi		
	i=0,j=0;	
	while(metin[i]!='\0'){    	
		matris_ikili[j][0]=metin[i];
		matris_ikili[j][1]=metin[i+1];	
		j=j+1;
		i=i+2;
	}
	
	for(i=0;i<harf_sayisi/2;i++){
		for(j=0;j<2;j++){
			matris_sayi_ikili[i][j]=matris_ikili[i][j]-65;
		}
	}
	printf("\n\n");
//sifreli metnin sayısal karşılığının bulunması 
  	int sifreli_metin_sayi[harf_sayisi][2];
  	
  	for(i=0;i<harf_sayisi;i++){
  		sifreli_metin_sayi[i][0]=0;
  		sifreli_metin_sayi[i][1]=0;
	}
  	
    for(i=0;i<harf_sayisi/2;i++){
    	for(j=0;j<2;j++){
    		sifreli_metin_sayi[i][j] = matris_sayi_ikili[i][0] * anahtar_matris[0][j] + matris_sayi_ikili[i][1] * anahtar_matris[1][j]; 
			sifreli_metin_sayi[i][j]=sifreli_metin_sayi[i][j]%26;
			counter++;	
		}
	}	
//sifreli metnin karakter karşılığını ekrana yazdırma işlemi	
	printf("\n\nSifrelenmis metin :");
	for(i=0;i<harf_sayisi/2;i++){
		for(j=0;j<2;j++){
			printf("%c", harfler[sifreli_metin_sayi[i][j]]);
		}
	}
	printf("\nIslem sayisi: %d",counter);
}	


	return 0;
}


