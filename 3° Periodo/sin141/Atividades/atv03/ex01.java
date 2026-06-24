package atv03;

public class ex01 {

    static class Pessoa {
        String nome;
        String telefone;

        public Pessoa(String nome, String telefone) {
            this.nome = nome;
            this.telefone = telefone;
        }
    }

    static class Agenda {
        int ano;
        float altura;
        boolean emUso;
        Pessoa[] pessoas;
        String nomeAgenda;
        String nomeDono;

        public Agenda(int ano, float altura, boolean emUso, String nomeAgenda, String nomeDono, int qtdPessoas) {
            this.ano = ano;
            this.altura = altura;
            this.emUso = emUso;
            this.nomeAgenda = nomeAgenda;
            this.nomeDono = nomeDono;
            this.pessoas = new Pessoa[qtdPessoas];
        }
    }
}
