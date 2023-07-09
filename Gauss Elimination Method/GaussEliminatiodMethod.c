#include<stdio.h>
#define N 10

int main(){
	
	
	int i,j,k,n;	
	float katsayi,tmp;

//Kullanicidan uygun matris boyutu alma
	
	do{
	printf("\nBilinmeyen sayisini giriniz(MAX:%d): ",N);
	scanf("%d", &n);
    }while(n>10);
	
	float matris[n][n+1];
	float cevap[n];		
	
//kullanicidan denklemleri alma işlemi	

	for(i=0;i<n;i++){
		printf("\n%d. denklemin katsayilarini bosluk birakarak giriniz(sonuc dahil):\n",i+1);
        for(j=0;j<=n;j++){
        	printf("%c:", 65+j);
        	scanf("%f", &matris[i][j]);
        	if((j+1)==n)
        	    printf("=");
		}
	}
		
//Denklem matrisini ekrana yazdırma
	
    for(i=0;i<n;i++){
    	for(j=0;j<=n;j++){
    		printf("%.2f ", matris[i][j]);
		}
		printf("\n");
	}
	
    for(i=0;i<n;i++){
	    cevap[i]=0;
    }	
	
//İlk main kısım (üst üçgen matris oluşturma)	

	for(i=0;i<n;i++){
		
		katsayi=matris[i][i];
		
		for(j=0;j<=n;j++){		
			matris[i][j]=matris[i][j]/katsayi;                         //Her satır değiştiğinde o satırı ilk elemanına bölüp ilk elemanını 1 yapma işlemi
			
	    }	
	    
		for(k=0;k<n;k++){
			if(k>i){
				tmp=matris[k][i];                                       
				for(j=0;j<=n;j++){
				    matris[k][j]=matris[k][j]-(matris[i][j]*tmp);      // Hangi sutünda isek o sutunun altındaki elemanları sıfır yapma(Kendi hariç)
				}
			}
		}
	}	
	
//Denklem matrisini ekrana yazdırma

    printf("\nYardimci ust ucgen matris:\n\n");	
    
    for(i=0;i<n;i++){
    	for(j=0;j<=n;j++){
    		printf("%.3f  ", matris[i][j]);
    		if(j==(n-1)){
    			printf("=  ");
			}
		}
		printf("\n");
	}
	
//İkinci main kısım(Asıl eliminasyon uygulaması)

printf("\n\nKokler:\n");
		
    cevap[n-1]= matris[n-1][n];

    for(i=n-2;i>=0;i--){
	    for(j=0;j<n;j++){
            matris[i][n]=matris[i][n]-matris[i][j]*cevap[j];
	    }
    	if((j)==n){
	    	cevap[i]=matris[i][n];
    	}
    } 

    for(i=0;i<n;i++){
      	printf("\nX%d: %.3f",i+1,cevap[i]);
    }
	
	return 0;
}
