
let rec longueur = function
    [] -> 0
    | x::y-> 1 + longueur y;;

(*
longueur [3;4;5;6];;

let rec concat l1 l2 = match l1 with
    [] -> l2
    | x::y -> concat y (l2 @ [x]);;

concat [1;4] [1;6;3];;

let rec nieme l n = match l with
    [] -> failwith "n>long(l)"
    | x::y ->
        if n = 0 then x
        else nieme y (n-1);;

nieme [1;5;6;7] 3;;

let rec npremiers l n = match l with
    [] -> []
    | x::y -> 
        if n = 0 then []
        else [x] @ (npremiers y (n-1));;

(* npremiers [1;5;6;1] 1;; *)

let rec met_a_plat = function
    [] -> []
    | x::y -> x @ (met_a_plat y);;

met_a_plat [[1;3];[5;6];[3]];;

let head = function
    [] -> failwith "list vide"
    | x::y -> x;;
    
    
let tail = function
    [] -> []
    | x::y -> y;;



let rec paire_vers_liste = function
    ([], []) -> []
    | (x,y) ->
        [(head x, head y)] @ (paire_vers_liste (tail x, tail y));;


paire_vers_liste ([1 ; 2 ; 3] , ['a' ; 'b' ; 'c']);;


let rec conca_fst_couple = function
   [] -> []
   | x::y -> [fst x] @ conca_fst_couple y;;
   
   
let rec conca_snd_couple = function
   [] -> []
   | x::y -> [snd x] @ conca_snd_couple y;;

let liste_vers_paire = function
    x -> (conca_fst_couple x, conca_snd_couple x);;

liste_vers_paire [(1,'a') ; (2, 'b') ; (3,'c')];;

let rec supprime1 l x = match l with
    [] -> []
    | a::b ->
        if a = x then b
        else [a] @ (supprime1 b x);;

supprime1 [5; 1; 2; 10; 9; 10] 10;;

let rec supprime2 l x = match l with
    [] -> []
    | a::b ->
        if a = x then
            (supprime2 b x)
        else [a] @ (supprime2 b x);;

supprime2 [10; 5; 1; 2; 10; 9; 10] 10;;

let rec min_liste = function 
    [] -> failwith "no elem"
    | x::y ->
        if y = [] then x
        else
            let curr_min = min_liste y in 
                if x < curr_min then x
                else curr_min;;

min_liste [6; 5; 3; 10; 90];;
*)
let rec exist l a = match l with
    [] -> false
    | x::y -> 
        if a = x then
            true
        else
            exist y a;;
(*
let rec doublon = function
    [] -> []
    | x::y -> 
        if exist y x then
            doublon y
        else
            [x] @ doublon y;;

doublon [4;6; 0;0;0;0;4;6;6];;

*)
let rec inserer_tete x ll = match ll with
    [] -> []
    | a::b -> [x::a] @ inserer_tete x b;;

let rec parties l = match l with
    [] -> [[]]
    | a::b -> (inserer_tete a (parties b))@(parties b);;


parties [1; 2; 3; 4];;

(* Ya surement mieux... *)
let rec sous_listes n l = 
    let p = parties l in 
    let rec garder n ll = match ll with
        [] -> []
        | a::b -> if (longueur a) == n then
                    (garder n b)@[a]
                else
                    garder n b
    in garder n p;;
sous_listes 2 [1;2;3;4];;


let inserer_tete_map x ll =
    List.map (function l -> x::l) ll;;

inserer_tete_map 1 [[1;5]; []; [9;0;10]];;

let rec parties_map l = match l with
    [] -> [[]]
    | a::b -> ( List.map (function l -> a::l) (parties b))@(parties b);;

parties_map [1; 2; 3; 4];;

let longueur_f l =
    List.fold_left (function a -> function b -> a+1) 0 l;;
longueur_f [];;

let conca_f l1 l2 = 
    List.fold_left (function a -> function b -> b::a) l1 l2;;
conca_f [1;4;5] [4;6;1];;

let met_a_plat_f ll = 
    List.fold_left (function a -> function b -> a@b) [] ll;;
met_a_plat_f [[1;4;5]; [6;1;9]; []];;

let supprime2_f l x = 
    List.fold_left (function a->function b-> if b=x then a else b::a) [] l;;

supprime2_f [10; 5; 1; 2; 10; 9; 10] 10;;

let doublon_f l = 
    List.fold_left (
        function a -> function b -> if (exist a b) then a else b::a
    ) [] l;;

doublon_f [4;6; 0;0;0;0;4;6;6];;


let map_f l f= 
    List.fold_right (function a -> function b -> (f a)::b ) 
    l [];;
map_f [1;2;3] (function a-> a+1);;


let rec sous_listes_mieux n l = match (n, l) with
     (0, _) -> [[]]
    |(_, []) -> [[]]
    |(_, x::y) ->   inserer_tete x (sous_listes_mieux n y)
;;

(* s_l 2 [1;2;3;4] *)
inserer_tete 1 [[2]; [3];[4]];;
inserer_tete 2 [[3];[4]];;
inserer_tete 3 [[4]];;

(* s_l 3 [1;2;3;4] *)
inserer_tete 1 [[2;3]; [2;4];[3;4]];;
inserer_tete 2 [[1;3];[1;4];[3;4]];;
inserer_tete 3 [[1;2]; [1;4]; [2;4]];;