#include<stdio.h>
#include<math.h>
#define size 15

float degerBul(float deger,float[],int n);

int main(){
	
	int i,n;
	
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
	
	int bolum;
	float bas,son;	
	
	printf("\nIntegral araligi giriniz(bas son): ");
	scanf("%f %f",&bas,&son);
	
	printf("\nGrafigin kac parcaya bolunecegini seciniz(n):  ");
	scanf("%d", &bolum);
		
	int counter=0;
	float art,result=0;
	
	art=(son-bas)/bolum;

	while(counter<bolum){
		if(counter==0){
		bas=counter*art+bas;
	}
	else{
		bas=son;
	}
		son=bas+art;
		
		
		result=result+((son-bas)/2)*(degerBul(bas,katsayi,n)+degerBul(son,katsayi,n));	
					
		counter++;
	}	
	
	printf("Result: %f",result);
	
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