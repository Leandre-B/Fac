
lire <- function(fichier, perequation, classique) {
    data <- read.csv(fichier)

    arbitres <-data.frame(
        id=character(),
        nom=character(),
        prenom=character(),
        licence=character(),
        indemnite=double()
    )
    if(!is.null(classique))
        conditions = c(perequation, classique)
    else
        conditions = c(perequation)
        
    data_clear = (data[which(
            data$libelle=="Arbitre" 
            & data$presence=="P"
            & data$indemnite!=""
            & ( substr(data$lb_nom_abg, 1, 3) %in% conditions)
            ),])

    for(i in 1:nrow(data_clear)){
        found = 0
        n = nrow(arbitres)
        for(j in 1:n){
            if(is.na(arbitres[j, "id"]))
                break
            if(data_clear[i,"id"] == arbitres[j, "id"]) {
                arbitres[j,"indemnite"] <- data_clear[i,"indemnite"] + as.double(arbitres[j,"indemnite"])
                found = 1;
                break
            }
        }
        if(found == 0){
            arbitres[nrow(arbitres)+1,] = 
                c(data_clear[i,"id"],
                    data_clear[i,"nom"],
                    data_clear[i,"prenom"],
                    data_clear[i,"numero_licence"],
                    data_clear[i,"indemnite"]
                )
        }
        
    }

    clubs <-data.frame(
        club=character(),
        facture=double()
    )

    for(i in 1:nrow(data_clear)){
        found = 0
        cs = list(c(strsplit(data_clear[i, "GS1"], " - ")[[1]][2], "0"), 
                    c(strsplit(data_clear[i, "GS2"], " - ")[[1]][2], "0")
        )
        # print(cs)
        n = nrow(clubs)
        for(j in seq_len(n)){
            if(is.na(clubs[j, "club"]))
                break

            for(k in 1:length(cs)) {
                if(clubs[j, "club"] == cs[[k]][1]) {
                    clubs[j, "facture"] <- data_clear[i, "indemnite"]/2 + as.double(clubs[j, "facture"])
                    cs[[k]][2] <- "1"
                }
            }
        }
        for(k in 1:length(cs)) {
            if(cs[[k]][2] == "0"){
                clubs[nrow(clubs)+1,] = 
                    c(  cs[[k]][1],
                        data_clear[i,"indemnite"] /2
                    )
            }   
        }
    }

    return(list(arbitres=arbitres, clubs=clubs))
}

# competitionsJeunes = c("DMU", "DFU")
# output <- lire("officiels.csv", perequation=c("PRM", "PRF"), classique=competitionsJeunes)
# head(output$arbitres)
# head(output$clubs)
