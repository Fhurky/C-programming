#include<stdio.h>
#include<math.h>

int screen(){
	int decision;	
	printf("Choose what you want to do\n\n");
	printf("1 for addition\n");
	printf("2 for extraction\n");
	printf("3 for multiplication\n");
	printf("4 for division\n");
	printf("5 for modding\n");
	printf("6 for exponentiation\n");	
	printf("Otherwise for exit\n");
	printf("\n--> ");	
	scanf("%d", &decision);
	return decision;
}

int main(){
	
	float numb1,numb2;
	int exit = 1,decision;
	
	while(exit){
		decision = screen();
		
		switch(decision){
			case 1:
				printf("----> addition\n\n");
				printf("Enter two numbers with blank between them\t");scanf("%f %f",&numb1,&numb2);
				printf("%.2f + %.2f = %.2f\n\n",numb1,numb2,numb1+numb2);
				break;
			
			case 2:
				printf("----> extraction\n\n");
				printf("Enter two numbers with blank between them\t");scanf("%f %f",&numb1,&numb2);
				printf("%.2f - %.2f = %.2f\n\n",numb1,numb2,numb1-numb2);
				break;
				
			case 3:
				printf("----> multiplication\n\n");
				printf("Enter two numbers with blank between them\t");scanf("%f %f",&numb1,&numb2);
				printf("%.2f x %.2f = %.4f\n\n",numb1,numb2,numb1*numb2);
				break;
				
			case 4:
				printf("----> division\n\n");
				printf("Enter two numbers with blank between them\t");scanf("%f %f",&numb1,&numb2);
				printf("%.2f / %.2f = %.4f\n\n",numb1,numb2,numb1/numb2);
				break;
				
			case 5:
				printf("----> modding\n\n");
				printf("Enter two numbers with blank between them\t");scanf("%f %f",&numb1,&numb2);
				printf("%d MOD %d = %d\n\n",(int)numb1,(int)numb2,(int)numb1%(int)numb2);
				break;
				
			case 6:
				printf("----> exponentiation\n\n");
				printf("Enter two numbers with blank between them\t");scanf("%f %f",&numb1,&numb2);
				printf("%d^%d = %.0lf\n\n",(int)numb1,(int)numb2,pow((int)numb1,(int)numb2));				
				break;
								
			default:
				printf("EXIT...\n\n");
				return;
		}	
		
		printf("If you want to \ncountinue : 1 stop: 0:  ");scanf("%d", &exit);
	}
	
	return 0;
}