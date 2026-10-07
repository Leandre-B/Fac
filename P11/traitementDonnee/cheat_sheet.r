################ FILTRAGE ###############

df_filtre <- df[df$col_A < 5 | df$col_B != "Exclu", ]
df_filtre <- subset(df, col_A > 10 & col_B == "Exclu")

# Valeur présente dans une liste
df_filtre <- df[df$col_D %in% c("Valeur1", "Valeur2"), ]
df_filtre <- subset(df, col_D %in% c("Valeur1", "Valeur2"))

# Condition sur du texte
df_filtre <- df[grepl("mot", df$col_Texte), ]

# Exclure les NA
df_filtre <- df[!is.na(df$col_A), ]
df_filtre <- subset(df, !is.na(col_A))
data <- na.omit(data)



#########################################

################# MODIF #################


df$col_B <- df$col_B * 1.2
df$col_C[df$col_A > 10 & df$col_B == "Validé"] <- "Gagnant"

# Colonnes
df <- cbind(df, new_col = c(4, 5, 6))

df$col_a_supprimer <- NULL
# ou df <- df[, -2] 
# ou df <- subset(df, select = -c(nom_col1, nom_col2))

# Lignes
nouvelle_ligne <- data.frame(col_A = 10, col_B = "Oui")
df <- rbind(df, nouvelle_ligne)
clubs <- rbind(clubs_1, clubs_2);

df <- df[-1, ]
df <- df[-c(1:3), ] # delete lignes 1 à 3
df <- df[df$col_A != 10, ] # Filtrage comme en haut

##########################################

######## Trucs cools #######
df[!duplicated(df[c("nom", "prenom", "sexe")]), ]
resultat <- aggregate(indemnite ~ id + nom + prenom, data = df_arbitres, FUN = sum)

# FUN =   sum /mean /median /min / max
#         length : Compter le nombre d'éléments (effectif du groupe)
#         sd : Écart-type
#         var : variance

clubs_1 <- data.frame(
    club=data$GS1,
    indemnite=data$indemnite/2
)
data$GS1 <- sapply(strsplit(data$GS1, ' - '), function(x) x[2])
##########################################


###### TRIER #######
df_trie <- df[order(df$age, decreasing = TRUE), ]
df_trie <- df[order(df$niveau_etudes, decreasing = TRUE, df$age), ]

# Définir l'ordre logique des classes
df$niveau <- factor(df$niveau, levels = c("Primaire", "Collège", "Lycée", "Université"))

# order() va maintenant trier selon cet ordre logique
df_trie <- df[order(df$niveau), ]

m_etud <- c("NR", "Primaire", "Secondaire", "Bac", "Supérieur")
data$ETUD <- factor(etu, levels=c(0,1,2,3,4), labels=m_etud) 
#####################

######### GRAPH ############
# Nuage de points ou Lignes (plot)
plot(df$x, df$y, type = "p", main = "Nuage", xlab = "X", ylab = "Y", col = "blue")
# type = "p" (points), "l" (lignes), "b" (points et lignes)

# Diagramme circulaire (pie)
# Nécessite de compter les effectifs avec table() d'abord
effectifs <- table(df$categorie)
pie(effectifs, main = "Répartition", col = c("red", "green", "blue"))

# Boîte à moustaches (boxplot)
# variable numérique ~ variable catégorique
boxplot(age ~ niveau, data = df, main = "Âge par niveau", xlab = "Niveau", ylab = "Âge", col = "orange")

# Histogramme (hist)
# Pour voir la distribution d'une SEULE variable numérique
hist(df$salaire, breaks = 10, main = "Distribution", xlab = "Salaire", ylab = "Fréquence", col = "grey")
# breaks = nombre approximatif de barres souhaité

# Diagramme en barres (barplot)
# Nécessite aussi les effectifs avec table()
barplot(table(df$sexe), main = "Comptage", xlab = "Sexe", ylab = "Nombre", col = c("pink", "lightblue"))
# las=2
#####################