#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <unistd.h>

void saat_goster(int saat,int dakika2);
void iftar_goster(int gun);
void sahur_goster(int gun);

int vakit[29][2]={
{19,24},{19,25},{19,27},{19,28},{19,29},
{19,30},{19,31},{19,32},{19,33},{19,34},
{19,35},{19,36},{19,37},{19,38},{19,39},
{19,40},{19,41},{19,42},{19,43},{19,45},
{19,46},{19,47},{19,48},{19,49},{19,50},
{19,51},{19,52},{19,54},{19,55},};

int sahur[29][2]={
{5,30},{5,29},{5,27},{5,25},{5,23},
{5,21},{5,19},{5,17},{5,16},{5,14},
{5,12},{5,10},{5,8},{5,6},{5,4},
{5,2},{5,0},{4,58},{4,57},{4,55},
{4,53},{4,51},{4,49},{4,47},{4,45},
{4,43},{4,41},{4,39},{4,37},
};

int main(){
	
	while(1){	
	time_t simdi;
	struct tm *yerel_zaman;
	int dakika = 0;
	
	simdi = time(NULL);
	yerel_zaman = localtime(&simdi);
	int gun = yerel_zaman->tm_mday;
	int ay = yerel_zaman->tm_mon;
	int saat = yerel_zaman->tm_hour;
	int dakika2 = yerel_zaman->tm_min;
	int saniye = yerel_zaman->tm_sec;

	if(gun >= 23  && gun <32){
	    gun = gun - 23;	
	}
	else{
		gun = gun + 8;
	}
	
	if ( vakit[gun][0] > saat && vakit[gun][1] < dakika2 && saat > sahur[gun][0]){
		dakika = 60*(vakit[gun][0] - saat) - dakika2 + vakit[gun][1]-1;
		iftar_goster(gun);
		saat_goster(saat,dakika2);
		
		printf("\n  Iftar icin kalan sure :%d saat %d dakika %d saniye",dakika/60,dakika%60,59-saniye);
		if( dakika < 60 ){
			printf("\n\nNot: Iftar hazirligina baslasaniz iyi olur. Iftara 1 saatten az kaldi");
		}
		printf("\n\n");
	}	
	else if( vakit[gun][0] > saat && vakit[gun][1] == dakika2 && saat > sahur[gun][0]){
		dakika = 60*(vakit[gun][0] - saat)-1;
	    iftar_goster(gun);
		saat_goster(saat,dakika2);
		
		printf("\n  Iftar icin kalan sure :%d saat 59 dakika %d saniye",dakika/60,59-saniye);
		if( dakika < 60 ){
			printf("\n\nNot: Iftar hazirligina baslasaniz iyi olur. Iftara 1 saatten az kaldi");
		}
		printf("\n\n");
	}
	else if( vakit[gun][0] > saat && vakit[gun][1] > dakika2 && saat > sahur[gun][0]){
		dakika = 60*(vakit[gun][0] - saat) - dakika2 + vakit[gun][1]-1;
		iftar_goster(gun);
		saat_goster(saat,dakika2);
		
		printf("\n  Iftar icin kalan sure :%d saat %d dakika %d saniye",dakika/60,dakika%60,59-saniye);
		if( dakika < 60 ){
			printf("\n\nNot: Iftar hazirligina baslasaniz iyi olur. Iftara 1 saatten az kaldi");
		}
		printf("\n\n");
	}
	else if(vakit[gun][0] == saat && vakit[gun][1] > dakika2 ){
		dakika =  vakit[gun][1] - dakika2-1;
		iftar_goster(gun);
		saat_goster(saat,dakika2);
		
		printf("\n  Iftar icin kalan sure : %d dakika %d saniye",dakika%60,59-saniye);
		if( dakika < 60 ){
			printf("\n\nNot: Iftar hazirligina baslasaniz iyi olur. Iftara 1 saatten az kaldi");
		}
		printf("\n\n");
	}	
	else if(vakit[gun][0] == saat && vakit[gun][1] == dakika2 ){
		iftar_goster(gun);
		saat_goster(saat,dakika2);
		
		printf("\n  .... IFTAR VAKTI HAYIRLI IFTARLAR .....");
		printf("\n\n");
	}
	else if(vakit[gun][0] == saat && vakit[gun][1] < dakika2){
		dakika = 60*(24 - saat + sahur[gun+1][0]) + sahur[gun+1][1] - dakika2 - 1; 
	    saat_goster(saat,dakika2);
	    
		    sahur_goster(gun+1);
			printf("\n  Imsak icin kalan sure: %d saat %d dakika %d saniye \n",dakika/60,dakika%60,59-saniye);
			if(dakika >= 60)
		    printf("\n  Sahur icin kalan sure: %d saat %d dakika \n",(dakika/60)-1,dakika%60);	
		    printf("\n\n");
			
	}
	else if(vakit[gun][0] < saat && saat < 24){
		
        dakika = 60*(sahur[gun+1][0] + 24 - saat) + sahur[gun+1][1] - dakika2-1;       
	    saat_goster(saat,dakika2);
	    sahur_goster(gun+1);
		printf("\n\n  Imsak icin kalan sure: %d saat %d dakika %d saniye\n",dakika/60,dakika%60,59-saniye);
		if(dakika >= 60)
		printf("\n  Sahur icin kalan sure: %d saat %d dakika \n",(dakika/60)-1,dakika%60);
				
	}
	else if(saat < sahur[gun][0]){
		dakika = (sahur[gun][0] - saat)*60 + sahur[gun][1] - dakika2-1;		
	    saat_goster(saat,dakika2);
		sahur_goster(gun);
		printf("\n\n  Imsak icin kalan sure: %d saat %d dakika \n",dakika/60,dakika%60);
		if(dakika >= 60)
		printf("\n  Sahur icin kalan sure: %d saat %d dakika %d saniye\n",(dakika/60)-1,dakika%60,59-saniye);
				
		if(dakika < 60){
			printf("\n\nNot: Sahur hazirligina baslasaniz iyi olur. Imsaga 1 saatten az kaldi");
		}			
	}
	else if( saat == sahur[gun][0] && dakika2 < sahur[gun][1]){
		
		dakika = sahur[gun][1] - dakika2-1;
	    saat_goster(saat,dakika2);
		sahur_goster(gun);
		printf("\n\n  Imsak icin kalan sure: %d saat %d dakika %d saniye \n",dakika/60,dakika%60,59-saniye);	
		printf("\n\nNot: Sahur hazirligina baslasaniz iyi olur. Imsaga 1 saatten az kaldi");
	
	}
	else if(saat == sahur[gun][0] && dakika2 == sahur[gun][1]){
		saat_goster(saat,dakika2);
		sahur_goster(gun);
		
		printf("\n  ....  HAYIRLI IMSAKLAR .....");
		printf("\n\n");
	}
	else if(saat == sahur[gun][0] && dakika2 > sahur[gun][1]){
		dakika = 60*(vakit[gun][0] - saat) + vakit[gun][1] - dakika2 -1;	
		saat_goster(saat,dakika2);	
		iftar_goster(gun);	
		printf("\n  Iftar icin kalan sure :%d saat %d dakika %d saniye",dakika/60,dakika%60,59-saniye);
		printf("\n\n");				
	}
	printf("\n\n");

    sleep(1);
    system("cls"); // Ekrandaki yazıyı siler
    usleep(50);	
}
	
	return 0;
}
void saat_goster(int saat,int dakika2){
	
		if(saat >= 10 && dakika2>=10)
		    printf("\n  Saat = %d:%d \n", saat,dakika2);
		else if(saat >= 10 && dakika2 < 10 ){
		    printf("\n  Saat = %d:0%d \n", saat,dakika2); 	
		}
		else if(saat < 10 && dakika2 >= 10){
		    printf("\n  Saat = 0%d:%d \n", saat,dakika2);	
		}
		else{
		    printf("\n  Saat = 0%d:0%d \n", saat,dakika2);	
		}
}

