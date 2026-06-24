package atv02;

import java.util.ArrayList;

class ListaAutorizacao {
    String nomeEvento;
    ArrayList<String> pessoasAutorizadas;

    public ListaAutorizacao(String nomeEvento) {
        this.nomeEvento = nomeEvento;
        this.pessoasAutorizadas = new ArrayList<>();
    }

    void adicionarPessoa(String nome) {
        pessoasAutorizadas.add(nome);
    }

    boolean estaAutorizado(String nome) {
        return pessoasAutorizadas.contains(nome);
    }

    void exibirLista() {
        System.out.println("Evento: " + nomeEvento);
        System.out.println("Pessoas autorizadas:");
        for (String pessoa : pessoasAutorizadas) {
            System.out.println("- " + pessoa);
        }
    }
}