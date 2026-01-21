#!/bin/bash

CHOIX=1
while([[ $CHOIX -ne 0 ]])
do
    printf "0 - Sortir du programme\n1 - Affiche date\n2 - Afficher utilisateurs connectés\n3 - Afficher taille disponible sur le disque\nChoix :"
    read CHOIX
    printf "\n"
    case $CHOIX in
        1)
            date;;
        
        2)
        cat /etc/passwd | cut -d ':' -f 1 ;;

        3)
         free -h;;
        
        *)
            printf "chox invalide\n"

    esac
    printf "\n"
done
echo "end"