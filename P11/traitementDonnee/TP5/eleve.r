
data <- read.delim(
    "eleves.tsv",
    fileEncoding = "ISO-8859-1"
);
data = unique(data)
data_clean <- data[0,]

for(i in 1:(nrow(data))){
    keep = TRUE
    for(j in 1:nrow(data)){
        if( i != j &
            data[i, "Identité"] == data[j, "Identité"] &
            data[i, "Sexe"] == data[j, "Sexe"])
        {    
            if(data[i, "Âge"] < data[j, "Âge"]) {
                keep = FALSE
            }
        }
    }
    if(keep) {
        data_clean <- rbind(data_clean, data[i,])
    }
}
# print(data_clean)

#### Graph r_sexes
n_f = nrow((data_clean[which(
            data_clean$Sexe=="F"),]))
n_h = nrow((data_clean[which(
            data_clean$Sexe=="M"),]))
print(n_f) 
print(n_h)
s <- c(n_f, n_h)
print(s)
png(filename="r_sexes.png")
b <- barplot(s, xlab="Sexes", ylab="Nombre d'élèves",
        main="Répartition Femmes/Hommes chez les élèves",
        names = c("F", "M"))
text(x = b, y = s - 1, labels = s )
dev.off()
####


#### Graph r_ages_etudes
age_etu <- data.frame(
    Age = data_clean$Âge, 
    etud = data_clean$Niveau.d.études
)
age_etu$etud <- factor(age_etu$etud, 
    levels=c("Primaire", "Collège", "Lycée", "Université")
)

png(filename="r_ages_etudes.png")
boxplot( age_etu$Age ~ age_etu$etud,
        data = age_etu,
        main = "Age en fonction du niveau d'études",
        xlab = "Niveaux d'études",
        ylab = "Ages")
dev.off()
####