#include <iostream>
#include <string>
#include <cmath>
struct Fraction{
    int numerateur;
    int denominateur;
};

int pgcd(int x, int y){
    if(x<y) return pgcd(y,x);
    if(x%y==0) return y;
    else return pgcd(y,x%y);
}

Fraction simpl(struct Fraction f){
    int pgcdF=pgcd(std::abs(f.numerateur),std::abs(f.denominateur));
    f.numerateur/=pgcdF;
    f.denominateur/=pgcdF;
    return f;
}

void saisie(struct Fraction & fraction){
    int deno,nume;
    std::cout<<"Saisir le numerateur : ";
    std::cin>>nume;

    std::cout<<"Saisir le denominateur : ";
    std::cin>>deno;

    fraction.numerateur = nume;
    fraction.denominateur = deno;
}

void affichache(struct Fraction fraction){
    std::cout<<fraction.numerateur<<"/"<<fraction.denominateur;
}

Fraction mult(struct Fraction f1,struct Fraction f2){
    struct Fraction fMult;
    fMult.numerateur=f1.numerateur * f2.numerateur;
    fMult.denominateur = f1.denominateur*f2.denominateur;
    return simpl(fMult);

}

Fraction add(struct Fraction f1,struct Fraction f2){
    struct Fraction fAdd;
    fAdd.numerateur = f1.numerateur*f2.denominateur + f2.numerateur*f1.denominateur;
    fAdd.denominateur=f1.denominateur*f2.denominateur;
    return simpl(fAdd);
}

Fraction opp(struct Fraction f1){
    struct Fraction fOpp;
    fOpp.numerateur=-f1.numerateur;
    fOpp.denominateur = f1.denominateur;
    return fOpp;
}

Fraction inv(struct Fraction f1){
    struct Fraction fInv;
    fInv.numerateur=f1.denominateur;
    fInv.denominateur = f1.numerateur;
    return fInv;
}

Fraction soustr(struct Fraction f1,struct Fraction f2){
    struct Fraction fSoustr;
    fSoustr.numerateur = f1.numerateur*f2.denominateur - f2.numerateur*f1.denominateur;
    fSoustr.denominateur=f1.denominateur*f2.denominateur;
    return simpl(fSoustr);
}

Fraction div(struct Fraction f1,struct Fraction f2){
    struct Fraction fdiv;
    fdiv.numerateur = f1.numerateur*f2.denominateur;
    fdiv.denominateur=f1.denominateur*f2.numerateur;
    return simpl(fdiv);
}

int main(){

    struct Fraction f1,f2,fMult,fAdd,fOpp,fInv,fSoustr,fdiv;
    std::cout<<"Saisie la 1ere fraction : ";
    saisie(f1);
    std::cout<<"Saisie la 2eme fraction : ";
    saisie(f2);

    std::cout<<"Les fraction sont : ";
    affichache(f1);
    std::cout<<" et ";
    affichache(f2);
    std::cout<<std::endl;

    fMult = mult(f1,f2);
    std::cout<<"Multiplication : ";
    affichache(fMult);
    std::cout<<std::endl;

    fAdd = add(f1,f2);
    std::cout<<"Addtion : ";
    affichache(fAdd);
    std::cout<<std::endl;

    fOpp = opp(f1);
    std::cout<<"Opposee : ";
    affichache(fOpp);
    std::cout<<std::endl;

    fInv = inv(f1);
    std::cout<<"Inverse : ";
    affichache(fInv);
    std::cout<<std::endl;

    fSoustr = soustr(f1,f2);
    std::cout<<"Soustraction : ";
    affichache(fSoustr);
    std::cout<<std::endl;

    fdiv = div(f1,f2);
    std::cout<<"Division : ";
    affichache(fdiv);
    std::cout<<std::endl;

    return 0;
}
