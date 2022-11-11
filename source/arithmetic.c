#include <stdio.h>

int main() {

   int a = 21;
   int b = 10;
   int c ;
   printf("A is %d\n",a);
   printf("B is %d\n",b);
   c = a + b;
   printf("Addition - Value of c is %d\n", c );

   c = a - b;
   printf("Substraction - Value of c is %d\n", c );

   c = a * b;
   printf("Multiplication - Value of c is %d\n", c );

   c = a / b;
   printf("Divide - Value of c is %d\n", c );

   c = a % b;
   printf("Modulus - Value of c is %d\n", c );

   c = a++;
   printf("Increament - Value of c is %d\n", c );

   c = a--;
   printf("Decrement - Value of c is %d\n", c );
}
