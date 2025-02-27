# include <iostream>
# include <array>
using tab_int = std :: array < int , 5 >;

bool miroirs(tab_int t1, tab_int t2, int n){
    if(n<4/2) return true;
    else{
        if(t1[4-n]==t2[n])
            return miroirs(t1,t2,n-1);
        else return false;
    }

}

int main ()
{
    tab_int t1 = {3 , 8 , 12 , 0 , 7} , t2 = {7 , 0 , 12 , 8 , 3};
    std :: cout << " t1 et t2 miroirs ? " << miroirs ( t1 , t2 , 4);
    t2 [2] = -31;
    std :: cout << "nt1 et t2 miroirs ? " << miroirs ( t1 , t2 , 4);
    return 0;
}
