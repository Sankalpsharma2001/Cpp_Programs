
#include <iostream>

using namespace std;

int main()
{
    char str[40],ch,*ptr;
    int i=0;
    cout<<"Enter a string"<<endl;
    while((ch=cin.get())!='\n')
    {
        str[i++]=ch;
        
    }
    str[i++]='\0';
    cout<<"Typed string is "<<endl;
    ptr=str;
    while(*ptr!='\0')
    {
        cout<<*ptr;
        ptr++;
    }
    

    return 0;
}
