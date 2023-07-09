#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

struct tekerlek{
	int data;
	struct tekerlek *next;
	struct tekerlek *prev;
	
};

int *create_arr3(int *arr1,int *arr2,int range,int size);            //3. çarkı oluşturmak için
int *generate_unique_numbers(int M, int size);                       //Diziye tekrar etmeyen sayıların konması
int kontrol_dizi2(int *dizi,int key,int size);                       //2. çarkın doğru oluşturulup oluşturulmadığının kontrolü
int where_key_int(struct tekerlek *head,int key,int size);           //3. keyin çarkın hangi gözünde olduğunu integer olarak döndüren fonksiyon

void print_arr(int *arr,int *arr2,int *arr3,int size);                                                   //Yapım aşamasında çarkların doğru oluşturulduğunu kontrol etmek için yazmıştım. Şuan kodda yer almıyor
void printf_all(struct tekerlek *head1, struct tekerlek *head2, struct tekerlek *head3, int size);        //3 çarkın da ekrana yazdırılması
void where_key(struct tekerlek *head,int key,int size);                                                   //keyin hangi çarkta hangi gözde olduğunun ekrana yazdırılmasını sağlıyor
void print_tekerlek(struct tekerlek *head,int size);                                                      //Tek çarkı ekrana yazdırıyor
void print_dondurme(int cark1, int cark2, int size, int key);                                             //Çarkların saate yönlerine göre ne kadar döndürülmesi gerektiğini ekranda gösteriyor                           *********            

struct tekerlek *create_add(int *dizi,int size);                                                          //Çarkların oluşturulması ve dizideki sayıların çarklara eklenmesini yapıyor                                    

void donduruluyor(struct tekerlek *head1, struct tekerlek *head2, struct tekerlek *head3, int key, int size);  //Tüm çarkların dondurulmesi ve ekranda her adım sonunda gösterilmesi                                      *********

int main(){
	
    int M,size;
    int i;
    int key,key2;
    int *arr,*arr2,*arr3;                                                                          //Çift yönlü linkli liste oluşturulmadan önce her bir çarkın elemanlarını ayrı bir dizide oluşturmaya çalıştım
    printf("\n  Not: range degeri size degerinin 2 katindan buyuk olmalidir. \n");
    printf("\n  Size:  ");scanf("%d", &size);
    printf("\n  Range: ");scanf("%d", &M);                                                         //****************** Size ve range değerleri kullanıcıdan alınıyor
    
    if(size*2 >= M){
    	printf("\nHatali girdi...Programdan cikiliyor...");
    	return 0;
	}                                                                                              //****************** Hatalı girdi yapıldıysa program sonlanıyor
	
	arr = generate_unique_numbers(M, size); //1.tekerlek olusumu                                   
	sleep(1);
	arr2= generate_unique_numbers(M, size); //2.tekerlek olusumu

    key = rand()%size;                                                                             //****************** Keyin random belirlenmesi
    srand(time(NULL));
    key = arr[key]; 
    
    kontrol_dizi2(arr2,key,size);   
    arr3 = create_arr3(arr,arr2,M,size);    //3.tekerlek olusumu  
    key2 = rand()%size;
    arr3[key2] = key;                       //3.tekerleğe key konulması
    
	printf("\nKEY: %d\n\n", key); 
    
    struct tekerlek* head1;
    struct tekerlek* head2;
    struct tekerlek* head3;
    
    head1 = create_add(arr,size);                                                                   //****************** Oluşturulan dizilerin linkli listeye aktarılması işlemi
    head2 = create_add(arr2,size);
    head3 = create_add(arr3,size);
    
    //tüm tekerleklerin farklı konumlarda olduğundan emin olunması işlemi                           //*********************** Tüm keyler farklı konumlarda olmalı
    
    while(where_key_int(head1,key,size) == where_key_int(head2,key,size) || where_key_int(head1,key,size) == where_key_int(head3,key,size) || where_key_int(head2,key,size) == where_key_int(head3,key,size)){
    	if(where_key_int(head2,key,size) == where_key_int(head3,key,size)){
    		head2 = head2->next;
    		head3 = head3->prev;
		}
		if(where_key_int(head1,key,size) == where_key_int(head3,key,size)){
			head3 = head3->prev;
		}
		if(where_key_int(head1,key,size) == where_key_int(head2,key,size)){
			head2 = head2->next;
		}	
	}
    
    print_tekerlek(head1,size);
    printf("\n");
    print_tekerlek(head2,size);
    printf("\n");
    print_tekerlek(head3,size);
    printf("\n");
    
	//Key konumlarini belirleme
	
	where_key(head1,key,size);
	where_key(head2,key,size);
	where_key(head3,key,size);
	
	int cark1,cark2,cark3;
	
	cark1 = where_key_int(head1,key,size);
	cark2 = where_key_int(head2,key,size);
	cark3 = where_key_int(head3,key,size);
	
	printf("\n\n2.Cark "); print_dondurme(cark1,cark2,size,key);                            // Ne tarafa dönmeli?
	printf("\n3.Cark "); print_dondurme(cark1,cark3,size,key);
    
    int siralama = where_key_int(head1,key,size);
    
    //Tekerleklerin cevrilmesi
    
    printf("\n\nTekerlekler donduruluyor...\n\n");
    donduruluyor(head1,head2,head3,key,size);              //************************************* DONDURME FONKSIYONU***************************************
     
    free(arr);
    free(arr2);
    free(arr3);

    return 0;
}

