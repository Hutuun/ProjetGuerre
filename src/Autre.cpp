#include "Autre.h"

char convertNbtoChar(int i)
{
    if(i==0)
        return '0';
    else if(i==1)
        return '1';
    else if(i==2)
        return '2';
    else if(i==3)
        return '3';
    else if(i==4)
        return '4';
    else if(i==5)
        return '5';
    else if(i==6)
        return '6';
    else if(i==7)
        return '7';
    else if(i==8)
        return '8';
    else if(i==9)
        return '9';
    return ' ';
}

std::string convertIntToString(int i)
{
    if(i==0)
        return "0";
    std::string tempo,res;
    while(i!=0)
    {
        int c = i%10;
        i = i/10;
        tempo += convertNbtoChar(c);
    }
    for(unsigned int i=tempo.size()-1;i<tempo.size();i--)
    {
        res += tempo[i];
    }
    return res;
}
