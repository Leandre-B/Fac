function fixRGB(n, i, j){
    let rgb=[0,0,0];
    if(n==1){
        rgb[0]=255;
        rgb[1]=32*i;
        rgb[2]=32*j;
    }
    if(n==2){
        rgb[0]=32*i;
        rgb[1]=255;
        rgb[2]=32*j;
    }
    if(n==3){
        rgb[0]=32*i;
        rgb[1]=32*j;
        rgb[2]=255;
    }
    return rgb;
}

let tables = document.getElementsByTagName("table");
let br = document.createElement("br");
let n=1;
for(let table of tables){
    //add 9 tr
    for(let i=0; i<9; ++i){
        let tr = document.createElement("tr");
        //add 9 td
        for(let j=0; j<9; ++j){    
            let rgb=fixRGB(n, i, j);
            let td = document.createElement("td");
            td.style.backgroundColor="rgb("+ rgb[0] +" "+ rgb[1] +" "+ rgb[2] +")";
            tr.appendChild(td);
        }
        table.appendChild(tr);
    }
    n+=1;
    
}