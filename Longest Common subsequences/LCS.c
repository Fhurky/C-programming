#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int max(int a, int b);
int LCSLength(char *str1, char *str2, int m, int n, int T[m+1][n+1]);
void findLCS(char *str1, char *str2, int m, int n, int T[m+1][n+1], char *lcs, int i, int j, int length, char ***allLCS, int *count);
void checkUniqueness(char **allLCS, int count);
void createSelectedMatrix(char *str1, char *str2, int m, int n, int T[m+1][n+1], int **selected);
void printMatris(char *str1, char *str2, int m, int n, int T[m+1][n+1]);

void wait(double seconds);

int main(){
	
	int i,j;
    char str1[20];
    char str2[20];
    
    printf("Enter the first string: ");  // MAERBPHCAPPBA (1.String)
    scanf("%s", &str1);
    printf("Enter the second string: "); // AMRRERCHAZBZA (1.String)
    scanf("%s", &str2);
    
    int m = strlen(str1);
    int n = strlen(str2);

    int T[m+1][n+1]; // LCS matrisimiz tanimlandi
    
    int **selected = malloc((m+1)*sizeof(int *));  // Selected matrisi olusturuldu
    for(i=0;i<=m;i++){
        selected[i] = malloc((n+1)*sizeof(int));
    }
    
    int length = LCSLength(str1, str2, m, n, T);  // lenght hesbi yapildi
    
    if(length == 1){                                                    // Eger ayni kelimenin tam tersi yazilmis ve kelime harfleri unique ise 
    	printf("\nEslesen en az 2 uzunluklu string bulunamadi...\n");   // recursive'den dolayi cok fazla fonksiyon cagriliyor ve hata olusmasini sagliyor
    	return 0;                                                       // length == 1 mi diye kontrol edip sorunu cozmek istedim
	}
	
	printf("\nLongest length: %d\n", length);  // Longest length yazdirildi

    char lcs[length+1];                        // Son elemani null olan char dizisi olusturuldu
    lcs[length] = '\0';

    char **allLCS = malloc(200 * sizeof(char *));   // 100 charlik kapasitede tümm lcs leri tutan matris tanimlandi( her satirda bir string seklinde düsünülebilir )
    int count = 0;
   
    createSelectedMatrix(str1, str2, m, n, T, selected); // Selected (1/0) fonksiyonu
    
    findLCS(str1, str2, m, n, T, lcs, m, n, length, &allLCS, &count); // lCS fonksiyonu cagrildi
    
    checkUniqueness(allLCS, count);

    for(i=0;i<count;i++){ //free islemleri
        free(allLCS[i]); 
    }
    free(selected);
    free(allLCS);

    return 0;
}
int max(int a, int b){
	//-------------------------
	//a>b ise a yi degil ise b yi returnler
	//-------------------------
    return (a>b) ? a : b;
}

