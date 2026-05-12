public class Game {
    private int[][] board;
    private int curr_player;

    Game(int player){
        board = new int[3][3];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board.length; j++) {
                board[i][j] = 0;
            }
        }
        curr_player = player;
    }

    public void jouer(int x, int y){
        if(board[y][x]==0 && x>=0 && x<3 && y>=0 && y<3)
            board[y][x]=curr_player;

        // Verif si curr_player a gagné

        Boolean gagne = true;
        // ligne
        for (int i = 0; i < board.length && gagne; i++) {
            if(board[i][x] != curr_player)
                gagne = false;
        }

        // colonne
        if(gagne == false){
            for (int i = 0; i < board.length && gagne; i++) {
                if(board[y][i] != curr_player)
                    gagne = false;
            }
        }
        if(gagne == false){
            for (int i = 0; i < board.length && gagne; i++) {
                if(board[i][i] != curr_player)
                    gagne = false;
            }
        }

        if(gagne == false){
            for (int i = 0; i < board.length && gagne; i++) {
                if(board[i][2-i] != curr_player)
                    gagne = false;
            }
        }
        Boolean draw = true;
        if(gagne)
            System.out.println("Player " + curr_player + " a gagné !");
        else{ //check if draw
            for (int i = 0; i < board.length && draw; i++) {
                for (int j = 0; j < board.length && draw; j++) {
                    if(board[i][j]!=0)
                        draw = false;
                }
            }
        }
        if(draw)
            System.out.println("Egalité.");
        // Switch player

        if(curr_player == 1)
            curr_player = 2;
        else
            curr_player = 1;


    }

    public void affiche_board(){
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board.length; j++) {
                System.out.print(board[i][j]);
            }
            System.out.println("");
        }
    }
}