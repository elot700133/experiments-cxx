
//=============================================
// Add two int, check for overflow
// doesn't mod result if it does overflow
// return -1: overflow
// return 0; no overflow

int addOvf(int* result, int a, int b) 
{ 
    // INT_MAX - b provides us maximum that 'a' can be if there is no overflow
    if( a > INT_MAX - b)
        return -1; 
    else
    { 
        *result = a + b; 
        return 0; 
    } 
}


//===============================================
// Add two int, check for overflow
// Will mod result even when there is overflow
//
//
int addOvf(int* result, int a, int b) 
{ 
    *result = a + b;
    // when both `a` and `b` are positive, there is no way result will be negative
    if(a > 0 && b > 0 && *result < 0) 
        return -1; 
    // vice versa
    if(a < 0 && b < 0 && *result > 0) 
        return -1; 
    return 0; 
} 
