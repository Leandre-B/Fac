#include <iostream>
#include <math.h>
#include <string>

bool validTriangle(float a, float b, float c){

    if(a>=0 or b>=0 or c>=0 ){
        if((a>=b and a>=c) and a<=(b+c))
            return true;
        if((b>=a and b>=c) and b<=(a+c))
            return true;
        if((c>=a and c>=b) and c<=(a+b))
            return true;
    }
    return false;
}

float perimTriangle(float a,float b,float c){
    return (a+b+c);
}

float aireTriangle(float a,float b,float c){
    float s=((a+b+c)/2.0);
    return (sqrt(s*(s-a)*(s-b)*(s-c)));
}

bool equi(float a,float b,float c){
    if(a==b and b==c)
        return true;
    return false;
}

bool iso (float a, float b, float c){
    if(a==b or a==c or b==c )
        return true;
    return false;

}

bool rect (float a, float b, float c){
    if( (a*a)==(b*b + c*c) or (b*b)==(a*a + c*c) or (c*c)==(b*b + a*a) )
        return true;
    return false;

}

bool plat (float a, float b, float c){
    if( a==(b + c) or b==(a + c) or c==(b + a) )
        return true;
    return false;
}

std::string natureTriangle (float a, float b, float c){
    if(equi(a,b,c))
        return "triangle equilateral";
    if(iso(a,b,c)){
        if(rect(a,b,c))
            return "triangle isocele et rectangle";
        if(plat(a,b,c))
            return "triangle isocele et plat";
        else
            return "triangle isocele";
    }
    if(rect(a,b,c))
        return "triangle rectangle";
    if(plat(a,b,c))
        return "triangle plat";
    return "triangle quelconque";
}


void coteTriangle(float & a, float & b, float & c){
    std::cin>>a>>b>>c;
}

int main(){

    float a,b,c;
    do{
        std::cout<<"Longueur des cotes : ";
        coteTriangle(a,b,c);
        if(!validTriangle(a,b,c))
            std::cout<<"Triangle invalide, recommencez."<<std::endl;
    }while(!validTriangle(a,b,c));


    std::cout<<"Il s'agit d'un " << natureTriangle(a,b,c)<< " de perimetre "<<perimTriangle(a,b,c)<<" et d'aire "<<aireTriangle(a,b,c)<<std::endl;

    return 0;
}
