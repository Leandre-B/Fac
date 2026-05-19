
public class Game {
    private int[][] board;
    private int curr_player;
    private Boolean game_end;

    Game(int player){
        board = new int[3][3];
        game_end = false;
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board.length; j++) {
                board[i][j] = 0;
            }
        }
        curr_player = player;
    }

    public int getCurr_player(){
        return curr_player;
    }

    public Boolean jouer(int x, int y){
        if(game_end)
            return false;
        Boolean placed = false;
        if(x>=0 && x<3 && y>=0 && y<3){
            if(board[y][x]==0){
                placed = true;
                board[y][x]=curr_player;
            }
        }
        if(!placed){
            System.out.println("Cannot play here ! ");
            return false;
        }
        // Verif si curr_player a gagné

        Boolean gagne = true;
        // ligne
        for (int i = 0; i < board.length; i++) {
            if(board[i][x] != curr_player)
                gagne = false;
        }

        // colonne
        if(gagne == false){
            gagne = true;
            for (int i = 0; i < board.length; i++) {
                if(board[y][i] != curr_player)
                    gagne = false;
            }
        }
        if(gagne == false){
            gagne = true;
            for (int i = 0; i < board.length; i++) {
                if(board[i][i] != curr_player)
                    gagne = false;
         
                }
        }

        if(gagne == false){
            gagne = true;
            for (int i = 0; i < board.length; i++) {
                if(board[i][2-i] != curr_player)
                    gagne = false;
            }
        }
        if(gagne){
            System.out.println("Player " + curr_player + " a gagné !");
            game_end = true;
        }
        else{ //check if draw
            Boolean draw = true;
            for (int i = 0; i < board.length && draw; i++) {
                for (int j = 0; j < board.length && draw; j++) {
                    if(board[i][j]==0)
                        draw = false;
                }
            }
            if(draw){
                System.out.println("Egalité.");
                game_end = true;
            }
        }

        // Switch player
        if(curr_player == 1)
            curr_player = 2;
        else
            curr_player = 1;
        

        this.affiche_board();
        return placed;
    }

    public void affiche_board(){
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board.length; j++) {
                System.out.print(board[i][j]+" ");
            }
            System.out.println("");
        }
        System.out.println("");
        System.out.println("");
    }
}