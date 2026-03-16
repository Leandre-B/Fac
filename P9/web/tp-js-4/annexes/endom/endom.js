// Q1
document.querySelector("#page h1").textContent="lakznflkazn";

// Q2
document.querySelector("#page table").style.width="80%";

// Q3
Array.from(document.querySelectorAll("#page dl dd")).forEach(d=> d.style.backgroundColor="lightcyan");

// Q4
Array.from(document.querySelectorAll("#page li")).forEach(l=> l.textContent="Hello");

// Q5
let toDelete = document.querySelectorAll("#page table")[1];
toDelete.parentNode.removeChild(toDelete);

// Q6
//fait mais suppr mdrr

// Q7
//fait mais suppr mdrr

// Q8
console.log(document.getElementsByName("h_adr_rue").value);
document.getElementsByName("h_adr_rue").value="49000";
console.log(document.getElementsByName("h_adr_rue").value);

// Q9
let chekboxes = document.getElementsByName("h_hab_options[]");
Array.from(chekboxes).forEach(c=>{
  console.log(c);
  if(c.value=="piscine" || c.value=="garage"){
    c.setAttribute("checked", "true");
  }
});