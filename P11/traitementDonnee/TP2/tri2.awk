/.+,.+/{
    st_letter=toupper(substr($1, 1, 1))
    rest=tolower(substr($1, 2, length($1)-1))
    prenom = st_letter rest
    
    printf("%s %s\n", prenom,toupper($2))
}

BEGIN {
    FS=","
}