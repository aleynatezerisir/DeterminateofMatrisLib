#define CHMAT_UNSIGNED_CHAR     1
#define CHMAT_UNSIGNED_INT      2
#define CHMAT_INT               3
#define CHMAT_FLOAT             4
#define CHMAT_DOUBLE            5


class CHMAT
{
public:
    //members
    int X = 0, Y = 0, type = 0;
    void* data = 0;
    //---constructer & destructor ---------------------
    CHMAT(int x, int y, int typ);
    ~CHMAT();    
    //---methods ---------------------
    int set(int x, int y, int val);
    void print_mat();
    int det_matrix(int matrix[30][30], int n);
   
    //---operators ------------------
    void operator = (int a);
    void operator += (int a);
    void operator -= (int a);
    void operator *= (int a);
    void operator /= (int a);
    int& operator () (int x, int y);
};