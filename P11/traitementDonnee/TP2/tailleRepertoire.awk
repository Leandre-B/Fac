BEGIN{
    total = 0
}

{
    total = total + $5
}

END{
    # NR-1 car la 1ere ligne de ls -l ne correspond pas a un fichier
    printf("Il y a %d fichiers pour un total de %d octets.", NR-1, total)
}