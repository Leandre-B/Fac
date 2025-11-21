#include <iostream>

int fonction(int x, int y){
    if(x==0) return (y+1);
    else if(x>0 and y==0) return fonction(x-1,1);
    else return fonction(x-1,fonction(x,y-1));
}


int main(){
    for(int x = 0;x<=3;++x){
        for(int y = 0;y<=3;++y){
            std::cout<<"fonction("<<x<<","<<y<<")="<<fonction(x,y)<<std::endl;
        }
    }

    return 0;
}
