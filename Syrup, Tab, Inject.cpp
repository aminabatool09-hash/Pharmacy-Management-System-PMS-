
#include <iostream>
#include <fstream> // ifstream & ofstream etc
#include <iomanip>  // for setw()

using namespace std;

int const Max = 100;

class Pharmacy {
    private: 
		string name_1[Max], formula_1[Max], med_type[Max];
		string name_4, formula_4, name_2;
		int amount_1[Max], total_1[Max], price_1[Max];
		int amount_4, total_4, price_4;
    	int buy_1, amnt_1, bill_1, ttl_1, number;
		char yes_3;
		
	public:
		Pharmacy() {
			ifstream infile("Pharmacy.txt");
			for (int i = 0; i < Max; i++) {
				infile >> name_1[i];
				infile >> formula_1[i];
				infile >> med_type[i];
				infile >> amount_1[i];
				infile >> price_1[i];
				infile >> total_1[i];
			}
		}
		//////////////////////////////////////////////////////////
	
		// list of medicine
		void list()	{
			cout <<  "\n--> List of Medicines available." << endl << endl;
        	cout <<"\tName"<<"\t\tFormula"<<"\t\tType"<<"\t\t\tAmount"<<"      Price"<<" \tTotal." << endl;
            
	 		for (int j = 0; j < Max; j++) {
          	  	if (name_1[j] != "") {
					cout << "-----------------------------------------------------------------------------------" << endl;
        	    	cout << "| " << setw(3) << j+1 << "| ";
					cout << setw(15) << left << name_1[j] <<"|  ";
        	    	cout << setw(20) << formula_1[j] <<"|  ";
        	    	cout << setw(12) << med_type[j] <<"|  ";
            		cout << setw(7) << amount_1[j] <<"|  ";
            		cout << setw(7) << price_1[j] <<"|  ";
            		cout << total_1[j] << endl;
    			}
    			if(name_1[j]=="") {
    				break;
				}
			}
			cout << "-----------------------------------------------------------------------------------" << endl << endl;
		}
	
	
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			
		// search medicine
    	void search_medicine(int &bill_ab) {
    		string name_2;
			cout  << "\n--> Serch Medicine." << endl;
    		cout <<"\tEnter Medicine Name: "; getline(cin, name_2);
    		int r, r1=0, address[Max];
			for(r=0; r<Max; r++) {
    			if(name_2 ==  name_1[r]) {
    				cout << "Serial no: " << r1+1 << endl;
    				cout <<"\n-> Name\t\t  Formula\t   \tType\t    Amount      Price     Total." << endl;
    
            		cout << "-----------------------------------------------------------------------------------" << endl;
            		cout << "-> ";
					cout << setw(15) << left << name_1[r]<<"|  ";
            		cout << setw(20) << formula_1[r]<<"|  ";
	            	cout << setw(10) << med_type[r] <<"|  ";
            		cout << setw(7) << amount_1[r] <<"|  ";
            		cout << setw(7) << left << price_1[r] <<"|  ";
            		cout << left << total_1[r] << endl;
            		cout << endl;
					address[r1] = r;
					r1++;
				}
			}
			if(r1 ==0) {
				char yes_1;
				cout << "\tThis Medicine is not Available. "<< endl;
            	cout << "\n--> Search by Formula for a similar medicine? (Y/N) ";
            	cin >> yes_1;
            	if (yes_1 == 'Y' || yes_1 == 'y') {
                	cin.ignore();
					string formula;
                	cout << "\n\n\tEnter the formula of the medicine: "; getline(cin, formula);
                	wrt_formula(formula);
            	}
			}
			else {
				int r2;
				char yes_2;
            	cout << "\nDo you want to sell the medicine? (Y/N)" ; cin >> yes_2;
            	if (yes_2 == 'Y') {
            		cout << "Enter serial number: "; cin >> r2;
            		if(r2<=r1) {
            			cout << "Address2 = " << address[r2-1] << endl;
            			int r3 = address[r2-1];
            			cout << "R3: " << r3 << endl;
            			sell_medicine(r3);
					}
					else if(r2>r1) {
						cout << "You Exceeded the range..." << endl;
					}
				}
			}
		}
    
   	void wrt_formula(string formula) {
        cout << "\n\n\tSearching for medicines with similar formula...\n" << endl;
        int s, s1=0, address_f[Max]; 
		for ( s = 0; s < Max; s++) {
            if (formula == formula_1[s]) {
                cout << "-> Name\t\t  Formula\t    Amount      Price     Total." << endl;
                cout << "-----------------------------------------------------------------------------------" << endl;
                cout << "-> ";
                cout << setw(15) << left << name_1[s];
                cout << setw(20) << left << formula_1[s];
                cout << setw(10) << left << med_type[s] <<"|  ";
            	cout << setw(7) << left << amount_1[s] <<"|  ";
            	cout << setw(7) << left << price_1[s] <<"|  ";
                cout << left << total_1[s] << endl << endl;
                address_f[s1] = s;
				s1++;
				}
			}
			if(s1 ==0) {
				cout << "\tThis Medicine is not Available... "<< endl;
			}
			else {
				int s2, chk_1 =0;
				char yes_4;
            	cout << "\nDo you want to sell the medicine? (Y/N)" ; cin >> yes_4;
            	do{
					if (yes_4 == 'Y') {
            			cout << "Enter serial number: "; cin >> s2;
            			if(s2<=s1) {
            				cout << "Address2 = " << address_f[s2-1] << endl;
            				int s3 = address_f[s2-1];
            				cout << "S3: " << s3 << endl;
            				sell_medicine(s3);
            				chk_1++;
						}
						else if(s2>s1) {
							cout << "You Exceeded the range..." << endl;
						}
					}
					else{
						return;
					}
				} while (chk_1 < 1);
			}
    }
    
