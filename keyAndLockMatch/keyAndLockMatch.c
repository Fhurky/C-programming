#include <stdio.h> 

int partition(int [], int, int, int);            //Diziyi bölüp siralamak için kullanilan yardimci islev.
void keyAndLockMatch(int [], int [], int, int);  //Somunlari ve civatalari eslestiren ana islev.

int main(){
	
    int key[] = {2,1,6,11,3,4,5,8,12};
    int lock[] = {3,6,2,12,5,1,11,8,4};
    int i,n = 9;

    keyAndLockMatch(key,lock,0,n-1);

    //Eslesen çiftleri yazdirma iselmi
    printf("key ve lock Eslestir:\n");
    for(i=0;i<n;i++){
        printf("key %d, lock %d\n", key[i], lock[i]);
    }
    //Her kapinin anahtari bulundu mu? test islemi
    for(i=0;i<n;i++){
    	if(key[i] != lock[i]){
    		printf("\nAnahtar-kilit uyumu saglanamadi...\n");
    		return 0;
		}
	}
    printf("\nAnahtar-kilit uyumu saglandi...\n");
    return 0;
}



int partition(int arr[], int low, int high, int pivot){
    int i=low-1;  //Islem baslamadan önce i'yi pivot elemandan bir önceki konuma ayarlayin.
    int j,temp;  //Geçici bir degisken tanimlayin, elemanlarin yerlerini degistirmek için kullanilacak.
    
    for(j=low;j<high;j++){
        if(arr[j]<pivot){
            i++;  //Eger arr[j] pivot'tan küçükse, i'yi artirin.
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;  //arr[i] ve arr[j] elemanlarini yer degistirdi.
        }
		else if(arr[j] == pivot){
            temp=arr[j];
            arr[j]=arr[high];
            arr[high]=temp;
            j--;  //Esitse, arr[j] ve arr[high] elemanlarini yer degistirdi ve j'yi azaltti.
        }
    }

    temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;  //Son olarak, pivot elemanini bulundugu yere yerlestirin.

    return i+1;  //Yeni pivot konumunu döndürün.
}


void keyAndLockMatch(int key[], int lock[], int low, int high){
    if(low<high){
        int pivot = partition(key, low, high, lock[high]);  //Somunlari bölmek için bir pivot seçer.
        partition(lock, low, high, key[pivot]);  //Civatalari ayni pivota göre böler.

        keyAndLockMatch(key, lock, low, pivot - 1);  //Sol tarafi eslestirme islemi için rekürsif olarak çagirir.
        keyAndLockMatch(key, lock, pivot + 1, high);  //Sag tarafi eslestirme islemi için rekürsif olarak çagirir.
    }
}
