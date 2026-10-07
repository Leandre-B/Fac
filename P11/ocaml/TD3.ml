(* type 'a arbBin = F of 'a | Noeud of ('a arbBin *'a arbBin);;

let a = Noeud (
    Noeud(
        F 1, F 2
    ),
    Noeud(
        Noeud(
            F 3,F 4
        ),
        F 6
    )
);;

let a2 = Noeud (
    Noeud(
        F 1, F 2
    ),
    Noeud(
        F 8,
        F 6
    )
);;

let rec nbNoeud a = match a with
    F _ -> 0
    | Noeud (a1, a2) -> 1+ (nbNoeud  a1) + (nbNoeud a2);; 
nbNoeud a;;

let rec nbFeuille a = match a with
    F _ -> 1
    | Noeud (a1, a2) -> (nbFeuille a1) + (nbFeuille a2);;

nbFeuille a;;

let rec hauteur a = match a with
    F _ -> 0
    | Noeud (g, d) -> 
        let h1 = 1+ (hauteur g) in
            let h2 = 1+ (hauteur d) in
                if h1 > h2 then h1 else h2;;

hauteur a;;

let rec meme_forme a1 a2 = match (a1, a2) with
    (F _, F _) -> true
    | (F _, Noeud _) -> false
    | (Noeud _, F _) -> false
    | (Noeud (g1, d1), Noeud (g2, d2)) ->
        meme_forme g1 g2 && meme_forme d1 d2;;

meme_forme a a2;;

let rec listeF a = match  a with
    F x -> [x]
    | Noeud (g, d) -> (listeF g) @ (listeF d);;

listeF a;;
listeF a2;;

let rec map_arbre f a = match a with
    F x -> f x
    | Noeud (g, d) -> Noeud( map_arbre f g, map_arbre f d );;

map_arbre (fun x -> F (x*2)) a;; 
*)

(* 
type operateur_bin = Mult | Add;;
type operateur_un = Moins;;
type arbre = 
  Const of int
| Var of string
| Noeud1 of (operateur_un * arbre)
| Noeud2 of (operateur_bin * arbre * arbre);;

let a = Noeud2(
    Add,
    Noeud2(
        Mult, Var "x", Const 3
    ),
    Noeud1(
        Moins, Var "y"
    )
);;

let rec chaine_de_arbre a = match a with
      Const c -> string_of_int c
    | Var v -> v
    | Noeud1 (_, r) -> "(-"^(chaine_de_arbre r)^")"
    | Noeud2 (o, a1, a2) -> match o with
    | Add -> "("^chaine_de_arbre a1 ^"+"^chaine_de_arbre a2 ^")"
    | Mult -> "("^chaine_de_arbre a1 ^"*"^chaine_de_arbre a2 ^")";;

chaine_de_arbre a;;

let rec exist c li = match li with
    [] -> false
    | (n, _)::r -> if n = c then true else exist c r;;

let rec close a li = match a with
      Const _ -> true
    | Var v -> exist v li
    | Noeud1 (_, r) -> close r li
    | Noeud2 (_, a1, a2) -> (close a1 li) && (close a2 li);; 

close a [("y", 4); ("x", 5)];;

let rec find v li = match li with
      [] -> failwith "not found"
    | (n, x)::r -> if n = v then x else find v r;; 

let rec eval a li =
    if not (close a li) then failwith "pas close"
    else match a with
      Const c -> c
    | Var v -> (find v li)
    | Noeud1 (_, r) -> -(eval r li)
    | Noeud2 (o, a1, a2) -> match o with
    | Add -> (eval a1 li) + (eval a2 li)
    | Mult -> (eval a1 li)* (eval a2 li);;

eval a [("y", 4); ("x", 5)];; *)




type operateur = Mult | Plus | Moins;;
type arbre = 
  C of int
| N of (operateur * arbre list);;

let a = N(Plus, [
    C 1;
    N(Mult, [
        C 5;
        C 2
    ])
    ]
);;

let rec nb_const a = match a with
      C _ -> 1
    | N (o, la) -> List.fold_right (fun la s -> s + (nb_const la)) la 0;;
                
nb_const a;;

let rec correct a = match a with
      C _ -> true
    | N (o, la) -> 
        if la=[] then false
        else List.fold_left (fun b a -> b && (correct a)) true la;; 

correct a;;

let rec calcul a = match a with
      C c -> c
    | N(o, []) -> failwith "expression incorrecte"
    | N(o, x::r) -> match o with
          Mult ->  (calcul x)*(List.fold_left (fun r a -> r*(calcul a)) 1 r)
        | Plus ->  (calcul x)+(List.fold_left (fun r a -> r+(calcul a)) 0 r)
        | Moins -> (calcul x)-(List.fold_left (fun r a -> r-(calcul a)) 0 r);;

let a2 = N(Plus, [C 1; C 4; C 7]);;
calcul a;;
calcul a2;;

let rec chaine_de_arbre a = match a with
      C c -> string_of_int c
    | N(o, []) -> failwith "expression incorrecte"
    | N(o, x::r) -> match o with
          Mult ->  "("^ (chaine_de_arbre x)^(List.fold_left (fun r a -> r^"*"^(chaine_de_arbre a)) "" r) ^ ")"
        | Plus ->  "("^ (chaine_de_arbre x)^(List.fold_left (fun r a -> r^"+"^(chaine_de_arbre a)) "" r) ^ ")"
        | Moins -> "("^ (chaine_de_arbre x)^(List.fold_left (fun r a -> r^"-"^(chaine_de_arbre a)) "" r) ^ ")";;
chaine_de_arbre a;;
chaine_de_arbre a2;;

