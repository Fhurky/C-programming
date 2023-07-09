#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define size 15

float degerBul(float deger,float[],int n);

int main(){
	//
	int i,n,iterasyon=0;
	
	//Denklemi kullanıcıdan alma işlemi
	do{
	printf("\nGireceginiz denklemin en buyuk derecesini giriniz:(max:%d)\t",size);
	scanf("%d", &n);
    }while(n>=size);
    //
    float katsayi[n+1]; 
    
    for(i=0;i<=n;i++){
		katsayi[i]=0;
	}
	i=0;
	
	while(i<=n){
		printf("\n%d.dereceli terimin katsayisini giriniz:  ",n-i);
		scanf("%f", &katsayi[i]);
		i++;
	}
	//
	float delta,hata,baslangic,deger;
	
	i=0;
	
    printf("\nGirdiginiz denklem:\t");
	while(i<=n){
		printf("%.2f(x^%d) ",katsayi[i],n-i);
		i++;
	}
//Gerekli değerlerin kullanıcıdan alınması işlemi	
	printf("\n\nBir baslangic degeri giriniz:\t");
	scanf("%f", &baslangic);
	
	printf("\nBir %cX belirleyiniz\t", 225);
	scanf("%f", &delta);		

	printf("\nHata payini giriniz:\t");
	scanf("%f", &hata);	
//Yaklaşık kök hesabı	
	while(delta>hata){
        while(degerBul(baslangic,katsayi,n)*degerBul(baslangic+delta,katsayi,n)>0){
        	baslangic=baslangic+delta;
        	iterasyon++;
		}
        delta=delta/2;
    }
	
	printf("\n\nKok=%f , %c%f ",baslangic,241,delta);
	printf("\tIterasyon sayisi: %d\n\n\n\n",iterasyon);
	
	system("PAUSE");
	return 0;
}

float degerBul(float deger,float katsayi[],int n){
	//
	int i=0;
	float result=0;
	
	while(i<=n){
		
		result = result + katsayi[i]*pow(deger,n-i);
		i++;	
	}
	
	return result;
}