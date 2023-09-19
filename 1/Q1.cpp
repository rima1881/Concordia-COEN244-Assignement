#include <iostream>
#include <vector>
#include "./Driver.hpp"
#include  "./TA.hpp"


int main(){

    using namespace std;

    vector<TA> data;


    cout << "\nOpenning The file\n";

    //openning the file
    Driver driver("./db.txt");


    cout << "reading the data\n";
    data = driver.readFile();
    //if data size is 0 there was a problem with txt or there was nothing in txt
    //eithere way running the rest of program is useless
    if(data.size() == 0){
        cout << "\ncan not read data!!! (press ctrl+c to stop program)";
        while (true);
        
    }

    


    cout << "checking the data\n";
    //checking ta's status
    for(int i=0;i < data.size();i++)
        if(!data[i].checkStatus())
            //removing extra data
            data.erase(data.begin() + i);


    cout << "updating the files\n";
    if(!driver.updateFile(data)){
        cout << "there was an error!!! with the file while updating (press ctrl+c to stop program)";
        while (true);
    }

    cout << "the operation finished\n\n";

    return 0;
}