

let rec newton x y eps = 
    if (y*.y > x-.eps) && (y*.y < x+.eps) then
        y
    else
        let y2 = (y +. (x/.y))/.2. in
            newton x y2 eps;; 
let racine x = newton x x 0.001;;




let is_correct x y eps = (y*.y > x-.eps) && (y*.y < x+.eps);;
let racine_n1 x yn =
    (yn +. (x/.yn))/.2.;;    
    

let rec racine_aux x y eps = 
    if is_correct x y eps then 
        y
    else
        let yn1 = racine_n1 x y in
            racine_aux x yn1 eps;;
let racine x = racine_aux x x 0.001;;

(* 
print_float(racine 32.);;
print_endline "";; 
*)


(* 
j'aimerai ça : 
let rec appl_jusque fct x cond
mais du coup qu'un seul arg x ?? Alors que j'ai besoin
de plusieurs
*)

let rec appl_jusque fct x y eps cond = 
    if (cond x y eps) then
        y
    else
        appl_jusque fct x (fct x y) eps cond;;




let racine x = 
    appl_jusque racine_n1 x x 0.001 is_correct;;

print_float (racine 32.);;
