#include<stdio.h>
#include<math.h>
#define size 15

int main(){
	
    int n,i,j,k,iterasyon;

//Gerekli bilgiler kullanıcıdan istendi

    do{
    printf("\nDenklem sayisini giriniz: ");
    scanf("%d", &n);
    }while(n>size);
    
    float islem[n];
	float matris_denklem[n][n+1]; 
	float sonuc[n];
	float kural_max,tmp;
	
	int kontrol[n];
	
	for (i = 0; i < n; i++){
        printf("%d.Denklem katsayilarini giriniz:\n",i+1);
        for (j = 0; j < n; j++){
        	printf("%c%d:",65+j,i+1);
            scanf("%f", &matris_denklem[i][j]);
        }
    }

    for (i = 0; i <n; i++){
        printf("\n%d.denklemin sonucunu giriniz:  ", i+1);
        scanf("%f", &sonuc[i]);
        matris_denklem[i][n]=sonuc[i];
    }

//Katsayi matrisi kurallara uygun hale getirildi   
    
    for(i=0;i<n;i++){
		
	    kural_max=abs(matris_denklem[i][0]);
		kontrol[i]=0;
		
		for(j=0;j<n;j++){
			if(abs(matris_denklem[i][j])>kural_max){
				kural_max=abs(matris_denklem[i][j]);
			    kontrol[i]=j;
			}
		}
	}
	
	for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
		if(kontrol[i]<i){
        	tmp=matris_denklem[i][j];
			matris_denklem[i][j]=matris_denklem[kontrol[i]][j];
			matris_denklem[kontrol[i]][j]=tmp;	
	    	}
	    }
	}
	
	for(i=0;i<n;i++){
		sonuc[i]=matris_denklem[i][n];
	}
	
//Kurallara uygun olusturulan denklemin ekrana yazdırılması işlemi

	printf("\n\nKurallara uygun matris olusturuldu. Satirlar güncellendi....\n\n");
	
	for(i=0;i<n;i++){
		for(j=0;j<n+1;j++){
			if(j!=n)
			    printf("%.1f  ", matris_denklem[i][j]);
			else{
				printf("  =  %.1f", matris_denklem[i][j]);
			}
		}
		printf("\n");
	}

//Gerekli bilgiler istendi
    
    printf("\nIterasyon sayisini giriniz: ");
    scanf("%d", &iterasyon);
    
	printf("\n\n");
    
	for (i = 0; i < n; i++){
        printf("  x%d\t\t", i);
    }

    printf("\n");
    
//Başlangıç degerlerinin kullanıcıdan istenmesi

    for (i = 0; i < n; i++){
    	printf("\n%c0.Baslangic tahminlerini giriniz: ",65);
        scanf("%f", &islem[i]);
	}
	
	printf("\n\n");
	
//Guas seidel formül kısmı (Her iterasyonu ekrana basma işlemi dahil)
   	
    for (k = 0; k < iterasyon; k++){
        printf("%d\t", k);
        for (i = 0; i < n; i++){
        	
            islem[i] = sonuc[i];
            
            for(j = 0; j < n; j++){
                if (j != i){
                    islem[i] = islem[i] - matris_denklem[i][j] * islem[j];
                } 
            }
            
            islem[i] = islem[i] / matris_denklem[i][i];
            printf("%f\t", islem[i]);
            
		}
        printf("\n"); 
	}
	
//Ekrana çıktı alma
	
    for (i = 0; i < n; i++) {
        printf("\n\n");
        printf("\t X%d = %f\n", i, islem[i]);
	}
	
	
       return 0;
    }
    