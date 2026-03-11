function sMatrix(m){
    let to_print="";
    m.forEach(element => {
       element.forEach(elem => {
            to_print+=elem;
        });
        to_print+="\n";
    });
    return (to_print);


}