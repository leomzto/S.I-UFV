public class ex04 {

    static class ControleRemoto {}
    static class Antena {}
    static class SistemaSom {}

    static class Televisao {
        ControleRemoto controle;
        Antena antena;
        SistemaSom som;

        public Televisao(ControleRemoto controle, Antena antena, SistemaSom som) {
            this.controle = controle;
            this.antena = antena;
            this.som = som;
        }
    }
}

