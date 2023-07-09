#include<stdio.h>
#include<math.h>
#define size 15

float degerBul(float deger,float[],int n);

int main(){
	
	int i,n,iterasyon=0,bulundu=1;
	float bas,son,hata,ans;
	
	do{
	printf("\nGireceginiz denklemin en buyuk derecesini giriniz:(max:%d)\t",size);
	scanf("%d", &n);
    }while(n>=size);
	
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
	
    printf("\nGirdiginiz denklem:\t");
	while(i<=n){
		printf("%.2f(x^%d) ",katsayi[i],n-i);
		i++;
	}	
	
	
	printf("\nAralik giriniz:(a,b)\t");
	scanf("%f %f", &bas,&son);
	
	printf("\nHata payini giriniz:\t");
    scanf("%f", &hata);
	
	while(((son-bas)/2>hata)&&(bulundu)){
		if(degerBul(bas,katsayi,n)*degerBul(son,katsayi,n)<0){
			if(degerBul(bas,katsayi,n)*degerBul((bas+son)/2,katsayi,n)<0){
				son=(bas+son)/2;
				ans=son;
				iterasyon++;
			}
			else if(degerBul(son,katsayi,n)*degerBul((bas+son)/2,katsayi,n)<0){
				bas=(bas+son)/2;
				ans=bas;
				iterasyon++;
			}
			else if(degerBul((bas+son)/2,katsayi,n)==0){
				ans=(bas+son)/2;
				iterasyon++;
				bulundu=0;
			}
		}
	}
	
	printf("Kok:%f ", ans,241);
	printf("\nIterasyon sayisi: %d", iterasyon);
	
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