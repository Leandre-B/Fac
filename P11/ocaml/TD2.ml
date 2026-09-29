let rec nieme l x = match l with
    [] -> failwith "pas de nieme elem"
    | r::y -> 
        if x=0 then
            r
        else
            nieme y (x-1) ;;


nieme [1; 4; 2; 5; 6] 4;;

let rec prefixe l p = match p with
    [] -> true
    | x::y ->
        match l with
            [] -> false
            | u::v -> 
                if x=u then
                    prefixe v y
                else
                    false;;
(* 
match (l1, l2) with
[], _ -> true
_, [] -> false
.....
*)

prefixe [1;5;6;7] [1;1];;

let rec inclusion  l s = match (l, s) with
     _, [] -> true
    | [], _ -> false
    | x1::r1, x2::r2 ->
        if x1=x2 then
            inclusion r1 r2
        else
            inclusion r1 s;;

inclusion [1;2;3;4;5] [1;5];;


let rec minimum l = match l with
    [] -> failwith "pas d'elem"
    |x::[] -> x
    | x::y ->
        let curr_min = minimum y in
            if curr_min<x then curr_min
            else x;;

minimum [1;9999999;2;5];;



(* Exo 4 *)
let rec trouver_tous p li = match li with
[] -> []
| x::r ->
    if (p x) then
        x::(trouver_tous p r)
    else
        trouver_tous p r;;

trouver_tous (function x -> x mod 2 == 0) [1;4;5;2];;

let rec ajouter n li = 
    List.map (function x -> x+n) li ;;

let rec appartient x l = match l with
    [] ->false
    | y::r -> 
        if y=x then true
        else appartient x r;;


let appartient_sslite x ll = trouver_tous (appartient x) ll;;

appartient_sslite 4 [[5;3;4]; [2;1]];;

let supprime_ssliste x ll = List.map( trouver_tous (function n -> x!=n) ) ll;;

supprime_ssliste 4 [[5;3;4]; [2;1]];;
    

(* Exo 5 *)
let plus = function x-> function y->x+y;;

List.fold_left (function x-> function y->x+y) 0 [1;2;3;4;5];;



let rec ajouter_tete x ll = match ll with
    [] -> [[]]
    | y::r -> (x::y)::ajouter_tete x r;;
    
ajouter_tete 1 [[];[1;5];[0;1;0]];;