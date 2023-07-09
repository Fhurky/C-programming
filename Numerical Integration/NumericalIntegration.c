#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define size 15

float degerBul(float deger,float[],int n);

int main(){
	
	//
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

    //MAIN kısım
    
    int karar=0;
    printf("\nHangi simpson yontemini seciyorsunuz? \n Simpson 1/3 icin 1'i\n Simpson 3/8 icin 2'yi tuslayiniz...\n");
    scanf("%d", &karar);
if(karar==2){	
	int bolum;
	float bas,son;	
	
	printf("\nIntegral araligi giriniz(bas son): ");
	scanf("%f %f",&bas,&son);
	
	printf("\nGrafigin kac parcaya bolunecegini seciniz(n):  ");
	scanf("%d", &bolum);
	
	int counter=0;
	
	float art;
	
	art=(son-bas)/bolum;
	
	float result=0;
	float x1,x2;
	
	while(counter<bolum){
		
		if(counter==0){
		bas=counter*art+bas;
	}
	else{
		bas=son;
	}
		son=bas+art;
		
		x1=bas+(son-bas)/3;
		x2=bas+(2*(son-bas))/3;
		
		result=result+((son-bas)*(degerBul(bas,katsayi,n)+degerBul(son,katsayi,n)+3*degerBul(x1,katsayi,n)+3*degerBul(x2,katsayi,n)))/8;		
		
		
		counter++;
	}
	
	printf("\n\nResult: %f", result);
}

else if(karar==1){
	int bolum;
	float bas,son;	
	
	printf("\nIntegral araligi giriniz(bas son): ");
	scanf("%f %f",&bas,&son);
	
	printf("\nGrafigin kac parcaya bolunecegini seciniz(n):  ");
	scanf("%d", &bolum);
	
	int counter=0;
	
	float art;
	
	art=(son-bas)/bolum;
	
	float result=0;
    float x;
	
	while(counter<bolum){
		
		if(counter==0){
		bas=counter*art+bas;
	}
	else{
		bas=son;
	}
		son=bas+art;
		
        x=(bas+son)/2;
		
		result=result+((son-bas)*(degerBul(bas,katsayi,n)+degerBul(son,katsayi,n)+4*degerBul(x,katsayi,n)))/6;		
		
		
		counter++;
	}
	
	printf("\n\nResult: %f", result);	
	
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