let N = parseInt(document.querySelector("input").value);
console.log(N);

let table = document.createElement("table");
for (let i = 0; i < N+1; i++) {
    let tr = document.createElement("tr");
    for (let j = 0; j < N+1; j++) {
        let td = document.createElement("td");
        tr.append(td);
    }
    table.append(tr);
}

let n=0;
for(let tr of table.children){
    let k=0;
    for(let td of tr.children){
        if(k==0 || (n==k))
            td.textContent = "1";
        else{
            if(n!=0){
                let val = parseInt(tr.previousElementSibling.children[k-1].textContent);
                val+=parseInt(tr.previousElementSibling.children[k].textContent);
                if(!isNaN(val))
						td.textContent=val;
            }
        }
        ++k;

    }
    ++n;
}

document.querySelector("body").append(table);

n=0;
for(let tr of table.children){
    k=0
    for(let td of tr.children){
        //td.innerHTML = "<abbr title = \"C("+n+","+k+")\">"+td.textContent+"</abbr>";

        //ou
        let abbr = document.createElement("abbr");
        abbr.textContent = td.textContent;
        abbr.title = "C("+n+","+k+")"
        td.textContent="";  
        td.append(abbr);
        
        k++
    }
    n++;
}