#include <iostream>
#include <math.h>
using namespace std;

int deciTobin(int n){

    float ans = 0, i = 0, rem, bit;
 
 while (n != 0)
    {
        bit = n & 1;
        ans += (bit * pow(10, i));
        n = n >> 1;
        i++;
    }
    return ans ;

}

int binTodeci(int m ){

    int ans =0 , i=0 , rem ;

    while(m!=0){

        rem=m%10;
        ans+=(rem*pow(2,i));
        m/=10;
        i++;

    }
    return ans ;
}

int main()
{
    int m;
    
    

       cout << deciTobin(45) << endl ;

       cout << binTodeci(101101) << endl ;

    
    

    return 0;
}


/* 
2's compliment 

1. find 1's complient == flip 1-0 ans 0-1
2. add 1 to 1's complment
*/
