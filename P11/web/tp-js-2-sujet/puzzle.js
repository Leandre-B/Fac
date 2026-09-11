let puzzle = null;

fetch('puzzle.json', {
        method: 'GET'
    })
    .then((response) => response.json())
    .then((puzzles) => {
        // Extraction du premier puzzle et construction du générateur
        console.log('Success:', puzzles);
        puzzle = puzzles[0];
        let generator = new PuzzleGenerator(puzzle);

        // Q1.1 Injection de l'auteur
        // generator.insertAuthor();
        document.querySelectorAll("body p")[0].innerHTML += "<a href=\""+puzzle.url+"\">"+puzzle.auteur+"</a>";

        // Q1.2 Injection des images
        // generator.insertImages();

        puzzle.images.forEach(element => {
            
            let image = document.createElement("img");
            image.height = 50; image.width = 30; image.alt = element.alt;
            request = new Request("img/"+element.src);
            fetch(request)
                .then((reponse)=>{
                    if(reponse.ok) {
                        return reponse.blob();
                    }else
                        console.log(reponse.status)
                })
                .then((myBlob)=>{
                    const urlObject = URL.createObjectURL(myBlob);
                    image.src = urlObject;
                }
            );
            document.getElementById("images").appendChild(image);

        });

        // Q1.3 Injection de l'énoncé
        // generator.insertStatement();
        document.querySelector("h3").innerText = puzzle.énoncé;


        // Injection des en-têtes du tableau (ne pas faire cette question)
        generator.insertTableHeaders();

        // Q1.4 Injection des indices
        // generator.insertHints();
        let n_indice = 1;
        ol = document.querySelector("ol")
        puzzle.indices.forEach(indice => {
            li = document.createElement("li");
            li.innerHTML = " <input type=\"checkbox\" name=\"indices[]\" id=\"indice"+n_indice+"\" value=\"indice"+n_indice+"\"></input> <label for=\"indice"+n_indice+"\">"+indice+"</label>";
            ol.appendChild(li);
            ++n_indice;
        });


        // Q1.5 Injection des menus déroulants
        // generator.insertDropDowns();
        table = document.querySelector("fieldset table");
        for(i=0; i<puzzle.facettes.length; i++)
            table.rows[0].cells[i].innerText = puzzle.facettes[i].nom;

        for(i=0; i<3; i++) {
            text = puzzle.facettes[0].valeurs[i];
            table.rows[i+1].cells[0].innerText = text;
        }
        for(k=0; k<3; ++k) {
            for(i=0; i<3; i++) {
                select = document.createElement("select");
                select.name=puzzle.facettes[0].valeurs[i]+"_"+puzzle.facettes[k+1].nom;
                html="";
                html+="<option value=\"vide\"></option>"
                for(j=0; j<3; j++) {
                    if(k==1){
                        value = puzzle.facettes[1+k].valeurs[j].split("-")[0];
                    }
                    else
                        value = puzzle.facettes[1+k].valeurs[j];
                    html+="<option value=\""+value+"\">"+puzzle.facettes[k+1].valeurs[j]+"</option>"
                }
                select.innerHTML = html;
                table.rows[i+1].cells[1+k].appendChild(select);
            }
        }

        // Q2.1 Clic sur cellules
        // generator.handleClicks();

        document.querySelector("table").addEventListener("click", (e)=>{
            if(e.target.innerText ==""){
                e.target.innerText = "X";
                e.target.style.backgroundColor = "red";
            }
            else if(e.target.innerText =="X"){
                e.target.innerText = "O";
                e.target.style.backgroundColor = "green";
            }
            else if(e.target.innerText =="O"){
                e.target.innerText = "";
                e.target.style.backgroundColor = "";
            }
        });

        document.querySelector("ol").addEventListener("click", (e)=>{
            if(e.target.id != ""){
                input_style = document.querySelector("label[for=\""+e.target.id+"\"]");
                if(input_style.style.textDecoration == "line-through")
                    input_style.style.textDecoration = "";
                else
                    input_style.style.textDecoration = "line-through";
            }
        });

        // Q2.2 Cochage des indices
        // generator.handleHints();

        // Q3 Gestion du formulaire
        // generator.handleDropDowns();

        document.querySelector("input[type=\"submit\"").addEventListener("click", (e)=>{
            e.preventDefault();

            
            const params = new URLSearchParams();
            Array.from(document.querySelectorAll("select")).forEach((e)=>{
                params.append(e.name, e.value);
            }); 
            console.log(params);

            requete = new Request("puzzle.php", {
                method: "POST",
                body: params
            })

            fetch(requete)
                .then((reponse)=>{
                    return reponse.json()
                })
                .then((resultat)=>{
                    correct = true;
                    for(let key in resultat.réponse) {
                        let select = document.querySelector("select[name=\""+key+"\"]");
                        if( resultat.réponse[key] == 0 ){
                            select.style.backgroundColor = "red";
                            correct = false;
                        }
                        else{
                            select.style.backgroundColor = "green   ";
                        }
                    }
                    if(correct)
                        alert("BRAVO !!!!!!!!!!!!!!!")
                })

        });

        return puzzle;
    })
    .catch((error) => {
        console.error('Error:', error);
    });




// Q4 Minuteur