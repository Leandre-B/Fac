function prompt_positive_number(base){
    let input;
    do{
     input=prompt("Saisir un nombre entier positif en base "+base);
     input=parseInt(input, base)
    }while(isNaN(input));



    return input;
}
