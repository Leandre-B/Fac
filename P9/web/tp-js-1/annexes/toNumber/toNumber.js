function toNumber(s) {

    let s_to_int=0;
    for(let i= s[0]=='-' ? 1 : 0; i<s.length; ++i){
        console.log(i);
        let c=s[i].charCodeAt()-48;
        if(c<0 || c>9)
            return NaN;
        s_to_int=s_to_int*10+c;
    }
    return s[0]=='-' ? -s_to_int : s_to_int;
}
