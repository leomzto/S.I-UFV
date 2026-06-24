package RevisaoP3.ex01;

public class Main {
    public static void main(String[] args) {
        Biblioteca biblioteca = new Biblioteca();

        biblioteca.adicionar(new Livro ("1213", "senhor dos aneis", "tou"));
        biblioteca.adicionar(new Livro ("1214", "senhor", "ton"));
        biblioteca.adicionar(new Livro ("1215", "senhor dos ", "toen"));
        biblioteca.adicionar(new Livro ("1216", "aneis", "ken"));
        biblioteca.adicionar(new Livro ("1217", "aneis do senhor", "tuken"));

    }
}
