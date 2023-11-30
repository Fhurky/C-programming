#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct HashEntry{
    char userName[50];
    int deleted;
};

// Mine hoca derstte bu de�i�kenler gibi t�m fonksiyonlarin kullandigi degerleri global tanimlayabilirsiniz dedi ve kendisi de �yle yapti
int tableSize,mod,count=0,max=0; //HashTablosu, eleman sayisi(count), mod bilgisi,tableSize ve max degeri her fonksiyonda olduklari i�in global tanimlandi
// Buradaki max degeri t�m insert islemleri baz alindiginde gidilen en uzak iterasyonu buluyor bu sayede eger bir elemen eklendiyse ne kadar uzakta olursa olsun o elemani bulabiliyoruz
// Bir elemanin eklenme kosulu ise 5*tableSize degeri kadar iterasyon deniyoruz. Yine de bos yer bulamadiysak(biz bulamamis olabiliriz) elemani ekleyemiyoruz. 
// Burdaki 5*tableSize degerinin katsayisi olan 5'i arttirarak elemeanin eklenme ihtimalini cok y�kseltebiliriz ama sonsuz kez denemedigimiz s�rece GARANTISI YOK!!!
struct HashEntry* table;     //her fonksiyonda kullanildigi icin GLOBAL tanimlandi.

long long int h1(long int key){
	//----------------------
	// h1 hash fonkisonu
	//----------------------
    return (key % tableSize);
}

long long int h2(long int key){
	//----------------------
	// h2 hash fonkisonu
	//----------------------
    return (key % (tableSize-2))+1;
}

long long int hx(long long int key, int i, char *userName){
	//----------------------
	// Son hash fonkisonu 
	// i degerine gore h2() hash fonksiyonunun dondurdugu degeri carparak ekler
	//----------------------
    long long int total = h1(key) + i*h2(key);
    if(i==0 && mod==0){
    	printf("\nh1('%s')= %d and h2('%s')= %d\n",userName,h1(key),userName,h2(key));
	}
    return total % tableSize;
}

long long int calculateHorner(char *key){
	//----------------------------------------
	// Girilen ismin (char) basamak degerlerine gore karsiligini bulur
	// 11 sayisini kullanir
	// Mod secimine gore farkli ilerler
	//---------------------------------------
    int i=0, j=0;
    long long int total = 0;

    while(key[j] != '\0'){
        j++;
    }
    j = j-1;
    i = j; 
    while(i>=0){
        total = total + key[j-i]*(pow(11,i));
        i--;
    }  
    return total%tableSize;
}

int isPrime(int num){
	//----------------------
	// Sayi prime mi diye kontrol eder
	//----------------------
	int i;
    for(i=2;(i*i)<=num;i++){
        if (num%i == 0){
            return 0;
        }
    }
    return 1;
}
int findNextPrime(int num){
	//----------------------
	// Sayidan buyuk en kucuk prime'i bulur
	//----------------------
    while(!isPrime(num)){
        num++;
    }
    return num;
}
int findTableSize(){
    //------------------------------------------------------------------
    // Eleman sayisini(int) ve load faktoru(float) kullanicidan alan ve
    // table size degerini hesaplayip (int) donduren fonksiyon
    //------------------------------------------------------------------
    int numberOf;
    float loadFactor;
    
    printf("Enter the number of elements: ");
    scanf("%d", &numberOf); 
    
    printf("Enter the load factor(float): ");
    scanf("%f", &loadFactor); 
    
    
    tableSize = (float)numberOf / loadFactor; 
    tableSize = findNextPrime(tableSize);
    max = tableSize;
    return tableSize;
}

