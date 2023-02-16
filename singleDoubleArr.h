#include <iostream>
#include <cstring>
using namespace std;

class SingleDoubleArray{
public:
char *getSingleArray(char **, char *, int);
char **getDoubleArray(char *, char *);

void displaySingleArray(char *);
void displayDoubleArray(char **, int);

int calcSingleSize(char **, char *, int);
int calcDoubleSize(char *, char *);

char** trimDoubleArray(char**,int s,int e);
char* trimSingleArray(char*,int s,int e);

bool isCharSame(char*,char*,int);

};

char* SingleDoubleArray::getSingleArray(char **in, char *enc, int s)
{
    // Calulate Single Array Result Size
    int size = calcSingleSize(in, enc,s);

    // Dynamically Allocate Size
    char *result = nullptr;
    result = new char[size + 1];
    memset(result, 0, size + 1); // set all bytes to zero

    // Converting Double Array into Single Array
    int index = 0;
    for (int i = 0; i < s; i++)
    {
        // Store  Value
        for (int j = 0; j < strlen(in[i]); j++)
        {
            result[index++] = in[i][j];
        }
        // Store Encrypted Value
        for (int j = 0; j < strlen(enc); j++)
        {
            result[index++] = enc[j];
        }
    }
    return result;
}
char** SingleDoubleArray::getDoubleArray(char* arr,char* enc){
    int e_size = strlen(enc);

    int size = calcDoubleSize(arr,"@@@");

     char** result = new char* [size];
     int index=0;

    // functions to set Data in Result
    int s=0;
    for(int i=0; i<strlen(arr);i++){
        if(isCharSame("@@@",arr,i)){
            // Encrypt Value find  break and store
            result[index++]= trimSingleArray(arr,s,i-1);
            s=i+e_size;
            
        }
    }

     return result;

}

void SingleDoubleArray::displaySingleArray(char* arr){
    cout<<arr<<endl;
}
void SingleDoubleArray::displayDoubleArray(char** arr,int n){
    for(int i=0 ;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

int SingleDoubleArray::calcSingleSize(char **arr, char *enc, int s)
{
    int encrSize = strlen(enc);
    int size = 0;
    for (int i = 0; i < s; i++)
    {
        size += strlen(arr[i]);
        size += encrSize;
    }
    return size;
}
int SingleDoubleArray::calcDoubleSize(char *arr, char *enc)
{
    int size = 0;
    char *word;
    int s_size = strlen(arr);
    int e_size = strlen(enc);
    //Comparing Values from first till last including last variable of encryp
    for (int i = 0; i < s_size - e_size +1;) 
    {
        if (isCharSame(enc, arr, i))
        {   
            // Values matches
            size++;
            i += e_size;
        }
        else
        {
            // values not matches
            i++;
        }
    }
    return size;
}

char* SingleDoubleArray::trimSingleArray(char* arr,int s_index,int e_index){
    int size = e_index-s_index+1;
    char *trimed = nullptr;
    trimed = new char[size + 1];
    memset(trimed, 0, size + 1);

    for(int i=0 ; i<size;i++){
        trimed[i]=arr[s_index+i];
    }
    return trimed;
}
char** SingleDoubleArray::trimDoubleArray(char** arr,int s_index,int e_index){
    int size = e_index-s_index+1;
    char** trimed = new char* [size];

    for(int i=0 ; i<size;i++){
        trimed[i]=arr[s_index+i];
    }
    return trimed;
}

bool SingleDoubleArray::isCharSame(char *a, char *b, int s)
{
    int a_size = strlen(a);
    bool isSame = true;
    for (int i = 0; i < a_size; i++)
    {
        if (b[s + i] != a[i])
        {
            isSame = false;
            break;
        }
    }
    return isSame;
}


