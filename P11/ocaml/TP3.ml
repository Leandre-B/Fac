(* EXO 1 *)
(* type 'a arbreBin = F of 'a | Noeud of ('a arbreBin * 'a arbreBin);;

let a = Noeud(Noeud(F 2, F 3), Noeud(Noeud(F 5, F 4), F 9));;
let b = Noeud(Noeud(F 2, F 3), Noeud(Noeud(F 5, F 4), Noeud(F 10, F 11)));;

let rec nb_f a = match a with
  F a -> 1
  | Noeud(a, b) -> (nb_f a) + (nb_f b);;

nb_f a;;

let rec pronf = function
  F a -> 0
  | Noeud(g, d) -> let max a b = if a>b then a else b in
    max ((pronf g) +1 ) ((pronf d) + 1);;

pronf a;;

let rec meme_forme a b = match (a, b) with
    (F _, F _) -> true
  | (Noeud(_, _), F _) -> false
  | (F _, Noeud(_, _)) -> false
  | (Noeud(g1, d1), Noeud(g2, d2)) -> (meme_forme g1 g2) && (meme_forme d1 d2);; 

meme_forme a b;;

let rec list_val = function
    F v -> [v]
  | Noeud (g, d) -> (list_val g) @ (list_val d);;

list_val a;;
list_val b;;


let rec map_arbre f a = match a with
    F v -> F (f v)
  | Noeud(g, d) -> Noeud((map_arbre f g), (map_arbre f d));;

let incr a = map_arbre (fun x-> x+1) a;;
incr a;; *)



(* EXO 2 *)
(* type operateur_bin = Mult | Add;;
type operateur_un = Moins;;
type arbre = Const of int
  | Var of string
  | Noeud1 of (operateur_un * arbre)
  | Noeud2 of (operateur_bin * arbre * arbre);;

let op = (Noeud2(Add, (Noeud2(Mult, Var "x", Const 3)) ,Var "y"));;

let rec chaine_de_arbre e = match e with
    Const c -> string_of_int c
  | Var v -> v
  | Noeud1(Moins, a) -> "-" ^ (chaine_de_arbre a)
  | Noeud2(Mult, a1, a2) -> "("^ (chaine_de_arbre a1) ^"*"^ (chaine_de_arbre a2) ^")"
  | Noeud2(Add, a1, a2) -> "("^ (chaine_de_arbre a1) ^"+"^ (chaine_de_arbre a2) ^")";;

chaine_de_arbre op;;

let rec exist v li = match (v, li) with
  (_, []) -> false
  |(x, (s, _)::r) -> if x=s then true else exist v r;;
  
(* exist "x" [("y", 3); ("z", 5)];; *)

let rec close e li = match e with
    Const c -> true
  | Var v -> exist v li
  | Noeud1(Moins, e1) -> close e1 li
  | Noeud2(_, e1, e2) -> (close e1 li) && (close e2 li);;

close op [("x", 1); ("y", 1)];;

let rec get_value x li = match li with
  [] -> failwith "r"
  | (y, v)::r -> if x=y then v else get_value x r;;

get_value "y" [("x", 4); ("y", 1)];;


let rec eval e li = match e with
    Const c -> c
  | Var v -> get_value v li
  | Noeud1(Moins, a) -> -(eval a li)
  | Noeud2(Mult, a1, a2) -> (eval a1 li) * (eval a2 li)
  | Noeud2(Add, a1, a2) -> (eval a1 li) + (eval a2 li) ;;

eval op [("x", 2); ("y", 1)];; *)

(* EXO 3 *)
type operateur = Mult | Plus | Moins;;
type arbre = 
  C of int
| N of (operateur * arbre list);;

let op = N(Mult, [C 3;C 4;C 5; N(Plus, [C 4;C 5])]);;

let rec nb_const = function 
    (C _) -> 1 
  | N(_, li) -> (List.fold_left(fun a -> fun b -> a+(nb_const b)) 0 li);;

nb_const op;;

let rec correct = function
    C _ -> true
  | N(_, []) -> false
  | N(_, li) -> (List.fold_left(fun a->fun b-> a && (correct b))) true li;;

correct op;;

let rec calcul = function
    C v -> v
  | N(Mult, li) -> (List.fold_left(fun a->fun b-> a * (calcul b))) 1 li
  | N(Moins, li) -> (List.fold_left(fun a->fun b-> a - (calcul b))) 0 li
  | N(Plus, li) -> (List.fold_left(fun a->fun b-> a + (calcul b))) 0 li;;

calcul op;;