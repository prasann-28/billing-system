#include<iostream>
#include<fstream>

using namespace std;

class Shopping
{
private:
    int pcode;
    float product_price;
    float dis;
    char name;
public:
    Shopping();

    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void remove_item();
    void list();
    void receipt();

};

void Shopping :: menu(){
    m:
    int choice;
    string email;
    string password;

    cout << "\t\t\t\t ____________________________________________________________________\n";
    cout << "\t\t\t\t                                                                     \n";
    cout << "\t\t\t\t            Supermarket Main Menu                                                         \n";
    cout << "\t\t\t\t                                                                     \n";
    cout << "\t\t\t\t ____________________________________________________________________\n";

    cout << "\t\t\t\t| 1] Administrator         |\n";
    cout << "\t\t\t\t|                          |                                           \n";
    cout << "\t\t\t\t| 2] Buyer                 |\n";
    cout << "\t\t\t\t|                          |                                           \n";
    cout << "\t\t\t\t| 3] Exit                 |\n";
    cout << "\t\t\t\t|                          |                                           \n";
    cout << "\t\t\t\t| Please Select: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        {cout << "\t\t\t\t\tPlease Login";
        cout << "Enter Email: ";
        cin >> email;
        cout << "Enter Password";
        cin >> password;

        if(email=="admin@test.com" && password=="admin@test.com"){
            administrator();
        }
        else{
            cout << "Invalid Password";
        }
        break;}
    case 2:
        {
            buyer();
        }
    case 3: {
        exit(0);
    }
    default:
        cout << "Select from given options";
        break;
    }

    goto m;
}

void Shopping :: administrator(){

    m:
    int choice;
    cout << "\n\t\t\t Administrator Menu";
    cout << "\n\t\t\t______________________";
    cout << "\n\t\t\t 1. Add the product";
    cout << "\n\t\t\t 2. Modify the product";
    cout << "\n\t\t\t 3. Delete the product";
    cout << "\n\t\t\t 4. Back to main menu";
    cout << "\n\t\t\t Enter your choice";
    cin >> choice;
    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        remove_item();
        break;
    case 4:
        menu();
        break;
    default:
        break;
    }
    goto m;

}

void Shopping :: buyer(){
    m:
    int choice;
    string product;

    cout << "\n\t\t\t Buyer Menu";
    cout << "\n\t\t\t______________________";
    cout << "\n\t\t\t 1. Buy the product";
    cout << "\n\t\t\t 2. Go back";
    cout << "\n\t\t\t Enter your choice";

    cin >> choice;

    switch (choice)
    {
    case 1:
        {
            receipt();
            break;
        }
    case 2:
        menu();
        break;

    default:

        break;
    }
    goto m;
}

void Shopping :: add() {
    m:
    fstream db1;
    int code;
    int token =0;
    float price;
    float discount;
    string pname;

    cout << "\n\t\t\t______________________";
    cout << "\n\t\t\t Add new product";
    cout << "\n\t\t\t Enter product code";
    cin >> code;
    cout << "\n\t\t\t Enter Name of product";
    cin >> name;
    cout << "\n\t\t\t Enter Price of product";
    cin >> price;
    cout << "\n\t\t\t Enter Discount of product";
    cin >> discount;

    db1.open("db.txt", ios::in);

    if(!db1){
        db1.open("db.txt", ios::app|ios::out);
        db1 << " " << code << " " << name << " " << price << " " << discount << " \n";
        db1.close();
    }
    else{

        db1 >> pcode >> name >> product_price >> dis;

        while(!db1.eof()){
            if(code == pcode){
                token++;
            }
            db1 >> pcode >> name >> price >> dis;
        }

        db1.close();

            

    if(token==1){
        goto m;
    }
    else{
        db1.open("db.txt", ios::app|ios::out);
        db1 << " " << code << " " << pname << " " << price << " " << discount << " \n";
        db1.close();
    }
    }
    cout << "Record inserted";
}

