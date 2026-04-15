/**
 * Retourne si la partie "Participant" du formulaire est bien remplie.
 */
function participantValid() {
	if(document.getElementById("nom").value=="")
		return false;
	if(document.getElementById("prenom").value=="")
		return false;
	if(document.getElementById("netu").value=="")
		return false;
	return true;
}

participantValid();

/**
 * Retourne si au moins un bouton radio identifié par `inputName` est coché.
 */
function radioValid(inputName) {
	let radios = document.querySelectorAll("[type=\"radio\"][name=\""+inputName+"\"]");	
	let checked = new Boolean(false);
	radios.forEach(r => {
		if(r.checked==true){
			checked = true;
		}
	});
	return checked;
}


/**
 * Retourne si les select de classe `className` ont bien tous une valeur, et différente les unes des autres.
 */
function sortValid(className) {
	let values = [];
	let n=0;
	let selects = document.querySelectorAll("."+className);
	selects.forEach(s => {
		n++;
		if(s.value!="" && !values.includes(s.value))
			values.push(s.value);
	});

	return values.length == n;
}


/**
 * Traite la soumission du formulaire.
 * Un formulaire mal rempli affichera un message dans un `alert` et ne sera pas soumis.
 * Retourne si le formulaire a été soumis ou non.
 */
function submitForm(/*event*/) {
	let errors = "";
	if(!participantValid()){
		errors+="Error\n Participant non valide\n";
	}
	if(!radioValid("app_php")){
		errors+="Error\n Bounton php non valide\n";
	}
	if(!radioValid("app_js")){
		errors+="Error\n Bounton js non valide\n";
	}
	if(!sortValid("sort_php")){
		errors+="Error\n Sort php non valide\n";
	}
	if(!sortValid("sort_js")){
		errors+="Error\n Sort js non valide\n";
	}
	if(errors!="")
		window.alert(errors);
}

submitForm();
