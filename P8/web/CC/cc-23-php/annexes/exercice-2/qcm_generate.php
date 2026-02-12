<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8">
    <title>QCM</title>
    <style>
        div {
            border: 1px solid black;
            margin: 2px;
            padding: 0px 5px 1px;
        }
    </style>
</head>

<body>
    <form method="post" action="qcm_check.php">
        <?php
        require_once __DIR__ . '/questions.php';
        require_once __DIR__ . "/questions_answers.php";
        require_once __DIR__ . "/encode_statement.php";
        $questions=questions(intval($_GET["questions"], 10));
        $answers=questionsAnswers($questions);

        // QUESTION 5
        // A COMPLETER
        foreach($questions as $kq=>$vq){
            echo "<div>";
            echo "<p>";
            echo encodeStatement($vq);
            echo "</p>";
            foreach($answers[$kq] as $ka=>$va){
                if($ka!="0"){
                    echo "<input type=\"radio\" name=\"".$kq."\" value=\"".$va["SOLUTION"]."\" checked/>";
                    echo "<label>".encodeStatement($va["ANSWER"])."</label>";
                    echo "<br>";
                }
            }
            echo "</div>";
        }
        ?>

        <br />
        <input type="submit" value="Soumettre" />
    </form>
</body>

</html>