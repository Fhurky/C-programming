#include<stdio.h>
#include<math.h>
#define size 10

int faktoriyel(int);

int main(){
	
	int degisken,i,j;

//Gerekli bilgilerin kullanıcıdan alınması işlemi
	
	do{
	printf("\nKac degisken gireceksiniz? :");
	scanf("%d", &degisken);
    }while(size<degisken);
    
    float dizi[degisken][degisken+1];
    
    for(i=0;i<degisken;i++){
    	for(j=0;j<=degisken;j++){
    		dizi[i][j]=0;
		}
	}
	
	printf("\nx degerlerini ve f(x) degerlerini alt alta giriniz...\n");
	
	for(i=0;i<degisken;i++){
		for(j=0;j<2;j++){
			if(j==0){
				printf("X%d: ",i+1);
				scanf("%f",&dizi[i][j]);
			}
			else{
				printf("=");
				scanf("%f", &dizi[i][j]);
				printf("\n");
			}
		}
	}
	
//İhtiyacımız olan Vfx matrisinin oluşturulması
	
	for(j=2;j<degisken;j++){
		for(i=j-1;i<degisken;i++){
			dizi[i][j]=dizi[i][j-1]-dizi[i-1][j-1];
		}
	}
	
//Vfx matrisini yazdırma işlemi

printf("\n|---TABLO---|\n\n");
	
	for(i=0;i<degisken;i++){
		for(j=0;j<=degisken;j++){
			if(j!=degisken)
			    printf("%.0f|", dizi[i][j]);
			else{
				printf("%.0f", dizi[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
//ilk sıfır sütununu bulma işlemi

	int count=0,found=0;
	
	j=2;
	
	while((j<=degisken)&&(found==0)){
		for(i=0;i<degisken;i++){
			count=count+dizi[i][j];
		}
		if(count==0){
			found=1;
		}
		else{
			count=0;
		}
		if(found!=1){
		j++;
    	}
	}
	
    count=j-1;
	
	float katsayi[count+1];
	i=0;
	j=1;
	
	int k=0;
	
	while(k<count){
		
		katsayi[k]=dizi[i][j];
		k++;
		i++;
		j++;
	}
//Artım miktaını bulma
	int fark;
	fark=dizi[2][0]-dizi[1][0];
	
    for(i=0;i<count;i++){
    	katsayi[i]=katsayi[i]/faktoriyel(i);
    	if(i!=0){
    		katsayi[i]=katsayi[i]/pow(fark,i);
		}
    	
	}
	
	int sayac;
	
//Denklemin oluşturulduğu kısım------------------------------------
	
	printf("\n\nGirdiginiz verilere gore denkleminiz-->   F(x)= ");
	for(i=count;i>0;i--){
		
		sayac=i-1;
		
		if(sayac>=0){
		    printf("%.0f",katsayi[sayac]);
	    }
	    while(sayac>0){
	    	
	    	if(dizi[sayac-1][0]>0)
	        printf("(X-%.0f)",dizi[sayac-1][0]);
	        
	        else if(dizi[sayac-1][0]<0){
	        printf("(X+%.0f)",-1*dizi[sayac-1][0]);
	        }
	        else if(dizi[sayac-1][0]==0){
	        printf("(X)",dizi[sayac-1][0]);	
			}
	        
	        
	        sayac--;
	    }
	    if(i>1){
	        printf("+");
        } 
	}		
	return 0;
}

int faktoriyel(int sayi){
	
	int result=1,i;
	
	for(i=sayi;i>1;i--){
		result=result*i;
	}
		
	return result;
}