    	////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// add medicine
		void add_medicine() {
			cout << endl;
			cout << "--> Add Medicine. (Press Enter)";
			do{			
				string name_3, formula_3, med_type_3;
				int amount_3, price_3, total_3;
				int no_med = 0;
				cin.ignore();
				cout << "\n\tName: " ; getline(cin, name_3);		
				cout << "\tFormula: "; getline(cin, formula_3);
				cout << "\tType: "; getline(cin, med_type_3);
				cout << "\tAmount: "; cin >> amount_3;
				cout << "\tPrice: "; cin >> price_3;
				total_3 = amount_3 * price_3;
				cout << "\tTotal: " << total_3 << endl;
				ofstream of("Pharmacy.txt", ios::app);
				for (int w=0; w< Max; w++) { // w is ued to check empty slot for new medicine
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
					med_type[no_med] = med_type_3;
					amount_1[no_med] = amount_3;
					price_1[no_med] = price_3;
					total_1[no_med] = total_3;
					//ofstream of("Pharmacy.txt", ios::app);
					of << name_1[no_med] << endl;
					of << formula_1[no_med] << endl;
					of << med_type[no_med] << endl;
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
			number= a;
			int check_f =0;
    		do{
    		cout << "\n\n\tEnter the amount to Sell: "; cin >> buy_1;
    			if (buy_1 <= amount_1[number]) {
        			amnt_1 = amount_1[number] - buy_1;
        			bill_1 = price_1[number] * buy_1;
        			ttl_1 = total_1[number] - bill_1;

      
        			amount_1[number] = amnt_1;
        			total_1[number] = ttl_1;
			
        			ofstream out("Pharmacy.txt");
        			for (int i = 0; i < Max; i++) {
            			if (name_1[i] != "") {
             				out << name_1[i] << endl;
            				out << formula_1[i] << endl;
             	   			out << med_type[i] << endl;
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
        			cout << setw(12) << left << med_type[number];
        			cout << setw(7) << left << amount_1[number];
        			cout << setw(7) << left << price_1[number];
        			cout << left << total_1[number] << endl;

        			cout << "\n\n\tYour Bill to Pay is: " << bill_1 << endl;
        			char yes_5; 
					cout << "\n\n\tFor any Sehat Scheme: (Y/N) ";
        			cin >> yes_5;
        			//cout << "Before: The Value of a = " << a << endl;  // to check error
        			if(yes_5 == 'Y'  || yes_5 == 'y') {
        				a = bill_1;
        				//out << "After: The Value of a = " << a << endl;  // to check error
        				//scheme_bill(int &a);
					}
					else if (yes_5 == 'N'  || yes_5 == 'n'){
						a=-1;  
						cout << "\nMenu:  " ;
					}
					else {
					}
        			cout << "1. Chech_F: " << check_f << endl;
    				check_f++;
    				cout << "2. Chech_F: " << check_f << endl;
				} 
				else {
        			cout << "\tThis amount is NOT AVAILABLE." << endl;
    			}
    		} while(check_f < 1);
		}
		
		void new_list() {
        	for (int i = 0; i < Max; i++) {
            	if (amount_1[i] != 0) {
            		do{
            			
					} while(name_1[i]=="");
            	}
        	}
        	ofstream out("Pharmacy.txt");
        	for (int i = 0; i < Max; i++) {
            	out << name_1[i] << endl;
            	out << formula_1[i] << endl;
            	out << med_type[i] << endl;
				out << amount_1[i] << endl;
            	out << price_1[i] << endl;
            	out << total_1[i] << endl;
        	}
        	out.close();
		}
	 ~Pharmacy() {} // Destructor
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
			int temp_c_id = c_id;
			cout << "temp_c_id = " << temp_c_id << endl;
			cout << "c_id = " << c_id << endl;
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
				cout << "Z = " << z << endl;
				cout << "C = " << c << endl;
				//c=0;
				z=0;
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
	int choice, a=-1;  // a is used for 2 main purposes 1. For Index (in fewer cases)   2. For Bill (mostly used)
	
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
			//p1.sell_medicine(a);
			p1.search_medicine(a);
			p1.sell_medicine(a);  
		} else if(choice == 5) {
			cout << "\nThanks for Using. " << endl;
		} else {
			cout << "Invalid Option... " << endl;
			break;
		}
		//cout << "1---> A: " << a << endl;
		if(a!=-1){
			cout << "Value of a is: " << a << endl;
			p2.scheme_data();
			p2.scheme_discount(a);  // here a is used for bill
			a = -1;
			//cout << "2---> A: " << a << endl;
		}
	} while (choice != 5);
}
