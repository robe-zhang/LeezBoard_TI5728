__kernel void matrix_transposition(__global int* a, __global int* b)
{
    int col = get_global_id(0);
    int row = get_global_id(1);
  
    b[col*4+row] = a[row*4+col]; 
}

