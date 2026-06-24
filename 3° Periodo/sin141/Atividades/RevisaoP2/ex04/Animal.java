package RevisaoP2.ex04;

public abstract class Animal {
    private String nome;
    private int idade;

    public Animal() {
        this.nome = "";
        this.idade = 0;
    }

    public Animal(String nome, int idade) {
        this.nome = nome;
        this.idade = idade;
    }

    public String getNome() { return nome; }
    public int getIdade() { return idade; }
    public void setNome(String nome) { this.nome = nome; }
    public void setIdade(int idade) { this.idade = idade; }

    public void apresentar() {
        System.out.println("Nome: " + nome);
        System.out.println("Idade: " + idade);
    }

    public abstract void emitirSom();
}
