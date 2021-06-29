// CHMAT_Console.cpp : 
#include <stdlib.h>
#include <stdio.h>
#include "chmat.h"


int main()
{
    
    //CHMAT m(3, 3, CHMAT_UNSIGNED_CHAR);
    CHMAT m(4, 4, CHMAT_INT);
    m.set(1,1,1);
    m.set(1, 2, 3);
    m.set(2, 1, 2);
    m.set(2, 2, 4);
    m.set(1, 3, 5);
    m.set(2, 3, 6);
    m.set(3, 3, 17);
    m.set(3, 2, 8);
    m.set(3, 1, 9);
    m.set(1, 4, 10);
    m.set(2, 4, 11);
    m.set(3, 4, 12);
    m.set(4, 1, 13);
    m.set(4, 2, 14);
    m.set(4, 3, 15);
    m.set(4, 4, 16);
    m.print_mat();
    //the rest might crash for char type why?
   
}