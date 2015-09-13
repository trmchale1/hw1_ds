#include <stdio.h>
#include <string.h>

struct order {
	char type;
	char item[20];
	int cust_num;
	int trans_num;
	int price;
	int quantity; 
};

struct payment {
	char type;
	int cust_num;
	int trans_num;
	int price;
};

int main(int argc, char **argv)
{
	FILE *f;
	char buf1;
	char buf2[20];
	int buf3,buf4,buf5,buf6;
	
	f = fopen("transactions.txt","r");

	struct order allOrders[100];
	struct payment allPAyments[100];

	int numOrders = 0;
	int numPAyments = 0;

	struct order first;
	struct payment second;
	 while(fscanf((FILE*)f,"%c\n",&buf1) != EOF){
	 	if(buf1 == 'O'){
                first.type = buf1;
                printf("%c ", first.type);
                
                fscanf((FILE*)f,"%s\n",buf2);
                strcpy(first.item,buf2);
                printf("%s ",first.item);
                
                fscanf((FILE*)f,"%d\n",&buf3);
                first.cust_num = buf3;
                printf("%d ",first.cust_num);
                
                fscanf((FILE*)f,"%d\n",&buf4);
                first.trans_num = buf4;
                printf("%d ",first.trans_num);
                
                fscanf((FILE*)f,"%d\n",&buf5);
                first.price = buf5;
                printf("%d ",first.price);

                fscanf((FILE*)f,"%d\n",&buf6);
                first.quantity = buf6;
                printf("%d\n",first.quantity);

                allOrders[numOrders] = first;
                numOrders++;  
        }
        else{
        		second.type = buf1;
        		printf("%c ", second.type);

        		fscanf((FILE*)f,"%d\n",&buf3);
        		second.cust_num = buf3;
        		printf("%d ",second.cust_num);

        		fscanf((FILE*)f,"%d\n",&buf4);
                second.trans_num = buf4;
                printf("%d ",second.trans_num);

                fscanf((FILE*)f,"%d\n",&buf5);
                second.price = buf5;
                printf("%d\n",second.price);

                allPAyments[numPAyments] = second;
                numPAyments++;
        }
     }       

     	/*Now I have two arrays of type struct, containing all orders and all payments*/

	return 0;
}
