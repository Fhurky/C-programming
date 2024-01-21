#include <stdio.h>
#include <stdlib.h>

// Graf d�g�m� i�in veri yapisi
typedef struct Node{
    int data;
    struct Node* next;
}Node;

// Graf i�in veri yapisi
typedef struct Graph{
    int numVertices;
    Node** adjacencyList;
}Graph;

Graph* createGraph(int numVertices);
void addEdge(Graph* graph, int src, int dst);
void visualizeGraph(Graph* graph);
void removeEdge(Graph* graph, int src, int dst);
Graph* readGraphFromFile();
void adjacencyMatrix(Graph* graph);
void BFS(Graph* graph, int src, int dest,int** matris);
void DFS(Graph* graph, int vertex, int* visited, int* communitySize, int t);
void findCommunities(Graph* graph, int t);

int main(){
	
	int i,j,k,t,max,tmp1,tmp2,km;
	printf("\nK(iterasyon sayisi) ve T(min_topluluk) degerini aralarinda bosluklu giriniz: ");
	scanf("%d %d", &k,&t);
	
    Graph* graph = readGraphFromFile();
    
    //edge_betweenness hesaplayabilmek icin bir dinamik matris ac
    int** edge_betweenness = (int**)malloc(graph->numVertices * sizeof(int*));
    
    for (i=0;i<graph->numVertices;++i){
    	
        edge_betweenness[i] = (int*)malloc(graph->numVertices * sizeof(int));
        // t�m degerleri 0 olarak set et bu sayede edge kullanilirsa deger 1 artacak
        for (j=0;j<graph->numVertices;++j){
            edge_betweenness[i][j] = 0;
        }
    }
    km = k;
    while(k>0){
    //visualizeGraph(graph); 
    //adjacencyMatrix(graph);
    printf("\n------------------------------%d. iterasyon-----------------------------\n",km-k+1);
    for(i=0;i<graph->numVertices;i++){
    	for(j=0;j<graph->numVertices;j++){
    		if(i!=j){
    			BFS(graph, i, j, edge_betweenness);
			}
		}
	}  
   printf("\n");
   printf("Edge betweenness matrisi: \n");
    for(i=0;i<graph->numVertices;i++){ // Matrisi guzel yazdirmak icin g�rsel bi islem yaptim
    	for(j=0;j<graph->numVertices;j++){
    		if(edge_betweenness[i][j]<10)
    		printf("%d  ", edge_betweenness[i][j]);
    		else{
    		printf("%d ", edge_betweenness[i][j]);	
			}
		}
		printf("\n");
	}

	max = 0; // max degerini sifirladik
	printf("\n");
	printf("Edge lerin kullanilma sayilari: \n");
	for(i=0;i<graph->numVertices;i++){ //matriste en b�y�k elemani bulduk
		for(j=0;j<graph->numVertices;j++){
			if(i<j){
			if(edge_betweenness[i][j] !=0 ){
				if(max < edge_betweenness[i][j]){
					max = edge_betweenness[i][j];
				}
				printf("%d-%d: %d",i,j, edge_betweenness[i][j]);
				printf("\n");
			}
		    }
		}
	}
    // matristeki en b�y�k elemanin konumunu bulduk
	tmp1=0, tmp2=0;
	for(i=0;i<graph->numVertices;i++){
		for(j=0;j<graph->numVertices;j++){
			if(max == edge_betweenness[i][j]){
				tmp1 = i;
				tmp2 = j;
			}
		}
	}
	
	// En b�y�k elemani matriste bulduk
	// En b�y�k elemanin i ve y degerleri silinmesi gereken edge i veriyor bize
	removeEdge(graph,tmp1,tmp2);
	removeEdge(graph,tmp2,tmp1);
	
	//silinmesi gereken edge i sildik
	
	printf("\n");
	
	//graph g�sterdik
	visualizeGraph(graph);
	
	// edge betweenness matrisini tekrar sifirladik diger iterasyon icin
	
    for(i=0;i<graph->numVertices;i++){
    	for(j=0;j<graph->numVertices;j++){
    		edge_betweenness[i][j] = 0;
		}
	}
	// edge kaldirildiktan sonra topluluklari bulduk
	
	findCommunities(graph,t);
	printf("\n-----------------------------------------------------------\n");
	k--;
	//diger adima gectik
    }
    
    free(graph);

    return 0;
}
// Yeni bir graf olusturur
Graph* createGraph(int numVertices){
    int i;
    // Graf yapisi i�in bellek ayristir
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    // D�g�m listeleri i�in bellek ayristir
    graph->numVertices = numVertices;
    graph->adjacencyList = (Node**)malloc(numVertices * sizeof(Node*));
    
    // D�g�m listelerini baslangi�ta bos olarak ayarla
    for (i=0;i<numVertices;i++){
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}

// Grafa bir kenar ekler
void addEdge(Graph* graph, int src, int dst){
    // Yeni bir d�g�m olustur ve hedef d�g�m� kayitli oldugu d�g�m listesine ekle
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = dst;
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
    
    // Yeni bir d�g�m olustur ve kaynak d�g�m� kayitli oldugu d�g�m listesine ekle
    Node* newNode1 = (Node*)malloc(sizeof(Node));
    newNode1->data = src;
    newNode1->next = graph->adjacencyList[dst];
    graph->adjacencyList[dst] = newNode1;
}

// Grafigin g�rsellestirmesini yapan fonksiyon
void visualizeGraph(Graph* graph){
	int i;
    printf("Graph Visualization:\n");
    // Her d�g�m i�in bagli oldugu d�g�mleri ekrana yazdirir
    for (i=0;i<graph->numVertices;i++){
        printf("%d : ", i);
        Node* temp = graph->adjacencyList[i];
        while (temp) {
            printf("%d", temp->data);
            temp = temp->next;
            if (temp) {
                printf(",");
            }
        }
        printf(";\n");
    }
    printf("\n");
}

// Iki d�g�m arasindaki baglantiyi kaldiran fonksiyon
void removeEdge(Graph* graph, int src, int dst){
    Node* current = graph->adjacencyList[src];
    Node* previous = NULL;

    // D�g�m� ara
    while(current != NULL && current->data != dst){
        previous = current;
        current = current->next;
    }

    // Baglantiyi kaldir
    if(current != NULL){
        if(previous != NULL){
            previous->next = current->next;
        }else{
            graph->adjacencyList[src] = current->next;
        }
        free(current);
    }
    Node* current1 = graph->adjacencyList[dst];
    Node* previous1 = NULL;

    // D�g�m� ara
    while(current1 != NULL && current1->data != src){
        previous1 = current1;
        current1 = current1->next;
    }

    // Baglantiyi kaldir
    if(current1 != NULL){
        if (previous1 != NULL){
            previous1->next = current1->next;
        }else{
            graph->adjacencyList[dst] = current1->next;
        }
        free(current1);
    }
}

// Dosyadan graf okuma fonksiyonu
Graph* readGraphFromFile(){
    // Dosyayi okuma modunda a�
    FILE* file = fopen("graph3.txt", "r");

    // Dosya a�ilamazsa hata mesajini ekrana yazdir ve programi sonlandir
    if (file == NULL) {
        fprintf(stderr, "Dosya a�ilamadi:\n");
        exit(EXIT_FAILURE);
    }

    // Grafin d�g�m sayisini dosyadan oku ve bir graf olustur
    int numVertices;
    fscanf(file, "%d", &numVertices);
    Graph* graph = createGraph(numVertices);

    int src, dst;
    // Dosyadan kenarlari okuyarak grafa ekleyin
    while (fscanf(file, "%d,%d", &src, &dst) == 2) {
        addEdge(graph, src, dst);
    }

    // Dosyayi kapat
    fclose(file);

    // Olusturulan grafi d�nd�r
    return graph;
}

void adjacencyMatrix(Graph* graph){
	
	int i, j;
    printf("\nAdjacency Matrix:\n");
    for(i=1;i<= graph->numVertices;i++){
        for(j=1;j<=graph->numVertices;j++){
            int isAdjacent = 0;
            Node* temp = graph->adjacencyList[i];

            // D�g�mler arasinda baglanti var mi kontrol et
            while(temp){
                if(temp->data == j){
                    isAdjacent = 1;
                    temp = NULL;
                }
                temp = temp->next;
            }
            printf("%d ", isAdjacent);
        }
        printf("\n");
    } 
}

// BFS ile en kisa yolu bulan fonksiyon
void BFS(Graph* graph, int src, int dest,int** matris){
    int* visited = (int*)malloc((graph->numVertices + 1) * sizeof(int));
    int* parent = (int*)malloc((graph->numVertices + 1) * sizeof(int));

    int i;
    for (i=0;i<=graph->numVertices;i++){
        visited[i] = 0;
        parent[i] = -1;
    }

    // BFS sirasinda kullanilacak kuyruk
    int* queue = (int*)malloc((graph->numVertices + 1) * sizeof(int));
    int front = 0, rear = 0;

    // Baslangi� d�g�m�n� isaretle ve kuyruga ekle
    visited[src] = 1;
    queue[rear++] = src;

    while(front < rear){
        int current = queue[front++];
        Node* temp = graph->adjacencyList[current];

        // Komsu d�g�mleri gez
        while(temp){
            int neighbor = temp->data;

            if(!visited[neighbor]){
                visited[neighbor] = 1;
                parent[neighbor] = current;
                queue[rear++] = neighbor;

                // Hedef d�g�m�ne ulastiysak, yol bulundu demektir
                
                if(neighbor == dest){
                	
                    //printf("Shortest path from %d to %d: ", src, dest);
                    
                    int node = dest;
                    while(node != -1){                    	
                        //printf("%d ", node);                       
                        int tmp = node;
                        node = parent[node];                                         
                        matris[tmp][node]++;
                            
                    }                   
                    // Bellegi serbest birak
                    free(visited);
                    free(parent);
                    free(queue);                                  
                    return;
                }
            }
            temp = temp->next;
        }
    }
    // BFS sona erdi ve hedefe ulasilamadi
    //printf("There is no path from %d to %d.\n", src, dest);
    // Bellegi serbest birak
    free(visited);
    free(parent);
    free(queue);
}
void DFS(Graph* graph, int vertex, int* visited, int* communitySize, int t){
    visited[vertex] = 1;
    printf("%d ", vertex);
    (*communitySize)++;

    Node* temp = graph->adjacencyList[vertex];
    while(temp){
        int neighbor = temp->data;
        if (!visited[neighbor]){
            DFS(graph, neighbor, visited, communitySize, t);
        }
        temp = temp->next;
    }
}

// Topluluklari bulan ve ekrana yazan fonksiyon
void findCommunities(Graph* graph, int t){
    int i;
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));

    for (i=0;i<graph->numVertices;i++){
        visited[i] = 0;
    }

    printf("Communities in the graph:\n");

    for (i=0;i<graph->numVertices;i++){
        if (!visited[i]) {
            printf("Community: ");
            int communitySize = 0; // Toplulugun baslangi� boyutu
            DFS(graph, i, visited, &communitySize, t);

            // Kontrol ekle: Topluluktaki d�g�m sayisi t'den k���kse g�sterme
            if (communitySize >= t) {
                printf("\n");
            } else {
                printf(" (Not shown: size < %d)\n", t);
            }
        }
    }

    free(visited);
}
