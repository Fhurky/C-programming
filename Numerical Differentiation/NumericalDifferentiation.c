#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define size 15

float degerBul(float deger,float[],int n);

int main(){
	
	int i,n,karar;
	float h,x;
	
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
	
	
	//Merkezi,ileri ve geri fark ayrımı
	
	printf("\nHangi fark sonucunu gormek istiyorsunuz? Tuslayiniz...\nMerkezi:0  Ileri:1,  Geri:2\n");
	scanf("%d", &karar);
	
	
if(karar==1){
	
	//Baslangıç ve h değerlerinin kullanıcıdan alınması
	
	printf("\nTurev noktasini seçiniz(X0):  ");
	scanf("%f", &x);
	
	printf("\n'h' degisim miktarini seciniz:  ");
	scanf("%f", &h);
		
	printf("\n%f",(degerBul(x+h,katsayi,n)-degerBul(x,katsayi,n))/h);	
}
else if(karar==0){
	
	//Baslangıç ve h değerlerinin kullanıcıdan alınması
	
	printf("\nTurev noktasini seçiniz(X0):  ");
	scanf("%f", &x);
	
	printf("\n'h' degisim miktarini seciniz:  ");
	scanf("%f", &h);
		
	printf("\n%f",(0.5*degerBul(x+h,katsayi,n)-0.5*degerBul(x-h,katsayi,n))/h);	
	
	
}
else if(karar==2){
	
	//Baslangıç ve h değerlerinin kullanıcıdan alınması
	
	printf("\nTurev noktasini seçiniz(X0):  ");
	scanf("%f", &x);
	
	printf("\n'h' degisim miktarini seciniz:  ");
	scanf("%f", &h);
		
	printf("\n%f",(degerBul(x,katsayi,n)-degerBul(x-h,katsayi,n))/h);	
	
}
	
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
