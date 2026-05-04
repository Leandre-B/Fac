function nbOcc(s, ss){
    let tot=0;  
    for(;;){
        let pos=s.indexOf(ss);
        if(pos==-1)
            break;
        ++tot;
        s=s.substr(pos+ss.length);
    }
    return tot;
}