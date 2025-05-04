#include<iostream>
#include<string>
using namespace std;
const int t=10;
struct person{
    string name;
    long long phone;
};
class hasht{
    person*table[t];
    bool occupied[t];
    public:
    hasht(){
        for(int i=0;i<t;i++){
            table[i]=nullptr;
            occupied[i]=false;
        }

    }
    public:
    int hashfunc(long long phone){
        return phone%t;
    }
    void add(string name,long long phone){
        int index=hashfunc(phone);
        int i=0;
        int nindex;
        while(i<t){
            nindex=(index+i*i)%t;
            if(!occupied[nindex]){
                table[nindex]=new person{name,phone};
                occupied[nindex]=true;
                cout<<"insearts:"<<name<<"at index"<<" "<<nindex<<endl;
                return;
            }
            else if(table[nindex] && table[nindex]->phone==phone){
                cout<<"double number is not allowed:";
                return;
            }
            i++;
        }
        cout<<"table is full:";
    }
    int search(long long phone,string& foundname){
        int index=hashfunc(phone);
        int comparison=0;
        int i=0;
        while(i<t){
            int nindex=(index+i*i)%t;
            comparison++;
            if(!occupied[nindex]){
                foundname=" ";
                return comparison;
            }
            if(table[nindex]&& table[nindex]->phone==phone){
                foundname=table[nindex]->name;
                return comparison;
            }
            i++;
        }
        foundname=" ";
        return comparison;
    }
    void display() {
        cout << "\n--- Hash Table ---\n";
        for (int i = 0; i < t; i++) {
            if (table[i]) {
                cout << i << " -> " << table[i]->name << " : " << table[i]->phone << endl;
            } else {
                cout << i << " -> [empty]";
            }
        }
    }
};
int main(){
    hasht tb;
    int n;
    cout<<"enter a number of person:";
    cin>>n;
    for(int i=0;i<n;i++){
        string name;
        long long phone;
        cout<<"enter a name and phone number of the person:";
        cin>>name>>phone;
        tb.add(name,phone);
    }
    tb.display();

    int m;
    cout<<"enter a how many numbers to search:";
    cin>>m;
    for(int i=0;i<m;i++){
        long long phone;
        cout<<"enter a phone number to search:";
        cin>>phone;
        string name;
        int comparison=tb.search(phone,name);
        if(name != ""){
            cout << "found: " << name << " with " << comparison << " comparisons.";
        }
        else{
            cout<<"data is not found:";
        }
        

        
    }
    return 0;
}