int LCSLength(char *str1, char *str2, int m, int n, int T[m+1][n+1]){
	//-------------------------
	//LCS Matrisini olusturur ilk satir ve sutun = 0
	//sonrasinda sirayla derstte isledigimiz metodala matrisi doldurur
	//matrisin sag en altindaki deger longest lenghti verir
	//-------------------------
	int i,j;
	for(i=0;i<=m;i++){
		for(j=0;j<=n;j++){
			T[i][j] = 0;
		}
	}
	
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            if(i==0||j==0){
                T[i][j] = 0;
            }else if(str1[i-1] == str2[j-1]){
                T[i][j] = T[i-1][j-1] + 1;
            }else{
                T[i][j] = max(T[i-1][j], T[i][j-1]);
            }
        }
        //printf cagir   
        printMatris(str1, str2,  m,  n, T);
        wait(0.7);     //0.7 saniye beklet
        system("cls"); // ekrani temizler      
    }
    printf("\n------------LCS MATRIS-----------\n\n");
    printf("    ");
    for(i=0;i<n;i++){
        printf("%c ", str2[i]);
    }
    printf("\n");

    for(i=0;i<=m;i++){
        if(i>=1){
            printf("%c ", str1[i-1]);
        }else{
            printf("  ");
        }

        for(j=0;j<=n;j++){
            printf("%d ", T[i][j]);
        }

        printf("\n");
    }
    
    printf("\n-----------------------\n");
    
    return T[m][n];
}
void findLCS(char *str1, char *str2, int m, int n, int T[m+1][n+1], char *lcs, int i, int j, int length, char ***allLCS, int *count){
	//-------------------------
	// Recursive olarak calisi
	// harfler esit ise capraza ilerler
	// yoksa üst büyükse üste ilerler
	// yoksa sol büyükse sola ilerler
	// yoksa sol ve üst esit demektir ve iki taraftan da ilerlenir
	// bu durumda ayni sonuclar elde edilme ihtimali dogar
	// bu sorun print fonksiyonunda cozüldü
	//-------------------------
    int k;
    if(i == 0 || j == 0){ 
        char *newLCS = malloc((length + 1)*sizeof(char));
        strcpy(newLCS, lcs);
        (*allLCS)[(*count)++] = newLCS; //count degerini sürekli kullanmak icin     
        return;
    }

    if(str1[i-1] == str2[j-1]){ 	
        lcs[length-1] = str1[i-1];
        findLCS(str1, str2, m, n, T, lcs, i-1, j-1, length-1, allLCS, count); // sol üst
        
    }else if(T[i-1][j] > T[i][j-1]){
        findLCS(str1, str2, m, n, T, lcs, i-1, j, length, allLCS, count); // üst
        
    }else if(T[i][j-1] > T[i-1][j]){    	
        findLCS(str1, str2, m, n, T, lcs, i, j-1, length, allLCS, count); // sol     
		      
    }else{	
        findLCS(str1, str2, m, n, T, lcs, i-1, j, length, allLCS, count); // üst
        findLCS(str1, str2, m, n, T, lcs, i, j-1, length, allLCS, count); // sol   
    }
}
void checkUniqueness(char **allLCS, int count){
	//---------------------------------
	// allLcs dizisindeki unique degerler yazdirildi
	//---------------------------------
	int i,j,isUnique,cnt = 1;
    printf("\nBenzersiz LCS'ler:\n");
    
    for(i=0;i<count;i++){
        isUnique = 1;
        for(j=0;j<i && isUnique;j++){
            if (strcmp(allLCS[i], allLCS[j]) == 0){
                isUnique = 0;
            }
        }
        if(isUnique){
            printf("%d. %s\n", cnt,allLCS[i]);
            cnt++;
        }
    }
}
void createSelectedMatrix(char *str1, char *str2, int m, int n, int T[m+1][n+1], int **selected){
	//------------------------------------------
	// Ek matris 0 olarak set edildi eger harf kullanilmis ise 1 olarak degistirildi
	// En sonda ekranda yazdilirdi
	//------------------------------------------
	int i,j;
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            if(i==0 || j==0){
                T[i][j] = 0;
                selected[i][j] = 0; // Ek matrisi baslangiçta 0 olarak ayarla
            }else if(str1[i-1] == str2[j-1]){
                selected[i][j] =  1;
            }else{
        
                selected[i][j] = 0; // Eslesme yoksa 0 olarak ayarla
            }
        }
    }
    printf("\n------------SELECTION MATRIS-----------\n\n");
    printf("    ");
    for(i=0;i<n;i++){
        printf("%c ", str2[i]);
    }
    printf("\n");

    for(i=0;i<=m;i++){
        if(i>=1){
            printf("%c ", str1[i-1]);
        }else{
            printf("  ");
        }

        for(j=0;j<=n;j++){
            printf("%d ", selected[i][j]);
        }

        printf("\n");
    }
    
    
    printf("\n-----------------------\n");
}
void printMatris(char *str1, char *str2, int m, int n, int T[m+1][n+1]){
	//------------------------------------
	// printleme fonksiyonu (matris)
	//------------------------------------
	int i,j;
	printf("\n------------SELECTION MATRIS CALCULATING-----------\n\n");
	printf("    ");
	for(i=0;i<n;i++){
        printf("%c ", str2[i]);
    }
    printf("\n");
    for(i=0;i<=m;i++){
        if(i>=1){
            printf("%c ", str1[i-1]);
        }else{
            printf("  ");
        }
        for(j=0;j<=n;j++){
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }
    printf("\n-----------------------\n");
}
void wait(double seconds){
	//------------------------
	// Bekletme fonksiyonu
	//-----------------------
    time_t sec = (time_t)seconds; // saniyeyi al
    long nsec = (seconds - (double)sec) * 1e9; // nanosaniyeye çevir

    struct timespec req, rem;

    req.tv_sec = sec;
    req.tv_nsec = nsec;

    while(nanosleep(&req, &rem) == -1){
        // Eger beklenen süre boyunca bir sinyal alinirsa geri kalan zamani ayarla
        req = rem;
    }
}
