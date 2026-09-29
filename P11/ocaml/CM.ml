

let vide = function
[] -> true
| _ -> false;; 

let singleton = function
x::[] -> true |
_ -> false;;

let tete = function
  [] -> failwith "liste vide" |
  x::_ -> x;;

let queue = function
  [] -> failwith "liste vide" |
  _::x -> x;;

let deuxieme = function
  [] -> failwith("liste vide") |
  x::[] -> failwith("pas de 2eme elem") |
  x::y::_ -> y;;


let rec longueur l = 
  if vide l then
    0
  else
    longueur (queue l) +1;;

(* 
let rec longueur = function 
  [] -> 0 |
  x::r  -> 1+ longueur r;;
*)


let longueur_terminale l =
    let rec longueur_terminale_aux n = 
    function
        [] -> n
        | x::r -> longueur_terminale_aux (n+1) r 
    in
    longueur_terminale_aux 0 l;;


(* print_endline ("");;
print_int (deuxieme [1; 5; 6]);; *)

let rec appartient l a = 
  if vide l then
    0
  else if (tete l) = a then 
    1
  else
    appartient (queue l) a;;

let rec appartient_2 l a = 
  match l with
  | [] -> false
  | x::y -> a=x || appartient_2 y a;; 


let rec renverser = function
  [] -> []
  | x::y -> renverser y @ [x];;


let rec conca_full = function
  [] -> ""
  | x::y -> x^" "^conca_full y;;

let rec renverser_terminal l = function
  [] -> l
  | x::y -> renverser_terminal (x::l) y;;



(* print_int(longueur_terminale [1;4;6;10]);; *)
(* print_int (appartient [1;5;6;4;0] 4);; *)
let l = renverser_terminal [] ["1"; "5"; "7"; "9"];;
print_string (conca_full (l));;



let pair x = (x mod 2 = 0);;

let rec trouver f l = match l with
  [] -> failwith "aucun elem pair"
  | x::y -> 
      if (f x) then x
      else trouver f y;;

trouver pair [1; 2; 3; 4];;



let carre x = x*x;;
let rec map f list = match list with 
  [] -> []
  | x::y -> [(f x)] @ map f y;; 

map carre [1; 2; 3; 4; 5];;


let rec somme_list l = match l with
  [] -> 0
  | x::y -> x+somme_list y;; 

somme_list [3;5;1];;

let plus x y = x + y;;

let conca x y = x^y;;

let rec app_succ f l b = match l with
  [] -> b
  | x::y -> app_succ f y (f b x );; 

let rec app_succ2 f l b = match l with
  [] -> b
  | x::y -> f x (app_succ2 f y b);;

app_succ plus [1; 5; 6] 0;;
app_succ conca ["a"; "b"] "";;


let plus_grand x y = 
  if x > y then x
  else y;;

let somme_long x y = x + String.length y;;

let map2 f x y = x@[(f y)];; 
let map3 f x y = (f x)::y;; 

app_succ plus_grand [3; 5 ;10; 1; 0] 0;;
app_succ somme_long ["AZEAZE"; "azz"; "1"] 0;;
app_succ (map2 carre) [1; 2; 3; 4] [];;
app_succ2 (map3 carre) [1; 2; 3; 4] [];;
