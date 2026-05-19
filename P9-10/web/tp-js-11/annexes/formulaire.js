///////// UTILITAIRES ///////////////////////////////////////////////////////////////////

// Masque les "tooltips"
function deactivateTooltips() {
	Array.from(document.querySelectorAll(".tooltip")).forEach((tooltip )=>
	{
		tooltip.style.visibility = 'hidden';
	}
)};

// Renvoie le "tooltip" associé à l'élément elt (ie. l'élément qui suit elt dans sa fratrie) 
// Renvoie false si le "tooltip" n'existe pas
function getTooltip(elt) {
	let next = elt.nextSibling;
	if(next == null)
		return false;
	while(next.className != "tooltip" || next.nodeName == "BR"){
		next =  next.nextSibling;
		if(next == null)
			return false;
	}
	console.log(next);
	if(next.className != "tooltip" || next==null)
		return false;
	return next;
}

// Fonction booléenne de validation et affichage :
// Si la condition "cond" est vraie : classe "correct" l'élément "elt", masque le "tooltip", et renvoie vrai
// Sinon : classe "incorrect" l'élément "elt", affiche le "tooltip", et renvoie faux
function validate(cond,elt,tooltip) {
	if(cond){
		elt.className = "correct";
		if(tooltip != false)
			tooltip.style.visibility = 'hidden';
	}else{
		elt.className = "incorrect";
		if(tooltip != false)
			tooltip.style.visibility = 'visible';
	}
}


///////// ECOUTEURS ///////////////////////////////////////////////////////////////////
// Fonctions booléennes de vérification des champs du formulaire : 1 fonction par champ.
// Chaque fonction est une méthode de l'objet "check" et dénommée selon son champ, 
// e.g. check.gender est la fonction de vérification pour le champ de nom "gender"
var check = {};

check['gender'] = function(){ return (document.getElementById("homme").checked || document.getElementById("femme").checked) };
check['lastName'] = function(){
	let value = String(document.getElementById("lastName").value);
	if(value.length <= 2)
		return false;
	for (let i=0; i<value.length; ++i) {
		if(!isNaN(parseInt(value[i])))
			return false;
	}
	return true;
};
check['firstName'] = function(){
	let value = String(document.getElementById("firstName").value);
	if(value.length <= 2)
		return false;
	for (let i=0; i<value.length; ++i) {
		if(!isNaN(parseInt(value[i])))
			return false;
	}
	return true;
};

check['age'] = function(){
	let value = parseInt(document.getElementById("age").value);
	if(isNaN(value))
		return false;
	if(value<5 || value>140)
		return false;
	return true;
};
check['login'] = function(){
	let value = String(document.getElementById("login").value);
	return(value.length >= 4)
};
check['pwd1'] = function(){
	let value = String(document.getElementById("pwd1").value);
	return(value.length >= 6)
};
check['pwd2'] = function(){
	let value = (document.getElementById("pwd1").value);
	return(value == document.getElementById("pwd2").value);
};
check['country'] = 	function(){
	let value = String(document.getElementById("country").value);
	return value != "none";
};


	///////// GESTIONNAIRES D'EVENEMENTS /////////////////////////////////////////////////////
(function() { // IIFE pour éviter les variables globales.
	var myForm = document.querySelector('#myForm');
	var select = document.querySelector('select');

	// A COMPLETER : ENREGISTREMENT DES GESTIONNAIRES POUR LES DIFFERENTS CHAMPS
	// UTILISANT LES DIFFERENTES FONCTIONS DE VERIFICATION. 
	document.getElementById("homme").addEventListener("click", (e)=>{
		validate(check['gender'](), e.target, getTooltip(e.target));
	});

	document.getElementById("femme").addEventListener("click", (e)=>{
		validate(check['gender'](), e.target, getTooltip(e.target));
	});

	document.getElementById("lastName").addEventListener("keyup", (e)=>{
		validate(check['lastName'](), e.target, getTooltip(e.target));
	});

	document.getElementById("firstName").addEventListener("keyup", (e)=>{
		validate(check['lastName'](), e.target, getTooltip(e.target));
	});

	document.getElementById("age").addEventListener("keyup", (e)=>{
		validate(check['age'](), e.target, getTooltip(e.target));
	});

	document.getElementById("login").addEventListener("keyup", (e)=>{
		validate(check['login'](), e.target, getTooltip(e.target));
	});

	document.getElementById("pwd1").addEventListener("keyup", (e)=>{
		validate(check['pwd1'](), e.target, getTooltip(e.target));
	});

	document.getElementById("pwd2").addEventListener("keyup", (e)=>{
		validate(check['pwd2'](), e.target, getTooltip(e.target));
	});

	document.getElementById("country").addEventListener("mouseup", (e)=>{
		validate(check['country'](), e.target, getTooltip(e.target));
	});

	myForm.addEventListener("submit", (e)=>{
		validate(check['gender'](), e.target, getTooltip(e.target));
		validate(check['lastName'](), e.target, getTooltip(e.target));
		validate(check['lastName'](), e.target, getTooltip(e.target));
		validate(check['age'](), e.target, getTooltip(e.target));
		validate(check['login'](), e.target, getTooltip(e.target));
		validate(check['pwd1'](), e.target, getTooltip(e.target));
		validate(check['pwd2'](), e.target, getTooltip(e.target));
		validate(check['country'](), e.target, getTooltip(e.target));
		console.log("submit");
	});


	myForm.addEventListener("reset", (e)=>{
		
	});



})();

///////// DESACTIVATION PAR DEFAUT ///////////////////////////////////////////////////////////////
deactivateTooltips();
