#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct order {
	char type;
	string item;
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
	char buf1;
	string buf2;
	int buf3,buf4,buf5,buf6;
    
    ifstream myfile;
    myfile.open ("transactions.txt");
	if(myfile.fail()){
        cout << "could not open up file" << endl;
        return 0;
    }


    struct order first;
    struct payment second;

    struct order allOrders[100];
	struct payment allPAyments[100];

	int numOrders = 0;
	int numPAyments = 0;
    
	 while(!myfile.eof()){
	 	myfile >> buf1;
        if(buf1 == 'O'){
                
                first.type = buf1;
                cout << first.type << endl;

                myfile >> buf2;
                first.item = buf2;
                cout << first.item << endl;

                myfile >> buf3;
                first.cust_num = buf3;
                cout << first.cust_num << endl;

                myfile >> buf4;
                first.trans_num = buf4;
                cout << first.trans_num << endl;

                myfile >> buf5;
                first.price = buf5;
                cout << first.price << endl;

                myfile >> buf6;
                first.quantity = buf6;
                cout << first.quantity << endl;

                allOrders[numOrders] = first;

                numOrders++;  
        }
        else{
                
        		second.type = buf1;
        		cout << second.type << endl;
        		
                myfile >> buf3;
        		second.cust_num = buf3;
        		cout << second.cust_num << endl;

        		myfile >> buf4;
                second.trans_num = buf4;
                cout << buf4 << endl;

                myfile >> buf5;
                second.price = buf5;
                cout << buf5 << endl;

                allPAyments[numPAyments] = second;
                numPAyments++;
        }
     }       

       // myfile.close();
     	/*Now I have two arrays of type struct, containing all orders and all payments*/

	return 0;
}
