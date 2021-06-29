#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include "chmat.h"

int FillBMPInfo(BITMAPINFO* info, int x, int y, int bits)
{
    info->bmiHeader.biBitCount = bits;
    info->bmiHeader.biClrImportant = 0;
    info->bmiHeader.biClrUsed = 0;
    info->bmiHeader.biCompression = BI_RGB;
    info->bmiHeader.biHeight = y;
    info->bmiHeader.biPlanes = 1;
    info->bmiHeader.biSize = sizeof(BITMAPINFO);
    info->bmiHeader.biSizeImage = x * y * bits / 8;
    info->bmiHeader.biWidth = x;
    info->bmiHeader.biXPelsPerMeter = 0;
    info->bmiHeader.biYPelsPerMeter = 0;
    return(0);
}


CHMAT::CHMAT(int x, int y, int typ)
{ 
    if (typ == CHMAT_UNSIGNED_CHAR)
        data = calloc(x * y, sizeof(char));
    else if (typ == CHMAT_INT)
        data = calloc(x * y, sizeof(int));
    else if (typ == CHMAT_FLOAT)
        data = calloc(x * y, sizeof(float));
    else if (typ == CHMAT_DOUBLE)
        data = calloc(x * y, sizeof(double));
    else if (typ = CHMAT_UNSIGNED_INT)
        data = calloc(x * y, sizeof(int));
    if (data != NULL)
    {
        X = x;
        Y = y;
        type = typ;
    }
}



CHMAT::~CHMAT() { free(data); }



int CHMAT::set(int x, int y, int val)
{
    if (x<1 || x>X) return (-1);
    if (y<1 || y>Y) return (-1);
    if (type == CHMAT_UNSIGNED_CHAR)
        ((unsigned char*)data)[(y - 1) * X + (x - 1)] = val;
    else if (type == CHMAT_INT)
        ((int*)data)[(y - 1) * X + (x - 1)] = val;
    else if(type == CHMAT_DOUBLE)
        ((double*)data)[(y - 1) * X + (x - 1)] = val;
    else if (type == CHMAT_FLOAT)
        ((float*)data)[(y - 1) * X + (x - 1)] = val;
    else if (type == CHMAT_UNSIGNED_INT)
        ((unsigned int*)data)[(y - 1) * X + (x - 1)] = val;
    return 0;
}

void CHMAT::print_mat()
{
    int x, y;
    unsigned char* ucd = (unsigned char*)data;
    int* id = (int*)data;
    double* dd = (double*)data;
    float* fd = (float*)data;
    unsigned int* uid = (unsigned int*)data;
    int matrix[30][30];
    for (y = 0; y < Y; y++)
    {
        for (x = 0; x < X; x++)
        {
            if (type == CHMAT_UNSIGNED_CHAR){
                printf("%d ", ucd[y * X + x]);
                matrix[y][x] = ucd[y * X + x];
            }
            else if (type == CHMAT_INT) {
                printf("%d ", id[y * X + x]);
                matrix[y][x] = id[y * X + x];
            }
            else if (type == CHMAT_DOUBLE) {
                printf("%d ", dd[y * X + x]);
                matrix[y][x] = dd[y * X + x];
            }
                
            else if (type == CHMAT_FLOAT) {
                printf("%d ", fd[y * X + x]);
                matrix[y][x] = fd[y * X + x];
            }
            else if (type == CHMAT_UNSIGNED_INT) {
                printf("%d ", uid[y * X + x]);
                matrix[y][x] = uid[y * X + x];
            } 
        }
        printf("\n");
    }
    printf("\n");

    printf("Determinate of the matrix: %d\n",det_matrix(matrix,X));
}

//30 veya daha küçük matrisin determinantýný hesaplayan fonksiyon...
int CHMAT::det_matrix(int matrix[30][30],int n) {
    int det = 0;
    int submatrix[30][30];

    if (n == 2)
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    else {
        for (int x = 0; x < n; x++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, x) * matrix[0][x] * det_matrix(submatrix, n - 1));
        }
    }
    return det;
}