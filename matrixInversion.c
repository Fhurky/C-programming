#include<stdio.h>
#define N 10

int main(){
	
	int i,j,k,n;	
	float katsayi,tmp;

//Kullanicidan uygun matris boyutu alma
	
	do{
	printf("\nKare matrisin boyutunu giriniz(MAX:%d): ",N);
	scanf("%d", &n);
    }while(n>10);
	
	float matris[n][n];	
	
//kullanicidan matris alma işlemi	

	for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        	printf("%d.satir, %d. sutundaki sayiyi giriniz:  ",i+1,j+1);
        	scanf("%f", &matris[i][j]);
		}
	}
	
//Birim matris oluşturma işlemi	

	float birim[n][n];
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j){
				birim[i][j]=0;
			}
			else{
				birim[i][j]=1;
			}
		}
	}
	
//Main kısım	

	for(i=0;i<n;i++){
		
		katsayi=matris[i][i];
		
		for(j=0;j<n;j++){		
			matris[i][j]=matris[i][j]/katsayi;                         //Her satır değiştiğinde o satırı ilk elemanına bölüp ilk elemanını 1 yapma işlemi
			birim[i][j]=birim[i][j]/katsayi;			
	    }	
	    
		for(k=0;k<n;k++){
			if(k!=i){
				tmp=matris[k][i];                                       
				for(j=0;j<n;j++){
				    matris[k][j]=matris[k][j]-(matris[i][j]*tmp);      // Hangi sutünda isek o sutundaki diğer satir elemanlarını 0 yapma işlemi (Kendi hariç)
					birim[k][j]=birim[k][j]-(birim[i][j]*tmp);
				}
			}
		}
	}
	
//Yazdırma işlemi	

	printf("\nMatrisin tersi:\n\n");
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%.2f ", birim[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}