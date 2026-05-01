#include <iostream>
#include <fstream> // ifstream & ofstream etc
#include <iomanip>  // for setw()
//#include <conio.h> //for ASCII codes
using namespace std;



class Pharmacy {
    private: 
		string name_1[100], name_4, formula_1[100], formula_4;
		string name_2;
		char yes_3;
		int amount_1[100], amount_4, total_1[100], total_4, price_1[100], price_4;
		//ifstream infile;
		//sell_medicine inicializations
		int buy_1;
    	int amnt_1, bill_1, ttl_1, number;
		
	public:
//		void file_read() {
		Pharmacy() {
			ifstream infile("PMS1.txt");
			for (int i = 0; i < 100; i++) {
				infile >> name_1[i];
				infile >> formula_1[i];
				infile >> amount_1[i];
				infile >> price_1[i];
				infile >> total_1[i];
			}
		}
		//////////////////////////////////////////////////////////
	
		// list of medicine
		void list()	{
			cout << endl;
			cout <<  "--> List of Medicines available." << endl;
			cout << endl;
        	cout <<"\tName"<<"\t\tFormula"<<"\t\t\tAmount"<<"      Price"<<" \tTotal." << endl;
            
	 		for (int j = 0; j < 100; j++) {
          	  if (name_1[j] != "") {
				cout << "-----------------------------------------------------------------------------------" << endl;
        	    cout << "| " << setw(3) << j+1 << "| ";
				cout << setw(15) << left << name_1[j] <<"|  ";
        	    cout << setw(20) << left << formula_1[j] <<"|  ";
            	cout << setw(10) << left << amount_1[j] <<"|  ";
            	cout << setw(10) << left << price_1[j] <<"|  ";
            	cout << left << total_1[j] << endl;
    			}
    			if(name_1[j]=="") {
    				break;
				}
			}
			//cout << endl;
			cout << "-----------------------------------------------------------------------------------" << endl;
			cout << endl;
		}
	
	
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
		// search medicine
    	void search_medicine(int &bill_ab) {
			cout  << "\n--> Serch Medicine." << endl;
    		string name_2;
    		cout <<"\tEnter Medicine Name: "; getline(cin, name_2);
    		int r;
			for(r=0; r<100; r++) {
    			if(name_2 ==  name_1[r]) {
    				cout << endl;
    				cout <<"-> Name\t\t  Formula\t    Amount      Price     Total." << endl;
    
            		cout << "-----------------------------------------------------------------------------------" << endl;
            		cout << "-> ";
					cout << setw(15) << left << name_1[r];
            		cout << setw(20) << left << formula_1[r];
	            	cout << setw(10) << left << amount_1[r];
	            	cout << setw(10) << left << price_1[r];
            		cout << left << total_1[r] << endl;
            		cout << endl;
            		char yes_3;
            		cout << "\nDo you want to sell this? (Y/N)" ; cin >> yes_3;
            		if (yes_3 == 'Y') {
            			sell_medicine_a(r);
            			bill_ab = r;
            			
					}
					break;
				}
			}
			if(r==100) {
				cout << "\tThis Medicine is not Available. "<< endl;
				char yes_4;
            	cout << "\n--> Search by Formula for a similar medicine? (Y/N) ";
            	cin >> yes_4;
            	if (yes_4 == 'Y' || yes_4 == 'y') {
                	cin.ignore();
                	string formula;
                	cout << "\n\n\tEnter the formula of the medicine: "; getline(cin, formula);
                	wrt_formula(formula);
            	}
			}
		}
    
   	void wrt_formula(string formula) {
        cout << "\n\n\tSearching for medicines with similar formula...\n" << endl;
        int s; 
		for ( s = 0; s < 100; s++) {
            if (formula_1[s] == formula) {
                cout << "-> Name\t\t  Formula\t    Amount      Price     Total." << endl;
                cout << "-----------------------------------------------------------------------------------" << endl;
                cout << "-> ";
                cout << setw(15) << left << name_1[s];
                cout << setw(20) << left << formula_1[s];
                cout << setw(10) << left << amount_1[s];
                cout << setw(10) << left << price_1[s];
                cout << left << total_1[s] << endl << endl;
                char yes_5;
            		cout << "\nDo you want to sell this? (Y/N)" ; cin >> yes_5;
            		if (yes_5 == 'Y') {
            			sell_medicine_a(s);
					}
				break;
            }
        }
        if (s==100) {
            cout << "No medicines found with formula: " << formula << endl;
        }
    }
    
