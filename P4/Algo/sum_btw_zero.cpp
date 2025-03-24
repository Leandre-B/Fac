#include <iostream>

struct Maillon{
  int val;
  Maillon* next;
};

using Liste = Maillon*;

void add(Liste & l, int v){
  Liste p=new Maillon;
  p->val=v;
  p->next=l;
  l=p;
}


void aff(Liste l){
  if(l==nullptr) std::cout<<std::endl;
  else{
    std::cout<<l->val<<" ";
    aff(l->next);
  }
}

void sum_btw_zero(Liste & l){
  if(l!=nullptr)
  {
    //obligé de séparé dans des if differents, sinon ça plante (normal)
    if(l->next!=nullptr)
    {
      if(l->next->val!=0)
      {
        l->val+=l->next->val;
        Liste p=new Maillon;
        p=l->next;
        l->next=l->next->next;
        delete p;
        if(l->next!=nullptr)
          sum_btw_zero(l);
      }
      else
        sum_btw_zero(l->next);
    }
  }
}

int main(){
  Liste l = nullptr;

  add(l,0);
  add(l,3);
  add(l,6);
  add(l,0);
  add(l,7);
  add(l,0);
  add(l,8);
  add(l,9);
  add(l,2);
  add(l,0);
  add(l,12);
  add(l,3);
  add(l,0);
  add(l,0);

  aff(l);
  sum_btw_zero(l);
  aff(l);
  return 0;
}
