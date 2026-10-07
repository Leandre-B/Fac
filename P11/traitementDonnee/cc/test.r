data <- read.csv("TP3/officiels.csv")
data <- na.omit(data)
data <- subset(data, 
                libelle=="Arbitre"  &
                presence=="P" &
                indemnite!="" &
                ( substr(data$lb_nom_abg, 1, 3) %in% c("PRM", "PRF", "DMU", "DFU"))
)

indem <- aggregate(indemnite ~ id, data=data, FUN = sum)
indem$indemnite <- indem$indemnite
# print(indem)


data$GS1 <- sapply(strsplit(data$GS1, ' - '), function(x) x[2])
data$GS2 <- sapply(strsplit(data$GS2, ' - '), function(x) x[2])

clubs_1 <- data.frame(
    club=data$GS1,
    indemnite=data$indemnite/2
)

clubs_2 <- data.frame(
    club=data$GS2,
    indemnite=data$indemnite/2
)

clubs_1 <- aggregate(indemnite ~ club, data=clubs_1, FUN=sum)
clubs_2 <- aggregate(indemnite ~ club, data=clubs_2, FUN=sum)

clubs <- rbind(clubs_1, clubs_2);

print(clubs)
