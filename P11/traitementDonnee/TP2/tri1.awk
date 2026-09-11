# On ne transforme que le dernier enregistrement en MAJ
# Probleme quand le nom (ou prenom) est composé.
# Ou quand séparé par autre chose que des espaces

/.+/{
    for(i=1; i<NF; i++){
        printf("%s ", $i)
    }
    print toupper($NF)
}