void createHashTable(int tableSize) {
	//-------------------------------
	// Hesaplanan TableSize(int) degeri kadar node acan fonksiyon
	//-------------------------------
	int i;
    table = (struct HashEntry*)malloc(tableSize * sizeof(struct HashEntry)); 
    if(table == NULL){
        printf("Memory ERROR...\n");
		printf("Pls restart the app...\n"); 
    }
    for(i=0;i<tableSize;i++){
        table[i].deleted = 1;
        strcpy(table[i].userName,"???");
    }
}
struct HashEntry *makeHashTable(struct HashEntry *table) {
	//-------------------------------
	// TableSize boyutunda yeni bir hash tablosu olusturulur
	// Eski tablodaki yalnizca kayitli( deleted = 1 )degerler yeni tabloya aktarilir
	// Eski tablo FREE lenir.
	//-------------------------------
	int i;
	struct HashEntry *tableNew;
    tableNew = (struct HashEntry*)malloc(tableSize * sizeof(struct HashEntry)); 
    if(table == NULL) {
        printf("Memory ERROR...\n");
		printf("Pls restart the app...\n"); 
    }
    for(i=0;i<tableSize;i++){
    	if(table[i].deleted == 0){
        tableNew[i].deleted = 0;
        if(mod == 0){
        	printf("\nUser named %s has been transferred...\n", table[i].userName);
		}
        strcpy(tableNew[i].userName,table[i].userName);
        } 
        else{
        	tableNew[i].deleted = 1;
        	strcpy(tableNew[i].userName, "???");
		}
    }
    free(table);
    printf("\nTransfer process completed successfully, and the old hash has been deleted...\n");
    return tableNew;
}
void printHashTable(struct HashEntry* table){
	//-------------------------------
	// Hash tablosu printlenir
	//-------------------------------
	int i;
	printf("\n------------------(Number Of User: %d)-----------------------\n",count);
	for(i=0;i<tableSize;i++){
		printf("%d. address:%s        delete:%d\n",i,table[i].userName,table[i].deleted);
	}
	printf("\n-----------------------------------------\n");
}
void insertUser(char* userName){
	//-------------------------------
	// userName degerinin indexi hesaplanir eger bos ise eleman eklenir
	// bos degil ise i++ yapilir ve yeniden hesaplanir
	// i<tableSize degeri kadar bos yer aranir bulunursa eklenir
	// bulunmaz ise bos yer yok mesaji verilir
	//-------------------------------
    int index, i = 0;
    do{
        index = hx(calculateHorner(userName),i,userName);
        if(!strcmp(table[index].userName,userName) && table[index].deleted == 0){
        	printf("\nThe item (%s) was not added because it already exists in the table at address %d.\n", userName, index);
        	if(i>max){
        		max = i;
			}
        	return ;
		}
        if(table[index].deleted) {
            strcpy(table[index].userName, userName);
            table[index].deleted = 0;
            count++;
        	printf("\nThe name %s has been placed at address %d.\n", userName, index);
            return;
        }
        
        else{
        	if(mod == 0)
        	printf("\nThe name %s could not be placed at address %d (already occupied).\n", userName, index);
		}
        i++;
    }while(i<5*tableSize);
}

