public class Morpion {
    public static void main(String[] args) {
        Game game = new Game(1);
        game.jouer(0, 0);
        game.jouer(1, 0);
        game.jouer(0, 1);
        game.jouer(1, 1);
        game.jouer(0, 2);
        game.jouer(1, 0);
        game.affiche_board();
    }
}
