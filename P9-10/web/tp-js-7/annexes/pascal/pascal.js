// Tableau

function creerTableau(N) {
	// Tableau nu
	// Q1
	let pascal = document.createElement("table");
	for(let i=0; i<N; ++i){
		let tr = document.createElement("tr");
		for(let j=0; j<N; ++j){
			let td = document.createElement("td");
			tr.insertBefore(td, tr.lastChild);
		}
		pascal.insertBefore(tr, pascal.lastChild);
	}
	console.log(pascal);
	
	// Coefficients
	// Q2

	let n=0;
	for(let tr of pascal.children){
		let k=0;
		for(let td of tr.children){
			if(k==0 || k==n){
				td.innerHTML="1";
			}else{
				if(n!=0){
					let val = parseInt(tr.previousElementSibling.children[k-1].innerHTML);
					val += parseInt(tr.previousElementSibling.children[k].innerHTML);
					if(!isNaN(val))
						td.innerHTML=val;
				}
			}
			++k;
		}
		++n;
	}

	// Abbréviations
	// Q3


	document.getElementsByTagName("body")[0].insertBefore(pascal, document.getElementsByTagName("body")[0].lastChild)

}

// Listeners
window.addEventListener("load", function () {
	var input = document.querySelector("INPUT[type=number]");
	var N = parseInt(input.value);
	creerTableau(N + 1);
})

document.querySelector("INPUT[type=number]").addEventListener("change", function (e) {
	var N = parseInt(e.target.value);
	var div = document.querySelector("div");
	var table = document.getElementsByTagName("table")[0];
	table.parentNode.removeChild(table);
	creerTableau(N + 1);

})