void searchUser(){
	//-------------------------------
	// Kullanicidan alinan userName degeri i<tableSize olmak �zre
	// tabloda aranir var ise konum bilgisi verilir
	// yok ise yoktur bilgisi verilir
	//-------------------------------
    int index, i = 0;
    char userName[20];
    printf("\nEnter the userName:  ");
    scanf("%s", &userName);
    do{
        index = hx(calculateHorner(userName),i,userName);

        if(strcmp(table[index].userName, userName) == 0 && !table[index].deleted){
        	printf("\nThe name %s was found at address %d.\n", userName, index);
            return;
        }
        else{
        	if(mod == 0)
        	printf("\nThe name %s could not be found at address %d.\n", userName, index);
        }
		i++;
    }while(i<=max);
    printf("\nThere is no user with this name...\n");
    return ;
}
void editUser(){
	//-------------------------------
	// Bu fonksiyon aktif silme islemi yapar
	// userName'i bulur
	// yeniden isimlendirmek icin yeni ismi kullanicidan alir
	// yeni userName ye gore yeni konuma yeni kullaniciyi ekler
	// Eski kullanicinin hem ismini hem deleted degerini sifilar
	//-------------------------------
    int index, i = 0;
    char userName[20];
    printf("\nEnter the userName:  ");
    scanf("%s", &userName);
    do{
        index = hx(calculateHorner(userName),i,userName);

        if(strcmp(table[index].userName, userName) == 0 && !table[index].deleted){
        	printf("\nThe name %s was found at address %d.\n", userName, index);
            printf("\nEnter the new username (editing the user: %s):   ", table[index].userName);
        	strcpy(table[index].userName,"???");
        	table[index].deleted = 1;      	
        	scanf("%s", &userName);
        	insertUser(userName);
            return;
        }
        else{
        	if(mod == 0)
        	printf("\nThe name %s could not be found at address %d.\n", userName, index);
        }
		i++;
    }while(i<=max);
    printf("\nThere is no user with this name...\n");
    return ;
}
void deleteUser(){
	//-------------------------------
	// Bu fonksiyon pasif silme islemi yapar
	// Kullaniciyi bulur, var ise deleted = 0 yapar
	// ama isim hala bellekte y�kl�d�r
	//-------------------------------
    int index, i = 0;
    char userName[20];
    printf("\nEnter the userName:  ");
    scanf("%s", &userName);
    do{
        index = hx(calculateHorner(userName),i,userName);
        if(!strcmp(table[index].userName,userName) && table[index].deleted == 0){
        	printf("%s was found at address %d. Are you sure you want to delete it? (Y:1 N:0):   ", table[index].userName, index);
        	int decision;
        	scanf("%d", &decision);
        	if(decision){
        	    printf("%s was deleted from address %d. (Remaining users: %d)\n", userName, index, count - 1);
        	    table[index].deleted = 1;
        	    count--;
            }
            else{
            	printf("\nDeletion process has been canceled...\n");
			}
        	return ;
		}
        else{
        	if(mod == 0)
        	printf("%s could not be found at address %d.\n", userName, index);
		}
        i++;
    }while(i<max);
    printf("\nThere is no user with this name...\n");
}
void takeUser(){
	//-------------------------------
	// Kullanicidan isim alinir
	//-------------------------------
	char name[20];
	printf("\nEnter the user name: ");
	scanf("%s", name);
	insertUser(name);
}

int main() {
	
	int exit = 1, choice;
	createHashTable(findTableSize());
	printf("\nChoose the MOD:\n\n1 for NORMAL\n0 for DEBUG\n\n");
	scanf("%d", &mod);  
    
    while(exit){
    	printf("\n--------------------\n");
    	printf("1 for NewUser:\n");
    	printf("2 for SearchUser\n");
    	printf("3 for DeleteUser\n");
    	printf("4 for EditUser\n");
    	printf("5 for RemakeHash\n");
    	printf("6 for ShowHash\n");
    	printf("7 for DebugMod\n");
    	printf("8 for NormalMod\n");
    	printf("0 for Exit\n");
    	printf("--------------------\n");
    	
    	printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n-----------------NewUser selected\n");
                takeUser();
                break;
            case 2:
                printf("\n-----------------SearchUser selected\n");
                searchUser();
                break;
            case 3:
                printf("\n-----------------DeleteUser selected\n");
                deleteUser();
                break;
            case 4:
                printf("\n-----------------EditUser selected\n");
                editUser();
                break;
            case 5:
                printf("\n-----------------RemakeHash selected\n");
                table = makeHashTable(table);
                printHashTable(table);
                break;
            case 6:
                printf("\n-----------------Show selected\n");
                printHashTable(table);
                break;
            case 7:
                printf("\n-----------------DebugMod selected\n");
                mod = 0;
                break;
            case 8:
                printf("\n-----------------NormalMod selected\n");
                mod = 1;
                break;
            case 0:
                printf("\n-----------------Exiting...\n");
                exit = 0; 
                break;
            default:
                printf("\n-----------------Invalid choice. Please enter a valid option.\n");
                break;
        }
    	
	}
    return 0;
}

