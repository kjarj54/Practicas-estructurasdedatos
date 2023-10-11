#include <iostream>

using namespace std;


int decimalAbinario(int x,int i){
    if(x>0){
        return (x%10)*pow(2,i)+decimalAbinario(x/10,i+1);
    }else {
        return 0;
    }
}


int funX(int x,int i){
    if(x>0){
        return (x%2)*pow(10,i)+decimalAbinario(x/10,i+1);
    }else {
        return 0;
    }
}

int binarioAdecimal(int x,int i){
    if(x>0){
        int decimal=x%10;
        int po=pow(2,i);
        return decimal*po+binarioAdecimal(x/10,i+1);
    }else {
        return 0;
    }
}


int main(){
    cout<<decimalAbinario(10,0)<<endl;

    cout<<binarioAdecimal(11,0)<<endl;

    cout<<funX(111,0)<<endl;


}



