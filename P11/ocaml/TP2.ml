let rec longueur = function
    [] -> 0
    | x::y-> 1 + longueur y;;


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

let rec exist l a = match l with
    [] -> false
    | x::y -> 
        if a = x then
            true
        else
            exist y a;;

let rec doublon = function
    [] -> []
    | x::y -> 
        if exist y x then
            doublon y
        else
            [x] @ doublon y;;

doublon [4;6; 0;0;0;0;4;6;6];;


let rec inserer_tete x ll = match ll with
    [] -> []
    | a::b -> [[x] @ a] @ inserer_tete x b;;


let rec parties l = function
    [] -> []
    | a::b -> [inserer_tete a ] @ parties b;;

parties [1; 2; 3; 4];;

[1] -> []; [1]
[2; 1] -> [2]; [2; 1]; []; [1]