# - Titre (fr) : Nom du concert (en français).
# — Age minimum : Âge minimum nécessaire pour pouvoir assister au concert.
# — Région : Nom de la région administrative dans laquelle se déroule le concert.
# — label_multivalued : Liste des genres musicaux du concert, séparés par des point-
# virgules ;.
data<-read.csv2("fete-de-la-musique-2019.csv")
# data<-na.omit(data)
# head(data)

titre_18 <- data
# titre_18 <- subset(titre_18, !is.na(Titre..fr.) & !is.na(Age.minimum))
titre_18 <- subset(data, Age.minimum > 18)
titre_18 <-titre_18[,c("Titre..fr.", "Age.minimum")]
head(titre_18)


repartition <- data

png(filename="r_repartition_concerts_regions.png")
barplot(table(repartition$Région), main = "Répartition des concerts par région", las=2)
dev.off()

repartition <- subset(repartition, !is.na(Région) & Région!="")
repartition <- cbind(repartition, nombre_concert = 1)
repartition <- aggregate(nombre_concert ~ Région, data=repartition, FUN=sum)
# print(repartition)



# head(data)
labels <-subset(data, !is.na(label_multivalued))

li <- unlist(sapply(strsplit(labels$label_multivalued, ';'), function(x) x))
# print(unique(li))

li <- sort(table(li), decreasing = TRUE)
# print(li)