void Shopping :: edit(){
    fstream f, f1;
    int code;
    int newcode;
    int token =0;
    float price;
    float discount;
    string pname;

    cout << "\n\t\t\t______________________";
    cout << "\n\t\t\t Modify Record";
    cout << "\n\t\t\t Enter product code";
    cin >> code;

    f.open("db.txt");
    if(!f){
        cout<<"\nFile doesn't exist";
    }
    else{
        f1.open("db1.txt",ios::app|ios::out);
        f >> pcode >> name >> price >> dis;
        if(code==pcode){
            cout << "\n\t\t\t Enter new product code";
            cin >> newcode;
            cout << "\n\t\t\t Enter new name ";
            cin >> pname;
            cout << "\n\t\t\t Enter new price";
            cin >> price;
            cout << "\n\t\t\t Enter new discount";
            cin >> discount;

            f1 << " " << code << " " << pname << " " << price << " " << discount << " \n";
            token++;
        }
            else{
             f1 << " " << pcode << " " << name << " " << product_price << " " << dis << " \n";
            }
            f >> pcode >> name >> product_price >> dis;
        }

        f.close();
        f1.close();

        remove("db.txt");
        rename("db1.txt", "db.txt");

        if(token==0){
            cout << "Record Not Foumd!";
        }
        }

void Shopping :: remove_item(){
    fstream f,f1;
    int pkey, token=0;
    cout << "\nDelete Product";
    cout <<"\nEnter Product code";
    cin >> pkey;
    f.open("db.txt", ios::in);

    if(!f){
        cout << "File doesnt exists" << endl;
    }
    else{
        f1.open("db1.txt",ios::app|ios::out);
        f>>pcode>>name>>product_price>>dis;

        while(!f.eof()){
            if(pcode==pkey){
                cout << "Product deleted successfully";
                token++;
            }
            else{
                f1 << " " << pcode << " " << name << " " << product_price << " " << dis << " \n";
                
            }

            f>>pcode>>name>>product_price>>dis;

        }
        f.close();
        f1.close();

        remove("db.txt");
        rename("db1.txt", "db.txt");

        if(token==0){
            cout << "Record Not Foumd!";
        }
        
    }
}

void Shopping :: list(){
    fstream data;
    data.open("db.txt",ios::in);
    cout << "\n\n_____________________________________________\n"<< "";
    cout << "Product No, Name, Price, ";
    data >> pcode >> name >> product_price >> dis;
    while(!data.eof()){
        cout << pcode << name << product_price << endl;
        data >> pcode >> name >> product_price >> dis;
    }
    data.close();
}

void Shopping :: receipt(){
    m:
    fstream data;
    int arrc[100];
    int arrq[100];
    int counter = 0;
    float amount = 0;
    float dis =0 ;
    float total = 0;
    char choice = 'a';

    cout << "Receipt\n";

    data.open("db.txt", ios::in);
    if(!data){
        cout << "Empty db";
    }
    else{
        data.close();
        list();
        cout<<"\n______________________________________"<< endl;
        cout << "Please place the order";
        cout<<"\n______________________________________"<< endl;
        cout<<"\n______________________________________"<< endl;

        do{
            cout << "Enter product code:";
            cin >> arrc[counter];
            cout << "Enter product quantity:";
            cin >> arrq[counter];

            for(int i =0; i < counter; i++){
                if(arrc[counter]==arrc[i]){
                    cout << "duplicate";
                    goto m;
                }

            }
            counter++;
            cout <<"\n\n cont.? y or n";
            cin >> choice;
        }
        while(choice=='y');

        cout << "\n Receipt"<<endl;
        cout << "Product No, Name, Price, ";
        for(int i=0; i<counter; i++){
            data.open("db.txt",ios::in);
            data >> pcode >> name >> product_price >> dis;
            while(!data.eof()){
                if(arrc[i]==pcode){
                    amount = product_price * arrq[i];
                    int t =0 ;
                    t = amount - ((amount*dis)/100);
                    total = total + t;
                    cout << pcode << name << product_price << endl;
                }
                data >> pcode >> name >> product_price >> dis;
            }

        }
        data.close();

    }

    cout << "______________________________\n\n";
    cout << "Total Amount: \t" << total << endl;



}

int main(){
    Shopping s;
    s.menu();

}
Shopping::Shopping(/* args */)
{
}

// Shopping::~Shopping()
// {
// }