int *create_arr3(int *arr1,int *arr2,int range,int size){  //3. çarkı oluşturmak için 1. ve 2. diziden yararlandığım fonksiyon
    int i;
    int *boyut1 = (int*)malloc(range*sizeof(int));
    int *boyut2 = (int*)malloc(range*sizeof(int));
    int *arr3 = (int*)malloc(size*sizeof(int));

    for(i=0;i<range;i++){
	    boyut1[i] = i;
	    boyut2[i] = 1;
    }

    for(i=0;i<size;i++){	
	    boyut2[arr1[i]]++;
	    boyut2[arr2[i]]++;
    }

    for(i=0;i<range;i++){
	    if(boyut2[i] == 3){
	        boyut1[i] = 0;
	    }
    }
  
    int yeterli = 0;

    for(i=0; i<range && yeterli < size;i++){
    	
	    if(boyut1[i] != 0){
		    arr3[yeterli] = boyut1[i];
		    yeterli++;
	    }	
    }  
    return arr3;
}
 
int* generate_unique_numbers(int M, int size) {
    int* dizi = malloc(size * sizeof(int));
    int i, j, num;
    srand(time(NULL)); // random sayı üretmek için zaman fonksiyonunu kullanıyoruz

    for (i = 0; i < size; i++) {
        num = rand() % M + 1; // 1-M arası rastgele sayı üretiyoruz
        j = 0;
        while (j < i && dizi[j] != num) { // daha önce üretilen sayılarla karşılaştırıyoruz
            j++;
        }
        if (j < i) { // sayı daha önce üretilmişse, tekrar üretiyoruz
            i--;
        }
        else{
        dizi[i] = num;
        }
    }

    return dizi;
}
int kontrol_dizi2(int *dizi,int key,int size){    //Rasgele üretilen 2.dizide key var mı? Yoksa rasgele bir yere key yerleştir
	srand(time(NULL));
	int i;
		
	for(i=0;i<size;i++){
		if(dizi[i] == key){
			return 1;
		}
	}
	dizi[rand()%size] = key;
	return 1;
}
void print_arr(int *arr,int *arr2,int *arr3,int size){         //Bu fonksiyon kullanılmıyor
	int i;
    printf("\n1.TEKERLEK:  ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("\n2.TEKERLEK:  ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    printf("\n3.TEKERLEK:  ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");
}

void print_tekerlek(struct tekerlek *head, int size){
	int i=0;
    while (head != NULL && i<size) {
        printf("%d ", head->data);
        head = head->next;
        i++;
    }
    printf("\n");
}

struct tekerlek *create_add(int *dizi,int size){
	
	struct tekerlek *head = NULL;
	struct tekerlek *tail = NULL;
	int i;
		
	for(i=0;i<size;i++){
		struct tekerlek* newnode = (struct tekerlek*)malloc(sizeof(struct tekerlek));
		struct tekerlek*hed = (struct tekerlek*)malloc(sizeof(struct tekerlek));
		newnode->data = dizi[i];
		
		if(head == NULL){
			head = newnode;
            tail = newnode;
            head->next = tail;
            tail->prev = head;        
		}
		
		else{
			tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
            head->prev = tail;
            tail->next = head;
		}	
	}
	return head;	
}
void where_key(struct tekerlek *head, int key,int size){
	int konum,i=0;
	struct tekerlek *head_ref = (struct tekerlek*)malloc(sizeof(struct tekerlek));
	
	head_ref = head;
	
	while(i<size){
		if(head_ref->data == key)
		konum = i+1;
		head_ref = head_ref->next, i++;
	}
	printf("Tekerlek konumu : %d. goz\n",konum);
}
int where_key_int(struct tekerlek *head,int key,int size){
	int konum,i=0;
	struct tekerlek *head_ref = (struct tekerlek*)malloc(sizeof(struct tekerlek));
	head_ref = head;
	
	while(i<size){
		if(head_ref->data == key)
		konum = i+1;
		head_ref = head_ref->next, i++;
	}
	return konum;
}

void printf_all(struct tekerlek *head1, struct tekerlek *head2, struct tekerlek *head3, int size){	
	printf("1.Tekerlek: ");print_tekerlek(head1,size);
    printf("2.Tekerlek: ");print_tekerlek(head2,size);
    printf("3.Tekerlek: ");print_tekerlek(head3,size);
    printf("\n\n");
}

void print_dondurme(int cark1, int cark2, int size, int key){                                                     //************************************
				
	if(cark1 - cark2 > 0){
	    if(cark1 - cark2 > (size/2)){
		    // sola öteleme
            printf(" Saatin tersi(sol) yonunde %d adim cevrilmelidir. ",size - cark1 + cark2);
	    }
	    else if(cark1 - cark2 <= (size/2)){
		    // sağa öteleme
		        printf(" Saat(sag) yonunde %d adim cevrilmelidir.",cark1 - cark2);
		    if(size%2 == 0 && size/2 == cark1-cark2){
		    	printf("\tNot: Saatin tersi(sol) yonunde de %d adim cevrilebilir.",cark1 - cark2);
			}
	    }
    }
    if(cark1 - cark2 < 0){
    	if(cark1 - cark2 >= -(size/2) ){
    		// sola öteleme
    		printf(" Saatin tersi yonunde(sol) yonunde %d adim cevrilmelidir.",cark2 - cark1);
    		if(size%2 == 0 && size/2 == cark1-cark2){
		    	printf("Not: Saatin yonunde de %d adim cevrilebilir.",cark2-cark1);
			}
		}
		else if(cark1 - cark2 < -(size/2)){
			printf(" Saat yonunde(sag) %d adim cevrilmelidir.\n\n",size + cark1 - cark2);
			// sağa öteleme
		}
	}	
}
void donduruluyor(struct tekerlek *head11, struct tekerlek *head12, struct tekerlek *head13, int key, int size){              //**************************************************
	
	int siralama = where_key_int(head11,key,size);
	
	struct tekerlek *head1 = (struct tekerlek*)malloc(sizeof(struct tekerlek));
	struct tekerlek *head2 = (struct tekerlek*)malloc(sizeof(struct tekerlek));
	struct tekerlek *head3 = (struct tekerlek*)malloc(sizeof(struct tekerlek));
	
	head1 = head11;
	head2 = head12;
	head3 = head13;
	
	while( siralama != where_key_int(head2,key,size) || siralama != where_key_int(head3,key,size)){
    	
		if(siralama - where_key_int(head2,key,size) > 0){
			if(siralama - where_key_int(head2,key,size) > (size/2)){
				head2 = head2->next;
			}
			else if(siralama - where_key_int(head2,key,size) <= (size/2)){
				head2 = head2->prev;
			}
		}
    	else if(siralama - where_key_int(head2,key,size) < 0){
    		if(siralama - where_key_int(head2,key,size) >= -(size/2)){
    			head2 = head2->next;
			}
			else if(siralama - where_key_int(head2,key,size) < -(size/2)){
				head2 = head2->prev;
			}
		}
    	
    	if(siralama - where_key_int(head3,key,size) > 0){
			if(siralama - where_key_int(head3,key,size) > (size/2)){
				head3 = head3->next;
			}
			else if(siralama - where_key_int(head3,key,size) <= (size/2)){
				head3 = head2->prev;
			}
		}
    	else if(siralama - where_key_int(head3,key,size) < 0){
    		if(siralama - where_key_int(head3,key,size) >= -(size/2)){
    			head3 = head3->next;
			}
			else if(siralama - where_key_int(head3,key,size) < -(size/2)){
				head3 = head3->prev;
			}
		}
	
    //Her döndürme isleminden sonra print islemi
        printf_all(head1,head2,head3,size);
 	
	}
}
