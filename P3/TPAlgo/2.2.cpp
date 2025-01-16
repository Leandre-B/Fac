#include <iostream>
#include <string>

struct Fraction{
    int numerateur;
    int denominateur;
};

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
    return fMult;

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
    return fSoustr;
}

Fraction div(struct Fraction f1,struct Fraction f2){
    struct Fraction fdiv;
    fdiv.numerateur = f1.numerateur*f2.denominateur;
    fdiv.denominateur=f1.denominateur*f2.numerateur;
    return fdiv;
}

// int PGCD(int x, int y){
//     if(x<y)
// }

int main(){

    struct Fraction f1,f2,fMult,fOpp,fInv,fSoustr,fdiv;
    std::cout<<"Saisie la 1ere fraction : ";
    saisie(f1);
    std::cout<<"Saisie la 2eme fraction : ";
    saisie(f2);

    std::cout<<"Les fraction sont : ";
    affichache(f1);
    std::cout<<" et "
    affichache(f2);
    std::cout<<std::endl;

    fMult = mult(f1,f2);
    std::cout<<"Multiplication : ";
    affichache(fMult);
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
