function createSimpleNode(tag, options, text){

    let element = document.createElement(tag);
    options.forEach(opt => {
        element.setAttribute(opt[0], opt[1]);    
    });
    
    if(text!=""){
        let txt = document.createTextNode(text);
        element.appendChild(txt);
    }

    document.body.appendChild(element);
}

createSimpleNode("img", [["src", "pix.png"]], "");
createSimpleNode("br", [], "");
createSimpleNode("a", [["href", "https://www.laquadrature.net/"]], "Un site");
createSimpleNode("br", [], "");
createSimpleNode("p", [], "Du texte");