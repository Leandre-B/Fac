let tab=s.split("");
let tabv=[];

for(let l of tab){
    if(voyelles.indexOf(l)!=-1)
        tabv.push(l);
}

let map = new Map();
for(let l of tabv){
    map.has(l) ? map.set(l, map.get(l)+1) : map.set(l, 1);
}

let max=0;
let maxv='';
map.forEach((v, k) =>{
    console.log(k, v);
    if(v>max){
        maxv=k;
        max=v;
    }
});