void iftar_goster(int gun){
	if(vakit[gun][0] >= 10 && vakit[gun][1]  >= 10 ){
		printf("\n  Iftar vakti: %d:%d \n",vakit[gun][0], vakit[gun][1]);
	}
	else if(vakit[gun][0] >= 10 && vakit[gun][1] < 10 ){
		printf("\n  Iftar vakti: %d:0%d \n",vakit[gun][0], vakit[gun][1]);
	}
	else if(vakit[gun][0] < 10 && vakit[gun][1] < 10 ){
		printf("\n  Iftar vakti: 0%d:0%d \n",vakit[gun][0], vakit[gun][1]);
	}
	else if(vakit[gun][0] < 10 && vakit[gun][1] >= 10 ){
		printf("\n  Iftar vakti: 0%d:%d \n",vakit[gun][0], vakit[gun][1]);
	}
	
}
void sahur_goster(int gun){
	
	if(sahur[gun][0] >= 10 && sahur[gun][1] >= 10 ){
		printf("\n  Imsak vakti: %d:%d \n",sahur[gun][0], sahur[gun][1]);
	}
	else if(sahur[gun][0] >= 10 && sahur[gun][1] < 10 ){
		printf("\n  Imsak vakti: %d:0%d \n",sahur[gun][0], sahur[gun][1]);
	}
	else if(sahur[gun][0] < 10 && vakit[gun][1] < 10 ){
		printf("\n  Imsak vakti: 0%d:0%d \n",sahur[gun][0], sahur[gun][1]);
	}
	else if(sahur[gun][0] < 10 && sahur[gun][1] >= 10 ){
		printf("\n  Imsak vakti: 0%d:%d \n",sahur[gun][0], sahur[gun][1]);
	}	
}
