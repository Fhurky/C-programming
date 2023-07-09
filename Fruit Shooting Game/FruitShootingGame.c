#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define MAX 20

struct node{
	int main;
	int main_2;                                                            //*********************BST nod yapımız
	struct node *right;
	struct node *left;
};
typedef struct{
	int item[MAX];
	int top;                                                               //**************Stack yapımız(DERSTTE ANLATILAN GİBİ)
}STACK;

struct node *yeni_node(int item) {
    struct node *tmp = (struct node *)malloc(sizeof(struct node));         //BST ye nod eklemek icin kullanılan yeni_node yapısı
    tmp->main = item;
    tmp->main_2 = item;
    tmp->left = NULL;
	tmp->right = NULL;
    return tmp;
}

int isEmpty(STACK *s);                                                      //****************************stack ile ilgili fonksiyonlar
int isFull(STACK *s);
int push(STACK*s,int x);
int pop(STACK *s,int *X);
int peek(STACK*s,int *X);
void stack_yazdir(STACK*s);

void sil_node(struct node **root, int key);                                 //******************************BST ite ilgili fonksiyonlar
struct node *insert(struct node *node, int main);
struct node *arama(struct node* root, int key);
int *meyveler(int N, int M);
void inorder(struct node *root);

int main(){
	int i,N,M,karar;
	
	printf("Meyve sayisini giriniz: ");scanf("%d",&M);
	karar = M;
	printf("\nMax meyve agirligini giriniz:  ");scanf("%d",&N);
	
	if(M>N){
		printf("\nMeyve sayisi max meyve agirliginden fazla olamaz, Programdan cikiliyor...");
		return 0;
	}
	
   //**********Meyveleri olusturma	

	int *dizi = (int*)malloc(sizeof(int));
	dizi = meyveler(N,M);
	
	struct node *root = NULL;
	root = insert(root, dizi[0]);
	
   //**********diziyi nodlara yerlestirme islemi
   
	for(i=1;i<M;i++){
		insert(root, dizi[i]);
	}
	
    //Meyve vurma islemi
    
     
    printf("\nNOT: BST'nin ekrana yazdirma islemi inorder siralamasina uygun yapildigindan BST ekrana kucukten buyuge gosterilecek(Siralama islemi yapilmadi)\n\n"); //!!!!!!!!!!!!!!!!!!!!!!!!!!!
    inorder(root);
    printf("\n");
    
    STACK *kova = (STACK*)malloc(sizeof(STACK));
    STACK *kova2 = (STACK*)malloc(sizeof(STACK));
    
    struct node *tmp2;
    int numara = 0,hit = 0;
    while(karar>0){                                                                                                                                    //Balon vurma islemi************************
    	printf("\nVurmak istediginiz meyveyi numarasi ve hasari aralarinda bosluk birakarak giriniz (A B): ");scanf("%d %d", &numara,&hit);             
    	  
    	tmp2 = arama(root,numara);
    	tmp2->main_2 = (tmp2->main_2) - hit;
    	
    	if(tmp2->main_2 <= 0){ 		
    		push(kova,tmp2->main);
    		sil_node(&root,numara);
    		karar = karar-1;
		}	
    	printf("\n");
    	inorder(root);
	}
	
    i=M;
    
    int *tmp3 = (int*)malloc(sizeof(int));
    
    while(i>0){
    	pop(kova,tmp3);
    	push(kova2,*tmp3);
    	i--;
	}
	printf("\nDusme sirasina gore: ");
	stack_yazdir(kova2);

	inorder(root);
	free(dizi);
	return 0;
}

int *meyveler(int N,int M){
	int i,j;
	srand(time(NULL));
	
//elemanları olusturma	
 
	int *dizi = (int*)malloc(M*sizeof(int));
     for (i=0; i<M; i++){
        int r = rand()%N+1;
        j=0;
        while (j<i && dizi[j]!=r){
            j++;
        }
        if (j==i){
            dizi[i]=r;
        } else {
            i--;
        }
    }
	return dizi;    
}
struct node *insert(struct node *node, int main){	//Derstte anlatılan gibi recursive insert fonksiyonu

    if (node == NULL){
	    return yeni_node(main);
    }

    if(main < node->main){
        node->left = insert(node->left, main);
    }
   
    else if (main > node->main){
        node->right = insert(node->right, main);
    }

    return node;
}
void inorder(struct node *root){                    //Derstte anlatılan gibi soldan yukarı eğer sağ altta nod varsa onları da alarak yukarı çıkan yazdırma yapısı
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->main);
        inorder(root->right);
    }

}
void sil_node(struct node** root, int key) {       //node silen asıl işin yapıldığı kısım BST korunuyor

    while (*root != NULL) {
        struct node *temp = *root;

        if (key < temp->main){
            root = &temp->left;
        }
        else if (key > temp->main){
            root = &temp->right;
        }    
        else {
            if (temp->left == NULL) {
                *root = temp->right;
                free(temp);
                return;
            }
            else if (temp->right == NULL) {
                *root = temp->left;
                free(temp);
                return;
            }
            struct node *min = temp->right;
            while (min->left != NULL){
                min = min->left;
            }
            temp->main = min->main;
            temp->main_2 = min->main_2;
            root = &temp->right;
            key = min->main;
        }
    }


    if (*root == NULL) {
        printf("BST artık bos!\n");
    }
}
struct node *arama(struct node* root, int key){    //arama yapıp bulunan meyvenin adresini döndürüyor
    if (root == NULL || root->main == key) {
        return root;
    }
    if (key < root->main) {
        return arama(root->left, key);
    }
    return arama(root->right, key);
}

int isEmpty(STACK *s){                             //Dersttekinin aynısı
	if(s->top == 0){
		return 1;
	}
	else{
		return 0;
	}
}
int isFull(STACK *s){                              //Dersttekinin aynısı     
	if(s->top == MAX){
		return 1;
	}
	else{
		return 0;
	}
}
int push(STACK *s,int x){                          //Dersttekinin aynısı
	if(isFull(s)){
		return 0;
	}
	else{
		s->item[s->top] = x;
		++s->top;
		return 1;
	}
}
int pop(STACK *s,int *X){                          //Dersttekinin aynısı
	if(isEmpty(s)){
		return 0;
	}
	else{
		--s->top;
		*X = s->item[s->top];
		return 1;
	}
}
int peek(STACK *s,int *X){                         //Dersttekinin aynısı
	int adr;
	if(isEmpty(s)){
		return 0;
	}
	else{
		adr= s->top-1;
		*X = s->item[adr];
		return 1;
	}
}
void stack_yazdir(STACK *s){                       //stack boş olana kadar filo yapısına göre en üstteki elemanı pop layıp ekrana basıyor(Sadece yazdırmıyor stack yapısını da bosaltıyor)
	int *X = (int*)malloc(sizeof(int));
	while(!isEmpty(s)){
		pop(s,X);
		printf("%d ",*X);
	}
}