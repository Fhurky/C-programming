#include<stdio.h>
#include<math.h>
#define size 15

float degerBul(float deger,float[],int n);

int main(){
	
	
	int i,n,iterasyon=0,bulundu=1;
	float bas,son,hata,ans,kiyas;
		
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
		
	
	printf("\nKokun oldugunu tahmin ettiginiz araligi giriniz:(a,b)\t");
	scanf("%f %f", &bas,&son);	
	
	printf("\nHata payini giriniz:\t");
    scanf("%f", &hata);	
    
    ans=((son*degerBul(bas,katsayi,n)-bas*degerBul(son,katsayi,n))/(degerBul(bas,katsayi,n)-degerBul(son,katsayi,n)));
	
	while((hata<(son-bas)*pow(2,iterasyon))&&(bulundu)&&(kiyas!=ans)){
		
        kiyas=ans;
					
		printf("%d.iterasyon: %f   \n",iterasyon+1,ans);

			if(degerBul(bas,katsayi,n)*degerBul(ans,katsayi,n)<0){
				son=ans;
				iterasyon++;
			}
			else if(degerBul(son,katsayi,n)*degerBul(ans,katsayi,n)<0){
				bas=ans;
				iterasyon++;
			}
			else if(degerBul(ans,katsayi,n)==0){
				iterasyon++;
				bulundu=0;
			}
		
			ans=((son*degerBul(bas,katsayi,n)-bas*degerBul(son,katsayi,n))/(degerBul(bas,katsayi,n)-degerBul(son,katsayi,n)));		
	}	
	
	printf("Kok:%f     Iterasyon sayisi:%d", ans,iterasyon);
	
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