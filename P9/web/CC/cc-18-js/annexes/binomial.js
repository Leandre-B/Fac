let n = parseInt(document.getElementById("n").value);
let a = parseInt(document.getElementById("a").value);
let b = parseInt(document.getElementById("b").value);



let result = 0;
for(let k=0; k<=n; ++k){
    let coef = document.querySelector("[title=\"C("+n+ ","+k+")\"]");
    result += parseInt(coef.innerHTML) * Math.pow(a, n-k) * Math.pow(b, k);
}
document.getElementById("resultat").value = result;

let ul = document.querySelector(".dev");

let item1="";
for(let k=0; k<=n; ++k){
    item1+="C("+n+ ","+k+").";
    item1+=a+"<sup>"+(n-k)+"</sup> ";
    item1+=b+"<sup>"+k+"</sup>+";
}
item1=item1.slice(0, -2);

ul.children[0].innerHTML = item1;

let item2="";
for(let k=0; k<=n; ++k){
    let coef = document.querySelector("[title=\"C("+n+ ","+k+")\"]");
    item2+=coef.innerHTML+".";
    item2+=a+"<sup>"+(n-k)+"</sup> ";
    item2+=b+"<sup>"+k+"</sup>+";
}
item2=item2.slice(0, -2);

ul.children[1].innerHTML = item2;

let item3="";
for(let k=0; k<=n; ++k){
    let coef = document.querySelector("[title=\"C("+n+ ","+k+")\"]");
    result = parseInt(coef.innerHTML) * Math.pow(a, n-k) * Math.pow(b, k);

    item3+=result+" + ";
}
item3=item3.slice(0, -2);

ul.children[2].innerHTML = item3;



if(document.querySelector("[value=\"o\"").checked){
    for(let tr of document.querySelector("tbody").children){
        for(let td of tr.children){
            if(td.nodeName=="TD"){
                if(parseInt(td.textContent)%2==1)
                    td.className="impaire";
            }
        }
    }
}

let span  = document.querySelector("span");
span.innerHTML="<a href=\"https://fr.wikipedia.org/wiki/Triangle_de_Sierpi%C5%84ski\">"+span.innerText;