/*
    Programme de Léandre Bodo MI 3B
Exercice 2.8) 2)
-Demande 2 dates à l'utilisateur
-Vérifie que ces dates sont valides
-si oui affiche le nombre d'années pleines écoulées entre elles
 var j = jour, m = mois, a = annee
*/
#include <iostream>

//vérifie qu'une année est bixextille ou non
bool bisextille(int annee){
    
    if( (((annee %4 == 0 and annee %100 !=0) or (annee % 400 == 0)) and (annee >= 1582)))
        return true;
        
    return false;
}
 
//vérifie si une date est valide
bool anneeValide(int j, int m, int a){
    
    if( a>=0 and (m <= 12 and m>0) and j > 0){
        if ((m == 1 or m == 3 or m == 5 or m == 7 or m == 8 or m == 10 or m == 12) and j <=31)
            return true;
            
        if ((m == 4 or m == 6 or m == 9 or m == 11) and j <=30)
            return true;
            
        if ((m == 2) and (bisextille (a)) and j <=29)
            return true;
            
        if ((m == 2) and !(bisextille (a)) and j <=28)
            return true;
    }
    return false;
}

//calcule le nombre d'année pleines entre deux dates
int anneesEcoulees(int j1, int j2, int m1, int m2, int a1, int a2){
    
    if ((a2>=a1) or (a2==a1 and m2>=m1) or (a2==a1 and m2==m1 and j2>=j1)){ // si date 2 > date 1
        if((j2<j1 and m2==m1) or (m2<m1))
            return (a2 - a1 -1);
        else
            return (a2-a1);
    }else{ //date 1 > date 2
        if((j1<j2 and m1==m2) or (m1<m2))
            return (a1 - a2 -1);
        else
            return (a1-a2);
    }
}

 int main(){
 
    int j1, j2, m1, m2, a1,a2;
    
    do{
        std::cout << "entrez une date valide (jour, mois, annee) " << std::endl;
        std::cin >> j1 >> m1 >> a1;
    }while (!(anneeValide(j1, m1, a1)));
    
    do{
        std::cout << "entrez une AUTRE date valide (jour, mois, année) " << std::endl;
        std::cin >> j2 >> m2 >> a2;
    }while (!(anneeValide(j2, m2, a2)));
    
    
    std :: cout << "Il s est ecoule " << anneesEcoulees(j1, j2, m1, m2, a1, a2) << " annee(s) complete(s) entre le "
                << j1 << "/" << m1 << "/" << a1 << " et le "
                << j2 << "/" << m2 << "/" << a2;
 return 0;
 }