#include <iostream>
#include <vector>

std::vector<int> saisir() {
    std::vector<int> v;
    int n = 1;
    while(n) {
        std::cin>>n;
        if(n!=0) {
            std::cin>>n;
            v.push_back(n);
        }
    }
    return v;
}

int main(){

    std::vector<int> v = {1,2,3,4,5};
    for(int i : v) {std::cout<<i<<" ";}
    std::cout<<"\n";

    int m = v[0];
    for(int i=1; i<v.size(); ++i)
        if(m < v[i])
            m=v[i];
    std::cout<<m<<"\n";

    m = v[0];
    for(std::vector<int>::const_iterator i(v.begin()); i!=v.end(); ++i) {
        //if(i==v.begin()) m = *i;
        //else if( m < *i) m =*i;
        if( m < *i) m =*i;
    }
    std::cout<<m<<"\n";

    m = v[0];
    for(auto n : v) {
        if(m < n) m=n;
    }

    std::cout<<m<<"\n";

    return 0;
}