    	////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// add medicine
		void add_medicine() {
			cout << endl;
			cout << "--> Add Medicine. (Press Enter)";
			do{			
				string name_3, formula_3;
				int amount_3, price_3, total_3;
				int no_med = 0;
				cin.ignore();
				cout << "\n\tName: " ; getline(cin, name_3);		
				cout << "\tFormula: "; getline(cin, formula_3);
				cout << "\tAmount: "; cin >> amount_3;
				cout << "\tPrice: "; cin >> price_3;
				total_3 = amount_3 * price_3;
				cout << "\tTotal: " << total_3 << endl;
				ofstream of("PMS1.txt", ios::app);
				for (int w=0; w< 100; w++) { // w is ued to check empty slot for new medicine
					if(name_1[w]=="") {  
						//cout << "\nThe Value for w: " << w << endl;   //to check
						no_med = w;
						cout << "\n\tThe Serial number for new Medicine is: " << no_med + 1 << endl;
						break;
					} 
				}
				if(no_med != 0) {
					name_1[no_med] = name_3;
					formula_1[no_med] = formula_3;
					amount_1[no_med] = amount_3;
					price_1[no_med] = price_3;
					total_1[no_med] = total_3;
					//ofstream of("PMS1.txt", ios::app);
					of << name_1[no_med] << endl;
					of << formula_1[no_med] << endl;
					of << amount_1[no_med] << endl;
					of << price_1[no_med] << endl;
					of << total_1[no_med] << endl;
				}
			 cin.ignore();
			cout << "\nAdd more (Y/N). "; cin >> yes_3;
			}	while(yes_3 == 'Y' || yes_3 == 'y');		
		} 
			
	
	
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		// sell medicine
		void sell_medicine(int &a) {
			cin.ignore();
//    		string name_2;
    		cout << "\n\tEnter Medicine Name: "; getline(cin, name_2);
    		cout << endl;
    		cout << setw(56) << "\n--> Sell Medicine." << endl;
			int r;
    		for (r = 0; r < 100; r++) {
        		if (name_2 == name_1[r]) {
    				cout <<"-> Name\t\t  Formula\t    Amount      Price     Total." << endl;
            		cout << "-----------------------------------------------------------------------------------" << endl;
            		cout << setw(15) << left << name_1[r];
            		cout << setw(20) << left << formula_1[r];
            		cout << setw(10) << left << amount_1[r];
            		cout << setw(10) << left << price_1[r];
            		cout << left << total_1[r] << endl;
            		a = r;
            		break;
        		}
    		}

    		if (r == 100) {
      	  		cout << "  This Medicine is NOT AVAILABLE. " << endl;
        		return;
    		}
    		//sell_medicine_a(number);
		}
		void sell_medicine_a(int &a) {
			number= a;
    		cout << "\n\n\tEnter the amount to Sell: "; cin >> buy_1;
    		if (buy_1 <= amount_1[number]) {
        		amnt_1 = amount_1[number] - buy_1;
        		bill_1 = price_1[number] * buy_1;
        		ttl_1 = total_1[number] - bill_1;

      
        		amount_1[number] = amnt_1;
        		total_1[number] = ttl_1;
			
        		ofstream out("PMS1.txt");
        		for (int i = 0; i < 100; i++) {
            		if (name_1[i] != "") {
             			out << name_1[i] << endl;
            			out << formula_1[i] << endl;
             	   		out << amount_1[i] << endl;
             	   		out << price_1[i] << endl;
             	   		out << total_1[i] << endl;
            		}
        		}
        		out.close();

    			cout <<"-> Name\t\t  Formula\t    Amount      Price     Total." << endl;
        		cout << "-----------------------------------------------------------------------------------" << endl;
        		cout << setw(15) << left << name_1[number];
        		cout << setw(20) << left << formula_1[number];
        		cout << setw(10) << left << amount_1[number];
        		cout << setw(10) << left << price_1[number];
        		cout << left << total_1[number] << endl;

        		cout << "\n\n\tYour Bill to Pay is: " << bill_1 << endl;
        		char yess_1; 
				cout << "\n\n\tFor any Sehat Scheme: (Y/N) ";
        		cin >> yess_1;
        		//cout << "Before: The Value of a = " << a << endl;  // to check error
        		if(yess_1 == 'Y'  || yess_1 == 'y') {
        			a = bill_1;
        			//out << "After: The Value of a = " << a << endl;  // to check error
        			//scheme_bill(int &a);
				}
				else if (yess_1 == 'N'  || yess_1 == 'n'){
					a=1;  
					cout << "\nMenu:  " ;
				}
				else {
				}
        		cout << endl;
    		} 
			else {
        		cout << "\tThis amount is NOT AVAILABLE." << endl;
    		}
		}

};
class Scheme : public Pharmacy {
	protected:
		long long c_id, check_length2;
		//int bill;
		//int c = 1;
		//int z = 0;
	public:
	void scheme_data() {
		int c=0;
		cout << "\n\n ---> Enter 12 Digit Card Number: " ;
		do{
			//cout << "Enter Scheme Name (Optional- Put Nil): "; getline(cin, scheme_name); //optional
			cin >> c_id;                      // c_id is the ID Number of Sehat Card
			long long temp_c_id = c_id;
//			cout << "temp_c_id = " << temp_c_id << endl;
//			cout << "c_id = " << c_id << endl;
    		int z = 0;
    		while (temp_c_id > 0) {
        		temp_c_id /= 10;
        		z++;
    		}
    		cout << "temp_c_id = " << temp_c_id << endl;
			//cout << "check_length == " << check_length << endl;      // to check error	
			if(z==12) {
				c++;
			} 
			else{
				cout << "\tPlease enter 12 digit input: ";
//				cout << "Z = " << z << endl;
//				cout << "C = " << c << endl;
				//c=0;
				z=0;
				cin.clear();
				cin.ignore();
				//c++;
			}
		} while (c==0);
	}
	void scheme_discount(int &bill) {
		//bill = a;
		while(check_length2 > 9999) {
			check_length2 = check_length2/10;	
		}
		if(check_length2 == 1234) {
			cout << "\n\tThe discount for this card is 55 perscent." << endl;
			bill = bill - bill * 0.55;
			cout << "\n\tThe bill after discount is: " << bill << endl;
		} else if(check_length2 == 1111) {
			cout << "\n\tThe discount for Special person card is 75 perscent." << endl;
			bill = bill - bill * 0.75;
			cout << "\n\tThe bill after discount is: " << bill << endl;
		} else {
			//cout << "check_length == " << check_length2 << endl;  // to check errror
			cout << "\n\tThe discount for normal card is 40 percent. " << endl;		
			bill = bill - bill * 0.4;
			cout << "\n\tThe bill after discount is: " << bill << endl;;
		}
	}
};

int main() {
	Pharmacy p1;
	Scheme p2;
	int choice, a=1;  // a is used for 2 main purposes 1. For Index (in fewer cases)   2. For Bill (mostly used)
	
	do {
		cout <<"\n1) Show List." << endl;
		cout <<"2) Search Medicine. " << endl;
		cout <<"3) Add Medicine. "<< endl;
		cout <<"4) Sell Medicine. " << endl;
		cout <<"5) Exit."; cin >> choice;
		cin.ignore();
//		p1.file_read();
		if(choice == 1) {
			p1.list();
		} else if(choice == 2) {
			p1.search_medicine(a);
		} else if(choice == 3) {
			p1.add_medicine();
		} else if(choice == 4) {
			p1.sell_medicine(a);
			p1.sell_medicine_a(a);  
		} else if(choice == 5) {
			cout << "\nThanks for Using. " << endl;
		} else {
			cout << "Invalid Option... " << endl;
			break;
		}
		//cout << "1---> A: " << a << endl;
		if(a!=1){
			cout << "Value of a is: " << a << endl;
			p2.scheme_data();
			p2.scheme_discount(a);  // here a is used for bill
			a = 1;
			//cout << "2---> A: " << a << endl;
		}
	} while (choice != 5);
}
