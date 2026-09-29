data <- read.csv("officiels.csv")

payement <-data.frame(
    id=character(),
    nom=character(),
    prenom=character(),
    licence=character(),
    indemnite=double()
)

data_clear = (data[which(
        data$libelle=="Arbitre" 
        & data$presence=="P"
        & data$indemnite!=""
        & ( substr(data$lb_nom_abg, 1, 3) =="DMU" | 
            substr(data$lb_nom_abg, 1, 3) =="DFU" |
            substr(data$lb_nom_abg, 1, 3) =="PRF" | 
            substr(data$lb_nom_abg, 1, 3) =="PRM" )
        ),])

# data_arb <- data[data&libelle == "Arbitre"] & ..
# !is.na(data$indemnite && data$truc %id% ...)

for(i in 1:nrow(data_clear)){
    n = nrow(payement)

    # for(j in 1:n){
    if(data_clear[i,"id"] %in% payement$id) {
        payement[j,"indemnite"] <- data_clear[i,"indemnite"] + as.double(payement[j,"indemnite"])
    }else{
        payement[nrow(payement)+1,] = 
            c(data_clear[i,"id"],
                data_clear[i,"nom"],
                data_clear[i,"prenom"],
                data_clear[i,"numero_licence"],
                data_clear[i,"indemnite"]
            )
    }
    
}
head(payement)


# sexe <- data$SEXE
# m_sexe <- c("Homme", "Femme")
# factor(sexe, levels=0:1, labels=m_sexe)

# etu <- data$ETUD
# m_etud <- c("NR", "Primaire"; "...")
# factor(etu, levels=0:4, labels=m_etud)
#                               [0-1]
# pactsSexe <- paste(round(100*prop.table(table(sexe)), 1), "%")