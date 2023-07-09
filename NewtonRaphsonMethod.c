#include<stdio.h>
#include<math.h>
#define size 15

float degerBul(float deger,float[],int n);
float turev(float,float[],int);

int main(){
	
	int n,i,iterasyon=1;
	float hata,kok,baslangic,karar;
	
	do{
	printf("\nGireceginiz denklemin en buyuk derecesini giriniz:(max:%d)\t",size);
	scanf("%d", &n);
    }while(n>=size);
	
	float katsayi[n+1];
	float fonkTurev[n];
	
	for(i=0;i<=n;i++){
		katsayi[i]=0;
		if(i!=n){
			fonkTurev[n]=0;
		}
	}
	
	i=0;
	while(i<=n){
		printf("\n%d.dereceli terimin katsayisini giriniz:  ",n-i);
		scanf("%f", &katsayi[i]);
		fonkTurev[i]=(n-i)*katsayi[i];
		i++;
	}	
	i=0;
	
    printf("\nGirdiginiz denklem:\t");
	while(i<=n){
		printf("%.2f(x^%d) ",katsayi[i],n-i);
		i++;
	}	
	i=0;
	
	printf("\nHata payini giriniz: ");
	scanf("%f", &hata);
	
	printf("\nBaslangic degerini giriniz: ");
	scanf("%f", &baslangic);	
	
	do{	
		if(turev(baslangic,fonkTurev,n)!=0){
			
		    kok=baslangic-(degerBul(baslangic,katsayi,n)/turev(baslangic,fonkTurev,n));		
		    iterasyon++;
		    
		
		    if(kok>baslangic){
		    	karar=kok-baslangic;
	    	}
	    	else{
	    		karar=baslangic-kok;
	    	}
	    	
	    	printf("\n%f\n", karar);
	    	
	    	baslangic=kok;
	    }
	    else{
	    	
			baslangic=baslangic+hata;
	    	
		    kok=baslangic-(degerBul(baslangic,katsayi,n)/turev(baslangic,fonkTurev,n));		
		    iterasyon++;
		    
		
		    if(kok>baslangic){
		    	karar=kok-baslangic;
	    	}
	    	else{
	    		karar=baslangic-kok;
	    	}
	    	
	    	printf("\n%f\n", karar);
	    	
	    	kok=baslangic;
		}
				
	}while(karar>hata);
		
	printf("\n\nKok: %f \t iterasyon sayisi: %d", kok,iterasyon);	
	
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

float turev(float deger1, float fonkTurev[],int n){
	
	int i=0;
	float turevResult=0;
	
	while(i<n){
		
		turevResult = turevResult + fonkTurev[i]*pow(deger1, n-i-1);
		i++;
			
	}	
		
	return turevResult;
}