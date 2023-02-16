#include <iostream>
#include <cstring>
#include "singleDoubleArr.h"
using namespace std;

#define ENCRYPTION "@@@"

int main()
{
    SingleDoubleArray SDA;

    char **arr = new char *[3];
    arr[0] = "Salman";
    arr[1] = "Naeem";
    arr[2] = "Sadiq";


    // SDA.displayDoubleArray(arr,3);  // working
    // SDA.displaySingleArray(singleArr);  // working
    // SDA.trimSingleArray(singleArr,5,strlen(singleArr)); //working
    // SDA.trimDoubleArray(arr,1,3); // working
    // SDA.calcSingleSize(arr,ENCRYPTION,3); // working
    // SDA.calcDoubleSize(singleArr, ENCRYPTION); // working
    // SDA.getSingleArray(arr,ENCRYPTION, 3)
    // SDA.getDoubleArray(singleArr,ENCRYPTION);

    int singleSize = SDA.calcSingleSize(arr,ENCRYPTION,3);
    cout<<"Single Size"<<singleSize<<endl;

    
    char *singleArr = SDA.getSingleArray(arr, ENCRYPTION, 3);
    cout << singleArr<<endl;


    int doubleSize = SDA.calcDoubleSize(singleArr, ENCRYPTION);
        cout<<"Double  Size"<<doubleSize<<endl;

    char** doubleArr = SDA.getDoubleArray(singleArr,ENCRYPTION);

    SDA.displayDoubleArray(doubleArr,doubleSize);
    return 1;
}
