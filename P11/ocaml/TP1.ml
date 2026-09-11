

let prixTTC prix_ht = prix_ht*.1.2;;


let isBisextil annee = 
    if ((annee mod 4) = 0) && ((annee mod 100) != 0) then
        true
    else
        (annee mod 400) = 0;;
(*Printf.printf "Is biss : %b\n" (isBisextil 2016);;*)

let isLower c = 
    (c >='a') && (c<='z');;

(*Printf.printf "Lower : %b\n" (isLower 'b');;*)

let moyenne2 a b = (a+b)/2;;
(*print_int (moyenne2 12 2);;*)

let quotientRest a b = (a/b,a mod b);;

let (q, r)  = quotientRest 16 3 in
    Printf.printf "q : %d, r : %d,\n" q r;;


let puissance_4 x = 
    let carre a = a*a in 
        (carre x) * (carre x);;
(*print_int(puissance_4 4);;*)

let min_to_maj x = char_of_int(int_of_char(x) - 32);;
min_to_maj 'b';; 


let rec fibo x = 
    if x = 0 then
        0
    else if x = 1 then
        1
    else
        fibo (x-1) + fibo (x-2);;

let rec nPremCarre x =
    if x = 0 then
        0
    else
        x*x + nPremCarre (x-1);;

let rec sigma f x = 
    if x=0 then
        f x
    else
        (f x) + sigma f (x-1);;

let nPremCarre2 x = 
    sigma (function a->a*a) x;;



(* rond f g= g ∘ f *)
let rond f g x = g (f x);;

rond fibo nPremCarre 4;;


(* NEWTON *)


let rec newton x y eps = 
    if (y*.y > x-.eps) && (y*.y < x+.eps) then
        y
    else
        let y2 = (y +. (x/.y))/.2. in
            newton x y2 eps;; 
let racine x = newton x x 0.001;;



let racine2 x = 
    let eps = 0.001 in 
    let is_correct x y = (y*.y > x-.eps) && (y*.y < x+.eps) in 
        let racine_n1 x yn = (yn +. (x/.yn))/.2. in 
            let rec newton x y = 
                if is_correct x y then
                    y
                else
                    let y2 = racine_n1 x y in
                        newton x y2
            in
                newton x x;;

racine2 32.;;
