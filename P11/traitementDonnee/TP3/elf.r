data <- read.table("elf1.txt", header=TRUE)

sexe <- data$SEXE
m_sexe <- c("Homme", "Femme")
data$SEXE <- factor(sexe, levels=0:1, labels=m_sexe)

etu <- data$ETUD
m_etud <- c("NR", "Primaire", "Secondaire", "Bac", "Supérieur")
data$ETUD <-  factor(etu, levels=0:4, labels=m_etud)

pctEtud <- paste(round(100*prop.table(table(etu)), 1), "%")
pactsSexe <- paste(round(100*prop.table(table(sexe)), 1), "%")

result = table(data$ETUD, data$SEXE)
result = cbind(result, pctEtud)
result = rbind(result, c(pactsSexe, ""))
rownames(result)[nrow(result)] <- "pct Sexe"

noquote(result)