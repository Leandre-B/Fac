

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

