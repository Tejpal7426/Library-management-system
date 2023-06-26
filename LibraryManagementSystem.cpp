#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<cmath>

using namespace std;

class Library{
    public:
    int id;
    string name;
    string author;
    double price;
    int pages;

    Library(int id, string name, string author, double price, int pages){
        this->id = id;
        this->name = name;
        this->author = author;
        this->price = price;
        this->pages = pages;
    }
};

bool checkId(int id, vector<Library>& lib){
    int count = lib.size();

    for(int i=0;i<count;i++){
        if(lib[i].id == id){
            return true;
        }
    }
    return false;
}

void display(const vector<Library>& lib) {
    cout << "----------------------------------------------------------------------------------------------------------------------------------------\n";
    cout << setw(8) << "Sr. No" << setw(15) << "Book ID" << setw(30) << "Book Name" << setw(30) << "Book Author" << setw(25) << "Book Price" << setw(15) << "Book Pages" << "\n";
    cout << "----------------------------------------------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < lib.size(); i++) {
        cout << setw(8) << (i + 1) << setw(15) << lib[i].id
             << setw(30) << left << lib[i].name.substr(0, 27) << setw(30) << left << lib[i].author.substr(0, 27)
             << setw(25) << fixed << setprecision(2) << (to_string(ceil(100*lib[i].price)/100.0) + "$") << setw(15) << lib[i].pages << "\n";
    }

    cout << "----------------------------------------------------------------------------------------------------------------------------------------\n";
}


void controls()
{
    cout << left;
    cout << setw(63) << "" << "Choose from the following options:\n";
    cout << setw(63) << "" << "Enter 1 to input details like id, name, author, price, pages\n";
    cout << setw(63) << "" << "Enter 2 to display details\n";
    cout << setw(63) << "" << "Enter 3 to update price\n";
    cout << setw(63) << "" << "Enter 4 to delete a book\n";
    cout << setw(63) << "" << "Enter 5 to quit\n";
}



int main(){
    vector<Library> lib{
        {1, "Book1", "Author1 ebjkgrn", 9.99, 200},
        {2, "Book2 jrgjewke rer", "Author2", 14.99, 300},
        {3, "Book3 werg4wg", "Author3 ekbjgrej", 19.99, 400}
    };

    int input=0;
    int count=3;

    cout << endl << endl;
    cout << setw(100) << "|Welcome to Library Management System|" << endl << endl;

    while(input!=5){
        controls();
        cin>>input;

        switch(input){
            case 1:
                {
                    int id, pages;
                    double price;
                    string name, author;

                    cout<<"Enter Book Id"<<endl;
                    cin>>id;

                    while(checkId(id,lib)) {
                        cout<<"Book Id already exists, please enter another id!\n"<<endl;
                        cout << "Enter Book Id" << endl;
                        cin>>id;
                    }

                    cin.ignore();
                    // to clear '\n' of previous input
                    cout<<"Enter Book Name"<<endl;
                    getline(cin, name);

                    cout<<"Enter Book Author name: "<<endl;
                    getline(cin, author);

                    cout<<"Enter Book Price"<<endl;
                    cin>>price;

                    cout<<"Enter Book Pages"<<endl;
                    cin>>pages;

                    lib.push_back(Library(id, name, author, price, pages));

                    count++;
                    break;
                }
            case 2:
                {
                    if(count == 0) cout<<"No books available!\n"<<endl;
                    else display(lib);
                    
                    break;
                }
                
            case 3:
                {
                    int id;
                    cout<<"Enter Book Id to update price"<<endl;
                    cin>>id;
                    bool found = false;

                    for(int i=0;i<count;i++){
                        if(lib[i].id == id){
                            cout<<"Enter new price"<<endl;
                            cin>>lib[i].price;

                            found = true;
                        }
                    }

                    if(!found) {
                        cout<<"Book not found!\n"<<endl;
                    }
                    break;
                }
                

            case 4:
                {
                    int id;
                    cout<<"Enter Book Id to delete"<<endl;
                    cin>>id;

                    bool found = false;

                    for(int i=0;i<count;i++){
                        if(lib[i].id == id){
                            found = true;
                            for(int j=i;j<count-1;j++){
                                lib[j]=lib[j+1];
                            }
                            count--;
                            lib.pop_back();
                            break;
                        }
                    }

                    if(!found) {
                        cout<<"Book not found!\n"<<endl;
                    }
                    break;
                }
            case 5:
                exit(0);
                break;

            default:
                cout<<"You have entered wrong value, please type again"<<endl;

        }
    }

}













